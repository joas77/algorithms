#pragma once

#include <vector>

/*
 * Returns the index of the peak
 * a peak v[i]  is defined as v[i-1] <= v[i] <= v[i+1]
*/
template <typename T>
int peakFindLinearSearch(const std::vector<T>& v)
{
    if(v.size() == 1) return 0;
    if(v.size() == 0) return -1;

    if(v.at(0) <= v.at(1)) return 1;

    for(std::size_t i = 1; i < v.size() - 1; i++)
    {
        if( ( v.at(i-1) <= v.at(i) ) && 
            ( v.at(i) <= v.at(i+1) )
        )
        {
            return i;
        }
    }

    const std::size_t lastIndex = v.size() -1;
    if(v.at(lastIndex) >= v.at(lastIndex - 1)) return lastIndex;

    return -1;
}