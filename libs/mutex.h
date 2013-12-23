/**
 * @file mutex.h
 * @brief a mutex class
 * @author wyf
 * @version 0.1
 * @date 2013-12-23
 */


#include <pthread.h>

namespace koala
{

class mutex
{
public:
    mutex();
    ~mutex();

    int lock();
    int unlock();
    int try_lock();

    class auto_lock
    {
    public:
        auto_lock(mutex &m);
        ~auto_lock();
    private:
        mutex &_mutex;
    };

private:
    int init();

    pthread_mutex_t _mutex;
};


};
