#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *next;
}node;

node *create(int n) {

	node *p, *s, *head;
	int i = 1;
	head = (node*)malloc(sizeof(struct node));
	p = head;

	if(n>0) {
		while(i<=n) {
			s = (node*)malloc(sizeof(struct node));
			s->data = i++;
			p->next = s;
			p = s;
		}
		s->next = head->next;
	}

	free(head);
	return s->next;
}

int main() {

	int n = 41;
	int m = 3;
	int i;
	node *p = create(n);
	node *temp;

	m %= n;//2

	while( p != p->next) {
		for(i = 1; i < m-1; i++) {
			p = p->next;
		}
		printf("%d->", p->next->data);//干掉他
		temp = p->next;
		p->next = temp->next;

		free(temp);
		p = p->next;
	}

	printf("%d\n", p->data);

	return 0;
}
