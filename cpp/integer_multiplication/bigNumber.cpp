#include <iostream>
#include "bigNumber.h"


BigNumber::BigNumber(std::string strData)
{
    for(auto&& i : strData) 
    {
        int z = (int)'0';
        int c = (int)i;
        int digit = c-z;
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
    return BigNumber("0");
}

BigNumber BigNumber::operator*(const BigNumber &other)
{
    return BigNumber("0");
}
