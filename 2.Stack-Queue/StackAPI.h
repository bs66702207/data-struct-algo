#include <stdlib.h>

typedef int ElemType;

typedef struct
{
	ElemType *base;
	ElemType *top;
	int stackSize;
} sqStack;

#define STACK_INIT_SIZE 100
initStack(sqStack *s) {
	s->base = (ElemType*)malloc(STACK_INIT_SIZE * sizeof(ElemType));
	if( !s->base )
		return -1;
	s->top = s->base;
	s->stackSize = STACK_INIT_SIZE;
}


#define STACKINGREMENT 10
Push(sqStack *s, ElemType e) {
	//如果栈满，追加空间
	if( s->top - s->base >= s->stackSize ) {
		s->base = (ElemType*)realloc(s->base, (s->stackSize + STACKINGREMENT) * sizeof(ElemType));
		if( !s->base)
			return -1;
		s->top = s->base + s->stackSize;//设置栈顶
		s->stackSize = s->stackSize + STACKINGREMENT;//设置栈的最大容量
	}

	*(s->top) = e;
	s->top++;
}

Pop(sqStack *s, ElemType *e) {
	if( s->top == s->base)
		return;
	*e = *--(s->top);
}

CLearStack(sqStack *s) {
	s->top = s->base;
}

DestroyStack(sqStack *s) {
	int i, len;
	len = s->stackSize;
	for(i=0; i<len; i++) {
		free(s->base);
		s->base++;
	}
	s->base = s->top = NULL;
	s->stackSize = 0;
}

int CalcStackElemNums(sqStack s) {
	return(s.top - s.base);
}
