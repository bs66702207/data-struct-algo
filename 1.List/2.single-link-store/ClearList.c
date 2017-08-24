Status ClearList(LinkList *L)
{
	LinkList p, q;
	p = (*L)->next;
	while(p != NULL) {
		q = q->next;
		free(p);
		p = q;
	}
	(*L)->next = NULL;

	return OK;
}
