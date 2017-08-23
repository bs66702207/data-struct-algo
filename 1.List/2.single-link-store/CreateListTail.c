//尾插法，每一个新来的元素插在第一个位置
void CreateListTail(LinkList *L, int n)
{
	LinkList p, r;
	int i;

	srand(time(0)); //初始化随机数种子
	*L = (LinkList)malloc(sizeof(Node));
	r = *L;

	for(i=0; i<n; i++) {
		p = (Node*)malloc(sizeof(Node));
		p->data = rand()%100+1;
		r->next = p;
		r = p;
	}

	r->next = NULL;
}
