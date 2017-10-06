#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "phonebook_opt.h"

/* TODO: FILL YOUR OWN IMPLEMENTATION HERE! */
entry **entryList = NULL;
entry **entryListHead = NULL;

entry *findName(char lastName[], entry *pHead)
{
    pHead=*(entryListHead+lastName[0]-97);
    while (pHead != NULL) {
        if (strcasecmp(lastName, pHead->lastName) == 0)
            return pHead;
        pHead = pHead->pNext;
    }
    return NULL;
}

entry *append(char lastName[], entry *e)
{
    /* allocate memory for the new entry and put lastName */
    if(entryList==NULL) {
        entryList = (entry **) malloc(sizeof(entry *)*26);
        entryListHead= (entry **) malloc(sizeof(entry *)*26);
    }
    e = *( entryList+ lastName[0]-97);

    if( *(entryListHead + lastName[0]-97) == NULL) {
        e=(entry *)malloc(sizeof(entry));
        * (entryListHead + lastName[0]-97 ) = e;
    }


    e->pNext = (entry *) malloc(sizeof(entry));
    e = e->pNext;
    strcpy(e->lastName, lastName);
    e->pNext = NULL;
    *(entryList + lastName[0] - 'a') = e;
    return e;
}
