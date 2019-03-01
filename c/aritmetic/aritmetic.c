#include <string.h>
#include "aritmetic.h"


stBigNum* aritBigNumNew(size_t digitCount)
{
    stBigNum * num = (stBigNum*) malloc(sizeof(stBigNum));
    num->digitCount = digitCount;
    uint8Vector_init_sizeof(&num->number, digitCount);
    return num;
}

/*
* Frees memory in num and set num=NULL 
* if num is NULL aritBigNumDelete does nothing
*/
void aritBigNumDelete(stBigNum * num)
{
    uint8Vector_delete(&num->number);
    free(num);
    num = NULL;
}

/*
* num shall be an empty number
*/
ErrorCode aritBigNumFromStr(stBigNum *num, const char * str)
{   
    size_t strLen = strlen(str);

    for(int i = strLen-1; i>= 0; i--)
    {
        uint8_t digit = (uint8_t) (str[i] - '0');
        if (digit > 9 ) 
        {
            return INVALID_STR_REPR;
        }
        uint8Vector_push_back(&num->number, digit);
        num->digitCount ++;
    }

    return OK;
}

char * aritBigNumToString(stBigNum * num)
{
    if(num->digitCount == 0)
    {
        return "NaN";
    }
    
    char * str = (char *) malloc((num->digitCount +1) * sizeof(char));
    char * str_it = str;

    str[num->digitCount] = '\0';
    for(int i = num->digitCount - 1; i>=0; i--)
    {
        *str_it = num->number.data[i] + '0';
        str_it++;
    }
    
    return str;
}

ErrorCode aritSum(stBigNum * result, stBigNum * x, stBigNum * y)
{
    ErrorCode errCode = OK;

    if ( y != NULL && x != NULL) 
    {
        size_t nDigits = MIN(x->digitCount, y->digitCount);
        uint8_t carry = 0;

        for(size_t i = 0; i < nDigits; i++)
        {
            uint8Vector_push_back(result, uint8Vector_at(x, i) + uint8Vector_at(y, i));
           
            uint8_t currentCarry = uint8Vector_at(result, i)/10;
            result->number.data[i] = ( uint8Vector_at(result, i)%10 ) + carry;
            carry = currentCarry;
        }
        
        // suming remainder digits


    }
    else
    {
        errCode = INVALID_NUMBER;
    }
    
    return errCode;
}