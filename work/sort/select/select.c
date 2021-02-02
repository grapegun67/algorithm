#include <stdio.h>

#define	ARRSIZE	10

int main()
{
	int arr[ARRSIZE];
	int ii, jj, tmp;

	printf("input....\n");
	for(ii = 0; ii < ARRSIZE; ii++) scanf("%d", &arr[ii]);

	for(ii = 0; ii < ARRSIZE-1; ii++){
		for(jj = ii+1; jj < ARRSIZE; jj++){
			if(arr[ii] > arr[jj]){
				tmp = arr[ii];
				arr[ii] = arr[jj];
				arr[jj] = tmp;
			}
		}
	}
	
	for(ii = 0; ii < ARRSIZE; ii++) printf("%d ", arr[ii]);

	printf("\n");
	return 0;
}
