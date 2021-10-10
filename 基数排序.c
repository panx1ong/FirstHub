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