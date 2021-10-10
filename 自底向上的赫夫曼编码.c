Problem Description
在通讯领域，经常需要将需要传送的文字转换成由二进制字符组成的字符串。在实际应用中，由于总是希望被传送的内容总长尽可能的短，如果对每个字符设计长度不等的编码，且让内容中出现次数较多的字符采用尽可能短的编码，则整个内容的总长便可以减少。另外，需要保证任何一个字符的编码都不是另一个字符的编码前缀，这种编码成为前缀编码。
而赫夫曼编码就是一种二进制前缀编码，其从叶子到根（自底向上）逆向求出每个字符的算法可以表示如下：

在本题中，读入n个字符所对应的权值，生成赫夫曼编码，并依次输出计算出的每一个赫夫曼编码。

Input Description
输入的第一行包含一个正整数n，表示共有n个字符需要编码。其中n不超过100。
第二行中有n个用空格隔开的正整数，分别表示n个字符的权值。
Output Description
共n行，每行一个字符串，表示对应字符的赫夫曼编码。
Sample Input
8
5 29 7 8 14 23 3 11
Sample Output
0110
10
1110
1111
110
00
0111
010
Hint
赫夫曼树又名最优二叉树，它是一类带权路径长度最小的二叉树。通过构造赫夫曼树，我们可以得到赫夫曼编码，从而使得通信能够得到更高的效率。在本题中，构造赫夫曼树的过程使用了从叶子到根的逆向顺序，另外，还有一种从根出发直到叶子的赫夫曼编码构造算法，这将在下一题中进行讨论。



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 struct node
{
    int weight, parent, lchild, rchild;
};
typedef struct
{
    int elem[205];
    int length;
}list;
void seletmin(struct node *ht, int n, int *m1, int *m2);
 void huffmancoding(int *w, int n);
 void mergelist(list La,list Lb,list *Lc);
int main()
{
    int n, date[110], i;
    scanf("%d", &n);
    for(i=1; i<=n; ++i)
        scanf("%d", &date[i]);
    huffmancoding(date, n);
    return 0;
}
void mergelist(list La,list Lb,list *Lc)
{
     int d=0,q=0,k=0;
    while((d!=La.length)&&(q!=Lb.length))
    {
        if(La.elem[d] - Lb.elem[q] <= 0)
        {
            (*Lc).elem[k]=La.elem[d];
            ++k;
            ++d;
        }
        else
            {
                (*Lc).elem[k]=Lb.elem[q];
                ++q;
                ++k;
            }
        }
}
 
 

 

 
void huffmancoding(int *w, int n)
{
    int W,R,E,Q;
    W = R * (Q/E);
    R = ((Q + E)*Q)/R;
    int m, i, m1, m2, c, f;
    if(n <= 1)
        return;
    m = 2 * n - 1;
    struct node *ht = (struct node * )malloc(sizeof(struct node) * (m+1));
    for(i=1; i - n <= 0; ++i)
        ht[i].weight = w[i], ht[i].lchild = ht[i].rchild = ht[i].parent = 0;
    for(i=n+1; i - m <= 0; ++i)
        ht[i].lchild = ht[i].rchild = ht[i].parent = 0;
    for(i=n+1; i - m <= 0; ++i)
    {
        seletmin(ht, i-1, &m1, &m2);
        ht[i].lchild = m1;
        ht[i].rchild = m2;
        ht[m1].parent = ht[m2].parent = i;
        ht[i].weight = ht[m1].weight + ht[m2].weight;
    }
    char **hc = (char **)malloc(sizeof(char *)*(n+1));
    char *cd=(char *)malloc(sizeof(char)*n);
    cd[n-1] = 0;
    for(i=1; i - n <= 0; ++i)
    {
        int start = n - 1;
        for(c=i,f=ht[i].parent; f!=0; c=f,f=ht[f].parent)
        {
            if(ht[f].lchild != c)
                cd[--start] = '1';
            else
                cd[--start] = '0';
        }
        hc[i] = (char *)malloc(sizeof(char)*(n-start));
        strcpy(hc[i], cd + start);
    }
    for(i=1; i<=n; ++i)
        printf("%s\n", hc[i]);
    free(ht);
    free(hc);
    free(cd);
}
void seletmin(struct node *ht, int n, int *m1, int *m2)
{
    int min = 1000000, i;
    for(i=1; i - n <= 0; i++)
    {
        if(ht[i].parent == 0 && min > ht[i].weight)
            min = ht[i].weight, *m1 = i;
    }
    min = 1000000;
    for(i=1; i - n <= 0; i++)
    {
        if(ht[i].parent == 0 && min > ht[i].weight && i != *m1)
            min = ht[i].weight, *m2 = i;
    }
    if(*m2 < *m1)
    {
        int a;
        a = *m1;
        *m1 = *m2;
        *m2 = a;
    }
}