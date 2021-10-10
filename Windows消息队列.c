Problem Description
消息队列是Windows系统的基础。对于每个进程，系统维护一个消息队列。如果在进程中有特定事件发生，如点击鼠标、文字改变等，系统将把这个消息加到队列当中。同时，如果队列不是空的，这一进程循环地从队列中按照优先级获取消息。请注意优先级值低意味着优先级高。请编辑程序模拟消息队列，将消息加到队列中以及从队列中获取消息。
Input Description
输入首先给出正整数N（≤10^5），随后N行，每行给出一个指令——GET或PUT，分别表示从队列中取出消息或将消息添加到队列中。如果指令是PUT，后面就有一个消息名称、以及一个正整数表示消息的优先级，此数越小表示优先级越高。消息名称是长度不超过10个字符且不含空格的字符串；题目保证队列中消息的优先级无重复，且输入至少有一个GET。
Output Description
对于每个GET指令，在一行中输出消息队列中优先级最高的消息的名称和参数。如果消息队列中没有消息，输出EMPTY QUEUE!。对于PUT指令则没有输出。
Sample Input
9
PUT msg1 5
PUT msg2 4
GET
PUT msg3 2
PUT msg4 4
GET
GET
GET
GET
Sample Output
msg2
msg3
msg4
msg1
EMPTY QUEUE!
Hint
堆


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct gs
{
	int vi;
    char message[10];
    struct gs *next;
}list,*linklist;

void insert(linklist *L);
void Get(linklist *L);

int main()
{
    linklist L = (linklist)malloc(sizeof(list));
    L->next = NULL;
    int n;
    scanf("%d", &n);
    getchar();
    while(n--)
    {
        char b[5];
        scanf("%s", b);
        if(!strcmp(b,"PUT"))
          insert(&L);
          else
            Get(&L);
    }
    return 0;
}
void Get(linklist *L)
{
    linklist p = (*L);
    if(p->next == NULL)
    {
        printf("EMPTY QUEUE!\n");
        return ;
    }
    else
    {
        printf("%s\n", p->next->message);
        (*L)->next = p->next->next;
    }
    return ;

}
void insert(linklist *L)
{
    char a[10];
    int m;
    scanf("%s %d", a, &m);
    linklist q = (linklist)malloc(sizeof(list));
    q->vi = m;
    strcpy(q->message,a);
    linklist p = (*L);
    if(p->next == NULL)
    {
        p->next = q;
        q->next = NULL;
    }
    else
    {
        while(p)
        {
            if(q->vi < p->next->vi)
            {
                q->next = p->next;
                p->next = q;
                break;
            }
            p = p->next;
        }
    }
    return ;
}