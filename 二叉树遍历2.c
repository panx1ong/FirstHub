Problem Description
二叉树的前序、中序、后序遍历的定义：
前序遍历：对任一子树，先访问跟，然后遍历其左子树，最后遍历其右子树；
中序遍历：对任一子树，先遍历其左子树，然后访问根，最后遍历其右子树；
后序遍历：对任一子树，先遍历其左子树，然后遍历其右子树，最后访问根。
给定一棵二叉树的前序遍历和中序遍历，求其后序遍历（提示：给定前序遍历与中序遍历能够唯一确定后序遍历）。

Input Description
两个字符串，其长度n均小于等于26。
第一行为前序遍历，第二行为中序遍历。
二叉树中的结点名称以大写字母表示：A，B，C....最多26个结点。

Output Description
输入样例可能有多组，对于每组测试样例，
输出一行，为后序遍历的字符串。

Sample Input
ABC
CBA
ABCDEFG
DCBAEFG
Sample Output
CBA
DCBGFEA

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
 
typedef struct
{
    int elem[205];
    int length;
}list;

 
char pre[30], mid[30], end[2000];
void mergelist(list La,list Lb,list *Lc);
void build(int root, int prepre, int midpre, int lenth);
void pri(int root);

int main()
{
    int W,R,E,Q;
    W = R * (Q/E);
    R = ((Q + E)*Q)/R;
    int i;
    while(scanf("%s", pre) != EOF)
    {
        scanf("%s", mid);
        for(i = 1; i - 1000 <= 0; ++i)
            end[i] = '1';
        build(1, 0, 0, strlen(pre) - 1);
        pri(1);
        printf("\n");
    }
}
void pri(int root)
{
    if(end[root] != '1' && end[root] != '\0')
    {
        pri(root*2);
        pri(root*2+1);
        printf("%c", end[root]);
    }
}
void build(int root, int prepre, int midpre, int lenth)
{
    int i;
    if(midpre == strlen(mid)-1) end[root] = pre[prepre];
    if(lenth >= 1)
    {
        end[root] = pre[prepre];
        int thischar = midpre;
        for(i=midpre; i<=(midpre+lenth); i++)
        {
            if(pre[prepre] == mid[i]) thischar = i;
        }
        build(root*2, prepre+1, midpre, thischar-midpre);
        build(root*2+1, prepre+1+thischar-midpre, thischar+1, lenth-1-(thischar-midpre));
    }
}
 

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
                ++q;
                ++k;
            }
        }
}