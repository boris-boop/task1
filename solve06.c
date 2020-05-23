#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"list.h"
#include"solve06.h"

int solve(list *head)
{
	int counter = 0,cmp,cmp1 = 1;
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
		if(cmp == 0 && cmp1 !=0)
			counter ++;
		else
			str = head->string;
		head = head->next;
		cmp1 = cmp;
	}
	return counter;
}
