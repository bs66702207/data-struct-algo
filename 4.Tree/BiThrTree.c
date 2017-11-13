#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
//线索存储标志位
//Link(0), 表示指向左右孩子的指针
//Thread(1)，表示指向前驱后继的线索
typedef enum {Link, Thread} PointerTag;

typedef struct BiThrNode
{
	char data;
	struct BiThrNode *lchild, *rchild;
	PointerTag ltag;
	PointerTag rtag;
}BiThrNode, *BiThrTree;

//始终指向刚刚访问过的结点
BiThrTree pre;

/*
   A
 B   E
C D   F

先序输入: ABC__D__E_F__回车. _表示空格
中序输出: CBDAEF, 可以利用起来的结点(C)B(D)A(E)(F)
*/

//创建一颗二叉树，约定用户遵照前序遍历的方式输入数据
CreateBiThrTree(BiThrTree *T)
{
	char c;
	scanf("%c", &c);
	if(' ' == c){
		*T = NULL;
	} else {
		*T = (BiThrNode *)malloc(sizeof(BiThrNode));
		(*T)->data = c;
		(*T)->ltag = Link;//default
		(*T)->rtag = Link;
		CreateBiThrTree(&(*T)->lchild);
		CreateBiThrTree(&(*T)->rchild);
	}
}

InThreading(BiThrTree T)
{
	if(T) {
		InThreading(T->lchild);//递归左孩子线索化

		if(T->lchild == NULL) {//如果该结点没有左孩子, 设置ltag为Thread, 并把lchild指向刚刚访问的结点
			T->ltag = Thread;
			T->lchild = pre;
		}

		if(pre->rchild == NULL) {
			pre->rtag = Thread;
			pre->rchild = T;
		}

		pre = T;

		InThreading(T->rchild);//递归右孩子线索化
	}
}

InOrderThreading(BiThrTree *p, BiThrTree T)
{
	*p = (BiThrTree)malloc(sizeof(BiThrNode));
	(*p)->ltag = Link;
	(*p)->rtag = Thread;
	(*p)->rchild = *p;
	if(T == NULL){
		(*p)->lchild = *p;	
	} else {
		(*p)->lchild = T;
		pre = *p;
		InThreading(T);
		pre->rchild = *p;
		pre->rtag = Thread;
		(*p)->rchild = pre;
	}
}

visit(char c)
{
	printf("%c\n", c);
}

//中序遍历，非递归
InOrderTraverse(BiThrTree T)
{
	BiThrTree p;
	p = T->lchild;

	while( p!= T ) {
		while(p->ltag == Link) {
			p = p->lchild;
		}
		visit(p->data);

		while(p->rtag == Thread && p->rchild != T) {
			p = p->rchild;
			visit(p->data);
		}
		p = p->rchild;
	}
}

int main()
{
	BiThrTree P, T = NULL;
	CreateBiThrTree(&T);
	//InThreading(T);//pre需要初始化
	InOrderThreading(&P, T);//pre初始化
	InOrderTraverse(P);
	return 0;
}
