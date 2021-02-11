#include <stdio.h>
#include <stdlib.h>


typedef struct list {

	int data;
	struct list* next;
}List;


void last_insert_node(List *head, int value)
{
	List* node = head;
	List* new_node = (List *)malloc(sizeof(List));

	new_node->data = value;
	new_node->next = NULL;

	while (1) {

		if (node->next == NULL) {
			node->next = new_node;
			break;
		}
		else if (node->next != NULL) {
			node = node->next;
		}

	}

}

void print_node(List* head)
{
	List* node = head->next;

	while (1) {
		printf("value: %d\n", node->data);
		if (node->next == NULL) {
			break;
		}
		
		node = node->next;
	}
}

int main()
{
	List* head = (List *)malloc(sizeof(List));
	head->next = NULL;

	for (int i = 1; i <= 10; i++) {
		last_insert_node(head, i);
	}

	print_node(head);

	return 0;
}
