#ifndef SPECIALLIB_H
#define SPECIALLIB_H

#include <iostream>
#include <cstdlib>
#ifndef T_S
#define T_S 10
#endif
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif
#include <list>
#include <stdlib.h>
#include <stdio.h>

enum EntryType{
    Legi,
    Emp,
    Del,
};

typedef struct	HashTableEntry{
    int         e;
    EntryType   info;
}				Hashentry;

typedef struct	HashTable{
    int             s;
    HashTableEntry *t;
}				HTable;
#endif