/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * main.cc
 * Copyright (C) 2012 imouse <imouse@wonderland>
 *
 * anjuta_test is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * anjuta_test is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <map>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <boost/shared_ptr.hpp>
#include <boost/lambda/lambda.hpp>
#include <boost/lambda/bind.hpp>

using namespace std;

class Node;
class Coordinate;

typedef boost::shared_ptr<Node> NodePtr;
typedef list<NodePtr> Path;

typedef multimap<unsigned long,Coordinate> OpenSet;
typedef set<Coordinate> CloseSet;
typedef vector<Coordinate> AdjNodes;
typedef map<Coordinate, NodePtr> NodesMap;

static ofstream out;

class Coordinate
{
    public:
        Coordinate()
            : x(0),y(0)
        {

        }

        Coordinate(unsigned long x, unsigned long y)
        {
            this->x = x;
            this->y = y;
        }
        friend bool operator < (const Coordinate &lft, const Coordinate &rht)
        {
            return (lft.x <<16|lft.y) < (rht.x <<16| rht.y);
        }

        friend bool operator == (const Coordinate &lft, const Coordinate &rht)
        {
            return lft.x == rht.x && lft.y == rht.y;
        }

        friend ostream & operator << (ostream &out, Coordinate cd)
        {
            out << "{" << cd.x << "," << cd.y << "}";
            return out;
        }
    public:
        unsigned long x;
        unsigned long y;
};

class Node
{
    public:
        Node()
        {
            _cur.x = 0;
            _cur.y = 0;
            _parent.reset();
            _g = 0;
            _f = 0;
        }

        Node(Coordinate cd)
        {
            _cur = cd;
            _parent.reset();
            _g = 0;
            _f = 0;
        }

        Node(unsigned long x, unsigned long y)
        {
            _cur.x = x;
            _cur.y = y;
            _parent.reset();
            _g = 0;
            _f = 0;
        }

        Node(const Node &node)
        {
            _cur = node.get_coordinate();
            _parent = node.get_parent();
            _g = node.get_g();
            _f = node.get_f();
        }


        friend bool operator < (const Node &l, const Node &r)
        {
            return l._f < r._f;
        }

        Coordinate get_coordinate() const { return _cur; }
        NodePtr get_parent() const { return _parent; }
        void set_parent(NodePtr &parent) { _parent = parent; }

        unsigned long get_g() const { return _g; }
        void set_g(unsigned long g) { _g = g; }

        unsigned long get_f() const { return _f; }
        void set_f(unsigned long h) {_f = _g + h; }

    private:
        Coordinate _cur;
        unsigned long _g;
        unsigned long _f;

        // parent
        NodePtr _parent;
};

// sort func

class GameMap
{
    public:
        GameMap() : _ptr(NULL) { };
        GameMap(unsigned long width, unsigned long height)
        {
            _ptr = new unsigned char[width*height];
            _width = width;
            _height = height;
        }
        GameMap(const char *ptr, unsigned long width, unsigned long height)
        {
            init(ptr, width, height);
        }

        bool init(const char *ptr, unsigned long width, unsigned long height)
        {
            _ptr = new unsigned char[width*height];
            if (_ptr != NULL)
                memcpy(_ptr, ptr, width*height);
            _width = width;
            _height = height;
            return true;
        }

        bool load_from_file(const string fname)
        {
            string buffer;
            string all;
            ifstream fmap;
            fmap.open(fname.c_str());
            if (!fmap)
                return false;

            _width = 0;
            _height = 0;
            while (getline(fmap, buffer))
            {
                _width = buffer.size();
                _height++;
                all.append(buffer);
            }

            if (_ptr != NULL)
                delete [] _ptr;
            _ptr = new unsigned char [_width * _height];
            memcpy(_ptr, all.c_str(), all.size());

            transform();

            return true;
        }

        bool dump(string dumpfile)
        {
            string buffer;
            ofstream df;
            df.open(dumpfile.c_str());
            unsigned long l = 0;
            for (l=0; l<_height*_width; ++l)
            {
                if (*(_ptr+l) == 1)
                    *(_ptr+l) = '.';
                if (*(_ptr+l) == 255)
                    *(_ptr+l) = '@';
            }

            for (l=0; l<_height; ++l)
            {
                buffer.append((char*)_ptr+l*_width, _width);
                buffer.append("\n");
            }

            df << buffer;
            return true;
        }

        unsigned int get_steps(Coordinate cd) { return get_steps(cd.x, cd.y); }
        unsigned int get_steps(unsigned long x, unsigned y)
        {
            if (x >= _width || y >= _height)
                return 0;

            return *(_ptr+x+y*_width);
        }

        void set_cell(unsigned long x, unsigned y, unsigned char ch)
        {
            if (x >= _width || y >= _height)
                return;
            *(_ptr+x+y*_width) = ch;
        }

