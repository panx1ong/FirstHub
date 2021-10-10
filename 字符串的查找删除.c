Problem Description
给定一个短字符串（不含空格），再给定若干字符串，在这些字符串中删除所含有的短字符串。

Input Description
输入只有1组数据。
输入一个短字符串（不含空格），再输入若干字符串直到文件结束为止。

Output Description
删除输入的短字符串(不区分大小写)并去掉空格,输出。

Sample Input
in
#include 
int main()
{

printf(" Hi ");
}
Sample Output
#clude
tma()
{

prtf("Hi");
}
Hint
注:将字符串中的In、IN、iN、in删除。


#include<stdio.h> 
#include<string.h>
#include<math.h>
int main(){
	//字符数组开大一点 
	char str1[1000];
	gets(str1);
	int len1 = strlen(str1);
	char str2[1000];
	while(gets(str2) != NULL){
		int len2 = strlen(str2);
		for(int i = 0;i < len2;i++){
			//遇到空格直接跳到下一次循环此空格就不打印了 
			if(str2[i] == ' '){
				continue;
			}
			//遇到与删除短字符串第一个字符相等时开始比较 
			//删除不区分大小写，所以大小写可采用绝对是32来判断 
			if(str2[i] == str1[0] || fabs(str2[i]-str1[0]) == 32){
				int k = 0; 
				for(int j = i;j < i + len1;j++){
					if(str2[j] == str1[k] || fabs(str2[j]-str1[k]) == 32){
						k++; 
					}
				}
				// k = len1表示遇到相等的字符串了，直接跳过这个字符串 
				if(k == len1){
					i = i + len1 - 1;	
				}else{
					printf("%c",str2[i]); // 如果第一个字符相等但是后面不相等，匹配失败。这个字符还是需要打印的 
				}
			}else{
				printf("%c",str2[i]); // 字符与删除短字符串第一个字符不相等那么直接打印
			}
		}
		printf("\n");
	}
	return 0;
}
