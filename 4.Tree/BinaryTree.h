
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

/*
traversing binary trea
前序遍历 中左右 ABDH I EJ CFK G
中序遍历 左中右 HDI B EJ A FK C G A
后序遍历 叶子开始 HID JE B KF G C A
层序遍历        A BC DEFG HIJK

          A
       ↙    ↘
     B         C
   ↙  ↘     ↙   ↘
  D    E    F     G
↙  ↘    ↘    ↘
H   I    J     K
*/
