Problem Description
复习考研累了的时候看看一集二十分钟左右的《生活大爆炸》也不失为一种乐趣。在剧中Sheldon可以说是一个极品，真不知Leonard是如何忍受这位极品室友成天的唠叨。
你知道么？Sheldon有一个神秘的小本本，记录了所有他从小开始讨厌的人名。Stuart这位漫画店老板就是小本本的一员哦，谁叫他常常毫不客气地挤兑Sheldon，曾多次赌赢过Sheldon呢。
Penny是一个漂亮的女孩，好奇心也很强。为了满足她的好奇心，我当回编剧让她意外知道了Sheldon的那个小本本放在了哪里。于是她几乎每天都去看，看看上面有哪些人。但是那个小本本上的人名实在太多。要知道她可是没上过大学在饭店里面当服务员啊。请聪明的你帮帮她处理处理那个小本本吧。

图1：《生活大爆炸》里的角色
Sheldon每天都会在小本本里记录些人名，当然有时也会与他们和好就会从小本本中将这个人名删除。我们假设Sheldon会在一个空的小本本上插入、删除、查询某个人。
要帮助Penny，你需要知道一个顺序表是怎么初始化、插入、删除以及查找的。下面我就将这些算法列举在下方。

图2：线性表的动态分配顺序存储结构以及初始化

图3：线性表的插入算法

图4：线性表的删除算法

图5：线性表的查找算法
Input Description
输入数据只有一组，有很多行。每行的格式可能是下列一种：
insert a name
delete name
show
search name
其中 a 是一个整数，代表在第a个名字前插入名字。name是一个姓名，只包含英文字母的大小写，每个名字不超过30个字符。
输入保证不会插入列表中已经存在的姓名，不会删除列表中不存在的姓名，也不会搜索列表中不存在的姓名。

Output Description
起始时，列表是空的。只输出show和search name 的结果。show将列表中的姓名全部输出，search只输出找到该名字的序号（从1开始）。每次输出占一行，姓名间用空格隔开。如果列表中没有名字了，show时也要输出一个空行。

Sample Input
insert 1 Stuart
insert 2 Bernadette
show
search Stuart
delete Stuart
show
insert 2 Stuart
show
insert 1 Amy
insert 2 Leslie
insert 3 Stephanie
show
delete Leslie
show
search Stuart
Sample Output
Stuart Bernadette
1
Bernadette
Bernadette Stuart
Amy Leslie Stephanie Bernadette Stuart
Amy Stephanie Bernadette Stuart
4
Hint
提示：
1、名字是不含空格的，指令也是一定的，所以可以用scanf("%s", str)来读取。
2、上述代码有些函数头中变量类型与变量之间有个&，这个表示该变量是引用类型的，是C++特性。在C语言中存在值传递与指针传递，值传递中形参不可以改变实参的值，需要通过指针来修改。而引用变量实际上就是实参的另一个名字，这种类型的形参改变会影响实参的值。
3、使用题目中的代码需要自己定义其中缺失的类型和变量，例如Status、OK以及Error等。
4、ElemType类型中可以只有一个字符数组用来存储姓名。
5、LocateElem_Sq函数在调用时需要传递一个函数指针，可以这样定义：
Status cmp(ElemType e1, ElemType e2);
注意这个函数用来判断e1和e2是否相等，如果相等则返回非零值，否则返回0。因此可以在这个函数里直接返回 !strcmp(...)但最好需要改变返回类型。
6、内存分配以及字符串操作需要的头文件分别是stdlib.h和string.h需要被包含进来。
7、题目要求每个输出占一行，所以要注意换行。
总结：
1、实际上，题目中几乎将主要代码都写出来了。解决这道题使用上面的代码是可能复杂了点，但将各个功能独立出来是个不错的思路。以后修改就方便了，特别适用于代码量较大的程序。
2、C语言中参数的传递分为值传递和指针传递，而C++中多了一个引用传递。值传递和指针传递都不可以改变传递进来的值，但指针可以改变其所指向的值。在C语言中，调用函数时传入的参数叫做“实参”，而在函数声明或定义中在函数头中的参数叫做“形参”。值传递与指针传递中，形参的改变是不影响实参的。C++中，引用传递，形参与实参实际上是同一个内容的不同名字，因而形参的变化会改变实参。引用传递是C++中一个很重要也很方便的特性，比如在可能会产生不必要的复制时，采用引用传递是一个很不错的解决方案。



#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#define LIST_SIZE 3

typedef struct
{
    char name[31];
}Temp;

typedef struct
{
    Temp *temp;
    int length;
    int listsize;
}SeqList;

void Show(SeqList l);
int InitList(SeqList *L);
void Delete(SeqList *L, Temp e);

int Insert(SeqList *L, int i, Temp e);
int Search(SeqList L, Temp e);



int main()
{
    char str[20];
    int v;
    Temp e;
    SeqList L;
    InitList(&L);
    while(scanf("%s", str) != EOF)
    {
        if(!strcmp(str, "insert"))
        {
            scanf("%d %s", &v, e.name);
            Insert(&L, v, e);
        }
        else if(!strcmp(str, "show"))
        {
            Show(L);
        }
        else if(!strcmp(str, "search"))
        {
            scanf("%s", e.name);
            printf("%d\n", Search(L, e) + 1);
        }
        else if(!strcmp(str, "delete"))
        {
            scanf("%s", e.name);
            Delete(&L, e);
        }
    }
    return 0;
}

int InitList(SeqList *L)
{
    (*L).temp = (Temp*)malloc(LIST_SIZE * sizeof(Temp));
    if(!L -> temp)
    {
        return 0;
    }
    L -> length = 0;
    L -> listsize = LIST_SIZE;
    return 1;
}



void Show(SeqList L)
{
    for(int i = 0; i - L.length < 0; ++i)
    {
        if(i == 0)
        {
            printf("%s", L.temp[i].name);
        }
        else
            {
                printf(" %s", L.temp[i].name);
            }
    }
    printf("\n");
}


int Insert(SeqList *L, int i, Temp e)
{
    Temp *m, *q, *p;
    if(L -> length >= L -> listsize)
    {
        m = (Temp*)realloc(L -> temp,(L -> listsize + 1) * sizeof(Temp));
        if(!m)
        {
            return 0;
        }
        L -> listsize ++;
        L -> temp = m;
    }
    q = (*L).temp + i - 1;
    for (p = L -> temp + L -> length; p - q >= 0; p--)
    {
        *p = *(p - 1);
    }
    *q = e;
    L -> length++;
    return 1;
}
void Delete(SeqList *L, Temp e)
{
    Temp *i, *t;
    for(i = L -> temp; i < L -> temp + L -> length; ++i)
    {
        if (!strcmp((*i).name, e.name))
        {
            for (t = i; t < L->temp+L->length - 1;++t)
            {
                *t=*(t + 1);
            }
            break;
        }
    }
    L -> length--;
}
int Search(SeqList L, Temp e)
{
    for(int i = 0; i - L.length < 0; ++i)
    {
        if(!strcmp(L.temp[i].name, e.name))
        {
            return i;
            break;
        }
    }
}
