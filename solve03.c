#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"list.h"
#include"solve03.h"

int solve(list *head)
{
	int counter = 0,cmp1 = 0,cmp2;
	char *str;
	if(head)
	{
		str = head->string;
		//strcpy(str1,head->string);
		head = head->next;
	}
	while(head)
	{
		cmp2 = strcmp(str,head->string);
		if(cmp1 <= 0 && cmp2 >= 0)
			counter ++;
		str = head->string;
		head = head->next;
		cmp1 = cmp2;
	}
	if(cmp1<=0)
		counter ++;
	return counter;
}
