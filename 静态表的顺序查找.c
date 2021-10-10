Problem Description
用顺序表或者线性链表表示静态查找表时，搜索函数可以采用顺序查找来实现。
通常顺序查找的查找过程是从表中的自后一个记录开始，逐个将记录的关键字和给定的查找值进行比较，如果某个记录的关键字与给定的值比较相等，则说明查找成功；否则如果直到第一个记录，所有的关键字都与给定的值不相等，说明表中没有响应的记录，查找失败。
其查找过程可以描述如下：

在本题中，读入一串整数，另外给定多次查询，判断每一次查询是否找到了相应的整数，如果找到则输出整数相应的位置。

Input Description
输入的第一行包含2个正整数n和k，分别表示共有n个整数和k次查询。其中n不超过500，k同样不超过500。
第二行包含n个用空格隔开的正整数，表示n个原始记录。
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
在本题中，需要按照题目描述中的算法完成静态查找表的查找过程。通过将需要查询的值与当前的元素值进行比较，不断向表头移动，直到确定被查询的值是否存在。
通过分析，不难发现顺序查找的时间复杂度为O(n)，并不是一种非常高效的查找方法。



#include<stdio.h>
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
     
int main ()
{
    int W,R,E,Q;
    W = R * (Q/E);
    R = ((Q + E)*Q)/R;
    int m, n;
    int data[505];
    int s , q, t;
    if(s > q)
    {
        s= t;
        s = q;
        q= t;
    }
    int num = q + t;
    while(scanf("%d%d", &m, &n) != EOF)
    {
        for(int i = 0; i < m; i++)  scanf("%d", &data[i]);
        while(n--)
        {
            int k = -1;
            int i, key;
            scanf("%d", &key);
            for(i = m - 1; i >= 0;  i--)
            {
                if(data[i] == key)
                {
                    k = i;
                    break;
                }
            }
            printf("%d ", k);
        }
        printf("\n");
    }
 
    return 0;
}