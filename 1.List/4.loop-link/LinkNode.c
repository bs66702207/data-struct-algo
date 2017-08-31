#include "LinkNode.h"
#include <stdlib.h>
#include <stdio.h>

Status InitList(LinkList *L)
{
	*L = (LinkList)malloc(sizeof(struct Node));
	(*L)->data = 0;
	(*L)->next = *L;
	return OK;
}

int ListEmpty(LinkList L)
{
	if(L->next == L) {
		return 1;//空
	} else {
		return 0;
	}
}

int ListLength(LinkList L)
{
	LinkList p;
	int length=0;
	p = L->next;
	while(p != L) {
		p = p->next;
		++length;
	}
	return length;
}

void ListTrave(LinkList L)
{
	LinkList p;
	p = L->next;
	printf("遍历链表:\n");
	while(p!=L) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

void HeadCreateList(LinkList *L, int n)
{
	//创建长度为n的单循环链表
	int i;
	(*L) = (LinkList)malloc(sizeof(struct Node));
	(*L)->next = (*L);
	printf("请输入链表元素值:\n");
	for(i=n; i>0; i--) {
		printf("请输入第%d个元素的值:", i);
		LinkList new;
		new = (LinkList)malloc(sizeof(struct Node));
		scanf("%d", &(new->data));
		new->next = (*L)->next;
		(*L)->next = new;
	}
}

void TailCreateList(LinkList *L, int n)
{
	int i;
	LinkList p;
	(*L) = (LinkList)malloc(sizeof(struct Node));
	(*L)->next = (*L);
	printf("wujian head %p\n", (*L));
	p = *L;
	printf("请输入链表元素值:\n");
	for(i=1; i<=n; i++) {
		printf("请输入第%d个元素的值:", i);
		LinkList new;
		new = (LinkList)malloc(sizeof(struct Node));
		scanf("%d", &(new->data));
		new->next = (*L);
		printf("wujian %d, %p, %p, %p\n", new->data, new->next, (*L), L);
		p->next = new;
		p = new;
		//printf("wujian %d, %p\n", (*p)->data, (*p)->next);
	}
}

Status ListInsert(LinkList *L, int location, ElemType e)
{
	LinkList p;
	LinkList q;
	int j=0;
	p = *L;
	while(p->next != *L && j < location-1) {
		p = p->next;
		++j;
	}
	if(p==*L || j>location-1) {
		return ERROR;
	}
	q = (LinkList)malloc(sizeof(struct Node));
	q->data = e;
	q->next = p->next;
	p->next=q;
	return OK;	
}

Status ListDelete(LinkList *L, int location, ElemType *e)
{
	LinkList p;
	LinkList q;
	int j=0;
	p = *L;
	while(p->next != *L && j < location-1) {
		p = p->next;
		++j;
	}
	if(p==*L || j>location-1) {
		return ERROR;
	}
	q = p->next;
	p->next = q->next;
	*e = q->data;
	free(q);
	return OK;
}

Status ListClear(LinkList *L)
{
	LinkList p,q;
	p = (*L)->next;
	int length;
	while(p->next != *L) {
		printf("%d\n", p->data);
		q = p->next;
		free(p);
		p = q;
	}
	printf("%d\n", p->data);
	free(p);
	(*L)->next = (*L);
	return OK;
}
