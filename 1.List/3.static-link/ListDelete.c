Status ListDelete(StaticLinkList L , int i)
{
	int j, k;
	if(i<1 || i > ListLength(L)+1)
		return ERROR;

	k = MAX_SIZE -1;

	for(j=1;j<=i-1;j++) {
		k = L[k].cur; //k1=1, k2=5
	}

	j = L[k].cur;//j=2
	L[k].cur = L[j].cur;//y=3

	Free_SLL(L, j);

	return OK;	
}

void Free_SLL(StaticLinkList space, int k)
{
	space[k].cur = space[0].cur;//[2].cur=6
	space[0].cur = k;
}
