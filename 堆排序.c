Problem Description
堆排序是一种利用堆结构进行排序的方法，它只需要一个记录大小的辅助空间，每个待排序的记录仅需要占用一个存储空间。
首先建立小根堆或大根堆，然后通过利用堆的性质即堆顶的元素是最小或最大值，从而依次得出每一个元素的位置。
堆排序的算法可以描述如下：

在本题中，读入一串整数，将其使用以上描述的堆排序的方法从小到大排序，并输出。

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
在本题中，需要按照题目描述中的算法完成堆排序的算法。
堆排序对于元素数较多的情况是非常有效的。通过对算法的分析，不难发现在建立含有n个元素的堆时，总共进行的关键字比较次数不会超过4n，且n个节点的堆深度是log2n数量级的。因此，堆排序在最坏情况下的时间复杂度是O(nlog2n)，相对于快速排序，堆排序具有同样的时间复杂度级别，但是其不会退化。堆排序较快速排序的劣势是其常数相对较大。



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