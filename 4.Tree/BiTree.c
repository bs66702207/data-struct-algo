#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
typedef struct BiTNode
{
	char data;
	struct BiTnode *lchild, *rchild;
}BiTnode, *BiTree;
//输入ab d  ce   
//创建一颗二叉树，约定用户遵照前序遍历的方式输入数据, NULL为叶子结点
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

//访问二叉树结点的具体操作，你想干嘛？！
visit(char c, int level) {
    printf("%c, 位于第%d层\n", c, level);
}

//前序遍历二叉树
PreOrderTraverse(BiTree T, int level) {
    if(T) {
        visit(T->data, level);
        PreOrderTraverse(T->lchild, level+1);
        PreOrderTraverse(T->rchild, level+1);
    }
}

int main()
{
    int level = 1;
    BiTree T = NULL;

    CreateBiTree(&T);
    PreOrderTraverse(T, level);
    return 0;
}
