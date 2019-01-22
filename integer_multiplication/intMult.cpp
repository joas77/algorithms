#include <string>
#include <iostream>
#include "bigNumber.h"

int main(int argc, char const *argv[])
{
    /* TODO: add command line options */
    std::string numX, numY;
    numX = "5678";
    numY = "1234";

    BigNumber x = BigNumber(numX);
    BigNumber y = BigNumber(numY);

    std::cout << "X = " << x.toString() << std::endl;
    std::cout << "Y = " << y.toString() << std::endl;

    return 0;
}