Problem Description
KMP算法是字符串模式匹配算法中较为高效的算法之一，其在某次子串匹配母串失败时并未回溯母串的指针而是将子串的指针移动到相应的位置。严蔚敏老师的书中详细描述了KMP算法，同时前面的例子中也描述了子串移动位置的数组实现的算法。前面你已经实现了子串移动的数组，现在就来利用该数组来实现KMP模式匹配。

下面是相应的算法：



图：KMP算法

Input Description
3组字符串，每组字符串占一行。每行包含由空格分隔的两个字符串，字符串仅由英文小写字母组成且长度不大于100。

Output Description
每组数据输出1行，输出后一个字符串在前一个字符串中的位置，如果不匹配，则输出0。

Sample Input
string str
thisisalongstring isa
nosubstring subt
Sample Output
1
5
0
Hint
提示：
表示字符串的数据结构依然是字符数组。
总结：
KMP算法调用很简单，但难的是理解算法的思想。掌握算法的思想才能说是掌握算法。



#include<stdio.h>
#include<string.h>
 
int next[105];
void getNext(char *p);
int kmp(char *s , char *p);
 
int main(){
     int W,R,E,Q;
    W=R*(Q/E);
    R=((Q+E)*Q)/R;
    char s[105];
    char p[105] ;
    while(scanf("%s%s", s, p) != EOF)
    {
        printf("%d\n", kmp(s,p)+1);
    }
 
    return 0 ;
}
void getNext(char *p)
{
    next[0] = -1 ;
    int k = -1,j=0;
    while(j < strlen(p))
        if(k == -1 || p[j]==p[k])
        {
            j++;
            k++;
            if(p[j] - p[k] != 0)
                next[j] = k ;
            else
                next[j] = next[k] ;
        }
        else k = next[k] ;
}
 
int kmp(char *s , char *p)
{
    int i = 0 ;
    int j = 0 ;
    getNext(p);
    int plen = strlen(p) ;
    while((i < strlen(s))&&(j < plen ))
        if(j == -1 || s[i]==p[j]) i++, j++;
        else j = next[j];
    if(j == strlen(p))
        return i-j ;
    else
        return -1 ;
}