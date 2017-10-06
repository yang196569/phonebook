#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "phonebook_opt.h"

#define TABLESIZE 3571
/* TODO: FILL YOUR OWN IMPLEMENTATION HERE! */
entry **entryList = NULL;
entry **entryListHead = NULL;


entry *findName(char lastName[], entry *pHead)
{
    unsigned int hashValue = BKDRHash(lastName);
    pHead=*(entryListHead + hashValue);

    while (pHead != NULL) {
        if (strcasecmp(lastName, pHead->lastName) == 0)
            return pHead;
        pHead = pHead->pNext;
    }
    return NULL;
}

entry *append(char lastName[], entry *e)
{
    unsigned int hashValue = BKDRHash(lastName);
    if(entryList==NULL) {
        entryList = (entry **) malloc(sizeof(entry *)*TABLESIZE);
        entryListHead= (entry **) malloc(sizeof(entry *)*TABLESIZE);
    }
    e = *( entryList+ hashValue);

    if( *(entryListHead + hashValue) == NULL) {
        e=(entry *)malloc(sizeof(entry));
        * (entryListHead + hashValue ) = e;
    }


    e->pNext = (entry *) malloc(sizeof(entry));
    e = e->pNext;
    strcpy(e->lastName, lastName);
    e->pNext = NULL;
    *(entryList + hashValue) = e;
    return e;
}

unsigned int BKDRHash(char str[])
{
    unsigned int seed = 1313;
    unsigned int hashValue = 0;

    while (*str) {
        hashValue = hashValue * seed + (*str++);
    }

    return (hashValue % TABLESIZE);
}