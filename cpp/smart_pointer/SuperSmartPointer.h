#pragma once
#include <iostream>
#include <map>

template <typename T>
class SuperSmartPointer
{
public:
    explicit SuperSmartPointer(T *inPtr);
    ~SuperSmartPointer();

    SuperSmartPointer(const SuperSmartPointer<T>& src);
    SuperSmartPointer<T>& operator=(const SuperSmartPointer<T>& rhs);

protected:
    T* mPtr;
    static std::map<T*, int> sRefCountMap;

    void finalizePointer();
    void initPointer(T* inPtr);
};

template <typename T>
std::map <T*, int>SuperSmartPointer<T>::sRefCountMap;

template <typename T>
void SuperSmartPointer<T>::initPointer(T* inPtr)
{
    mPtr = inPtr;
    if (sRefCountMap.find(mPtr) == sRefCountMap.end())
    {
        sRefCountMap[mPtr] = 1;
    }
    else
    {
        sRefCountMap[mPtr]++;
    }   
}

template <typename T>
SuperSmartPointer <T>::SuperSmartPointer(T* inPtr)
{
    initPointer(inPtr);
}

template<typename T>
void SuperSmartPointer<T>::finalizePointer()
{
    if(sRefCountMap.find(mPtr) == sRefCountMap.end())
    {
        std::cerr << "ERROR: Missing entry in map!" << std::endl;
        return;
    }
    sRefCountMap[mPtr]--;
    if(sRefCountMap[mPtr] == 0)
    {
        // No more references to this object -- delete it
        sRefCountMap.erase(mPtr);
        delete mPtr;
    }
}

template <typename T>
SuperSmartPointer<T>::SuperSmartPointer(const SuperSmartPointer<T>& src)
{
    initPointer(src.mPtr);
}

template <typename T>
SuperSmartPointer<T>::~SuperSmartPointer()
{
    finalizePointer();
}

