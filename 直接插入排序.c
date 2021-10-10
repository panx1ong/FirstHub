Problem Description
直接插入排序是一种最简单的排序方法，它的基本操作是将一个记录插入到已经排好序的有序表中，从而得到一个新的且记录数增加了1的有序表。
其算法可以描述如下：

在本题中，读入一串整数，将其使用以上描述的直接插入排序的方法从小到大排序，并输出。

Input Description
输入的第一行包含1个正整数n，表示共有n个整数需要参与排序。其中n不超过1000。
第二行包含n个用空格隔开的正整数，表示n个需要排序的整数。
Output Description
只有1行，包含n个整数，表示从小到大排序完毕的所有整数。
请在每个整数后输出一个空格，并请注意行尾输出换行。
Sample Input
10
2 8 4 6 1 10 7 3 5 9
Sample Output
1 2 3 4 5 6 7 8 9 10 
Hint
在本题中，需要按照题目描述中的算法完成直接插入排序的算法。直接插入排序算法的思路非常直接，就是通过将记录插入到已经有序的有序表中，并重排记录。
通过分析，不难发现直接插入排序的时间复杂度为O(n2)，并不是一种非常高效的排序方法。


#include<stdio.h>
int a[100001], n;
void sort(int left, int right)
{
    int i, j, temp, t;
    if(left > right)
    {
        return;
    }
    temp = a[left];
    i = left;
    j = right;
    while(i != j)
    {
        while(a[j] >= temp && i < j)
        {
            j--;
        }
        while(a[i] <= temp && i < j)
        {

            i++;
        }
        if(i < j)
        {
            t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    a[left] = a[i];
    a[i]= temp;
    sort(left, i - 1);
    sort(i + 1, right);
}
int main()
{
    int i;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    sort(0, n - 1);
    for(i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}