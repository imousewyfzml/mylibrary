/*
 * =====================================================================================
 *
 *       Filename:  tobjectpool.cpp
 *
 *    Description:  A object pool.
 *
 *        Version:  1.0
 *        Created:  07/02/2014 08:36:30 PM
 *       Revision:  
 *       Compiler:  gcc
 *
 *         Author:  tony, 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "tobjectpool.h"
#include <algorithm>

template <typename T>
const int TObjectPool<T>::kDefaultChunkSize;

template <typename T>
TObjectPool<T>::TObjectPool (int chunkSize) throw(std::invalid_argument, 
        std::bad_alloc) : mChunkSize(chunkSize) 
{
    if (mChunkSize <= 0)
    {
        throw std::invalid_argument("chunk size must be positive");
    }

    allocateChunk();
}

template <typename T>
void TObjectPool<T>::allocateChunk()
{
    T* newObjects = new T[mChunkSize];
    mAllObjects.push_back(newObjects);
    for (int i=0; i<mChunkSize; i++)
    {
        mFreeList.push(&newObjects[i]);
    }
}

// static 
template <typename T>
void TObjectPool<T>::arrayDeleteObject(T *obj)
{
    delete [] obj;
}

template <typename T>
TObjectPool<T>::~TObjectPool()
{
    // free each of the allocation chunks
    std::for_each(mAllObjects.begin(), mAllObjects.end(), arrayDeleteObject);
}


template <typename T>
T& TObjectPool<T>::acquireObject()
{
    if (mFreeList.empty()) 
    {
        allocateChunk();
    }

    T* obj = mFreeList.front();
    mFreeList.pop();
    return (*obj);
}

template <typename T>
void TObjectPool<T>::releaseObject (T& obj)
{
    mFreeList.push(&obj);
}


