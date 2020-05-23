#ifndef LIST_H
#define LIST_H

enum LIST_RETURN_CODES
{
	LIST_SUCCESS = 0,
	LIST_ERR_OPEN = -1,
	LIST_ERR_READ = -2,
	LIST_ERR_MEMORY = -3
};

struct _list;
typedef struct _list
	{
		char *string;
		struct _list *next;
	} list;

int read_list(char *name, list **p_head);
void print_list(list *head);
void delete_list(list *head);

#endif
