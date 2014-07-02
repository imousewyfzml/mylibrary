/**
 * @file thread.cpp
 * @brief implement a thread class
 * @author wyf
 * @version 0.1
 * @date 2013-12-23
 */

#include <iostream>
#include "thread.h"

namespace koala
{

extern "C" {
    static void *hook(void *args)
    {
        thread *pth = static_cast<thread *>(args);
        try
        {
            pth->thread_loop();
        } catch (...) {
            if (!pth->name().empty())
            {
                std::cerr << pth->name() << " terminating" << std::endl;
            }
        }
        pth->_done();

        return pth;
    }
}

thread::thread()
    : _id(-1),_runing(false)
{

}

thread::thread(const std::string &name)
    : _id(-1), _runing(false), _name(name)
{

}

thread::~thread()
{

}


/* --------------------------------------------------------------------------*/
/**
 * @brief Initilize before thread runing.
 *
 * @Returns <0,ERROR; =0,SUCCESS;
 */
/* ----------------------------------------------------------------------------*/
int thread::ready_to_run()
{
    return 0;
}


/* --------------------------------------------------------------------------*/
/**
 * @brief create a thread to run;
 *
 * @Returns <0, ERROR; =0,SUCCESS;
 */
/* ----------------------------------------------------------------------------*/
int thread::run()
{
    koala::mutex::auto_lock lk(_mutex);
    int ret = ready_to_run();
    if (ret < 0)
    {
        return ret;
    }

    ret = pthread_create(&_id, NULL, hook, this);
    if (ret < 0)
    {
        return ret;
    }
    
    _runing = true;
    return 0;
}


/* --------------------------------------------------------------------------*/
/**
 * @brief return the thread id;
 *
 * @Returns thread ID;
 */
/* ----------------------------------------------------------------------------*/
pthread_t thread::id()
{
    return _id;
}


std::string & thread::name()
{
    return _name;
}

void thread::_done()
{
    koala::mutex::auto_lock lk(_mutex);
    _runing = false;
}

};
