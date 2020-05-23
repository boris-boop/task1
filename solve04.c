#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"list.h"
#include"solve04.h"

int solve(list *head)
{
	int counter = 0,cmp1 = 0,cmp2,max = 0,i = 0;
	char *str;
	if(head)
	{
		str = head->string;
		//strcpy(str1,head->string);
		head = head->next;
	}
	while(head)
	{
		counter++;
		cmp2 = strcmp(str,head->string);
		if(cmp1 <= 0 && cmp2 >= 0)
		{
			i++;
			if(max < counter)
				max = counter - 1;
			counter = 0;
		}
		str = head->string;
		head = head->next;
		cmp1 = cmp2;
	}
	if(cmp1<=0)
		i++;
	if(i < 2)
		max = 0;
	return max;
}
