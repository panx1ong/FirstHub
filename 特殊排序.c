Problem Description
输入一系列整数，将其中最大的数挑出，并将剩下的数进行排序。

Input Description
输入第一行包括1个整数N，1<=N<=1000，代表输入数据的个数。
接下来的一行有N个整数。
Output Description
可能有多组测试数据，对于每组数据，
第一行输出一个整数，代表N个整数中的最大值，并将此值从数组中去除，将剩下的数进行排序。
第二行将排序的结果输出。
Sample Input
5
5 3 2 4 1
Sample Output
5
1 2 3 4
Hint
如果数组中只有一个数，当第一行将其输出后，第二行请输出"-1"。


#include <stdio.h>

int main()
{
	int a[10001];
	int len, i, j, k, temp;
	while(scanf("%d", &len) != EOF)
	{
		for(i = 0; i < len; i++)
		{
			scanf("%d", &a[i]);
		}
		for(j = 0; j < len - 1; j++)
		{
			for(k = 0; k < len - 1 - j; k++)
			{
				if(a[k] > a[k + 1])
				{
					temp = a[k];
					a[k] = a[k + 1];
					a[k + 1] = temp;
				}
			}
		}
		if(len == 1)
		{
			printf("%d\n-1\n", a[0]);

		}
		else
		{
			printf("%d\n", a[len - 1]);
			for(int x = 0; x < len - 2; x++)
			{
				printf("%d ", a[x]);
			}
			printf("%d", a[len - 2]);
			printf("\n");
		}
	}
	return 0;
}