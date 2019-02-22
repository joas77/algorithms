#include "aritmetic.h"
#include <stdio.h>


int main(int argc, char * argv[])
{
    uint8_t xNum[] = {1,2,3,4};
    uint8_t yNum[] = {5,6,7,8};

    stBigNum * pNumber = aritBigNumNew(0);
    aritBigNumFromStr(pNumber, "1234");

    printf("%s", aritBigNumToString(pNumber));


    return 0;
}