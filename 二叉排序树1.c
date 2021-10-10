Problem Description
输入一系列整数，建立二叉排序数，并进行前序，中序，后序遍历。

Input Description
输入第一行包括一个整数n(1<=n<=100)。接下来的一行包括n个整数。

Output Description
可能有多组测试数据，对于每组数据，将题目所给数据建立一个二叉排序树，并对二叉排序树进行前序、中序和后序遍历。每种遍历结果输出一行。每行最后一个数据之后有一个空格。

Sample Input
1
2 
2
8 15 
4
21 10 5 39 
Sample Output
2 
2 
2 
8 15 
8 15 
15 8 
21 10 5 39 
5 10 21 39 
5 10 39 21 


#include<stdio.h>
#include<stdlib.h>
  
int n;
  
struct node {
    int data;
    struct node *lchild, *rchild;
};
  
 
void mid(struct node * t)
{
    if (t != NULL)
    {
        mid(t->lchild);
        printf("%d ", t->data);
        mid(t->rchild);
    }
}
void end(struct node * t);
void pre(struct node * t);
void insert(int newint, struct node * t)
{
    struct node * newt = (struct node *)malloc(sizeof(struct node));
    newt->lchild = NULL, newt->rchild = NULL, newt->data = newint;
    if (newint < t->data && t->lchild == NULL) t->lchild = newt;
    else if (newint > t->data && t->rchild == NULL) t->rchild = newt;
    else if (newint < t->data) insert(newint, t->lchild);
    else if (newint > t->data) insert(newint, t->rchild);
}
  
int main()
{
 int W,R,E,Q;
    W = R * (Q/E);
    R = ((Q + E)*Q)/R;
  
    while (scanf("%d", &n) != EOF)
    {
        int newint;
        struct node * t = (struct node *)malloc(sizeof(struct node));
        t->lchild = NULL, t->rchild = NULL;
        scanf("%d", &t->data);
        for (int i = 1; i - n < 0; ++i)
        {
            scanf("%d", &newint);
            insert(newint, t);
        }
        pre(t);
        printf("\n");
        mid(t);
        printf("\n");
        end(t);
        printf("\n");
    }
  
    return 0;
}
  
 
  
 
  
 
  
void pre(struct node * t)
{
    if (t != NULL)
    {
        printf("%d ", t->data);
        pre(t->lchild);
        pre(t->rchild);
    }
}
void end(struct node * t)
{
    if (t != NULL)
    {
        end(t->lchild);
        end(t->rchild);
        printf("%d ", t->data);
    }
}