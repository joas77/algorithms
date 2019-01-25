#include <string>
#include <iostream>
#include "bigNumber.h"

int main(int argc, char const *argv[])
{
    /* TODO: add command line options */
    std::string numX, numY;
    numX = "5678";
    numY = "1234";

    std::vector<int> v(1);

    v.push_back(1);
    std::cout << "V = " << v[0] << std::endl;

    BigNumber x = BigNumber(numX);
    BigNumber y = BigNumber(numY);

    std::cout << "X = " << x.toString() << std::endl;
    std::cout << "Y = " << y.toString() << std::endl;

    return 0;
}