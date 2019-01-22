#ifndef BIG_NUMBER_H
#define BIG_NUMBER_H

#include <vector>
#include <string>

class BigNumber{
    public:
    BigNumber(std::string strData);

    std::string toString();
    int getDigitsNumber();

    BigNumber operator+(const BigNumber &other);
    BigNumber operator*(const BigNumber &other);
    BigNumber operator=(const BigNumber &other);

    //~BigNumber();

    private:
    std::vector<int> mRawData;

};

#endif // BIG_NUMBER_H
