#include <vector>
#include <algorithm>

using namespace std;

class Node;
typedef vector<Node *> QNodes;
// 坐标
class Location
{
    public:
        Location(int x, int y)
        {
            _x = x;
            _y = y;
        }

        bool operator == (const Location &sLocation)
        {
            if (sLocation._x == _x && sLocation._y == _y)
                return 1;
            else
                return 0;
        }

    public:
        int _x;
        int _y;
};

// 路径上的一个节点
class Node
{
    public:
        Node(const Location &L, int mCost, int lid, Node *parent = NULL)
            :_loc(L),_mCost(mCost),_lid(lid),_parent(parent)
        {
            _sorce = 0;
        }

        int operator = (const Node &n)
        {
            if (n._lid == _lid)
                return 1;
            else
                return 0;
        }

    public:
        Location _loc; // 位置
        int _mCost; // 移动到此处花费的步数
        int _sorce; // 从源到此处最近距离+此点到终点的最短路径
        int _lid; // 在map中的唯一ID
        Node *_parent; //路径中的上一个节点
};

// 地图
class MapHandler
{
    public:
        MapHandler()
        {
        }
        MapHandler(const vector<int> vmapdata, int w, int h)
        {
            _mapdata = vmapdata;
            w = _width;
            h = _high;
        }
    
        // 根据location实力化一个节点
        Node * get_node(const Location &L)
        {
            int x = L._x;
            int y = L._y;
            int cost = 0;

            if (x<0 || x>=_width || y<0 || y>=_high)
                return NULL;
            cost = _mapdata[y*_width+x];
            if (cost == -1)
                return NULL;

            return new Node(L, cost, (y*_width+x));
        }

        // 获取周围的节点
        QNodes get_neighbor_nodes(const Node *cur_node, const Location &dst)
        {
            QNodes result;

            Location cl = cur_node->_loc;
            Location dl = dst;

            Node * pn = NULL;
            
            pn = _handle_node(cl._x+1, cl._y, cur_node, dl._x, dl._y);
            if (pn != NULL)
                result.push_back(pn);
            pn = _handle_node(cl._x-1, cl._y, cur_node, dl._x, dl._y);
            if (pn != NULL)
                result.push_back(pn);
            pn = _handle_node(cl._x, cl._y+1, cur_node, dl._x, dl._y);
            if (pn != NULL)
                result.push_back(pn);
            pn = _handle_node(cl._x, cl._y-1, cur_node, dl._x, dl._y);
            if (pn != NULL)
                result.push_back(pn);

            return result;
        }

        
    private:
        Node *_handle_node(const int x, const int y, const Node *cur_node, const int dst_x, const int dst_y)
        {
            int dx,dy;
            int emCost;
            Location L(x,y);
            Node *pn = get_node(L);
            if (pn != NULL)
            {
                dx = max(dst_x,x) - min(dst_x,x);
                dy = max(dst_y,y) - min(dst_y,y);
                emCost = dx+dy;
                pn->_mCost += cur_node->_mCost;
                pn->_sorce += pn->_mCost + emCost;
                pn->_parent = (Node *)cur_node;
            }
            return pn;
        }
        

    private:
        vector<int> _mapdata; // 每个位置的权重; 地图数据
        int _width;
        int _high;
};

// 最终路径结果
class Path
{
    public:
        Path(const QNodes nodes, int total_cost)
        {
            _result = nodes;
            _total_cost = total_cost;
        }

    public:
        QNodes _result;
        int _total_cost;
};

// A* 算法
class AStar
{
    public:
        AStar(const MapHandler& mph)
        {
            _mph = mph;
        }

        Path find_path(const Location &from_loc, const Location &to_loc)
        {
            Node * next_node = NULL;
            Node * finish_node = NULL;
            Location end = to_loc;

            Node *fnode = _mph.get_node(from_loc);
            if (fnode == NULL)
                return Path(_open_nodes, -1);

            // 放入 open set中
            _open_nodes.push_back(fnode);
            _open_set.push_back(fnode->_lid);
            
            // 起始node
            next_node = fnode;
            while (next_node != NULL)
            {
                finish_node = _handle_node(next_node, end);
                if (finish_node != NULL)
                    return _trace_node(finish_node);
                next_node = _get_best_open_node();
            }

        }
    private:
        // 返回查找路径
        Path _trace_node(const Node *finish_node)
        {
            QNodes result;
            int total_cost;
            
            // TODO: 查找路径
            return Path(result, total_cost);
        }
        // 获取权重值最小的
        Node * _get_best_open_node()
        {
            Node * best_node = NULL;
            QNodes::iterator it = _open_nodes.begin();

            for (; it != _open_nodes.end(); ++it)
            {
                if (best_node == NULL)
                {
                    best_node = *it;
                }
                else
                {
                    if (best_node->_sorce >= (*it)->_sorce)
                    {
                        best_node = *it;
                    }
                } // if
            }//for 

            return best_node;
        }

        // 对周围的节点进行处理
        Node * _handle_node(const Node *cur_node, const Location &end)
        {
            QNodes neighbor_nodes;
            // 从open set中取出一个节点开始计算
            int idx = _node_idx(cur_node, _open_nodes);
            // 将 open set中的当前节点pop掉
            _discard_nodes.push_back(_open_nodes[idx]);
            _open_nodes.erase(_open_nodes.begin() + idx);
            // 添加到close_set中
            _close_set.push_back(cur_node->_lid);

            // 获取周围的节点
            neighbor_nodes = _mph.get_neighbor_nodes(cur_node, end);
            QNodes::iterator it = neighbor_nodes.begin();
            for (; it != neighbor_nodes.end(); ++it)
            {
                if ((*it)->_loc == end)
                    return (*it);
                else if (_check_in_set((*it)->_lid, _close_set) != 0)
                    // 在close set中的，不必关心
                    continue;
                else if (_check_in_set((*it)->_lid, _open_set) != 0)
                {
                    // 已经在Open中了，那么比较一下
                    idx = _node_idx((*it), _open_nodes);
                    Node * on = _open_nodes[idx];
                    if ((*it)->_mCost < on->_mCost)
                    {
                        // 将on从open中pop掉
                        // 删除在open_set中的集合
                        _discard_nodes.push_back(on);
                        _open_nodes.erase(_open_nodes.begin() + idx);
                        // 将it加入到open集合中
                        _open_nodes.push_back((*it));
                        _open_set.push_back((*it)->_lid);
                    }

                }
                else
                {
                    _open_nodes.push_back((*it));
                    _open_set.push_back((*it)->_lid);
                }

            } //for 

            return NULL;
            
        }
        
        int _node_idx(const Node *cur_code, QNodes &set)
        {
            for (int i=0; i<(int)_open_set.size(); i++)
            {
                if (set[i]->_lid == cur_code->_lid)
                    return i;
            }
            return -1;
        }

        int _check_in_set(const int lid, vector<int> &set)
        {
            vector<int>::iterator it = find(set.begin(), set.end(), lid);
            if (it != set.end())
                return 1;
            else
                return 0;
        }
        
    private:
        MapHandler _mph;
        vector<int> _open_set; // open set
        vector<int> _close_set; // close set
        QNodes _open_nodes; // open中的节点实例
        
        // 排除掉的节点
        QNodes _discard_nodes;
        
};


int main(int argc, char **argv)
{
    return 0;
}
