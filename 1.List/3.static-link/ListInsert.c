int Malloc_SLL(StaticLinkList space)
{
	int i = space[0];
	if(space[0].cur)
		space[0].cur = space[i].cur;

	return i;	
}

Status ListInsert(staticLinkList L, int i, ElemType e)
{
	int j,k,l;
	k = MAXSIZE - 1;//999
	if(i<1 || i > ListLength(L)+1)
		return ERROR;
	j = Malloc_SLL(L);//j=5

	if(j)
	{
		L[j].data = e;
		for(l=1; l<=i-1;i++) {
			k = L[k].cur;//k=1
		}
		L[j].cur = L[k].cur;
		L[k].cur = j;
		return OK;
	}
	return ERROR;
}
