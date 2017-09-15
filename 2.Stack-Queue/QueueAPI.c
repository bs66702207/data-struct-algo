typedef int ElemType;

typedef struct QNode {
	ElemType data;
	struct QNode *next;
} QNode, *QueuePrt;

typedef struct {
	QueuePrt front, rear;//队头、尾指针
} LinkQueue;

initQueue(LinkQueue *q) {
	q->front = q->rear = (QueuePrt)malloc(sizeof(QNode));
	if( !q->front)
		exit(0);
	q->front->next = NULL;
}

InsertQueue(Linqueue *q, ElemType e) {
	QueuePrt p;
	p = (QueuePrt)malloc(sizeof(QNode));
	if(p == NULL)
		exit(0);
	p->data = e;
	p->next = NULL;
	q->rear->next = p;
	q->rear = p;
}

Delete(Linqueue *q, ElemType *e) {
	Linqueue *p;
	if(q->front == q->rear)
		return;
	p = q->front->next;
	*e = p->data;
	q->front->next = p->next;
	if(q->rear == p)
		q->rear = p->front;
	free(p);
}

DestoryQueue(LinkQueue *q) {
	while( q->front) {
		q->rear = q->front->next;
		free(q->front);
		q->front = q->rear;
	}
}
