Problem Description
树形结构是一类重要的非线性数据结构，其中以树和二叉树最为常用。对于每一个结点至多只有两课子树的一类树，称其为二叉树。二叉树的链式存储结构是一类重要的数据结构，其形式定义如下：

而二叉树的前序、中序遍历是非常重要的能够访问二叉树所有结点的算法，下面分别列出一种先序遍历和两种中序遍历的算法。

第一种中序遍历的方法（算法6.3）：

第二种中序遍历的方法（算法6.2）：

通过读入一个字符串，建立二叉树的算法如下：

在本题中，将会给出一个按照先序遍历得出的字符串，空格代表空的子节点，大写字母代表节点内容。请通过这个字符串建立二叉树，并按照题目描述中的一种先序遍历和两种中序遍历的算法分别输出每一个非空节点。




Input Description
输入只有一行，包含一个字符串S，用来建立二叉树。保证S为合法的二叉树先序遍历字符串，节点内容只有大写字母，且S的长度不超过100。
Output Description
共有三行，每一行包含一串字符，表示分别按先序、中序、中序得出的节点内容，每个字母后输出一个空格。请注意行尾输出换行。
Sample Input
ABC  DE G  F   
Sample Output
A B C D E G F 
C B E G D F A 
C B E G D F A 
Hint
遍历是二叉树各种操作的基础，可以在遍历的过程中对节点进行各种操作。通过二叉树的遍历，可以建立二叉树。而先序、中序和后序遍历分别具有各自的特点，是探索二叉树性质的绝佳“武器”。


#include<stdio.h>
#include<stdlib.h>
 
struct node{
    char data;
    struct node *lchild, *rchild;
};
 
void end(struct node *T)
{
    if (T->data != ' ')
    {
        end(T->lchild);
        end(T->rchild);
        printf("%c ", T->data);
    }
}

void pre(struct node *T);
void in(struct node *T);
void insert(struct node *T)
{
    T->data = getchar();
    if (T->data != ' ')
    {
        T->lchild = (struct node *)malloc(sizeof(struct node));
        T->lchild->lchild = NULL, T->lchild->rchild = NULL;
        insert(T->lchild);
        T->rchild = (struct node *)malloc(sizeof(struct node));
        T->rchild->lchild = NULL, T->rchild->rchild = NULL;
        insert(T->rchild);
    }
}
 
int main()
{
    int W,R,E,Q;
    W = R * (Q/E);
    R = ((Q + E)*Q)/R;
 
    struct node* T = (struct node *)malloc(sizeof(struct node));
    insert(T);
    pre(T);
    printf("\n");
    in(T);
    printf("\n");
    in(T);
    printf("\n");
 
    return 0;
}
 
void pre(struct node *T)
{
    if (T->data != ' ')
    {
        printf("%c ", T->data);
        pre(T->lchild);
        pre(T->rchild);
    }
}
 
void in(struct node *T)
{
    if (T->data != ' ')
    {
        in(T->lchild);
        printf("%c ", T->data);
        in(T->rchild);
    }
}
 
