Problem Description
设已知有两个堆栈S1和S2，请用这两个堆栈模拟出一个队列Q。

所谓用堆栈模拟队列，实际上就是通过调用堆栈的下列操作函数:

int IsFull(Stack S)：判断堆栈S是否已满，返回1或0；
int IsEmpty (Stack S )：判断堆栈S是否为空，返回1或0；
void Push(Stack S, ElementType item )：将元素item压入堆栈S；
ElementType Pop(Stack S )：删除并返回S的栈顶元素。
实现队列的操作，即入队void AddQ(ElementType item)和出队ElementType DeleteQ()。

Input Description
输入首先给出两个正整数N1和N2，表示堆栈S1和S2的最大容量。随后给出一系列的队列操作：A item表示将item入列（这里假设item为整型数字）；D表示出队操作；T表示输入结束。
Output Description
对输入中的每个D操作，输出相应出队的数字，或者错误信息ERROR:Empty。如果入队操作无法执行，也需要输出ERROR:Full。每个输出占1行。
Sample Input
3 2
A 1 A 2 A 3 A 4 A 5 D A 6 D A 7 D A 8 D D D D T
Sample Output
ERROR:Full
1
ERROR:Full
2
3
4
7
8
ERROR:Empty
Hint
堆栈


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define OK 1
#define ERROR 0
#define max_size 10000
typedef struct node
{
    int v;
    struct node *next;
}gss;
int len1;
void insert(gss **first,int num,int *len);
int len2;

void delete(gss **first,int *len);

int main()
{
   gss *s1=NULL;
    gss *s2=NULL;
    int l1,l2;
    scanf("%d %d",&l1,&l2);
    if(l1 - l2 > 0){
        int tmp=l1;
        l1=l2;
        l2=tmp;
    }
    char ch;
    int num;
    len1=0;
    len2=0;
    while(~scanf("%c",&ch)&&ch!='T')
    {
        if(ch==' ')
            continue;
        if(ch=='A')
        {
            scanf("%d",&num);
            if(len1- l1 < 0)
            {
                insert(&s1,num,&len1);
            }
            else
            {
                if(s2!=NULL)printf("ERROR:Full\n");
                else{
                while(s1!=NULL)
                {
                    insert(&s2,s1->v,&len2);
                    delete(&s1,&len1);
                }
                insert(&s1,num,&len1);
                }
            }
        }
        else if(ch=='D')
        {
            if(s2!=NULL)
            {
                printf("%d\n",s2->v);
                delete(&s2,&len2);
            }
            else
            {
                if(s1==NULL)
                {
                    printf("ERROR:Empty\n");
                }
                else
                {
                    while(s1!=NULL)
                    {
                        insert(&s2,s1->v,&len2);
                        delete(&s1,&len1);
                    }
                    printf("%d\n",s2->v);
                    delete(&s2,&len2);
                }
            }
        }
    }

    return 0;
}
void delete(gss **first,int *len)
{
    gss *cur=*first;
    *first=(*first)->next;
    free(cur);
    (*len)--;
}

void insert(gss **first,int num,int *len)
{
     gss *p;
    p=(gss*)malloc(sizeof(gss));
    p->v=num;
    p->next=*first;
    (*len)++;
    *first=p;
}

