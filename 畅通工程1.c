Problem Description
某省调查城镇交通状况，得到现有城镇道路统计表，表中列出了每条道路直接连通的城镇。省政府“畅通工程”的目标是使全省任何两个城镇间都可以实现交通（但不一定有直接的道路相连，只要互相间接通过道路可达即可）。问最少还需要建设多少条道路？

Input Description
测试输入包含若干测试用例。每个测试用例的第1行给出两个正整数，分别是城镇数目N ( < 1000 )和道路数目M；随后的M行对应M条道路，每行给出一对正整数，分别是该条道路直接连通的两个城镇的编号。为简单起见，城镇从1到N编号。 
    注意:两个城市之间可以有多条道路相通,也就是说
    3 3
    1 2
    1 2
    2 1
    这种输入也是合法的
    当N为0时，输入结束，该用例不被处理。

Output Description
对每个测试用例，在1行里输出最少还需要建设的道路数目。

Sample Input
5 3
1 2
3 2
4 5
0
Sample Output
1




#include <stdio.h>
#include <stdlib.h>
#include <string.h>
  
int a[1000];
int Close(int x);
void Find(int x,int y);
int Close(int x);
 
int main()
{
    int m, n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n == 0)
        {
            break;
        }
        scanf("%d",&m);
        int s = 0;
        for(int i = 1;i <= n;i++)
        {
            a[i] = i;
        }
        int a, b;
        while(m--)
        {
            scanf("%d %d",&a,&b);
            Find(a, b);
        }
        for(int i = 1;i <= n;i++)
        {
            if(i == Close(i))
            {
                s++;
            }
        }
        printf("%d\n",s-1);
    }
    return 0;
}
void Find(int x,int y)
{
    int dx = Close(x);
    int dy = Close(y);
    if(dx != dy)
    {
        a[dx] = dy;
    }
}
 
int Close(int x)
{
   if(x != a[x])
   {
      a[x]=Close(a[x]);
   }
   return a[x];
}