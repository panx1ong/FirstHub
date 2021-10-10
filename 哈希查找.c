Problem Description
根据输入的int 数组建立哈希表，然后查找是否存在相应元素。
Input Description
第一行为测试数据的组数n, 下面有n组测试数据。对于每组测试数据，第一行为用空格隔开的int数列，数量不超过1,000,000，下面一行为查找数目m, 接下来的m行为m个需要查找的数（int型）。
Output Description
每组测试数据输出m行，如果存在相应的元素，输出“Yes.”，否则输出“No.”。
Sample Input
1
1 2 4 5 3 6
2
1
7
Sample Output
Yes.
No.
Hint
 哈希吧， 骚年们。


#include <stdio.h>
#include <string.h>

int main()
{
	int a[100000];
	char s[100000];
	int n, m, y;
	scanf("%d", &n);
	getchar();
	while(n--)
	{
		for(int i = 0; i < 10000; i++)
		{
			a[i] = 0;
		}
		gets(s);
	}
	for(int i = 0; i < strlen(s); i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			a[s[i] - '0'] = 1;
		}
	}
	scanf("%d", &m);
	while(m--)
	{
		scanf("%d", &y);
		if(a[y] == 1)
			printf("Yes.\n");
		else
			printf("No.\n");
	}
	return 0;
}