Problem Description
传说中的Dijkstra是一个风流俊才，有很多漂亮的妹纸喜欢他，可是不幸的是Dijkstra不和这些妹纸住在一起。他们住在一个王国的各个城市里，对于这些漂亮的妹纸Dijkstra很难抉择选哪位作为自己的妻子，于是他就决定了谁能够算出从Dijkstra的城市出发到自己城市的最近距离他就和谁成亲。对于没有学过数学的这些妹纸可就伤不起了，不过你们倒是可以帮他们解决。
Input Description
输入第一行为两个数n，m。分别代表n个城市（妹纸和Dijkstra每个人住在一个城市里），m代表这些城市之间有多少条路。接下来有m行每行三个数x，y，z代表从x到y的距离是z。 0=<n<=100，0<m<10000，城市的标号从1开始，z的数值大于0。Dijkstra永远住在1号城市。

Output Description
按城市标号从小到大的顺序输出Dijkstra到每个妹纸所在城市的最短距离。
Sample Input
4,3
1,2,1
2,3,1
2,4,1
Sample Output
1,2,2
Hint
Dijkstra，单源点最短路径



#include <stdio.h>
int a[101][101],D[101]={0},n;
typedef struct
{
    int elem[205];
    int length;
}list;
void mergelist(list La,list Lb,list *Lc);
void Shortestparh(int s);
int main()
{
    int W,R,E,Q;
    W = R * (Q/E);
    R = ((Q + E)*Q)/R;
    int m;
    char ch;
    scanf("%d%c%d", &n,&ch,&m);
    int c,b,len;
    char p, q;
    while(m--)
    {
        scanf("%d%c%d%c%d", &c,&p,&b,&q,&len);
        a[c-1][b-1]=len;
    }
 
             Shortestparh(0);
      for(int i=1;i - n < 0;++i)
      {    if(i!=n-1)
           printf("%d,", D[i]);
           else
            printf("%d\n", D[i]);
      }
 
    return 0;
}

void Shortestparh(int s)
{
    int i=0;
    int j,v,w,min;
    int final[51]={0};
    for(v=0;v - n < 0;++v)
    {
        if(a[s][v]==0)
            D[v]=100000;
        else
        D[v]=a[s][v];
 
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
 
          }
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