Problem Description
顺序表是我们数据结构中的基本储存形式，现在给定一个顺序表，有如下操作：
Insert X Y：在顺序表中X位置插入Y元素，遍历输出当前顺序表的所有元素。
Delete X：删除顺序表中的X元素，如果有多个X元素，只删除第一个X，遍历输出当前顺序的所有元素。
Locate X：输出顺序表中X元素的所在的位置，如果有多个X元素，只输出第一个X元素的位置。
GetElem X：输出顺序表中X位置上的元素。
Input Description
多组测试数据。
对于每组测试数据，首先输入的是两个整数n,m（0<m<n<100），分别表示顺序表初始有n个元素，m次操作。
接下来是n个整数，表示顺序表中的n个元素。
然后是m次操作命令，命令是Insert X Y，Delete X，Locate X，GetElem X中的一种，其中的X，Y均为整数。
Output Description
对于每组数据，输出有m行，对应m次操作：如果操作合法，则输出相应的结果。如果操作不合法，则输出"Wrong Input!"
Sample Input
5 8
1 3 4 5 6
Insert 4 7
Insert 8 10
Delete 6
Delete 10
Locate 5
Locate 10
GetElem 3
GetElem 9
Sample Output
1 3 4 7 5 6
Wrong Input!
1 3 4 7 5
Wrong Input!
5
Wrong Input!
4
Wrong Input!
Hint
要求使用顺序表实现


#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>

#define LIST_INIT_SIZE 100
#define LISTSTNCREMENT 10
#define TRUE 1
#define ERROR 0
typedef int Status;
typedef int ElemType;


typedef struct
{
	ElemType* elem;
	int length;
	int listsize;
}SqList;
Status InitList_Sq(SqList* L);
Status ListInsert_Sq(SqList* L, int i, ElemType e);
Status ListDelete_Sq(SqList* L, int i);
Status GetElem_sq(SqList L, int i);
Status LocateElem_sq(SqList L, ElemType e);
void print_sq(SqList L);







int main()
{

	SqList L;
	InitList_Sq(&L);
	char operation[31];
	int n, m, uzi;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &uzi);
		ListInsert_Sq(&L, i, uzi);
	}
	int X, Y;
	bool flag = 0;
	while (m--)
	{
		scanf("%s", operation);
		if (strcmp(operation, "Insert") == 0)
		{
			scanf("%d %d", &X, &Y);
			flag = ListInsert_Sq(&L, X, Y);
			if (flag)
				print_sq(L);
			else
				printf("Wrong Input!\n");
		}
		else if (strcmp(operation, "Delete") == 0)
		{
			scanf("%d", &X);
			flag = ListDelete_Sq(&L, X);
			if (flag)
				print_sq(L);
			else
				printf("Wrong Input!\n");
		}
		else if (strcmp(operation, "Locate") == 0)
		{
			scanf("%d", &X);
			if (LocateElem_sq(L, X))
				printf("%d\n", LocateElem_sq(L, X));
			else
				printf("Wrong Input!\n");
		}
		else if (!strcmp(operation, "GetElem"))
		{
			scanf("%d", &X);
			if (GetElem_sq(L, X))
				printf("%d\n", GetElem_sq(L, X));
			else
				printf("Wrong Input!\n");
		}
	}
	return 0;
}
Status InitList_Sq(SqList* L)
{
	(*L).elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!(*L).elem)
		exit(ERROR);
	(*L).length = 0;
	(*L).listsize = LIST_INIT_SIZE;
	return TRUE;
}
void print_sq(SqList L)
{

	for (int i = 1; i <= L.length; ++i)
	{
		if (i != 1)
			printf(" ");
		printf("%d", L.elem[i - 1]);
	}
	printf("\n");
}
Status ListInsert_Sq(SqList* L, int i, ElemType e)
{
	ElemType* p;
	if (i < 1 || i >(*L).length + 1)
		return ERROR;
	if ((*L).length >= (*L).listsize)
	{
		ElemType* newbase = (ElemType*)realloc((*L).elem, ((*L).listsize + LISTSTNCREMENT) * sizeof(ElemType));

		if (!newbase)
			exit(ERROR);
		(*L).elem = newbase;
		(*L).listsize += LISTSTNCREMENT;
	}
	ElemType* q = (*L).elem + i - 1;
	for (p = (*L).elem + (*L).length - 1; p >= q; --p)
		*(p + 1) = *p;
	*q = e;
	++(*L).length;

	return TRUE;
}
Status ListDelete_Sq(SqList* L, int i)
{
	ElemType* p, * q;
	if (i < 1 || i >(*L).length)
		return ERROR;
	p = (*L).elem + i - 1;
	q = (*L).elem + (*L).length - 1;
	for (++p; p <= q; ++p)
		*(p - 1) = *p;
	--(*L).length;

	return TRUE;
}
Status GetElem_sq(SqList L, int i)
{
	if (i < 1 || i > L.length)
		return ERROR;
	return L.elem[i - 1];
}
Status LocateElem_sq(SqList L, ElemType e)
{
	int i = 1;
	ElemType* p = L.elem;
	while (*p != e && i <= L.length)
	{
		i++;
		p++;
	}
	if (i > L.length)
		return ERROR;
	else
		return i;
}

