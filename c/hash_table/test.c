#include <stdio.h>
#include "hashTable.h"

int main()
{
    const char* key1 = "llave1";
    const char* key2 = "pts";

    printf("H(%s) = %u\n", key1, strToInt(key1));
    printf("H(%s) = %u\n", key2, strToInt(key2));
    
    return 0;
}
