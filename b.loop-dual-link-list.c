//线性表2
	4.单向循环链表 这里需要注意两点，一点是调试的时候**p = **L，如果修改p的话，会影响L的指向，所以这个时候需要定义*p；清空链表的时候注意最后一个数据成员节点的释放，以及L->next = L;
	5.双向循环链表 基本结构: |prior|data|next|，空链表状态是自己指向自己，在q和p之间插入s结点的关键代码为
		s->next = p;
		s->prior = p->prior;
		p->prior->next = s;
		p->prior = s;
	  删除p结点的关键代码为
		p->prior->next = p->next;
		p->next->prior = p->prior;
		free(p);
