Problem Description
算数四则运算的规则是1）先乘除，后加减；2）从左算到右；3）先括号内，后括号外。
由此，算式4+2*3-10/5的计算顺序为4+2*3-10/5=4+6-10/5=4+6-2=8。
给定一个以“#”作为结束符的算式，求出算式的结果。
给出严蔚敏《数据结构（C语言）》中的一段算法描述以作参考：

图1：表达式求值算法

图2：表达式求值算法（续）

图3：表达式求值算法（续）

Input Description
以“#”结尾的表达式，运算数为正整数。每个表达式占一行。

Output Description
输出表达式运算的结果。

Sample Input
4+2*3-10/5#
3*(7-2)#
2*3/2#
Sample Output
8
15
3
Hint
提示：
使用栈来解决本题，很多人都会想到。但怎样建栈，却带来了问题。同样，严书上的代码实际上也给大家带来了问题。看过严书光盘中代码的人应该知道，代码中使用了两个栈，一个是存储运算符的，类型为char；另一个存储运算数，类型为float。而操作两个栈的函数都一样。要知道，除非像C++中使用泛型，C语言中却基本不能实现这样的操作。所以在C语言环境中需要将这两个栈结合在一起。由于char与int有种特别的联系，可以使用int来代替char存储运算符。
总结：
注意灵活运用栈，要是能够学习C++使用template就更好了。可以模拟STL了。


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
 
 
#define N 1000+10
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define OK 1
#define OVERFLOW 0
#define ERROR 0
 
char str[N];
typedef  int Status;
typedef  int SElemType;
 
typedef struct{
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;
 
unsigned char prior[7][7] = {
{'>','>','<','<','<','>','>'},
{'>','>','<','<','<','>','>'},
{'>','>','>','>','<','>','>'},
{'>','>','>','>','<','>','>'},
{'<','<','<','<','<','=',' '},
{'<','<','<','<','<',' ','>'},
{'<','<','<','<','<',' ','='}};
 
char OPSET[7] = {'+','-','*','/','(',')','#'};
Status InitStack(SqStack *s);
Status Push(SqStack *s,SElemType c); 
Status GetTop(SqStack *s);
Status In(char c,char str[]);
void  Strcat(char *str1,char *str2);
Status Atoi(char *c);
Status precede(int a,char b); 
Status Pop(SqStack *s); 
Status Opereta(int a,int b,int c);
int EvaluateExpression(char *MyExpression);
int main()
{
	
	while(scanf("%s",str)!=EOF)
	{
		printf("%d\n",EvaluateExpression(str));
	}
	return 0;
 }
Status InitStack(SqStack *s)
{
	s->base = (SElemType*)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if(!s->base)
		exit(OVERFLOW);
	s->top = s->base ;
	s->stacksize = STACK_INIT_SIZE;
	return OK;
} 
Status Push(SqStack *s,SElemType c)
{
	if((s->top - s->base ) >= s->stacksize )
	{
		s->base = (SElemType*)realloc(s->base ,(s->stacksize +STACKINCREMENT)*sizeof(SElemType));
		if(!s->base )
			exit(OVERFLOW);
		s->stacksize += STACKINCREMENT;
	}
	*(s->top)++ = c;
	return OK;
}
 
Status GetTop(SqStack *s)
{
	SElemType e;
	if(s->base == s->top )
		return ERROR;
	e = *(s->top-1)    ;
	return e;
}

Status In(char c,char str[])
{
	int i = 0;
	while(c != str[i])
	{
		i++;
	}
	if(i < 7)
		return OK;
	return ERROR;
}

void  Strcat(char *str1,char *str2)
{
	int i = 0, j = 0;
	while(str1[i]!='\0')
	{
		i++;
	}
	while(str2[j]!='\0')
	{
		str1[i++] = str2[j++];
	}
	str1[i] = '\0';
} 

Status Atoi(char *c)
{
	int data= 0,d = 0;
	int i = 0;
	while(c[i]!='\0')
	{
		data = data*10 + c[i]-'0';
		i++;
	}
	return data;	
} 

Status precede(int a,char b)
{
	int i = 0,j = 0;
	while(OPSET[i] != a)
	{
		i++;
	}
	while(OPSET[j] != b)
	{
		j++;
	}
	return prior[i][j];
}
 
Status Pop(SqStack *s) 
{
	int e;
	if(s->base == s->top )
		return ERROR;
	e = *--(s->top);
	return e;
}
 
Status Opereta(int a,int b,int c)
{
	switch(b)
	{
		case '+':
			return a+c;
		case '-':
			return a-c;
		case '*':
			return a*c;
		case '/':
			return a/c;
	} 
}

int EvaluateExpression(char *MyExpression)
{
	SqStack OPTR;
	SqStack OPND;
	
	char TempData[20];
	int data,a,b;
	char *c,Dr[2],e;
	int theta;
	
	InitStack(&OPTR);
	Push(&OPTR,'#');
	InitStack(&OPND);
	
	c = MyExpression;
	TempData[0] = '\0';
	while(*c != '#'|| GetTop(&OPTR) != '#')
	{
		
		if(!In(*c,OPSET))
		{
			Dr[0] = *c;
			Dr[1] = '\0';
			Strcat(TempData,Dr);
			c++; 
			if(In(*c,OPSET))
			{
				data = Atoi(TempData);
				Push(&OPND,data);
				TempData[0] = '\0';
			}
		}
		else
		{
			switch(precede(GetTop(&OPTR),*c))
			{
				case '<':
					Push(&OPTR,*c);
					c++;
					break;
				case '=':
					Pop(&OPTR);
					
					c++;
					break;
				case '>':
					a = Pop(&OPND);
					b = Pop(&OPND);
					theta = Pop(&OPTR);
					Push(&OPND,Opereta(b,theta,a));
					break;
			}
		}
	}
	
	return GetTop(&OPND);
}