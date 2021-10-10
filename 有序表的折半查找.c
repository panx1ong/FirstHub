Problem Description
用有序表表示静态查找表时，通常检索函数可以用折半查找来实现。
折半查找的查找过程是：首先确定待查记录所在的范围，然后逐步缩小范围直到找到或者确定找不到相应的记录为止。而每次需要缩小的范围均为上一次的一半，这样的查找过程可以被称为折半查找。
其查找过程可以描述如下：

在本题中，读入一串有序的整数，另外给定多次查询，判断每一次查询是否找到了相应的整数，如果找到则输出整数相应的位置。

Input Description
输入的第一行包含2个正整数n和k，分别表示共有n个整数和k次查询。其中n不超过1000，k同样不超过1000。
第二行包含n个用空格隔开的正整数，表示n个有序的整数。输入保证这n个整数是从小到大递增的。
第三行包含k个用空格隔开的正整数，表示k次查询的目标。
Output Description
只有1行，包含k个整数，分别表示每一次的查询结果。如果在查询中找到了对应的整数，则输出其相应的位置，否则输出-1。
请在每个整数后输出一个空格，并请注意行尾输出换行。
Sample Input
8 3
1 3 5 7 8 9 10 15
9 2 5
Sample Output
5 -1 2 
Hint
在本题中，需要按照题目描述中的算法完成折半查找过程。通过将需要查询的值与当前区间中央的整数进行比较，不断缩小区间的范围，直到确定被查询的值是否存在。
通过课本中的性能分析部分，不难发现折半查找的时间复杂度为O(log2n)，这是一种非常高效的查找方法。


#include <stdio.h>
 
typedef struct
{
    int elem[205];
    int length;
}list;
void mergelist(list La,list Lb,list *Lc)
{
     int d=0,q=0,k=0;
    while((d!=La.length)&&(q!=Lb.length))
    {
        if(La.elem[d]<=Lb.elem[q])
        {
            (*Lc).elem[k]=La.elem[d];
            k++;
            d++;
        }
        else
            {
                (*Lc).elem[k]=Lb.elem[q];
                q++;
                k++;
            }
        }
}
     
 
int Search(int a[], int n, int x);
 
int main()
{
    int W,R,E,Q;
    W = R * (Q/E);
    R = ((Q + E)*Q)/R;
    int a[1005];
    int n, k, x;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)  scanf("%d", &a[i]);
    for (int i = 0; i < k; i++)  scanf("%d", &x),  printf("%d ", Search(a, n, x));
    printf("\n");
 
    return 0;
}
 
int Search(int a[], int n, int x)
{
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid;
        mid = (left + right) / 2;
        if (x > a[mid])  left = mid + 1;
        else  right = mid - 1;
    }
    if (a[left] == x)  return left;
    else  return -1;
}