Problem Description
输入一个N维矩阵，判断是否对称。

Input Description
输入第一行包括一个数：N(1<=N<=100)，表示矩阵的维数。

接下来的N行，每行包括N个数，表示N*N矩阵的元素。

Output Description
可能有多组测试数据，对于每组数据，

输出"Yes!”表示矩阵为对称矩阵。
输出"No!”表示矩阵不是对称矩阵。

Sample Input
1
68 
3
1 70 25 
70 79 59 
25 59 63 
3
6 46 82 
28 62 92 
96 43 28 
Sample Output
Yes!
Yes!
No!


#include <stdio.h>
#include <stdlib.h>

int main()
{
	int s[101][101];
	int n, i, j, p, q;
	while(scanf("%d", &n) != EOF)
	{
		int temp = 1;
		for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			scanf("%d", &s[i][j]);
		}
	}
	for(p = 0; p < n; p++)
	{
		for(q = p; q < n; q++)
		{
			if(s[p][q] != s[q][p])
			{
				temp = 0;
			}
		}
	}
	if(temp == 1)
	{
		printf("Yes!");
	}
	else
	{
		printf("No!");
	}
	printf("\n");
	}
	return 0;
}