#include <stdio.h>

#define ARRSIZE	10

int main()
{
	int ii, jj, tmp;
	int arr[ARRSIZE];

	printf("input....\n");
	for(ii = 0; ii < ARRSIZE; ii++) scanf("%d", &arr[ii]);

	for(ii = 0; ii < ARRSIZE; ii++){
		for(jj = 0; jj < ARRSIZE -1 - ii; jj++){
			if(arr[jj] > arr[jj+1]){
				tmp = arr[jj];
				arr[jj] = arr[jj+1];
				arr[jj+1] = tmp;
			}
		}
	}
	
	for(ii = 0; ii < ARRSIZE; ii++) printf("%d ", arr[ii]);
	printf("\n");

	return 0;
}
