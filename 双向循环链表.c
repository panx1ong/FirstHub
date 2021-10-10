Problem Description
双向链表是在结点中既保存了后一个结点指针又保存了前一个结点指针的链表。这种链表较单向链表而言能够快速查找某一结点的前后结点。下面给出双向链表的定义、插入以及删除算法描述。

图1：双向链表示例
（a）结点结构；（b）空的双向循环链表；（c）含有三个结点的双向循环链表

图2：双向链表的定义以及创建
双向链表在插入与删除时一定要注意其操作步骤的顺序。下面给出双向链表在插入与删除时的图示。

图3：双向链表插入与删除的图示
（a）双向链表的删除操作；（b）双向链表的插入操作

图4：双向链表的查找以及插入

图5：双向链表的删除操作
Input Description
输入数据只有一组，包含很多行。每行有1~3个整数。第一个整数如果是0，则表示输出双向链表中的所有元素；第一个整数如果是1，表示插入1个整数，其后跟2个整数i、e代表在第i个位置插入e；第一个整数如果是2，表示删除1个整数，其后跟1个整数i，表示删除的位置为i。
起始双向链表为空表。保证链表中每个元素不会重复，同时所有的操作都合法。

Output Description
当需要输出双向链表中的所有元素时输出，每次输出一行。整数间用一个空格隔开。

Sample Input
1 1 2
0
1 2 7
0
2 1
0
1 2 4
1 3 5
1 2 6
0
2 3
0
Sample Output
2
2 7
7
7 6 4 5
7 6 5
Hint
提示：
1、如果使用switch，注意每个case后面使用break。
2、结构体定义时，因为定义里面有用到这个类型的指针，所以需要在开始struct后面写上结构体名。
3、注意循环链表全部遍历结束的条件是遍历的指针是否又指向了头结点。
总结：
1、双向链表的重要之处在于插入和删除时的操作顺序，切勿弄乱顺序而丢失数据。
2、循环链表全部遍历的结束条件需要注意，不是非空，而是判断是否到头结点了。
本题考查的是双向循环链表，所以上述都需要注意。



#include<stdio.h>
#include<stdlib.h>

#define ERROR 0
#define OK 1
typedef struct Dulnode{
    int data;
    struct Dulnode *prior;
    struct Dulnode *next;
}DuLNode, *DuLinkList;
typedef int Status;
typedef int ElemType;

Status ListInsert_DuL(DuLinkList l, int i, ElemType e);

DuLinkList GetElemP_DuL(DuLinkList l, int i);
void print(DuLinkList l);
Status ListDelete_DuL(DuLinkList l, int i);
int main()
{
    int n,i,e;
    DuLinkList l,s;
    l =  (DuLinkList)malloc(sizeof(DuLNode));
    l -> next = l ;
    l -> prior = l ;
    while(scanf("%d",&n)!=EOF)
    {
        switch(n)
        {
            case 0:
                print(l);
                break;
            case 1:
                scanf("%d%d",&i,&e);
                ListInsert_DuL(l,i,e);
                break;
            case 2:
                scanf("%d",&i);
                ListDelete_DuL(l,i);
                break;
        }
    }
    return 0;
 }


Status ListInsert_DuL(DuLinkList l, int i, ElemType e)
{
    DuLinkList s ,p;
    if(!(p = GetElemP_DuL(l,i)))
        return ERROR;

    s = (DuLinkList)malloc(sizeof(DuLNode));
    s -> data = e;
    p -> prior -> next = s;
    s -> prior = p -> prior ;
    s -> next = p;
    p -> prior = s;
    s  = l -> next ;

    return OK;
}

 DuLinkList GetElemP_DuL(DuLinkList l,int i)
{
    DuLinkList s ;
    int j ;
    s = l -> next ;
    for( j = 1; j < i && s != l; ++j)
    {
        s = s -> next ;
    }
    return s;
}

void print(DuLinkList l)
{
    DuLinkList s = l->next ;
    int i = 0;
    while(s -l != 0)
    { 
        if(i)
            printf(" ");
        printf("%d",s->data );
        s = s -> next  ;
        ++i;
    }
    printf("\n");
    return ;
}

Status ListDelete_DuL(DuLinkList l,int i)
{
    DuLinkList p;
    if(!(p = GetElemP_DuL(l,i)))
        return ERROR;
    p -> prior -> next = p -> next ;
    p -> next -> prior = p -> prior;
    free(p);
}
