Problem Description
在带权有向图G中，求G中的任意一对顶点间的最短路径问题，也是十分常见的一种问题。
解决这个问题的一个方法是执行n次迪杰斯特拉算法，这样就可以求出每一对顶点间的最短路径，执行的时间复杂度为O(n3)。
而另一种算法是由弗洛伊德提出的，时间复杂度同样是O(n3)，但算法的形式简单很多。
可以将弗洛伊德算法描述如下：

在本题中，读入一个有向图的带权邻接矩阵（即数组表示），建立有向图并按照以上描述中的算法求出每一对顶点间的最短路径长度。

Input Description
输入的第一行包含1个正整数n，表示图中共有n个顶点。其中n不超过50。
以后的n行中每行有n个用空格隔开的整数。对于第i行的第j个整数，如果大于0，则表示第i个顶点有指向第j个顶点的有向边，且权值为对应的整数值；如果这个整数为0，则表示没有i指向j的有向边。当i和j相等的时候，保证对应的整数为0。
Output Description
共有n行，每行有n个整数，表示源点至每一个顶点的最短路径长度。如果不存在从源点至相应顶点的路径，输出-1。对于某个顶点到其本身的最短路径长度，输出0。
请在每个整数后输出一个空格，并请注意行尾输出换行。
Sample Input
4
0 3 0 1
0 0 4 0
2 0 0 0
0 0 1 0
Sample Output
0 3 2 1 
6 0 4 7 
2 5 0 3 
3 6 1 0 
Hint
在本题中，需要按照题目描述中的算法完成弗洛伊德算法，并在计算最短路径的过程中将每个顶点是否可达记录下来，直到求出每一对顶点的最短路径之后，算法才能够结束。
相对于迪杰斯特拉算法，弗洛伊德算法的形式更为简单。通过一个三重循环，弗洛伊德算法可以方便的求出每一对顶点间的最短距离。
另外需要注意的是，为了更方便的表示顶点间的不可达状态，可以使用一个十分大的值作为标记。而在题目描述中的算法示例使用了另外一个三维数组对其进行表示，这使原本的O(n3)时间复杂度增长到了O(n4)，这也是需要自行修改的部分。



#include<stdio.h>
int P[51][51]={0},D[51]={0},n;
 
int a[51][51];
typedef struct
{
    int elem[205];
    int length;
}list;
void mergelist(list La,list Lb,list *Lc)
{
     int d=0;
     int q=0;
     int k=0;
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
                ++q;
                k++;
            }
        }
}
void Shortestparh(int s)
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
    for(w=0;w - n < 0; ++w)
 
            if(final[w]==0&&a[v][w]>0&&(min+a[v][w])<D[w])
          {
              //printf("D%d:%d\n",w,D[w]);
              D[w]=min+a[v][w];
              for(j=0;j - n < 0; ++j)
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
    scanf("%d", &n);
    for(int i=0;i - n < 0; ++i)
        for(int j=0;j - n < 0; ++j)
        scanf("%d", &a[i][j]);
        for(int k=0;k - n < 0; ++k)
        {
             Shortestparh(k);
      for(int i=0;i - n < 0; ++i)
      {
 
              if(i==k)
                printf("0 ");
              else
              {
                  if(D[i]==100000)
                printf("-1 ");
              else
              printf("%d ", D[i]);
 
              }
 
      }
      printf("\n");
        }
 
    return 0;
}