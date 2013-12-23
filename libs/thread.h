/**
 * @file thread.h
 * @brief implement a thread class
 * @author wyf
 * @version 0.1
 * @date 2013-12-23
 */

#include <pthread.h>
#include <string>
#include "mutex.h"

namespace koala
{

class thread
{
public:
    thread();
    thread(const std::string &name);
    ~thread();

    virtual int run(void);
    virtual int ready_to_run(void);
    virtual int thread_loop(void) = 0;

    inline pthread_t id();
    inline std::string& name();

    inline void _done();
private:
    pthread_t _id;
    std::string _name;

    bool _runing;

    koala::mutex _mutex;
};


};
