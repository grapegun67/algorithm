#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENT	10

void SWAP(int* a, int* b)
{
		int tmp;
		tmp = *a;
		*a = *b;
		*b = tmp;
}

typedef struct heap {

	int heap[MAX_ELEMENT+1];
	int heapsize;
}Heaptype;

void insert(int data, Heaptype *Heap)
{
	int loc_element = Heap->heapsize;
	int* tmp_heap = Heap->heap;

	tmp_heap[loc_element] = data;

	while (1) {

		if (tmp_heap[loc_element / 2] < tmp_heap[loc_element]) {
			SWAP(&tmp_heap[loc_element / 2], &tmp_heap[loc_element]);
			loc_element /= 2;
		}

		else break;
	}
	
	Heap->heapsize++;
}

void delete(Heaptype* Heap)
{

	int* tmp_heap = Heap->heap;
	int tmp_loc = Heap->heapsize-1;
	int max_loc=0;
	tmp_heap[1] = tmp_heap[tmp_loc];
	tmp_heap[tmp_loc] = -2147000000;
	tmp_loc = 1;

	
	while (1) {
		
		if (tmp_loc * 2 >= Heap->heapsize-1) break;

		if (tmp_heap[tmp_loc * 2] >= tmp_heap[tmp_loc * 2 + 1]) max_loc = tmp_loc * 2;
		else if (tmp_heap[tmp_loc * 2] < tmp_heap[tmp_loc * 2 + 1]) max_loc = tmp_loc * 2 + 1;

		if (tmp_heap[tmp_loc] < tmp_heap[max_loc]) {
			SWAP(&tmp_heap[tmp_loc], &tmp_heap[max_loc]);
			tmp_loc = max_loc;
		}
		else break;
	}

	Heap->heapsize--;
}

int main()
{
	int ii, data, flag;
	Heaptype Heap;
	Heap.heap[0] = 2147000000;
	Heap.heapsize = 1;


	while (1) {

		printf("\n-----1.insert 2.delete 3.exit-----\n");
		scanf("%d", &flag);
		

		switch (flag)
		{
			case 1:
				printf("input...\n");
				scanf("%d", &data);

				insert(data, &Heap);

				printf("\nresult:\n");

				for (ii = 1; ii < Heap.heapsize; ii++) 
					printf("%d ", Heap.heap[ii]);
				printf("\n");
				break;
				
			case 2:

				if (Heap.heapsize == 1) {
					printf("no data!!\n");
					break;
				}
					
				delete(&Heap);

				printf("\nresult:\n");

				for (ii = 1; ii < Heap.heapsize; ii++) 
					printf("%d ", Heap.heap[ii]);

				printf("\n");
				break;

			case 3:
				return 0;
		}	

	}

	printf("\n");
	return 0;
}
