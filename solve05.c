#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"list.h"
#include"solve05.h"

int solve(list *head)
{
	int counter = 1,cmp,max = 0;
	char *str;
	if(head)
	{
		str = head->string;
		//strcpy(str1,head->string);
		head = head->next;
	}
	while(head)
	{
		cmp = strcmp(str,head->string);
		if(cmp < 0)
			counter ++;
		else
		{
			if(max < counter)
				max = counter;
			counter = 1;
		}
		str = head->string;
		head = head->next;
	}
	if(max < counter)
		max = counter;
	return max;
}
