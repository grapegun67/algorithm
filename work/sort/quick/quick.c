#include <stdio.h>

#define ARRSIZE	10

void swap(int* a, int* b)
{
		int tmp = 0;

		tmp = *a;
		*a = *b;
		*b = tmp;
}

int find_pivot(int low, int high, int arr[])
{
		int i, loc = 0;
		int pivot = arr[low];

		for (i = low; i <= high; i++) {
			if (arr[i] < pivot) loc++;
		}
		
		if (low != 0) return loc + low;

		return loc;
}

void quick(int low, int high, int arr[])
{

	if (high <= low) return;
	//if (high <= 0) return;
	//if (low >= ARRSIZE) return;


	int tmp_low = low;
	int tmp_high = high;
	int pivot = arr[low];
	int pivot_loc = find_pivot(low, high, arr);
	int ck_low = 0, ck_high = 0;


	if (pivot_loc == ARRSIZE - 1) {
		tmp_low = 0;
		tmp_high = pivot_loc - 1;
	}

	swap(&arr[pivot_loc], &arr[low]);

	
	while (1) {


		if (arr[tmp_low] >= pivot) ck_low = 1;
		else tmp_low++;


		if (arr[tmp_high] < pivot) ck_high = 1;
																					
		else tmp_high--;


		
		/*조건문*/

		if (ck_low == 1 && ck_high == 1) {

			ck_low = 0;

			ck_high = 0;
																																	swap(&arr[tmp_low++], &arr[tmp_high--]);

		}


		else if (tmp_low == pivot_loc || tmp_high == pivot_loc) break;

	}

	quick(low, pivot_loc - 1, arr);
	quick(pivot_loc + 1, high, arr);
}

int main()
{
	int ii;
	int arr[ARRSIZE];

	printf("input....\n");
	for (ii = 0; ii < ARRSIZE; ii++) scanf("%d", &arr[ii]);

	quick(0, ARRSIZE - 1, arr);

	for (ii = 0; ii < ARRSIZE; ii++) printf("%d ", arr[ii]);
	printf("\n");
	return 0;
}
