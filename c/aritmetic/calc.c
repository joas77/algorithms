#include "aritmetic.h"
#include <stdio.h>


int main(int argc, char * argv[])
{
    uint8_t xNum[] = {1,2,3,4};
    uint8_t yNum[] = {5,6,7,8};

    stBigNum x = {  .number = xNum,
                    .digitNum = 4,
                    .strRepresentation = "1234"
                };

    stBigNum y = {  .number = yNum,
                    .digitNum = 4,
                    .strRepresentation = "5678"
                };

    printf("x = %s ", x.strRepresentation);
    printf("y = %s \n", y.strRepresentation);

    return 0;
}