/**
 * @file mutex.h
 * @brief a mutex class
 * @author wyf
 * @version 0.1
 * @date 2013-12-23
 */

#ifndef KOALA_MUTEX
#define KOALA_MUTEX

#include <pthread.h>

namespace koala
{

class condition;

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

    // not copyable
    mutex(mutex &);
    mutex & operator=(mutex &);

    // In condition
    // we access _mutex for wait;
    friend class condition;

    typedef struct lockstate
    {
        pthread_mutex_t *state;
    }lockstate;


    inline void unlock(lockstate &state) const;
    inline void lock(lockstate &state) const;

    mutable pthread_mutex_t _mutex;
};


}; // namespace koala

#endif
