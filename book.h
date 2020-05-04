//Contains struct book declarations
#include <stdio.h>
#include "readline.h"

#ifndef BOOK_H
#define BOOK_H

//struct book declaration
struct book{
	char title[TITLE_LEN+1];
        char first[NAME_LEN+1];
        char last[NAME_LEN+1];
        double price;
        int num_requests;
        struct book *next;
};

//Prototype 1
struct book *append_to_list(struct book *list);

//Prototype 2
void update(struct book *list);

//Prototype 3
void printList(struct book *list);

//Prototype 4
void clearList(struct book *list);

//Prototype 5
struct book* delete_from_list(struct book *list);
#endif
