#include "aritmetic.h"
#include <stdio.h>


int main(int argc, char * argv[])
{
    uint8_t xNum[] = {1,2,3,4};
    uint8_t yNum[] = {5,6,7,8};

    stBigNum * pNumber = aritBigNumNew(0);
    aritBigNumFromStr(pNumber, "1234");
    char * string = "hola mundo";
    char * strNum = aritBigNumToString(pNumber);
    printf("%s\n", strNum);
    printf("%s\n", string);

    // TODO: free objects

    return 0;
}