Status GetElem(LinkList L, int i, ElemType)
{
	int j;
	LinkList p;
	p = L;
	while(p==NULL || j<i) {
		p = p->next;
		++j;
	}

	if( !p || j>i)
	{
		return ERROR;
	}

	*e = p->data;
	return OK;
}
