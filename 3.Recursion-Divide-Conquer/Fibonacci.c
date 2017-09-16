#include <stdio.h>

int Fib(int i) {
	if(i<2) {
		return i == 0 ? 0 : 1;
	}
	return Fib(i-1) + Fib(i-2);
}

/********************************************

                           fib5
              fib4                     fib3
	   fib3          fib2         fib2      fib1
   fib2    fib1  fib1    fib0 fib1    fib0
fib1 firb0

********************************************/

int main()
{
	int i;
	int a[40];

	a[0] = 0;
	a[1] = 1;
	printf("%d %d", a[0], a[1]);
	//iteration
	for(i=2; i<40; i++) {
		a[i] = a[i-1] + a[i-2];
		printf("%d ", a[i]);
	}
	printf("\n");
}
