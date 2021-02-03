#include <stdio.h>

#define	ARRSIZE	10

void merge(int lt, int rt, int arr[]) {

	if (lt == rt) return;

	int mid = (lt + rt) / 2;
	int index = 0, ii = lt, jj = mid+1;
	int tmp_array[ARRSIZE];

	merge(lt, mid, arr);     // 왼쪽 divide
	merge(mid + 1, rt, arr); //오른쪽 divide

	while (ii <= mid && jj <= rt) {

		if (arr[ii] <= arr[jj]) tmp_array[index++] = arr[ii++];    //요소간 비교 연산
		else tmp_array[index++] = arr[jj++];
	}

	while (ii <= mid) tmp_array[index++] = arr[ii++]; // 남은 요소들 처리
	while (jj <= rt) tmp_array[index++] = arr[jj++];  // 남은 요소들 처리

	index = 0;
	for (int i = lt; i <= rt; i++) arr[i] = tmp_array[index++]; //tmp_array에 복사
}

int main()
{
	int ii;
	int arr[ARRSIZE];

	printf("input....\n");
	for (ii = 0; ii < ARRSIZE; ii++) scanf("%d", &arr[ii]);
						 
	merge(0, ARRSIZE - 1, arr);


	for (ii = 0; ii < ARRSIZE; ii++) printf("%d ", arr[ii]);
	printf("\n");
	return 0;
}
