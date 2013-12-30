/**
 * @file condition.cpp
 * @brief a condition class
 * @author wyf
 * @version 0.1
 * @date 2013-12-24
 */

#include "condition.h"

namespace koala
{

condition::condition(mutex *mu)
    : _mu(mu)
{
    int rc = pthread_cond_init(&_cond, NULL);
    if (rc != 0)
    {
        // log rc
    }
}

condition::~condition()
{
    int rc = pthread_cond_destroy(&_cond);
    if (rc != 0)
    {

    }
}

int condition::wait()
{
    int rc = pthread_cond_wait(&_cond, &_mu->_mutex);
    if (rc != 0)
    {
        return rc;
    }
    return 0;
}

int condition::signal()
{
    int rc = pthread_cond_signal(&_cond);
    if (rc != 0)
    {
        return rc;
    }

    return 0;
}

int condition::broadcast()
{
    int rc = pthread_cond_broadcast(&_cond);
    if (rc != 0)
    {
        return rc;
    }

    return 0;
}

};
