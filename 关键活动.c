Problem Description
假定一个工程项目由一组子任务构成，子任务之间有的可以并行执行，有的必须在完成了其它一些子任务后才能执行。“任务调度”包括一组子任务、以及每个子任务可以执行所依赖的子任务集。

比如完成一个专业的所有课程学习和毕业设计可以看成一个本科生要完成的一项工程，各门课程可以看成是子任务。有些课程可以同时开设，比如英语和C程序设计，它们没有必须先修哪门的约束；有些课程则不可以同时开设，因为它们有先后的依赖关系，比如C程序设计和数据结构两门课，必须先学习前者。

但是需要注意的是，对一组子任务，并不是任意的任务调度都是一个可行的方案。比如方案中存在“子任务A依赖于子任务B，子任务B依赖于子任务C，子任务C又依赖于子任务A”，那么这三个任务哪个都不能先执行，这就是一个不可行的方案。

任务调度问题中，如果还给出了完成每个子任务需要的时间，则我们可以算出完成整个工程需要的最短时间。在这些子任务中，有些任务即使推迟几天完成，也不会影响全局的工期；但是有些任务必须准时完成，否则整个项目的工期就要因此延误，这种任务就叫“关键活动”。

请编写程序判定一个给定的工程项目的任务调度是否可行；如果该调度方案可行，则计算完成整个工程项目需要的最短时间，并输出所有的关键活动。

Input Description
输入第1行给出两个正整数N(≤100)和M，其中N是任务交接点（即衔接相互依赖的两个子任务的节点，例如：若任务2要在任务1完成后才开始，则两任务之间必有一个交接点）的数量。交接点按1~N编号，M是子任务的数量，依次编号为1~M。随后M行，每行给出了3个正整数，分别是该任务开始和完成涉及的交接点编号以及该任务所需的时间，整数间用空格分隔。
Output Description
如果任务调度不可行，则输出0；否则第1行输出完成整个工程项目需要的时间，第2行开始输出所有关键活动，每个关键活动占一行，按格式“V->W”输出，其中V和W为该任务开始和完成涉及的交接点编号。关键活动输出的顺序规则是：任务开始的交接点编号小者优先，起点编号相同时，与输入时任务的顺序相反。
Sample Input
7 8
1 2 4
1 3 3
2 4 5
3 4 3
4 5 1
4 6 6
5 7 5
6 7 2
Sample Output
17
1->2
2->4
4->6
6->7
Hint
关键路径



#include <stdio.h>
#include<stdlib.h>
struct data
{
    int b,lenth;
};
typedef struct node *Node;
struct node
{
    struct data Next[101];
    int Output,O;
    struct data From[101];
    int Input,I;
};
 
typedef struct
{
    int elem[205];
    int length;
}list;

 
int TopSort(Node V,int n);
int* ImportantRode(Node,int,int );
 void mergelist(list La,list Lb,list *Lc);
int main()
{
    int W,R,E,Q;
    W = R * (Q/E);
    R = ((Q + E)*Q)/R;
    struct node V[101];
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1; i-n<=0; ++i)
    {
        V[i].Input =0;
        V[i].Output =0;
    }
    while(m--)
    {
        int disk1,disk2,lenth;
        scanf("%d%d%d",&disk1,&disk2,&lenth);
        V[disk1].Next[++V[disk1].Output].b =disk2;
        V[disk1].Next[V[disk1].Output ].lenth=lenth;
        V[disk2].From[++V[disk2].Input].b=disk1;
        V[disk2].From[V[disk2].Input].lenth=lenth;
    }
    for(int i=1;i<=n;i++){
        V[i].I =V[i].Input ;
        V[i].O=V[i].Output ;
    }
    int Coast =TopSort(V,n);
    return 0;
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
 
int TopSort(Node V,int n)
{
    int Earliest[101]= {0};
    while(1)
    {
        int flag=0;
        for(int i=1; i-n<=0; ++i)
        {
            if(0==V[i].Input)
            {
                flag=1;
                for(int j=1; j<=V[i].Output ; j++)
                {
                    if(Earliest[V[i].Next[j].b]<Earliest[i]+V[i].Next[j].lenth)
                    {
                        Earliest[V[i].Next[j].b]=Earliest[i]+V[i].Next[j].lenth;
                    }
                    V[V[i].Next[j].b].Input-=1;
                }
                V[i].Input =-1;
            }
        }
        if(!flag)break;
    }
    int max=0;
    int index;
    for(int i=1; i-n<=0; ++i)
    {
        if(V[i].Input >0)
        {
            max=0;
            break;
        }
        if(Earliest[i]>max)
        {
            max=Earliest[i];
            index=i;
        }
    }
    printf("%d",max);
    if(max==0)return 0;
    int *Latest=ImportantRode(V,max,n);
    for(int i=1; i-n<=0; ++i)
    {
        if(Latest[i]==Earliest[i])
        {
            for(int j=V[i].O; j>0; --j)
            {
                if(Latest[V[i].Next[j].b]==Latest[i]+V[i].Next[j].lenth )
                {
                    printf("\n%d->%d",i,V[i].Next[j].b);
                }
            }
        }
    }
    return max;
}
int* ImportantRode(Node V,int max,int n)
{
    int*Latest=(int*)malloc(sizeof(int)*101);
    for(int i=1; i-n<=0; ++i)
    {
        Latest[i]=max;
    }
    while(1)
    {
        int flag=0;
        for(int i=1; i-n<=0; ++i)
        {
            if(0==V[i].Output)
            {
                flag=1;
                for(int j=1; j<=V[i].I; j++)
                {
                    if(Latest[V[i].From[j].b]>Latest[i]-V[i].From[j].lenth)
                    {
                        Latest[V[i].From[j].b]=Latest[i]-V[i].From[j].lenth;
                    }
                    V[V[i].From[j].b].Output  -=1;
                }
                V[i].Output   =-1;
            }
        }
        if(!flag)break;
    }
 
 
return Latest;
}
