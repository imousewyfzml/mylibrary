/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  test thread / mutex
 *
 *        Version:  1.0
 *        Created:  12/23/2013 10:22:14 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <list>
#include <unistd.h>
#include "thread.h"
#include "condition.h"

using namespace std;

template <typename T>
class test_thread : public koala::thread
{
public:
    virtual int thread_loop()
    {
        cerr << "test thead runing " << endl;
        cerr << "wait list " << endl;
        for(;;)
        {
            cerr << get() << endl;
        }
    }

    void put(T item)
    {
        koala::mutex::auto_lock lk(_mutex);
        _list.push_back(item);
        _cond.signal();
    }

    T get()
    {
        if (_list.empty())
        {
            _cond.wait(_mutex);
        }

        T tmp = _list.front();
        _list.pop_front();
        return tmp;
    }

private:
    list<T> _list;
    koala::condition _cond;
    koala::mutex _mutex;
};


int main()
{
    test_thread<int> th;
    th.run();
    sleep(3);
    th.put(1);
    sleep(2);
    th.put(2);
    sleep(1);
    th.put(1);
}
