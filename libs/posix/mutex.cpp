/**
 * @file mutex.cpp
 * @brief a mutex class implement
 * @author wyf
 * @version 0.1
 * @date 2013-12-23
 */

#include "mutex.h"

namespace koala
{

mutex::mutex()
{
    init();
}

int mutex::init()
{
    int rc;
    pthread_mutexattr_t attr;

    rc = pthread_mutexattr_init(&attr);
    if (rc != 0)
    {
        pthread_mutexattr_destroy(&attr);
        return rc;
    }

    rc = pthread_mutex_init(&_mutex, &attr);

    pthread_mutexattr_destroy(&attr);

    return rc;
}

mutex::~mutex()
{
    pthread_mutex_destroy(&_mutex);
}


int mutex::lock()
{
    return pthread_mutex_lock(&_mutex);
}

int mutex::unlock()
{
    return pthread_mutex_unlock(&_mutex);
}

int mutex::try_lock()
{
    return pthread_mutex_trylock(&_mutex);
}

mutex::auto_lock::auto_lock(mutex &_m)
    :_mutex(_m)
{
    _mutex.lock();
}

mutex::auto_lock::~auto_lock()
{
    _mutex.unlock();
}

// no copyable
mutex::mutex(mutex &)
{

}

mutex & mutex::operator=(mutex &)
{
    return *this;
}
};
