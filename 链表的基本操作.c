Problem Description
链表是数据结构中一种最基本的数据结构，它是用链式存储结构实现的线性表。它较顺序表而言在插入和删除时不必移动其后的元素。现在给你一些整数，然后会频繁地插入和删除其中的某些元素，会在其中某些时候让你查找某个元素或者输出当前链表中所有的元素。
下面给你基本的算法描述：

图1：链表类型的定义以及获得链表元素的算法描述

图2：链表的插入算法描述

图3：链表的删除算法描述

图4：链表的创建算法描述
Input Description
输入数据只有一组，第一行有n+1个整数，第一个整数是这行余下的整数数目n，后面是n个整数。这一行整数是用来初始化列表的，并且输入的顺序与列表中的顺序相反，也就是说如果列表中是1、2、3那么输入的顺序是3、2、1。
第二行有一个整数m，代表下面还有m行。每行有一个字符串，字符串是“get”，“insert”，“delete”，“show”中的一种。如果是“get”或者“delete”，则其后跟着一个整数a，代表获得或者删除第a个元素；如果是“insert”，则其后跟着两个整数a和e，代表在第a个位置前面插入e；“show”之后没有整数。
Output Description
如果获取成功，则输出该元素；如果删除成功则输出“delete OK”；如果获取失败或者删除失败，则输出“get fail”以及“delete fail”。如果插入成功则输出“insert OK”，否则输出“insert fail”。如果是“show”则输出列表中的所有元素，如果列表是空的，则输出“Link list is empty”。注：所有的双引号均不输出。
Sample Input
3 3 2 1
21
show
delete 1
show
delete 2
show
delete 1
show
delete 2
insert 2 5
show
insert 1 5
show
insert 1 7
show
insert 2 5
show
insert 3 6
show
insert 1 8
show
get 2
Sample Output
1 2 3
delete OK
2 3
delete OK
2
delete OK
Link list is empty
delete fail
insert fail
Link list is empty
insert OK
5
insert OK
7 5
insert OK
7 5 5
insert OK
7 5 6 5
insert OK
8 7 5 6 5
7
Hint
提示：
1、因为输入数据中含有大量的插入和删除操作（不管你信不信，反正我信了），所以必须使用链表，否则很可能会超时。这也是考查链表的特性吧。
2、初始化链表的元素是倒序的，这个使用题目中创建列表的方法（从头部插入）就可以了。
总结：
这题考查的是链表的特性。顺序表中，怎样判断何时使用顺序表何时使用链表呢？就要看它们的特点了。顺序表的特点是随机存取、随机访问，也就是说如果存取和查询比较频繁的话使用顺序表比较合适；链表的特点是插入和删除时不必移动其后的节点，如果插入和删除操作比较频繁的话使用链表比较合适。


#include<string.h>
#include<malloc.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1

typedef int Status;
typedef int Boolean;
typedef int ElemType;
struct LNode
{
    ElemType data;
    struct LNode *next;
};
typedef struct LNode *LinkList;
Status GetElem(LinkList L,int i,ElemType *e);
Status ListInsert(LinkList L,int i,ElemType e);
Status ListDelete(LinkList L,int i,ElemType *e);
void CreateList(LinkList *L,int n);


int ShowList(LinkList L)
{
    int numOfList = 0;
    LinkList p = L->next;
    while(p)
    {
        if(numOfList)
        {
            putchar(' ');
        }
        numOfList++;
        printf("%d",p->data);
        p = p->next;
    }
    if(numOfList == 0)
    {
        return 0;
    }
    else
    {
        putchar('\n');
        return numOfList;
    }
}

int main()
{
    int n;
    int m;
    char strInst[30];
    int a;
    LinkList L;
    int e;
    scanf("%d", &n);
    CreateList(&L, n);
    scanf("%d", &m);
    while(m--)
    {
        scanf("%s", strInst);
        if(strcmp(strInst, "get") == 0)
        {
            scanf("%d", &a);
            if(GetElem(L, a, &e) == OK)
            {
                printf("%d\n", e);
            }
            else
            {
                puts("get fail");
            }
        }
        else if(strcmp(strInst, "insert") == 0)
        {
            scanf("%d%d", &a, &e);
            if(ListInsert(L, a, e) == OK)
            {
                puts("insert OK");
            }
            else
            {
                puts("insert fail");
            }
        }
        else if(strcmp(strInst, "delete") == 0)
        {
            scanf("%d",&a);
            if(ListDelete(L, a, &e) == OK)
            {
                puts("delete OK");
            }
            else
            {
                puts("delete fail");
            }
        }
        else if(strcmp(strInst, "show") == 0)
        {
            if(ShowList(L) == 0)
            {
                puts("Link list is empty");
            }
        }
    }

    return 0;
}
Status GetElem(LinkList L,int i,ElemType *e)
{

    int j = 1;
    LinkList p = L -> next;
    while(p && j < i)
    {
        p = p -> next;
        j ++;
    }
    if(!p || j > i)
        return ERROR;
    *e = p -> data;
    return OK;
}

Status ListInsert(LinkList L,int i,ElemType e)
{

    int j = 0;
    LinkList p = L, s;
    while(p&&j < i - 1)
    {
        p = p -> next;
        j ++;
    }
    if(!p || j > i - 1)
        return ERROR;
    s = (LinkList)malloc(sizeof(struct LNode));
    s -> data = e;
    s -> next = p -> next;
    p -> next = s;
    return OK;
}

Status ListDelete(LinkList L,int i,ElemType *e)
{
    int j = 0;
    LinkList p=L, q;
    while(p -> next && j < i - 1)
    {
        p = p -> next;
        j ++;
    }
    if(!p -> next || j > i - 1)
        return ERROR;
    q = p -> next;
    p -> next = q -> next;
    *e = q -> data;
    free(q);
    return OK;
}

void CreateList(LinkList *L,int n)
{
    int i;
    LinkList p;
    *L = (LinkList)malloc(sizeof(struct LNode));
    (*L) -> next = NULL;
    for(i = n; i > 0; --i)
    {
        p = (LinkList)malloc(sizeof(struct LNode));
        scanf("%d",&p->data);
        p->next=(*L)->next;
        (*L)->next=p;
    }
}
