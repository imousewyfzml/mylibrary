/**
 * @file condition.h
 * @brief 
 * @author wyf
 * @version 0.1
 * @date 2013-12-24
 */

#ifndef KOALA_CONDITION
#define KOALA_CONDITION

#include <pthread.h>
#include "mutex.h"

namespace koala
{

class condition
{
public:
    condition(mutex *m);
    ~condition();

    int wait();
    // int timed_wait();
    int signal();
    int broadcast();

private:
    pthread_cond_t _cond;
    mutex* _mu;
};

};

#endif
