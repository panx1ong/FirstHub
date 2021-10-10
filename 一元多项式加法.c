Problem Description
让我们重温小学初中时那些一元多项式的加法吧，不同的是现在使用计算机来帮我们计算了。多年前不想写作业的梦想终于快要实现了！下面就给出书上的算法。

图：链表实现一元多项式加法
Input Description
输入数据包含多组测试数据，每组数据包含两行一元多项式。每个多项式包含若干对整数，每对整数的第一个是系数，第二个是指数。每个多项式不超过100项，整数间用空格隔开，并且指数是递减的。

Output Description
每组测试数据输出一行结果，每个整数后面空一格。(包括行尾)

Sample Input
3 2 4 1 7 0
2 4 1 1
2 3
1 4
3 2 4 1 7 0
2 4 -4 1
Sample Output
2 4 3 2 5 1 7 0 
1 4 2 3 
2 4 3 2 7 0 
Hint
提示：
1、由于多项式元素的重要信息在系数和指数，所以可以定义结点类型为含两个整数的结构体，一个代表系数而另一个代表指数。 2、定义完数据类型后，主要的就是怎么读取数据了。由于每个多项式占一行，所以可以用gets来读取一行，并判断是否为空行：while(gets(strA) && strlen(strA))...然后就将字符串中的数据转换为多项式类型。此时使用到一个字符串处理函数char * strtok ( char * str, const char * delimiters )。这个函数的主要功能是将字符串str按delimiters中的字符分割。使用这个字符串处理函数时注意在处理某个字符串时首次使用时传递的参数是字符串指针而以后在使用时传递的参数是NULL。 3、下面的算法与有序序列有序合并算法类似。因为是多次循环，如果里面含有迭代变量（i，j之类的）注意下次循环时初值对不对。
总结：
多项式加法的算法与有序序列有序合并的算法类似，注意多项式元素类型的定义即可。



#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
typedef struct Node
{
	int    conf;
	int    expn;
	struct Node* next;
}*node, Node;
int Compare_(node a, node b);
node Creat_LS(char x[]);
node Add_F(node ha, node hb);
void Out_put(node ha);

int main()
{
	char    a[201], b[201];
	node    ha, hb;
	while (gets(a) != NULL)
	{
		gets(b);
		ha = Creat_LS(a);
		hb = Creat_LS(b);
		ha = Add_F(ha, hb);
		Out_put(ha);
	}
	return 0;
}
int Compare_(node a, node b)
{
	if (a->expn < b->expn)
		return(0);
	else
		if (a->expn == b->expn)
			return(1);
		else
			return(2);
}

node Creat_LS(char x[])
{
	node    head = (node)malloc(sizeof(Node));
	node    q = head;
	head->next = NULL;
	int length_ = strlen(x);

	int    i = 0, d = 0;
	char    cNum[100], eNum[100];

	while (i < length_)
	{
		d = 0;
		node p = (node)malloc(sizeof(Node));
		while (x[i] == ' ' && i < length_)
			i++;
		while (x[i] != ' ' && i < length_)
			cNum[d++] = x[i++];
		cNum[d] = '\0';
		p->conf = atof(cNum);
		d = 0;
		while (x[i] == ' ' && i < length_)
			i++;
		while (x[i] != ' ' && i < length_)
			eNum[d++] = x[i++];
		eNum[d] = '\0';
		p->expn = atoi(eNum);
		q->next = p;
		p->next = NULL;
		q = q->next;
	}
	return(head);
}

node Add_F(node ha, node hb)
{
	int    c;
	double    sum;
	node    HA, term, term1, term2;
	HA = ha;
	while (ha->next != NULL && hb->next != NULL)
	{
		c = Compare_(ha->next, hb->next);
		switch (c)
		{
		case 0: {
			term = hb->next;
			hb->next = hb->next->next;
			term->next = ha->next;
			ha->next = term;
			ha = ha->next;
			break;
		}

		case 1:
			sum = ha->next->conf + hb->next->conf;
			if (sum == 0)
			{
				term1 = ha->next;
				term2 = hb->next;

				ha->next = ha->next->next;
				hb->next = hb->next->next;
				free(term1);
				free(term2);
			}
			else
			{
				ha->next->conf = sum;
				term2 = hb->next;
				hb->next = hb->next->next;
				free(term2);
				ha = ha->next;
			}
			break;
		case 2:
			ha = ha->next;
			break;
		}
	}

	if (hb->next == NULL)
	{
		return HA;
	}
	else
	{
		ha->next = hb->next;
		free(hb);
		return HA;
	}
}

void Out_put(node ha)
{
	node p = ha->next;
	if (p == NULL)
		printf("0 ");
	else
	{
		while (p != NULL)
		{
			printf("%d %d ", p->conf, p->expn);
			p = p->next;
		}
	}
	printf("\n");
}
