#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"list.h"
#include"solve07.h"

int solve(list *head)
{
	int counter = 0,cmp,max = 0,i = 0;
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
		if(cmp == 0 )
		{
			i++;
			if(max < counter)
				max = counter - 1;
			counter = 0;
		}
		else
		{
			counter ++;
			str = head->string;
		}
		head = head->next;
	}
	if(i<2)
		max = 0;
	return max;
}
