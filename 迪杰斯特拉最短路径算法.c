Problem Description
在带权有向图G中，给定一个源点v，求从v到G中的其余各顶点的最短路径问题，叫做单源点的最短路径问题。
在常用的单源点最短路径算法中，迪杰斯特拉算法是最为常用的一种，是一种按照路径长度递增的次序产生最短路径的算法。
可将迪杰斯特拉算法描述如下：

在本题中，读入一个有向图的带权邻接矩阵（即数组表示），建立有向图并按照以上描述中的算法求出源点至每一个其它顶点的最短路径长度。
Input Description
输入的第一行包含2个正整数n和s，表示图中共有n个顶点，且源点为s。其中n不超过50，s小于n。
以后的n行中每行有n个用空格隔开的整数。对于第i行的第j个整数，如果大于0，则表示第i个顶点有指向第j个顶点的有向边，且权值为对应的整数值；如果这个整数为0，则表示没有i指向j的有向边。当i和j相等的时候，保证对应的整数为0。
Output Description
只有一行，共有n-1个整数，表示源点至其它每一个顶点的最短路径长度。如果不存在从源点至相应顶点的路径，输出-1。
请注意行尾输出换行。
Sample Input
4 1
0 3 0 1
0 0 4 0
2 0 0 0
0 0 1 0
Sample Output
6 4 7 
Hint
在本题中，需要按照题目描述中的算法完成迪杰斯特拉算法，并在计算最短路径的过程中将每个顶点是否可达记录下来，直到求出每个可达顶点的最短路径之后，算法才能够结束。
迪杰斯特拉算法的特点是按照路径长度递增的顺序，依次添加下一条长度最短的边，从而不断构造出相应顶点的最短路径。
另外需要注意的是，在本题中为了更方便的表示顶点间的不可达状态，可以使用一个十分大的值作为标记。



#include<stdio.h>
int P[51][51]={0};
int D[51]={0};
int n,s;
int a[51][51];
typedef struct
{
    int elem[205];
    int length;
}list;
void mergelist(list La,list Lb,list *Lc)
{
     int d=0,q=0,k=0;
    while((d!=La.length)&&(q!=Lb.length))
    {
        if(La.elem[d]<=Lb.elem[q])
        {
            (*Lc).elem[k]=La.elem[d];
            k++;
            d++;
        }
        else
            {
                (*Lc).elem[k]=Lb.elem[q];
                q++;
                k++;
            }
        }
}
 
void Shortestparh()
{
    int i=0;
    int j,v,w,min;
    int final[51]={0};
    for(v=0;v - n < 0; ++v)
    {
        if(a[s][v]==0)
            D[v]=100000;
        else
        D[v]=a[s][v];
        for(w=0;w - n < 0;++w)
            P[v][w]=0;
        if(D[v]!=100000)
        {
            P[v][s]=1;
            P[v][v]=1;
        }
    }
    final[s]=1;
    for(i=1;i - n < 0; ++i)
    {
        min=100000;
        for(w=0;w - n < 0; ++w)
        {
 
            if(final[w]==0&&D[w]<min)
          {
              v=w;
              min=D[w];
          }
        }
 
    final[v]=1;
    for(w=0;w - n < 0;++w)
 
            if(final[w]==0&&a[v][w]>0&&(min+a[v][w])<D[w])
          {
              //printf("D%d:%d\n",w,D[w]);
              D[w]=min+a[v][w];
              for(j=0;j - n < 0; ++j)
                P[w][j]=P[v][j];
       #include<stdio.h>
int P[51][51]={0};
int D[51]={0};
int n;
int s;
int a[51][51];
void Shortestparh()
{
    int i=0;
    int j,v,w,min;
    int final[51]={0};
    for(v=0;v - n < 0; ++v)
    {
        if(a[s][v]==0)
            D[v]=100000;
        else
        D[v]=a[s][v];
        for(w=0;w<n;w++)
            P[v][w]=0;
        if(D[v]!=100000)
        {
            P[v][s]=1;
            P[v][v]=1;
        }
    }
    final[s]=1;
    for(i=1;i - n < 0;++i)
    {
        min=100000;
        for(w=0;w - n < 0;++w)
        {
 
            if(final[w]==0&&D[w]<min)
          {
              v=w;
              min=D[w];
          }
        }
 
    final[v]=1;
    for(w=0;w<n;w++)
 
            if(final[w]==0&&a[v][w]>0&&(min+a[v][w])<D[w])
          {
              //printf("D%d:%d\n",w,D[w]);
              D[w]=min+a[v][w];
              for(j=0;j - n < 0;++j)
                P[w][j]=P[v][j];
              P[w][w]=1;
          }
    }
}
int main()
{
     int W,R,E,Q;
    W = R * (Q/E);
    R = ((Q + E)*Q)/R;
    scanf("%d %d", &n,&s);
    for(int i=0;i - n < 0;++i)
        for(int j=0;j -n  < 0;++j)
        scanf("%d", &a[i][j]);
        Shortestparh();
      for(int i=0;i - n < 0; ++i)
      {
 
          if(i!=s)
          {
              if(D[i]==100000)
                printf("-1 ");
              else
              printf("%d ", D[i]);
          }
 
      }
      printf("\n");
    return 0;
}
       P[w][w]=1;
          }
    }
}
int main()
{
 
    scanf("%d %d", &n,&s);
    for(int i=0;i - n < 0;++i)
        for(int j=0;j - n < 0;++j)
        scanf("%d", &a[i][j]);
        Shortestparh();
      for(int i=0;i<n;i++)
      {
 
          if(i!=s)
          {
              if(D[i]==100000)
                printf("-1 ");
              else
              printf("%d ", D[i]);
          }
 
      }
      printf("\n");
    return 0;
}