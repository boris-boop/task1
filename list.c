#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#define LEN 4096

int  read_list(char *name, list **p_head)
{
	FILE *file;
	char buff[LEN];
	list *head, *curr, *tail;
	int len;

	if( !(file = fopen(name, "r")) )
		return LIST_ERR_OPEN;

	if( !fgets(buff, LEN, file) )
	{
		if( !feof(file) )
		{
			fclose(file);
			return LIST_ERR_READ;
		}

		if( !(head = (list *)malloc(sizeof(list))) )
		{
			delete_list(head);
			fclose(file);
			return LIST_ERR_MEMORY;
		}
		head->string = 0;
		head->next = 0;
		fclose(file);
		return LIST_SUCCESS;
	}

	len = strlen(buff);
	if( buff[len - 1]!='\n' )
	{
		fclose(file);
		return LIST_ERR_READ;
	}
	buff[len - 1] = '\0';

	if( !(head = (list *)malloc(sizeof(list))) )
	{
		delete_list(head);
		fclose(file);
		return LIST_ERR_MEMORY;
	}
	if( !(head->string = (char *)malloc( strlen(buff) + 1 )) )
	{
		delete_list(head);
		free(head);
		fclose(file);
		return LIST_ERR_MEMORY;
	}
	strcpy(head->string, buff);
	head->next = 0;
	tail = head;

	while( fgets(buff, LEN, file) )
	{
		len = strlen(buff);
		if( buff[len - 1]!='\n' )
		{
			tail->next = 0;
			delete_list(head);
			fclose(file);
			return LIST_ERR_READ;
		}
		buff[len - 1] = '\0';
		if( !(curr = (list *)malloc(sizeof(list))) )
		{
			tail->next = 0;
			delete_list(head);
			fclose(file);
			return LIST_ERR_MEMORY;
		}
		if( !(curr->string = (char *)malloc(len)) )
		{
			tail->next = 0;
			delete_list(head);
			free(curr);
			fclose(file);
			return LIST_ERR_MEMORY;
		}
		strcpy(curr->string, buff);
		tail->next = curr;
		tail = curr;
	}

	if( !feof(file) )
	{
		delete_list(head);
		fclose(file);
		return LIST_ERR_READ;
	}

	fclose(file);
	*p_head = head;
	return LIST_SUCCESS;
}

void print_list(list *head)
{
	list *curr;
	int count;

	for( curr = head, count = 0; curr && count<12; curr = curr->next, count++ )
		printf("%s\n", curr->string);
}

void delete_list(list *head)
{
	list *curr, *next;

	for( curr = head; curr; curr = next)
	{
		next = curr->next;
		free(curr->string);
		free(curr);
	}
}
