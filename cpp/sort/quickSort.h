#pragma once
#include <algorithm>

template<typename Iterator>
Iterator partition(Iterator itLeft, Iterator itRight)
{
    auto p = *itLeft;
    auto it = itLeft;
    ++it;

    for (auto jit = it; jit != itRight; ++jit)
    {
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
template <typename Iterator>
Iterator choosePivot(Iterator begin, Iterator end)
{
    return begin;
}

template <typename RandomAccessIterator>
void quicksort(RandomAccessIterator begin, RandomAccessIterator end)
{
    if (begin>=end) return;             // 0 or 1 element subarray
    auto it = choosePivot(begin, end);
    std::swap(*begin, *it);             // make pivot first

    auto jit = partition(begin, end);   // jit = new pivot position
    quicksort(begin, jit - 1);
    quicksort(jit +  1, end);
}