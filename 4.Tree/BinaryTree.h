
/*
← ↑ →  ↓  ↖  ↙  ↗  ↘

               [l]A[r]
         ↙              ↘ 
     [l]B[r]           [l]c[^]
   ↙       ↘          ↙
[^]D[^]   [^]E[^] [^]F[^]    
*/
typedef struct BiTnode
{
	ElemType data;
    struct BiTnode *lchild, *rchild;
} BiTNode, *BiTree;
