#include <stdio.h>

#define	ARRSIZE	10

int main()
{
	int ii, tmp,jj,row, gap = ARRSIZE;
	int arr[ARRSIZE];

	printf("input....\n");
	for (ii = 0; ii < ARRSIZE; ii++) scanf("%d", &arr[ii]);

	while (gap != 1) { //->전체반복
		if (gap % 2 == 0) gap /= 2;
		else gap = gap / 2 + 1;

		for (row = 0; row <= gap; row++) { //-> 행결정
												
			for (ii = row+gap; ii < ARRSIZE; ii+=gap) { //-> 부분 삽입정렬 시작 
				tmp = arr[ii];

				for (jj = ii - gap; jj >= 0; jj-=gap) {
					if (arr[jj] > tmp) arr[jj + gap] = arr[jj];
					else break;
				}
				arr[jj + gap] = tmp;
			}
		}
	}

	for (ii = 0; ii < ARRSIZE; ii++) printf("%d ", arr[ii]);
	printf("\n");
	return 0;
}

