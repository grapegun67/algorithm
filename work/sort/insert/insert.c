#include <stdio.h>

#define ARRSIZE	10

int main()
{
	int ii, jj, tmp;
	int arr[ARRSIZE];

	printf("input....\n");
	for(ii = 0; ii < ARRSIZE; ii++) scanf("%d", &arr[ii]);

	for(ii = 1; ii < ARRSIZE; ii++){
		tmp = arr[ii];

		for(jj = ii-1; jj >= 0; jj--){
			if(arr[jj] > tmp) arr[jj+1] = arr[jj];
			else break;
		}		
		arr[jj+1] = tmp;
	}

	for(ii = 0; ii < ARRSIZE; ii++) printf("%d ", arr[ii]);
	
	printf("\n");
	return 0;
}
