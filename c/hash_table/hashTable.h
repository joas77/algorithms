#ifndef HASH_TABLE_H
#define HASH_TABLE_H

typedef struct {
    const char * key;
    int data;    
}tuple;

typedef struct {
    tuple** table;
    unsigned int size;
}Table;

unsigned int strToInt(const char* string);
unsigned int hash(const char* key, unsigned int i, size_t size);
int hash_search(Table* T, const char* key);


#endif /*HASH_TABLE*/
