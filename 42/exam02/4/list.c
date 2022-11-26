#include <stdio.h>

typedef struct s_list
{
	int n;
	struct s_list *next;
}				t_list;

int main()
{
	t_list a;
	t_list b;
	t_list e;
	t_list *head;

	a.n = 10;
	a.next = &b;
	b.n = 5;
	b.next = &e;
	e.n = 7;
	e.next = NULL;
	
	head = &a;
	while ( head != NULL)
	{	
		printf("%d\n", head->n);
		head = head->next;
		
	}
}
