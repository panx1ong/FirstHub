Problem Description
求一个n×n矩阵对角线元素之和，其中1≤n<100，矩阵元素都小于10000。

Input Description
第一行是一个正整数n。

然后是n行，每行对应矩阵的每行，元素间用空格隔开。

Output Description
第一行为主对角线元素和，第二行为副对角线的元素和。

Sample Input
3
5724 1478 9358
6962 4464 5705
8145 3281 6827
Sample Output
17015
21967



#include <stdio.h>
#include <stdlib.h>
 
int main()
{
    int s[101][101];
    int n, i, j, p, q;
	int sum1 = 0;
	int sum2 = 0;
    while(scanf("%d", &n) != EOF)
    {
        for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &s[i][j]);
        }
    }
		for(i = 0, j =0; i < n; i++, j++)
		{
			sum1 += s[i][j];
		}
		for(i = 0, j = n - 1; j >= 0; i++, j--)
		{
			sum2 += s[i][j];
		}
		printf("%d\n%d\n", sum1, sum2);
    }
    return 0;
}