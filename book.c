#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "book.h"
#include "readline.h"

#define NEW_LEN 10

//Function 1
struct book *append_to_list(struct book *list)
{
	struct book *new_book = malloc(sizeof(struct book));

	//Reads input from user
//part a:
	printf("Enter the book's title: \n");
        read_line(new_book->title, TITLE_LEN);
       
        printf("Enter the author's first name: \n");
        read_line(new_book->first, NAME_LEN);

        printf("Enter the author's last name: \n");
        read_line(new_book->last, NAME_LEN);

//part c
	if(list == NULL)
	{
	printf("Enter the price: \n");
	scanf("%lf", &new_book->price);

	printf("Enter the number of requests: \n");
	scanf("%d", &new_book->num_requests);

	new_book->next  = NULL;
	return new_book;	
	}

//part b
	//Checks to see if the book exists
	struct book *cur = list, *prev = NULL;

	for(; cur != NULL; prev = cur, cur = cur->next)
	{
	if((strcmp(cur->title, new_book->title) == 0) &&
	   (strcmp(cur->first, new_book->first) == 0) &&
	   (strcmp(cur->last, new_book->last) == 0))
		{
		printf("Error: Book already exists. To update number of requests, enter operation code 'u'.\n");

		return list;
		}
	}

	printf("Enter the price: \n");
        scanf("%lf", &new_book->price);

        printf("Enter the number of requests: \n");
        scanf("%d", &new_book->num_requests);

//insert ordered book by author
	//for loop to check each element of the list
	for(prev = NULL, cur = list; cur != NULL && (strcmp(cur->last, new_book->last) <= 0); prev = cur, cur = cur->next)
	{
	if(strcmp(cur->last, new_book->last) == 0)
		{
		//insert ordered book by title AND author (checks if the first AND last names match)
		if(strcmp(cur->first, new_book->first) == 0)
			if(strcmp(cur->title, new_book->title) > 0)
			{
				if(prev == NULL)
                        	{
                                	new_book->next = cur;
                                	return new_book;
                        	}
                        	new_book->next = cur;
                        	prev->next = new_book;
                        	return list;
		}
		//sort the first names
		if(strcmp(cur->first, new_book->first) > 0)
		break;
		}
	}
	
	//if prev is NULL move the new_book to the front of the list
	if(prev == NULL)
	{
		new_book->next = cur;
		return new_book;
	}
		new_book->next = cur;
		prev->next = new_book;
		return list;	
}
void update(struct book *list)
{
	//Updates a book's number of requests

	struct book *new_book = malloc(sizeof(struct book));

	//Asks the user to enter the book’s title, author’s first name, and last name.
	printf("Enter the book's title: \n");
	read_line(new_book->title, TITLE_LEN);	

	printf("Enter the author's first name: \n");
	read_line(new_book->first, NAME_LEN);

	printf("Enter the author's last name: \n");
	read_line(new_book->last, NAME_LEN);

	//Finds the matching book (checks to see if the book exists)
	struct book *cur = list;

        for(; cur != NULL; cur = cur -> next)
        {
	if((strcmp(cur->title, new_book->title) == 0) &&
           (strcmp(cur->first, new_book->first) == 0) &&
           (strcmp(cur->last, new_book->last) == 0))
                {
                printf("Enter the added number of requests: \n");
		scanf("%d", &new_book->num_requests);
		cur->num_requests += new_book->num_requests;

		printf("%s by %s %s is updated.", new_book->title, new_book->first, new_book->last);
                return;
                }
	}

	printf("Book not found. To add a new book, enter operation code 'a'.");
}

//Function 3
void printList(struct book *list)
{
	//Headings
	printf("Title\t\t\t\t\t\t");
	printf("First name\t\t");
 	printf("Last name\t\t");
	printf("Requests\t");
	printf("Price\n");

	//Prints the list in order (title, first, last, requests, price)
	struct book *cur = list;

	for(; cur != NULL; cur = cur->next)
	{
	printf("%-50s", cur->title);
	printf("%-23s", cur->first);
	printf("%-8s", cur->last);
	printf("%20d\t\t", cur->num_requests);
        printf("%.2lf\n", cur->price);
	}
printf("\n");
}

//Function 4
void clearList(struct book *list)
{
	//Clears the list: all the memory allocated for the
	//linked list is deallocated

	struct book *p;

	while(list != NULL)
	{
	p = list;
	list = list->next;
		if(p != NULL)
		free(p);
	}
}

//Function 5
struct book* delete_from_list(struct book *list)
{
	if(list == NULL)
	{
        	printf("No books are in the list to be removed; Please enter operation code 'a' to append a new book to the list.\n");
		return list;
	}

	else
	{
	char title[TITLE_LEN];
	char first[NAME_LEN];
	char last[NAME_LEN];
	
	printf("Please enter the title of the book to be removed\n");
	read_line(title, TITLE_LEN);
 
	printf("Please enter the first name of the author to be removed\n");
        read_line(first, NAME_LEN);

	printf("Please enter the last name of the author to be removed\n");
        read_line(last, NAME_LEN);

	struct book *cur, *prev = NULL;

	for(cur = list; cur != NULL; prev = cur, cur = cur->next)
	{
		if((strcmp(cur->title, title) == 0)
		&& (strcmp(cur->first, first) == 0)
		&& (strcmp(cur->last, last) == 0))
		{
			if(prev == NULL)
			{
				list = cur->next;
				free(cur);
				return list;
			}
			else
			{
				prev->next = cur->next;
				free(cur);
				break;
			}
		}
	}
	return list;
}
}
