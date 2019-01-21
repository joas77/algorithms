#include <string.h>
#include <stddef.h>
#include <math.h>
#include <stdio.h>
#include "hashTable.h"

#define ALPHA ((unsigned int)(128))

unsigned int strToInt(const char* string)
{   
    size_t len = strlen(string);
    int result = 0;
    for(size_t i = 0; i<=len-1; i++)
    {
        result += pow(ALPHA, len-(i+1) ) * (unsigned int)string[i];
    }
    return result;
}

unsigned int hash(const char* key, unsigned int i, size_t size)
{
    return (strToInt(key) + i) % size;
}

int hash_insert(Table * T, const char* key)
{
    int i = 0;
    int j = 0;
    do{
        j = hash(key, i, T->size);
        
        if (T->table[j] == NULL) 
        {
            T->table[j]->key = key;
            return j;
        }
        else
        {
            i++;
        }
        
    }while(i != T->size);
    return -1;
}

int hash_search(Table* T, const char* key)
{
    size_t i = 0;
    size_t j;
    do{
        j = hash(key, i, T->size);
        if( strcmp(T->table[j]->key, key) == 0 )
        {
            return j;
        }
        i++;
    }while(T->table[j] == NULL || i == T->size);
    return -1; 
}
