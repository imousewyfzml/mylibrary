/*
 * =====================================================================================
 *
 *       Filename:  tobjectpool_test.cpp
 *
 *    Description:  test tobject pool
 *
 *        Version:  1.0
 *        Created:  07/02/2014 08:49:40 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */


#include "../tobjectpool.cpp"
#include <string>

int main(int argc, char **argv)
{
    TObjectPool<std::string> strPool(100);

    std::string& tmp = strPool.acquireObject();
    strPool.releaseObject(tmp);

    return 0;
}
