Problem Description
省政府“畅通工程”的目标是使全省任何两个村庄间都可以实现公路交通（但不一定有直接的公路相连，只要能间接通过公路可达即可）。现得到城镇道路统计表，表中列出了任意两城镇间修建道路的费用，以及该道路是否已经修通的状态。现请你编写程序，计算出全省畅通需要的最低成本。

Input Description
测试输入包含若干测试用例。每个测试用例的第1行给出村庄数目N ( 1< N < 100 )；随后的 N(N-1)/2 行对应村庄间道路的成本及修建状态，每行给4个正整数，分别是两个村庄的编号（从1编号到N），此两村庄间道路的成本，以及修建状态：1表示已建，0表示未建。

当N为0时输入结束。

Output Description
每个测试用例的输出占一行，输出全省畅通需要的最低成本。

Sample Input
4
1 2 1 1
1 3 6 0
1 4 2 1
2 3 3 0
2 4 5 0
3 4 4 0
3
1 2 1 1
2 3 2 1
1 3 1 0
0
Sample Output
3
0


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>
#define INF 0x3f3f3f3f
 
int graph[101][101];
int prim(int n) {
 
  int dis[n], vis[n];
  int ans = 0;
  for(int i = 1; i - n <= 0; i++) {
    dis[i] = graph[1][i];
    vis[i] = false;
  }
  dis[1] = 0; vis[1] = true;
  for (int i = 2; i - n <= 0; ++i)
    {
    int idx = -1;
    int mindis = INF;
    for (int j=1; j - n <= 0; ++j)
      if (!vis[j] && mindis>dis[j])
        mindis = dis[idx = j];
    ans += mindis;
    vis[idx] = true;
    for (int j=1; j - n <= 0; ++j)
      if (!vis[j] && dis[j]>graph[idx][j])
      {
          dis[j] = graph[idx][j];
      }
  }
  return ans;
}
int n;
int main() {
 
   while (~scanf("%d", &n)) {
    if (!n)
    {
        break;
    }
    memset(graph, INF, sizeof(graph));
    int m = n * (n - 1) >> 1;
    while (m--)
    {
      int x, y, v, s; scanf("%d%d%d%d", &x, &y, &v, &s);
      graph[x][y] = graph[y][x] = s ? 0 : v;
    }
    printf("%d", prim(n));
    printf("\n");
  }
}