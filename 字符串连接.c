将给定的字符串连接起来。书中的算法描述如下：

图：字符串连接算法

Input Description
三对字符串，每对字符串占一行，用空格隔开。每个字符串只包含数字和英文字母大小写且长度不超过100。


Output Description
将后一个字符串连接到前一个字符串后面，如果结果字符串长度超过100，输出一行“Result String is cutted.”否则将结果字符串输出来。

Sample Input
hello acmclub
123 456
doyour best
Sample Output
helloacmclub
123456
doyourbest
Hint
提示：
如果按照书上的算法定义字符串数据结构，其实也可以使用字符数组（长度限制在127），那么第一个字符就用来存储字符的长度。
总结：
字符与整数在一定范围内可以相互转换。这个性质可以好好利用。



#include<stdio.h>
#include<string.h>

void link_(char *a1,char *a2)
{
	int i, j;
   for(i=strlen(a1),j=0;j<=strlen(a2);j++)
     {
       a1[i++]=a2[j];
     }
   puts(a1);
   // printf("\n");

}

int main()
{

   char a1[101];
   char a2[101];

   while(scanf("%s",a1)!=EOF)
     {
        scanf("%s",a2);

        if(strlen(a1)+strlen(a2)<=100)
          link_(a1,a2);
           else
            printf("Result String is cutted.\n");
     }
return 0;
}
