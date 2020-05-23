#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"list.h"
#include"solve02.h"

int solve(list *head)
{
	int counter = 0,cmp;
	char *MAX;
	if(head)
	{
		MAX = head->string;
		//strcpy(MAX,head->string);
		head = head->next;
	}
	while(head)
	{
		cmp = strcmp(head->string,MAX);
		if(cmp > 0)
			counter ++;

		MAX = head->string;
		head = head->next;
	}
	return counter;
}
