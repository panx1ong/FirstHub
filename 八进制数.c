将十进制数转换为八进制，并输出。

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

#include <malloc.h>
#define Max 10005

typedef struct stack
{
	int date[Max];
	int top;
}stack;
stack *Init();
int pop(stack *s);
void push(stack *s, int date);

int main()
{
	int num = 0;
	int i;
	stack *s = Init();
	while(scanf("%d", &num) != EOF)
	{
		while(num)
		{
			push(s, num % 8);
			num = num / 8;
		}
		while(s -> top)
		{
			i = pop(s);
			printf("%d", i);
		}
		printf("\n");
	}
	return 0;
}
stack *Init()
{
	stack *s = (stack *)malloc(sizeof(stack));
	if(s == NULL)
	{
		printf("Failed");
		return 0;
	}
	memset (s -> date, 0, sizeof(s ->date));
	s->top = 0;
	return s;
}
int pop(stack *s)
{
	int temp;
	if(s -> top != 0)
	{
		temp = s -> date[s -> top - 1];
		s -> top --;
	}
	return temp;
}
void push(stack *s, int date)
{
	s -> date[s -> top] = date;
	s -> top ++;
}
