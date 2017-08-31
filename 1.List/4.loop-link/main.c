#include <stdio.h>
#include "LinkNode.h"
LinkList L1;
LinkList L2;
int main()
{
	int len=0;
	ElemType d;
//	HeadCreateList(&L1, 5);
//	len = ListLength(L1);
//	printf("the L1 by HeadCreate length = %d\n", len);
//	ListTrave(L1);
	TailCreateList(&L2, 5);
	len = ListLength(L2);
	printf("the L2 by TailCreate length = %d\n", len);
	ListTrave(L2);
#if 0
	ListInsert(&L2, 3, 100);
	len = ListLength(L2);
	printf("the L2 by TailCreate length = %d\n", len);
	ListTrave(L2);

	ListInsert(&L2, 5, 100);
	len = ListLength(L2);
	printf("the L2 by TailCreate length = %d\n", len);
	ListTrave(L2);

	ListDelete(&L2, 7, &d);
	len = ListLength(L2);
	printf("the L2 by TailCreate length = %d\n", len);
	ListTrave(L2);
#endif
	ListClear(&L2);
    len = ListLength(L2);
    printf("the L2 by TailCreate length = %d\n", len);

	return 0;
}
