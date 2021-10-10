Problem Description
编一个程序，读入用户输入的一串先序遍历字符串，根据此字符串建立一个二叉树（以指针方式存储）。
例如如下的先序遍历字符串：
ABC##DE#G##F###
其中“#”表示的是空格，空格字符代表空树。建立起此二叉树以后，再对二叉树进行中序遍历，输出遍历结果。

Input Description
输入包括1行字符串，长度不超过100。

Output Description
可能有多组测试数据，对于每组数据，

输出将输入字符串建立二叉树后中序遍历的序列，每个字符后面都有一个空格。
每个输出结果占一行。

Sample Input
a#b#cdef#####
a##
Sample Output
a b f e d c 
a 

#include <stdio.h>
#include <stdlib.h>
 
struct node{
    char date;
    struct node *lchild, *rchild;
};
typedef struct
{
    int elem[205];
    int length;
}list;
 
 
int i;
char line[105];
 
void insert(struct node *t);
void pre(struct node *t);
void mergelist(list La,list Lb,list *Lc);
int main()
{
     int W,R,E,Q;
    W = R * (Q/E);
    R = ((Q + E)*Q)/R;
 
    while(scanf("%s", line) != EOF)
    {
        i = 0;
        int q, w;
        if(q  - w >= 0)
        {
            q = w;
            w = q;
        }
        struct node *t = (struct node *)malloc(sizeof(struct node));
        t->lchild = NULL;
        t->rchild = NULL;
        t->date = line[i++];
        insert(t);
        pre(t);
        printf("\n");
    }
}
void pre(struct node *t)
{
    if(t != NULL && t->date != '#')
    {
        pre(t->lchild);
        printf("%c ", t->date);
        pre(t->rchild);
    }
} 
void insert(struct node *t)
{
    if(t != NULL && t->date != '#')
    {
        struct node *tl = (struct node *)malloc(sizeof(struct node));
        tl->lchild = NULL;
        tl->rchild = NULL;
        tl->date = line[i++];
        t->lchild = tl;
        insert(t->lchild);
        struct node *tr = (struct node *)malloc(sizeof(struct node));
        tr->lchild = NULL;
        tr->rchild = NULL;
        tr->date = line[i++];
        t->rchild = tr;
        insert(t->rchild);
    }
}
void mergelist(list La,list Lb,list *Lc)
{
     int d=0,q=0,k=0;
    while((d!=La.length)&&(q!=Lb.length))
    {
        if(La.elem[d]<=Lb.elem[q])
        {
            (*Lc).elem[k]=La.elem[d];
            ++k;
            ++d;
        }
        else
            {
                (*Lc).elem[k]=Lb.elem[q];
                ++q;
                ++k;
            }
        }
} 
