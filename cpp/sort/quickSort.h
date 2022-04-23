#pragma once
#include <iostream>
#include <algorithm>

template <typename RandomAccessIterator>
class QuickSorter
{
public:
    RandomAccessIterator partition(RandomAccessIterator itLeft, RandomAccessIterator itRight);
    void sort(RandomAccessIterator begin, RandomAccessIterator end);

private:
    int m_cmpCount = 0; 
    void quicksort(RandomAccessIterator begin, RandomAccessIterator end);
    RandomAccessIterator choosePivot(RandomAccessIterator begin, RandomAccessIterator end);
};

template<typename RandomAccessIterator>
RandomAccessIterator QuickSorter<RandomAccessIterator>::partition(RandomAccessIterator itLeft, RandomAccessIterator itRight)
{
    auto p = *itLeft;
    auto it = itLeft;
    ++it;

    for (auto jit = it; jit != itRight; ++jit)
    {
        m_cmpCount++;
        if(*jit < p)
        {
            std::swap(*jit, *it);
            ++it;
        }
    }

    --it;
    std::swap(*itLeft, *it);

    return it;
}

// Naive implementation
template <typename RandomAccessIterator>
RandomAccessIterator QuickSorter<RandomAccessIterator>::choosePivot(RandomAccessIterator begin, RandomAccessIterator end)
{
    return begin;
}

template <typename RandomAccessIterator>
void QuickSorter<RandomAccessIterator>::quicksort(RandomAccessIterator begin, RandomAccessIterator end)
{
    if (begin>=end)
    {
        return;      // 0 or 1 element subarray
    }
    
    auto it = choosePivot(begin, end);
    std::swap(*begin, *it);             // make pivot first

    auto jit = partition(begin, end);   // jit = new pivot position

    //m_cmpCount += std::distance(begin, jit - 1) +1;
    //m_cmpCount += std::distance(jit + 1, end) +1;
    quicksort(begin, jit - 1);
    quicksort(jit +  1, end);
}

template <typename RandomAccessIterator>
void QuickSorter<RandomAccessIterator>::sort(RandomAccessIterator begin, RandomAccessIterator end)
{
    m_cmpCount = 0;
    quicksort(begin, end);

    std::cout << "total of comparisions = " << m_cmpCount << std::endl;
    m_cmpCount = 0;
}