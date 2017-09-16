#include <stdio.h>

int factorial(int n) {
	if(n == 0) return 1;
	else return n * factorial(n-1);
}

int main()
{

	printf("!10 = %d\n", factorial(10));

	return 0;
}