        unsigned int get_distance(const Coordinate &src, const Coordinate &dest)
        {
            // man ha dun algrithem;
            return ((src.x>dest.x)?(src.x - dest.x):(dest.x - src.x)) + \
                ((src.y>dest.y)?(src.y - dest.y):(dest.y - src.y));
        }

        AdjNodes get_adjnodes(const Coordinate &cd) { return get_adjnodes(cd.x, cd.y); }
        AdjNodes get_adjnodes(const unsigned long x, const unsigned long y)
        {
            AdjNodes adjnodes;

            if (x >= _width || y >= _height)
                return adjnodes;

            // (1,0),(-1,0), (0,1),(0,-1)
            if (x != _width-1)
                adjnodes.push_back(Coordinate(x+1,y));
            if (x != 0)
                adjnodes.push_back(Coordinate(x-1,y));
            if (y != _height-1)
                adjnodes.push_back(Coordinate(x,y+1));
            if (y != 0)
                adjnodes.push_back(Coordinate(x,y-1));

            return adjnodes;
        }

        bool can_get_through(const Coordinate &cd) const
        {
            return *(_ptr + cd.x + cd.y*_width) != 255;
        }
    private:
        void transform()
        {
            for (unsigned long l=0; l<_width*_height; l++)
            {
                if (*(_ptr+l) == '.')
                    *(_ptr+l) = 1;
                else
                    *(_ptr+l) = 255;
            }
        }

    private:
        unsigned char *_ptr;
        unsigned long _width;
        unsigned long _height;

        map<unsigned long,NodePtr> _nodes_cache;
};


class AStar
{
    public:
        AStar() {}

        Path get_shorten_path(GameMap &gmap, const NodePtr &src, const NodePtr &dest)
        {
            OpenSet open_set;
            CloseSet closed_set;
            Path _tmpPath;
            bool found = false;
            NodePtr cur_node;
            NodePtr next_node;
            NodesMap nodes_map;

            // add to OPEN_SET
            open_set.insert(make_pair<unsigned long, Coordinate>(src->get_f(),src->get_coordinate()));
            nodes_map.insert(make_pair<Coordinate,NodePtr>(src->get_coordinate(), src));

            while (!open_set.empty() && !found)
            {
                cur_node = nodes_map[open_set.begin()->second];

                closed_set.insert(cur_node->get_coordinate());
                open_set.erase(find_if(open_set.begin(), open_set.end(),\
                                       boost::lambda::bind(&OpenSet::value_type::second,boost::lambda::_1) == \
                                       cur_node->get_coordinate()));

                if (cur_node->get_coordinate() == dest->get_coordinate())
                {
                    // arrived
                    found = true;
                    // re-path;
                    NodePtr _res_tmp = cur_node;
                    while (_res_tmp != NULL)
                    {
                        _tmpPath.push_front(_res_tmp);
                        _res_tmp = _res_tmp->get_parent();
                    }
                    break;
                    // open_set
                }

                AdjNodes adjnode_set = gmap.get_adjnodes(cur_node->get_coordinate());
                AdjNodes::iterator it = adjnode_set.begin();
                for (; it != adjnode_set.end(); ++it)
                {
                    // can't get through, like wall;
                    // already in closed set;
                    // ignore it;
                    if (!gmap.can_get_through(*it) || \
                        closed_set.count(*it) != 0)
                    {
                        continue;
                    }

                    unsigned long new_g = cur_node->get_g() + gmap.get_steps(*it);
                    bool better = false;
                    OpenSet::iterator fit = find_if(open_set.begin(), open_set.end(), 
                        boost::lambda::bind(&OpenSet::value_type::second,\
                        boost::lambda::_1)== (*it)); 
                    if (fit == open_set.end())
                    {
                        better = true;
                    }
                    else
                    {
                        if (new_g < nodes_map[fit->second]->get_g())
                        {
                            better = true;
                        }
                    }

                    if (better)
                    {
                        NodePtr _tmp(new Node(*it));

                        _tmp->set_g(new_g);
                        _tmp->set_f(gmap.get_distance(*it, dest->get_coordinate()));
                        _tmp->set_parent(cur_node);
                        open_set.insert(make_pair<unsigned long,Coordinate>(_tmp->get_f(),*it));

                        // update 
                        nodes_map[*it] = _tmp;
                    }
                } // for

            } // while

            return _tmpPath;
        }
};

int main()
{
    out.open("log.txt");

    GameMap gmap(50,50);
    gmap.load_from_file("map.txt");

    NodePtr src(new Node(Coordinate(0,0)));
    NodePtr dest(new Node(Coordinate(4,3)));

    AStar astar;
    Path res;
    res = astar.get_shorten_path(gmap, src, dest);
    Path::iterator it = res.begin();
    for (; it!=res.end(); ++it)
    {
        cout << (*it)->get_coordinate() << " ";
        gmap.set_cell((*it)->get_coordinate().x,(*it)->get_coordinate().y,'>');
    }
    cout << endl;

    gmap.dump("map_res.txt");

    std::cout << "Hello world!" << std::endl;
    return 0;
}
