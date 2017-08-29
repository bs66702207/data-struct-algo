int ListLength(StaticLinkList L)
{
	int j = 0;
	int i = L[MAXSIZE-1].cur;

	while(i) {
		i = L[i].cur;
		j++;
	}

	return j;
}
