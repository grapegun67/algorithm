#include <stdio.h>

#define MAX_SIZE	10

void SWAP(int* a, int* b)
{
	int tmp;
	
	tmp = *a;
	*a = *b;
	*b = tmp;
}

typedef struct heap {

	int data[MAX_SIZE];
	int heapsize;
}Heaptype;


void insert(int data, Heaptype *heap)
{
	int* tmp = heap->data;
	int loc_data = heap->heapsize;
	
	tmp[loc_data] = data;
	heap->heapsize++;

	while (1) {
		if (loc_data == 1) break;

		if (tmp[loc_data / 2] > tmp[loc_data]) {
			SWAP(&tmp[loc_data / 2], &tmp[loc_data]);
			loc_data /= 2;
		}
		else return;
	}
}

void delete(Heaptype* heap)
{
	int *tmp = heap->data;
	int loc_data = heap->heapsize -1;
	int tmp_data = 0;
	
	tmp[1] = tmp[loc_data];

	loc_data = 1;

	while (1) {
		if (loc_data * 2 >= heap->heapsize - 1) break;

		if (tmp[loc_data * 2] <= tmp[loc_data * 2 + 1]) tmp_data = loc_data * 2;
		else tmp_data = loc_data * 2 + 1;


		if (tmp[loc_data] > tmp[tmp_data]) SWAP(&tmp[loc_data], &tmp[tmp_data]);
		else break;

		loc_data = tmp_data;
	}
	heap->heapsize--;

}

void print_heap(Heaptype *heap)
{
	for (int ii = 1; ii < heap->heapsize; ii++)
	{
		printf("%d ", heap->data[ii]);
	}
	printf("\n");
}

int main()
{
	int flag = 0, data = 0;
	Heaptype Heap;

	Heap.heapsize = 1;


	while (1) {
		printf("\n1.insert 2.delete 3.printf 4.exit\n");
		scanf("%d", &flag);

		switch (flag)
		{
		case 1:
			printf("input.....\n");
			scanf("%d", &data);
			insert(data, &Heap);
			break;

		case 2:
			delete(&Heap);
			break;

		case 3: 
			print_heap(&Heap);
			break;


		case 4: return 0;
			
		}

	}

	return 0;
}
