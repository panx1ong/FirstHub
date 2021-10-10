Problem Description
平衡二叉树又称AVL树，它是一种具有平衡因子的特殊二叉排序树。平衡二叉树或者是一棵空树，或者是具有以下几条性质的二叉树：
1.       若它的左子树不空，则左子树上所有结点的值均小于它的根节点的值；
2.       若它的右子树不空，则右子树上所有结点的值均大于它的根节点的值；
3.       它的左右子树也分别为平衡二叉树，且左子树和右子树的深度之差的绝对值不超过1。
若将二叉树上结点的平衡因子定义为该结点的左子树深度减去它的右子树的深度，则平衡二叉树上的所有结点的平衡因子只可能为-1、0和1。只要二叉树上有一个结点的平衡因子的绝对值大于1，则这棵二叉树就是不平衡的。
通过平衡二叉树的性质不难得知，其插入、删除、查询都操作的时间复杂度均为O(log2n)。
维持平衡二叉树性质的操作可以被称为旋转。其中平衡二叉树的右旋处理可以描述如下：

而其左旋处理与右旋正好相反，可以描述如下：

在本题中，读入一串整数，首先利用这些整数构造一棵平衡二叉树。另外给定多次查询，利用构造出的平衡二叉树，判断每一次查询是否成功。


Input Description
输入的第一行包含2个正整数n和k，分别表示共有n个整数和k次查询。其中n不超过500，k同样不超过500。
第二行包含n个用空格隔开的正整数，表示n个整数。
第三行包含k个用空格隔开的正整数，表示k次查询的目标。
Output Description
只有1行，包含k个整数，分别表示每一次的查询结果。如果在查询中找到了对应的整数，则输出1，否则输出0。
请在每个整数后输出一个空格，并请注意行尾输出换行。
Sample Input
8 3
1 3 5 7 8 9 10 15
9 2 5
Sample Output
1 0 1 
Hint
在本题中，首先需要按照题目描述中的算法完成平衡二叉树的构造过程，之后需要通过在平衡二叉树中的不断向下查找，将需要查询的值与当前节点的值进行比较，直到确定被查询的值是否存在。
通过课本中的性能分析部分，不难发现平衡二叉树的查找、插入、删除等操作的时间复杂度均为O(log2n)，这是通过利用旋转操作使二叉树保持平衡状态而保证的。


#include<stdio.h>
#include<malloc.h>
 
#define True 1
#define False 0
#define EH 0
#define LH 1
#define RH -1
 
typedef int ElemType;
 
typedef struct BSTNode{
    ElemType data;
    int bf;
    struct BSTNode *lchild, *rchild;
} BSTNode, *BSTree;
 
void LeftRotate(BSTree *p);
int InsertAVL(BSTree *T, ElemType key, int *taller);
 
void RightRotate(BSTree *p);
int SearchKey(BSTree T, ElemType key);
 
void LeftBalance(BSTree *T);
 
void RightBalance(BSTree *T);
 

 

 
void Free(BSTree *T);
 
int main()
{
    BSTree T = NULL;
    int n, k, key;
    int taller;
     
    scanf("%d%d", &n, &k);
     
    while(n--){
         
        scanf("%d", &key);
        InsertAVL(&T, key, &taller);
    }
    while(k--){
         
        scanf("%d", &key);
        printf("%d ", SearchKey(T, key));
    }
    printf("\n");
    Free(&T);
    return 0;
}
 
void LeftRotate(BSTree *p){
     
    BSTNode *t = (*p)->rchild;
    (*p)->rchild = t->lchild;
    t->lchild = *p;
    *p = t;
}
 
void RightRotate(BSTree *p){
     
    BSTNode *t = (*p)->lchild;
    (*p)->lchild = t->rchild;
    t->rchild = *p;
    *p = t;
}
 
void LeftBalance(BSTree *T){
     
    BSTNode *lc = (*T)->lchild;
     
    switch(lc->bf){
         
    case LH:{
         
        lc->bf = (*T)->bf = EH;
        RightRotate(T);
        break;
    }
    case RH:{
         
        BSTNode *lr = lc->rchild;
         
        switch(lr->bf){
             
        case EH:{
             
            lc->bf = (*T)->bf = EH;
            break;
        }
        case LH:{
             
            lc->bf = EH;
            (*T)->bf = RH;
            break;
        }
case RH:{
             
            lc->bf = LH;
            (*T)->bf = EH;
            break;
        }
        }
        lr->bf = EH;
        LeftRotate(&(*T)->lchild);
        RightRotate(T);
    }
    }
}
 

 
int InsertAVL(BSTree *T, ElemType key, int *taller){
     
    if(!*T){
         
        *T = (BSTNode *)malloc(sizeof(BSTNode));
        (*T)->bf = EH;
        (*T)->data = key;
        (*T)->lchild = NULL;
        (*T)->rchild = NULL;
        *taller = True;
        return True;
    }
    else if(key == (*T)->data){
         
        *taller = False;
        return False;
    }
    else if(key < (*T)->data){
         
        if(InsertAVL(&(*T)->lchild, key, taller) == False){
             
            return False;
        }
        if(*taller == True){
             
            switch((*T)->bf){
                 
            case EH:{
                 
                (*T)->bf = LH;
                break;
            }
            case RH:{
                 
                (*T)->bf = EH;
                *taller = False;
                break;
            }
            case LH:{
                 
                LeftBalance(T);
                *taller = False;
                break;
            }
            }
        }
        return True;
    }
    else{
         
        if(InsertAVL(&(*T)->rchild, key, taller) == False){
             
            return False;
        }
        if(*taller == True){
             
            switch((*T)->bf){
                 
            case EH:{
                 
                (*T)->bf = RH;
                break;
            }
            case LH:{
                 
                (*T)->bf = EH;
                *taller = False;
                break;
            }
            case RH:{
                 
                RightBalance(T);
                *taller = False;
                break;
            }
            }
        }
    }
    return True;
}
void RightBalance(BSTree *T){
     
    BSTNode *rc = (*T)->rchild;
     
    switch(rc->bf){
         
    case RH:{
         
        rc->bf = (*T)->bf = EH;
        LeftRotate(T);
        break;
    }
    case LH:{
         
        BSTNode *rl = rc->lchild;
         
        switch(rl->bf){
             
        case EH:{
             
            rc->bf = (*T)->bf = EH;
            break;
        }
        case RH:{
             
            rc->bf = EH;
            (*T)->bf = LH;
            break;
        }
        case LH:{
             
            rc->bf = RH;
            (*T)->bf = EH;
            break;
        }
        }
        rl->bf = EH;
        RightRotate(&(*T)->rchild);
        LeftRotate(T);
    }
    }
}
void Free(BSTree *T) {
 
    if (*T) {
 
        Free(&(*T)->lchild);
        Free(&(*T)->rchild);
        free(*T);
        *T = NULL;
    }
}
 
int SearchKey(BSTree T, ElemType key){
     
    BSTNode *p = T;
     
    while(p){
         
        if(key == p->data) return True;
         
        else if(key < p->data) p = p->lchild;
         
        else p = p->rchild;
    }
    return False;
}
 

