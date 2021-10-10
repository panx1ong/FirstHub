Problem Description
我们大多都有在银行排队的经历，唉，那坑爹的排队啊！现在就让我们来算算我们这些客户平均需要等多久吧。
每天刚开始时银行会开m个窗口来为我们total个客户办理业务，当有客户需要办理业务时，先选择可以办理业务的窗口，如果有多个窗口可以办理业务就选择空闲时间最长的窗口，如果有多个窗口空闲的时间一样长，则选择序号小的窗口办理业务。假设我们每个人来到的时间和办理业务所需要的时间（为了简化问题，采用整数表示时间）都知道了。现在请你算算我们平均需要等待多久呢？

Input Description
有多组测试数据，每组数据开始有两个正整数m(<20)和total(<200)，后面有total对整数，对应客户先后到来的时间以及办理业务所需的时间。

Output Description
平均等待的时间，保留两位小数。

Sample Input
2 6 1 3 4 1 5 3 9 2 13 4 13 3
3 14 0 3 2 2 2 4 5 4 7 2 11 3 12 3 12 4 12 1 13 3 15 4 19 1 22 3 23 2
2 5 0 6 0 5 0 6 7 1 7 2
Sample Output
0.00
0.29
1.20
Hint
提示：
题目中选择办理的窗口有三个状态，实际上从序号自小到大查找可以最早办理业务的窗口就已经满足上述三个状态了。可以使用数组来模拟列表。
总结：
实际上数组既可以模拟堆栈又可以模拟队列。




#include<stdio.h>
#include<string.h>
 
int main()
{
	int a[100]; 
	double sum;
	int n,m,j,k,i,T,x,y,total,current;
	while (scanf("%d%d",&m,&total) != EOF)
	{
		
		sum = 0;
		current = 0;
		memset(a,0,sizeof(a));
		for (i = 0; i - total < 0; ++i)
		{
			scanf("%d%d",&x,&y);
			int min = 1000000;
			for (j = 0; j - m < 0; ++j)
			{
				if (a[j] - a[current] < 0)
				{
					min = a[j];
					current = j;
				}
			}
			if (x - a[current] <= 0)
			{
				sum = sum + (a[current] - x) ;
				a[current] = a[current] + y;
			}
			else
			{
				a[current] = x + y;
			}
			
		}
		
		printf("%.2lf\n",sum/(1.0*total) );
	}
	
		
	return 0;
 } 
