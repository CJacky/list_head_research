#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <linux/list.h>

struct list_head {
    struct list_head *next, *prev;
};

struct num {
	int id;
	char name[16];
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

void show_addr(struct num *s)
{
	printf("struct addr       %p\n", s);
	printf("id  : %10d (%p)\n", s->id  , &(s->id));
	printf("name: %10s (%p)\n", s->name, &(s->name));
	printf("next: %10p (%p)\n", s->node.next, &(s->node.next));
	printf("prev: %10p (%p)\n", s->node.prev, &(s->node.prev));
	printf("\n");
}

int main()
{

//	LIST_HEAD(head);
	struct list_head head = { &(head), &(head) };


	struct num *tmp;
	struct list_head *iterator;
	int i;   

	for (i=0 ; i<5 ; i++) {
		tmp = malloc(sizeof(struct num));
		tmp->id = i;
		tmp->name[0]= 'A'+i;
		tmp->name[1]= 'B'+i;
		tmp->name[2]= '\0';
		
		list_add(&tmp->node, &head);

		show_addr(tmp);
	}
	
	printf("size of list %lx\n\n", sizeof(struct list_head));
	printf("node size %lx\n", ((size_t) &((struct num*)0)->node));
	printf("\n");
	
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
