#include <stdio.h>
#include <stdlib.h>

#define LH +1
#define EH 0
#define RH -1

typedef enum{false, true} bool;

typedef struct BSTNode{
	int data;
	int bf;
	struct BSTNode *lchild, *rchild;	
}*BSTree, BSTNode;

/*
单向右旋平衡处理：若由于结点 a 的左子树为根结点的左子树上插入结点，导致结点 A 的平衡因子由 1 增至 2，致使以 A 为根结点的子树失去平衡，则只需进行一次向右的顺时针旋转

	     A                         B
	    / \			      / \
	   B   C                     D   A
          / \      ========>         |  / \
 	 D   E                   inode E   C
	 |
       inode

*/
void R_Rotate(BSTree *p)
{
	BSTree lc = (*p)->lchild;
	(*p)->lchild = lc->rchild;
	lc->rchild = *p;
	*p = lc;
}

/*
单向左旋平衡处理：如果由于结点 a 的右子树为根结点的右子树上插入结点，导致结点 A 的平衡因子由 -1变为 -2，则以 A 为根结点的子树需要进行一次向左的逆时针旋转

	     A                         C
	    / \			      / \
	   B   C                     A   E
              / \      ========>    / \  |
 	     D   E                 B   D inode
	         |
               inode

*/
void L_Rotate(BSTree *p)
{
	BSTree lc = (*p)->rchild;
	(*p)->rchild = lc->lchild;
	lc->lchild = *p;
	*p = lc;
}

void L_Balance(BSTree *T)
{
	BSTree lc, rd;
	
//查看以 T 的左子树为根结点的子树，失去平衡的原因，如果 bf 值为 1 ，则说明添加在左子树为根结点的左子树中，需要对其进行右旋处理；反之，如果 bf 值为 -1，说明添加在以左子树为根结点的右子树中，需要进行双向先左旋后右旋的处理
	lc = (*T)->lchild;
	switch(lc->bf)
	{
	case LH:
		(*T)->bf = lc->bf = EH;
		R_Rotate(T);
		break;
	case RH:
		rd = lc->rchild;
		switch(rd->bf)
		{
		case LH:
			(*T)->bf = RH;
			lc->bf = EH;
			break;
		case EH:
			(*T)->bf = lc->bf = EH;
			break;
		case RH:
			(*T)->bf = EH;
			lc->bf = LH;
			break;
		}
		rd->bf = EH;
		L_Rotate(&(*T)->lchild);
		R_Rotate(T);
		break;
	}
}

void R_Balance(BSTree *T)
{
	BSTree lc, rd;
	
	lc = (*T)->rchild;
	switch(lc->bf)
	{
	case RH:
		(*T)->bf = lc->bf = EH;
		L_Rotate(T);
		break;
	case LH:
		rd = lc->lchild;
		switch(rd->bf)
		{
		case LH:
			(*T)->bf = EH;
			lc->bf = RH;
			break;
		case EH:
			(*T)->bf = lc->bf = EH;
			break;
		case RH:
			(*T)->bf = EH;
			lc->bf = LH;
			break;
		}
		rd->bf = EH;
		R_Rotate(&(*T)->rchild);
		L_Rotate(T);
		break;
	}
}

//{12, 23, 45, 34, 98, 39, 46, 35, 23, 36}
int InsertAVL(BSTree * T, int e, bool *taller)
{
	if((*T) == NULL)//如果本身为空树，则直接添加 e 为根结点
	{
		(*T) = (BSTree)malloc(sizeof(BSTNode));
		(*T)->bf = EH;
		(*T)->data = e;
		(*T)->lchild = NULL;
		(*T)->rchild = NULL;
		*taller = true;
	}
	else if(e == (*T)->data)//如果二叉排序树中已经存在 e ，则不做任何处理
	{
		*taller = false;
		return 0;
	}
	else if(e < (*T)->data)//如果 e 小于结点 T 的数据域，则插入到 T 的左子树中
	{
		//如果插入过程，不会影响树本身的平衡，则直接结束
        	if(!InsertAVL(&(*T)->lchild,e,taller))
            		return 0;

        	//判断插入过程是否会导致整棵树的深度 +1
        	if(*taller)
        	{
            //判断根结点 T 的平衡因子是多少，由于是在其左子树添加新结点的过程中导致失去平衡，所以当 T 结点的平衡因子本身为 1 时，需要进行左子树的平衡处理，否则更新树中各结点的平衡因子数
            		switch ((*T)->bf)
            		{
                		case LH:
                    			L_Balance(T);
                    			*taller = false;
                    			break;
                		case  EH:
                    			(*T)->bf = LH;
                    			*taller = true;
                    			break;
                		case RH:
                    			(*T)->bf = EH;
                    			*taller = false;
                    			break;
            		}
        	}
	}
	else//如果 e>T->data 时，需要插入到以 T 为根结点的树的右子树中
	{
		if(!InsertAVL(&(*T)->rchild,e,taller))
            		return 0;
        	if (*taller)
        	{
            		switch ((*T)->bf)
            		{
                	case LH:
                    		(*T)->bf = EH;
                    		*taller = false;
                    		break;
                	case EH:
                    		(*T)->bf = RH;
                    		*taller = true;
                    		break;
                	case  RH:
                    		R_Balance(T);
                    		*taller = false;
                    		break;
            		}
        	}
	}

	return 1;
}

//判断现有平衡二叉树中是否已经具有数据域为 e 的结点
bool FindNode(BSTree root, int e, BSTree* pos)
{
    BSTree pt = root;
    (*pos) = NULL;
    while(pt)
    {
        if (pt->data == e)
        {
            //找到节点，pos指向该节点并返回true
            (*pos) = pt;
            return true;
        }
        else if (pt->data>e)
        {
            pt = pt->lchild;
        }
        else
            pt = pt->rchild;
    }
    return false;
}

//中序遍历平衡二叉树
void InorderTra(BSTree root)
{
    if(root->lchild)
        InorderTra(root->lchild);
   
    printf("%d ",root->data);
   
    if(root->rchild)
        InorderTra(root->rchild);
}

int main()
{
    int i, nArr[] = {12, 23, 45, 34, 98, 39, 46, 35, 23, 36};
    BSTree root=NULL,pos;
    bool taller;
    //用 nArr查找表构建平衡二叉树（不断插入数据的过程）
    for (i=0 ;i < 10; i++)
        InsertAVL(&root, nArr[i], &taller);

    //中序遍历输出
    InorderTra(root);

    //判断平衡二叉树中是否含有数据域为 103 的数据
    if(FindNode(root,103,&pos))
        printf("\n%d\n",pos->data);
    else
        printf("\nNot find this Node\n");
    return 0;
}
