Problem Description
堆栈是一种基本的数据结构。堆栈具有两种基本操作方式，push 和 pop。Push一个值会将其压入栈顶，而 pop 则会将栈顶的值弹出。现在我们就来验证一下堆栈的使用。

Input Description
对于每组测试数据，第一行是一个正整数 n，0<n<=10000(n=0 结束)。而后的 n 行，每行的第一个字符可能是'P’或者'O’或者'A’；如果是'P’，后面还会跟着一个整数，表示把这个数据压入堆栈；如果是'O’，表示将栈顶的值 pop 出来，如果堆栈中没有元素时，忽略本次操作；如果是'A’，表示询问当前栈顶的值，如果当时栈为空，则输出'E'。堆栈开始为空。

Output Description
 对于每组测试数据，根据其中的命令字符来处理堆栈；并对所有的'A’操作，输出当时栈顶的值，每个占据一行，如果当时栈为空，则输出'E’。当每组测试数据完成后，输出一个空行。

Sample Input
5
P 75
O
O
P 60
A
7
A
O
P 73
P 49
A
O
P 3
0
Sample Output
60

E
49



#include<stdio.h>
#include<stdlib.h>
#define Max 1000

struct stack
{
	int date[Max];
	int p;
};
int main()
{
	int i, n, a;
	struct stack *sta;
	char ch;
	while (scanf("%d", &n) != EOF)
	{
		if (n == 0)
		{
			break;
		}
			sta = (struct stack*)malloc(sizeof(struct stack));
			sta->p = 0;
			for (i = 0; i < n; i++)
			{
				getchar();
				scanf("%c", &ch);
				switch (ch)
				{
				case 'A':
					if (sta->p > 0)
					{
						printf("%d\n", sta->date[sta->p - 1]);
					}
					else
					{
						printf("E\n");
					}
					break;
				case 'P':
					scanf("%d", &a);
					sta->date[sta->p++] = a;
					break;
				case 'O':
					if (sta->p > 0)
					{
						sta->p--;
					}
					break;
				}
		     }
		printf("\n");
	}
	return 0;
}
