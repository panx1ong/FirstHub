Problem Description
已知线性表 LA 和 LB 中的数据元素按值非递减有序排列，现要求将 LA 和 LB 归并为一个新的线性表 LC， 且 LC 中的数据元素仍然按值非递减有序排列。例如，设LA=(3,5,8,11) ,LB=(2,6,8,9,11,15,20) 则
LC=(2,3,6,6,8,8,9,11,11,15,20)
算法描述如下：
从上述问题要求可知，LC中的数据元素或是LA中的数据元素，或是LB中的数据元素，则只要先设LC为空表，然后将LA或LB中的元素逐个插入到LC中即可。为使LC中元素按值非递减有序排列，可设两个指针 i 和 j 分别指向LA和LB中某个元素，若设 i 当前所指的元素为 a，j 所指的元素为 b，则当前应插入到 LC 中的元素 c 为 c = a < b ? a : b显然，指针 i 和 j 的初值均为1（实际写代码时往往是从 0 开始的），在所指元素插入 LC 之后，在 LA 或者 LB 中顺序后移。上述归并算法如下图：


 
图：有序列表有序插入算法
Input Description
有多组测试数据，每组测试数据占两行。第一行是集合A，第一个整数m（0<=m<=100）代表集合A起始有m个元素，后面有m个非递减排序的整数，代表A中的元素。第二行是集合B，第一个整数n(0<=n<=100)代表集合B起始有n个元素，后面有n个非递减排序的整数，代表B中的元素。每行中整数之间用一个空格隔开。

Output Description
每组测试数据只要求输出一行，这一行含有 m+n 个来自集合 A 和集合B 中的元素。结果依旧是非递减的。每个整数间用一个空格隔开。

Sample Input
4 3 5 8 11
7 2 6 8 9 11 15 20
Sample Output
2 3 5 6 8 8 9 11 11 15 20
Hint
        总结：
      本题书中提供的算法是基于顺序表的。在使用顺序表时需要两倍于数据元素数目。如果使用链表则只需要存储一倍的元素。然而使用链表同样需要存储一倍的指针。所以对于这类问题数据结构的选取，如果数据域占用的空间很大则可以使用链表存储来节省空间，而对于数据域占用不大的情况，则使用顺序表也可以。





#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h> 

#define TRUE 1
#define ERROR 0
#define MAXN 101
#define LIST_INIT_SIZE 100
#define LISTSTNCREMENT 10
int a[MAXN], b[MAXN];
typedef int ElemType;
typedef int Status;

typedef struct
{
	ElemType* elem;
	int length;
	int listsize;
}SqList;
void MergeList_Sq(SqList La, SqList Lb, SqList* Lc)
{
	InitList_Sq(Lc);
	int i = 1, j = 1, k = 0;
	int La_len, Lb_len;
	int ai, bj;
	La_len = LengthList(La); Lb_len = LengthList(Lb);
	while ((i <= La_len) && (j <= Lb_len))
	{
		GetElem_Sq(La, i, &ai);
		GetElem_Sq(Lb, j, &bj);
		if (ai <= bj) {
			ListInsert_Sq(Lc, ++k, ai);
			++i;
		}

		else {
			ListInsert_Sq(Lc, ++k, bj);
			++j;
		}
	}
	while (i <= La_len) {
		GetElem_Sq(La, i++, &ai); ListInsert_Sq(Lc, ++k, ai);
	}
	while (j <= Lb_len) {
		GetElem_Sq(Lb, j++, &bj); ListInsert_Sq(Lc, ++k, bj);
	}
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
	for (int i = 1; i <= L.length; i++)
	{
		if (i != 1)
			printf(" ");
		printf("%d", *(L.elem + i - 1));
	}
	printf("\n");
}

Status LengthList(SqList L)
{
	return L.length;
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
Status GetElem_Sq(SqList L, int i, ElemType* a)
{
	if (i < 1 || i > L.length)
		exit(ERROR);
	*a = L.elem[i - 1];
	return TRUE;
}





int main()
{
	int n, m;
	SqList A, B, C;
	while (~scanf("%d", &m))
	{
		InitList_Sq(&A);
		for (int i = 1; i <= m; i++)
		{
			scanf("%d", &a[i]);
			ListInsert_Sq(&A, i, a[i]);
		}
		scanf("%d", &n);
		InitList_Sq(&B);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &b[i]);
			ListInsert_Sq(&B, i, b[i]);
		}
		MergeList_Sq(A, B, &C);
		print_sq(C);
	}
	return 0;
}