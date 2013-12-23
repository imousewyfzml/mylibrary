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
#include <unistd.h>
#include "thread.h"

using namespace std;

class test_thread : public koala::thread
{
public:
    virtual int thread_loop()
    {
        cerr << "test thead runing " << endl;
    }
};


int main()
{
    test_thread th;
    th.run();
    sleep(10);
}
