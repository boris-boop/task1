#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "list.h"
#include "solve07.h"
#define ERROR_OPEN -1
#define ERROR_READ -2
#define ERROR_MEMORY -3
int main(int argc, char *argv[])
{
	list *head;
	int read;
	double t;
	char *name = 0;
	if (argc != 2)
	{
		printf("Usage %s [file]\n", argv[0]);
		return 1;
	}
	name = argv[1];
	read = read_list(name, &head);
	if (read != 0)
	{
		if (read == ERROR_OPEN)
		{
			printf("Error, can't open file\n");
			return 1;
		}
		else if (read == ERROR_READ)
		{
			printf("Error, can't read file\n");
			return 2;
		}
		else if (read == ERROR_MEMORY)
		{
			printf("Error, memory limit\n");
			return 3;
		}
		else
		{
			printf("Unknown error\n");
			return 4;
		}
	}
	print_list(head);
	t = clock();
	read = solve(head);
	t = clock()-t;
	printf("Result : %d\n", read);
	printf("Elapsed : %.2f\n", t/CLOCKS_PER_SEC);
	delete_list(head);
	return 0;
}
