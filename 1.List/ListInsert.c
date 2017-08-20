#define MAXSIZE 20
typedef int ElemType;
typedef struct
{
	ElemType data[MAXSIZE];
	int lenght;//线性表的当前长度
}SqList;

/*****************************************************/

#define OK 1
#define ERROR 0
#define TURE 1
#define FALSE 0

typedef int Status;

Status ListInsert(SqList *L, int i, ElemType *e)
{
	int k;

	if(L->lenght==MAXSIZE)//满了
	{
		return ERROR;
	}
	if(i<1 ||i>L->length+1)//插入位置不在范围内
	{
		return ERROR;
	}

	if(i <= L->length)//插入位置不在表尾
	{
		for(k=L->length-1;k >= i-1; k--)
			L->data[k+1] = L->data[k];
	}
	L->data[i-1] = e;
	L->length++;

	return OK;
}
