#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
typedef struct BiTNode
{
	char data;
	struct BiTnode *lchild, *rchild;
}BiTnode, *BiTree;

//创建一颗二叉树，约定用户遵照前序遍历的方式输入数据
CreateBiTree(BiTree *T)
{
	char c;
	scanf("%c", &c);
	if(' ' == c){
		*T = NULL;
	} else {
		*T = (BiTnode *)malloc(sizeof(BiTnode));
		(*T)->data = c;
		CreateBiTree(&(*T)->lchild);
		CreateBiTree(&(*T)->rchild);
	}
}
