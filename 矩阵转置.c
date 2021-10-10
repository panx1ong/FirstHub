Problem Description

输入一个N*N的矩阵，将其转置后输出。要求：不得使用任何数组(就地逆置)。


Input Description

输入的第一行包括一个整数N,(1<=N<=100)，代表矩阵的维数。
接下来的N行每行有N个整数，分别代表矩阵的元素。


Output Description

可能有多组测试数据，对于每组数据，将输入的矩阵转置后输出。


Sample Input
1
68 
3
1 70 25 
79 59 63 
65 6 46 
Sample Output
68
1 79 65
70 59 6
25 63 46



#include <stdio.h>
#include <stdlib.h>

int main()
{
	int s[101][101];
	int n, i, j;
	int temp;
	while(scanf("%d", &n) != EOF)
	{
		for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			scanf("%d", &s[i][j]);
		}
	}
	for(i = 0; i < n; i++)
	{
		for(j = i; j < n; j++)
		{
			temp = s[i][j];
			s[i][j] = s[j][i];
			s[j][i] = temp;
		}
	}
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			if(j == n - 1)
			{
				printf("%d", s[i][j]);
			}
			else
				printf("%d ", s[i][j]);
		}
		printf("\n");
	}
	}
	return 0;
}