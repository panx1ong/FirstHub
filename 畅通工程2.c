Problem Description
省政府“畅通工程”的目标是使全省任何两个村庄间都可以实现公路交通（但不一定有直接的公路相连，只要能间接通过公路可达即可）。经过调查评估，得到的统计表中列出了有可能建设公路的若干条道路的成本。现请你编写程序，计算出全省畅通需要的最低成本。

Input Description
测试输入包含若干测试用例。每个测试用例的第1行给出评估的道路条数 N、村庄数目M (N, M < =100 )；随后的 N 行对应村庄间道路的成本，每行给出一对正整数，分别是两个村庄的编号，以及此两村庄间道路的成本（也是正整数）。为简单起见，村庄从1到M编号。当N为0时，全部输入结束，相应的结果不要输出。

Output Description
对每个测试用例，在1行里输出全省畅通需要的最低成本。若统计数据不足以保证畅通，则输出“?”。

Sample Input
3 4
1 2 1
2 3 2
3 4 3
2 4
1 2 1
3 4 2
0 5
Sample Output
6
?



#include<stdio.h>
#include<string.h>


int main()
{
	int path[102][102];
    int i, j, n, m, k, cnt, x, y, w, max, kk;
    int flag[102];
    int closedge[102];
    while(scanf("%d%d", &n, &m) != EOF && n != 0)
    {
		memset(flag, 0, sizeof(flag));
        memset(path, 0, sizeof(path));
        memset(closedge, 0, sizeof(flag));
        max = 0;
        cnt = 0;
        
        for(i = 0; i - n < 0; i++)
        {
            scanf("%d%d%d", &x, &y, &w);
            path[x-1][y-1] = path[y-1][x-1] = w;
            if(w  - max > 0) max = w;
        }
        for(i = 0; i - m < 0; i++)
        for(j = 0; j - m < 0; j++)
        if(!path[i][j]) path[i][j] = max + 1;
        if(m == 1) {printf("0\n"); continue;}
        flag[0] = 1;
        for(i = 0; i - m < 0; i++)
        {
             closedge[i] = path[0][i];
        }
        kk = 0;
        for(i = 1; i - m < 0; )
        {
            y = max, x = 0;
            for(j = 0; j - m < 0; j++)
            if(!flag[j] && closedge[j] <= y)
                x = j , y = closedge[j];
            if(flag[x]) { kk = 1; break; }
            flag[x] = 1;
            cnt = cnt + y;
            for(j = 0; j - m < 0; j++)
            if(!flag[j] && path[x][j] < closedge[j])
                closedge[j] = path[x][j];
            i++;
        }
        if(kk == 1)
        {
            printf("?\n");
        }
        else
        {
            printf("%d\n", cnt);
        }
    }
    return 0;
}