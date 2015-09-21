#include <stdio.h>
#include <stdlib.h>
//#include <linux/list.h>

struct list_head {
    struct list_head *next, *prev;
};

struct num {
	int number;
	int ttt;
	struct list_head node;
};

void list_add(struct list_head *new, struct list_head *head)
{
	struct list_head *prev = head, *next = head->next;

	next->prev = new;
	new->next = next;
	new->prev = prev;
	prev->next = new;
}

/*
#define container_of(ptr, type, member) ({          \
	const typeof( ((type *)0)->member ) *__mptr = (ptr);    \
	(type *)( (char *)__mptr - offsetof(type,member) );})

*/
int main()
{

//	LIST_HEAD(head);
	struct list_head head = { &(head), &(head) };


	struct num *tmp;
	struct list_head *iterator;
	int i;   
	for (i=0 ; i<5 ; i++) {
		tmp = malloc(sizeof(struct num));
		tmp->number = i;
		list_add(&tmp->node, &head);
	}
	
	
//	list_for_each(iterator, &head) {
	for (iterator = head.next; iterator != &head; iterator = iterator->next)
	{
		//list_entry(iterator, node);
		tmp = (struct num*)( (char*) iterator - ((size_t) &((struct num*)0)->node) );
		printf("\n%lu\n", ((size_t) &((struct num*)0)->node));
		
		
		printf("%d\n", tmp->number);
	}

	return 0;
}
