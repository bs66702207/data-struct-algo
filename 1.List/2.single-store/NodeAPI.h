typedef struct Node
{
	ElemType data;
	struct Node *next;
} Node;

typedef struct Node *LinkList;

Status GetElem(LinkList L, int i, ElemType);
