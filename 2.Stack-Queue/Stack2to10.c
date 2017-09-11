#include <stdio.h>
#include <math.h>
#include "StackAPI.h"

sqStack sq;
ElemType a[10] = {1, 1, 0, 0, 1, 0, 0, 1} ;
int aLen = 8;

int main()
{
	int i;
	ElemType temp;
	ElemType sum = 0;
	initStack(&sq);
	for(i=0;i<8;i++) {
		Push(&sq, a[i]);
	}

	for(i=0;i<8;i++) {
		Pop(&sq, &temp);
		printf("temp = %d, (2^%d)=%d\n", temp, i, (int)pow(2, i));
		sum += temp * (int)pow(2, i);
	}

	printf("%d\n", sum);

	return 0;
}
