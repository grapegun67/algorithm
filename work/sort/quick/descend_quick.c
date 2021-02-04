#include <stdio.h>

#define ARRSIZE	10

void SWAP(int* a, int* b)
{

	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int loc_pivot_func(int lt, int rt, int arr[]) {

	int ii;
	int pivot = arr[lt];
	int loc_pivot = 0;

	for (ii = lt+1; ii <= rt; ii++) {
		if (pivot < arr[ii]) loc_pivot++;
	}


	if (lt != 0) loc_pivot += lt;
	return loc_pivot;
}

void quick(int lt, int rt, int arr[])
{
	if (lt >= rt) return;

	int tmp_lt = lt;
	int tmp_rt = rt;
	int ck_lt = 0;
	int ck_rt = 0;
	int pivot = arr[lt];
	int loc_pivot = loc_pivot_func(lt, rt, arr);

	SWAP(&arr[lt], &arr[loc_pivot]);


	while (tmp_lt != loc_pivot && tmp_rt != loc_pivot) {

		if (pivot > arr[tmp_lt]) ck_lt = 1;
		else tmp_lt++;

		if (pivot <= arr[tmp_rt]) ck_rt = 1;
		else tmp_rt--;

		/* 조건식 */
		if (ck_lt == 1 && ck_rt == 1) {
			ck_lt = 0;
			ck_rt = 0;

			SWAP(&arr[tmp_lt++], &arr[tmp_rt++]);
		}
	}
	
	quick(lt, loc_pivot - 1, arr);
	quick(loc_pivot + 1, rt, arr);
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
