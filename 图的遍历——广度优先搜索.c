Problem Description
广度优先搜索遍历类似于树的按层次遍历的过程。其过程为：假设从图中的某顶点v出发，在访问了v之后依次访问v的各个未曾被访问过的邻接点，然后分别从这些邻接点出发依次访问它们的邻接点，并使“先被访问的顶点的邻接点”先于“后被访问的顶点的邻接点”被访问，直至图中所有已被访问的顶点的邻接点都被访问到。若此时图中尚有顶点未被访问，则另选图中一个未曾被访问的顶点作为起始点。重复上述过程，直至图中所有顶点都被访问到为止。
其算法可以描述如下：

在本题中，读入一个无向图的邻接矩阵（即数组表示），建立无向图并按照以上描述中的算法遍历所有顶点，输出遍历顶点的顺序。

Input Description
输入的第一行包含一个正整数n，表示图中共有n个顶点。其中n不超过50。
以后的n行中每行有n个用空格隔开的整数0或1，对于第i行的第j个0或1，1表示第i个顶点和第j个顶点有直接连接，0表示没有直接连接。当i和j相等的时候，保证对应的整数为0。
输入保证邻接矩阵为对称矩阵，即输入的图一定是无向图。
Output Description
只有一行，包含n个整数，表示按照题目描述中的广度优先遍历算法遍历整个图的访问顶点顺序。每个整数后输出一个空格，并请注意行尾输出换行。
Sample Input
4
0 0 0 1
0 0 1 1
0 1 0 1
1 1 1 0
Sample Output
0 3 1 2 
Hint
在本题中，需要熟练掌握图的邻接矩阵存储方式。在建立完成无向图之后，需要严格按照题目描述的遍历顺序对图进行遍历。另外，算法中描述的FirstAdjVex函数和NextAdjVex函数，需要认真的自行探索并完成。在本题中需要使用队列结构，需要对队列的概念进行复习。
通过这道题目，应该能够对图的广度优先搜索建立更加直观和清晰的概念。



#include<stdio.h>
#include<string.h>
#include<stdlib.h>
 
int n,k,l;
int a[55][55],b[55];
int ans[55];
 
typedef struct
{
    int elem[205];
    int length;
}list;
void mergelist(list La,list Lb,list *Lc);
void DFS(int x);
int main()
{
    int W,R,E,Q;
    W = R * (Q/E);
    R = ((Q + E)*Q)/R;
    int i,j;
    scanf("%d",&n);
    {
        for(i=0;i-n<0;++i)
        {
            for(j=0;j-n<0;++j)
            {
                scanf("%d",&a[i][j]);
            }
        }
        k=0;
        l=0;
        for(j=0;j-n<0;++j)
            b[j]=1;
        for(i=0;i-n<0;++i)
        {
            if(b[i]==1)
            {
                DFS(i);
            }
        }
    }
    return 0;
}
void mergelist(list La,list Lb,list *Lc)
{
     int d=0,q=0,k=0;
    while((d!=La.length)&&(q!=Lb.length))
    {
        if(La.elem[d]-Lb.elem[q]<=0)
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
 
void DFS(int x)
{
    int i,j;
    if(b[x]==1)
    {
        ans[k++]=x;
        b[x]=0;
    }
    if(k==n)
    {
        for(i=0;i-n<0;++i)
        {
            printf("%d ",ans[i]);
        }
        printf("\n");
        exit(0);
    }
    for(i=0;i-n<0;++i)
    {
        if(a[x][i]==1&&b[i]==1)
        {
            ans[k++]=i;
            b[i]=0;
        }
    }
    DFS(ans[++l]);
    return;
}