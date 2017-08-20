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

Status GetElem(SqList L, int i, ElemType *e)
{
	if(L.lenght==0 || i<1|| i>L.length)
	{
		return ERROR;
	}
	*e = L.data[i-1];

	return OK;
}
