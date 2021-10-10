Problem Description
字符串的子串定位称为模式匹配，模式匹配可以有多种方法。简单的算法可以使用两重嵌套循环，时间复杂度为母串与子串长度的乘积。而KMP算法相对来说在时间复杂度上要好得多，为母串与子串长度的和。但其算符比较难以理解。
在KMP算法中，使用到了一个next数组。这个数组就是在比较失配时母串指针不必回溯，而子串指针移动相应位置即可。我们给出书中next数组的算式表示以及算法，请你实现之。

图1：next数组的算式表示

图2：next数组的算法表示
Input Description
一个模式串，仅由英文小写字母组成。长度不大于100。

Output Description
输出模式串对应的移动数组next。每个整数后跟一个空格。

Sample Input
abaabcac
Sample Output
0 1 1 2 2 3 1 2 
Hint
提示：
数据结构与以前相同，只用字符数组即可，只要调用上述函数即可。
总结：
KMP算法在字符串模式匹配算法中比较高效，具体KMP算法将在以后介绍。



#include<stdio.h>
#include<string.h>
 
void get_next(const char *T, int *next)
{
    int i = 1;
    int j = 0;
    next[1] = 0;
    while (i < strlen(T))
    {
        if (j == 0 || T[i - 1] == T[j - 1]) next[++i] = ++j;
        else j = next[j];
    }
}
 
int main()
{
    int W,R,E,Q;
    W=R*(Q/E);
    R=((Q+E)*Q)/R;
    char x[110];
    int next[110];
    scanf("%s", x);
    get_next(x, next);
    for (int i = 1; i <= strlen(x); ++i)
        printf("%d ", next[i]);
 
    return 0;
}
 
