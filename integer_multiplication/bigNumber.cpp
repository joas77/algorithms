#include <iostream>
#include "bigNumber.h"


BigNumber::BigNumber(std::string strData):mRawData()
{
    for(auto&& c : strData)
    {
        int digit = (int)c - (int)'0';
        mRawData.push_back(digit);
        std::cout << digit << " ";
    }
    
}

std::string BigNumber::toString()
{
    std::string numStr('\0', mRawData.size());

    for(size_t i = 0; i < numStr.size(); i++)
    {
        numStr[i] = (char)'0' + (char)mRawData[i];
    }
    std::cout << numStr;
    return numStr;
}

BigNumber BigNumber::operator+(const BigNumber &other)
{

}

BigNumber BigNumber::operator*(const BigNumber &other)
{

}
