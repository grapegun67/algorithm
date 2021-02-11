#include <stdio.h>
#include <stdlib.h>

typedef struct queue {

	int data;
	struct queue* next;
}Queue;

void insert(int data, Queue* queue)
{
	Queue *tmp = queue;

	if (tmp->next == NULL)
	{
		queue->data = data;
		queue->next = (Queue*)malloc(sizeof(Queue));
		queue->next->next = NULL;
	}

	else 
	{
		while (1)
		{
			if (tmp->next == NULL) break;
			else tmp = tmp->next;
		}
	}
	tmp->next = (Queue*)malloc(sizeof(Queue));
	tmp->next->data = data;
	tmp->next->next = NULL;
}

Queue * delete(Queue* queue)
{
	if (queue->next == NULL) {
		printf("no data\n");
		return queue;
	}
	return queue->next;
}

void print_queue(Queue* queue)
{
	Queue* tmp = queue->next;

	while (tmp != NULL)
	{
		printf("%d-> ", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}

int main()
{
	Queue *queue = (Queue *)malloc(sizeof(Queue));
	queue->next = NULL;
	int flag = 0, data = 0;

	while (1)
	{
		printf("\n<1.insert 2. delete 3.print 4.exit>\n");
		scanf("%d", &flag);

		switch (flag)
		{
		case 1:
			printf("input data: ");
			scanf("%d", &data);
			insert(data, queue);
			break;
		case 2:
			queue = delete(queue);
			break;
		case 3:
			print_queue(queue);
			break;
		case 4:
			return 0;
		}

	}

	return 0;
}

