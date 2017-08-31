#define OK 1
#define ERROR 0

typedef int ElemType;
typedef int Status;

typedef struct Node
{
	ElemType data;
	struct Node *next;
}Node, *LinkList;

Status InitList(LinkList *L);
int ListEmpty(LinkList L);//1 NULL, 0非NULL
int ListLength(LinkList L);
void ListTrave(LinkList L);
void HeadCreateList(LinkList *L, int n);//头插法
void TailCreateList(LinkList *L, int n);//尾插法，注意！二级指针相互赋值后，修改其一会修改另外一个指针
Status ListInsert(LinkList *L, int location, ElemType e);
Status ListDelete(LinkList *L, int location, ElemType *e);
Status ListClear(LinkList *L);
