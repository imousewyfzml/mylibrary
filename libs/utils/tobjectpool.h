#ifndef _OBJECTPOOL_H
#define _OBJECTPOOL_H

#include <queue>
#include <vector>
#include <stdexcept>
#include <memory>

using std::queue;
using std::vector;

template <typename T>
class TObjectPool
{
public:
    TObjectPool (int chunksize = kDefaultChunkSize) 
        throw( std::invalid_argument, std::bad_alloc);

    ~TObjectPool();

    T& acquireObject();

    void releaseObject (T& obj);

protected:

    // mFreelist store the objects that are not currtently in use 
    // by clients
    queue<T*> mFreeList;

    // mAllObjects store proints to all the objects. in use or not.
    vector<T*> mAllObjects;

    int mChunkSize;

    static const int kDefaultChunkSize = 16;

    void allocateChunk();
    static void arrayDeleteObject (T* obj);

private:
    // prevent assignment and pass-by-value
    TObjectPool (const TObjectPool<T> &sr);
    TObjectPool<T>& operator= (const TObjectPool<T> &rhs);

};

#endif
