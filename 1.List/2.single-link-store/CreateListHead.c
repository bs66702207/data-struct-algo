//头插法，每一个新来的元素插在第一个位置
void CreateListHead(LinkList *L, int n)
{
	LinkList p;
	int i;

	srand(time(0)); //初始化随机数种子

	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;

	for(i=0; i<n; i++) {
		p = (LinkList)malloc(sizeof(Node));
		p->data = rand()%100+1;
		p->next = (*L)->next;
		(*L)->next = p;
	}
}
