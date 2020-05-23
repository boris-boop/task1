#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"list.h"
#include"solve01.h"

int solve(list *head)
{
	int counter = 0,cmp;
	char *MAX;

	list *curr;
	counter = 1;
	MAX = head->string;
	//strcpy(MAX,head->string);
	curr = head->next;

	while(curr)
	{
		cmp = strcmp(MAX,curr->string);
		if(cmp == 0)
			counter ++;
		else if(cmp<0)
		{
			counter = 1;
			MAX = curr->string;
			//strcpy(MAX,head->string);
		}
		curr = curr->next;
	}
	return counter;
}
