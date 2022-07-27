#pragma once

#include <vector>

/*
 * Returns the index of the peak
 * a peak v[i]  is defined as v[i-1] <= v[i] <= v[i+1]
*/
template <typename T>
int peakFindLinearSearch(const std::vector<T>& v)
{
    if(v.size() == 1) return v.at(0);
    if(v.size() == 0) return -1;

    return 0;
}