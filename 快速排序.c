Problem Description
快速排序是对起泡排序的一种改进。它的基本思想是，通过一趟排序将待排序的记录分割成两个独立的部分，其中一部分记录的关键字均比另一部分的关键字小，在分成两个部分之后则可以分别对这两个部分继续进行排序，从而使整个序列有序。
快速排序的算法可以描述如下：

在本题中，读入一串整数，将其使用以上描述的快速排序的方法从小到大排序，并输出。

Input Description
输入的第一行包含1个正整数n，表示共有n个整数需要参与排序。其中n不超过100000。
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
在本题中，需要按照题目描述中的算法完成快速排序的算法。
快速排序是一种十分常用的排序算法，其平均时间复杂度为O(knlnn)，其中n为待排序序列中记录的个数，k为常数。大量的实际应用证明，在所有同数量级的此类排序算法中，快速排序的常数因子k是最小的，因此，就平均时间而言，快速排序是目前被认为最好的一种内部排序方法。
而在C语言的常用编译器中，qsort函数是一个非常常用的快速排序函数。


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