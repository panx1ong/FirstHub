Problem Description
在ZIP归档文件中，保留着所有压缩文件和目录的相对路径和名称。当使用WinZIP等GUI软件打开ZIP归档文件时，可以从这些信息中重建目录的树状结构。请编写程序实现目录的树状结构的重建工作。
Input Description
输入首先给出正整数N（≤10^4），表示ZIP归档文件中的文件和目录的数量。随后N行，每行有如下格式的文件或目录的相对路径和名称（每行不超过260个字符）：

路径和名称中的字符仅包括英文字母（区分大小写）；
符号“\”仅作为路径分隔符出现；
目录以符号“\”结束；
不存在重复的输入项目；
整个输入大小不超过2MB。
Output Description
假设所有的路径都相对于root目录。从root目录开始，在输出时每个目录首先输出自己的名字，然后以字典序输出所有子目录，然后以字典序输出所有文件。注意，在输出时，应根据目录的相对关系使用空格进行缩进，每级目录或文件比上一级多缩进2个空格。
Sample Input
7
b
c\
ab\cd
a\bc
ab\d
a\d\a
a\d\z\
Sample Output
root
  a
    d
      z
      a
    bc
  ab
    cd
    d
  c
  b
Hint
基本概念

#include <stdio.h>
#include<stdlib.h>
#include <string.h>
 
typedef int Bool;
typedef struct node *Node;
struct node
{
    char*Name;
    Bool EFMulu;
    Node File;
    Node sMulu;
    Node Brother;
} Head;
 
Node New(char*);
void Read();
void Print(Node,int);
Node InsertFile(Node,char*);
Node InsertMulu(Node,char*);

 
int main()
{
    int n;
    scanf("%d",&n);
    Head.Name=(char*)malloc(sizeof(char)*5);
    strcpy(Head.Name,"root");
    Head.File=NULL;
    Head.sMulu=NULL;
    Head.Brother=NULL;
    Head.EFMulu=1;
    for(int i=0; i<n; i++)
        {
            getchar();
            Read();
        }
        Print(&Head,0);
        return 0;
}
 
void Read()
{
    char FileName[261];
    Node temp=&Head;
    scanf("%s",FileName);
    char words[261];
    int j;
    int L=0;
    for(int i=0; i < strlen(FileName); i++)
        {
            if(FileName[i] == '\\')
            {
                for(j=L; j - i<0; j++)
                {
                    words[j-L] = FileName[j];
                }
                words[j-L] = '\0';
                temp -> sMulu = InsertMulu(temp -> sMulu, words);
                temp = temp -> sMulu;
                while(strcmp(temp->Name,words))temp = temp -> Brother;
                L = i + 1;
            }
        }
        if(L < strlen(FileName))
            {
                for(j=L; j <= strlen(FileName); j++)
                {
                    words[j-L] = FileName[j];
                }
                temp -> File = InsertFile(temp->File,words);
            }
}
Node InsertFile(Node H, char*K)
{
    if(! H || strcmp(H -> Name, K) > 0)
        {
            Node temp = New(K);
            temp -> EFMulu = 0;
            temp -> Brother = H;
            return temp;
        }
        H -> Brother = InsertFile(H->Brother,K);
        return H;
} 
Node InsertMulu(Node H,char*K)
{
    if(! H || strcmp(H -> Name, K) > 0)
        {
            Node temp = New(K);
            temp -> Brother = H;
            return temp;
        }
    if(strcmp(H -> Name, K)==0)
        return H;
    H -> Brother = InsertMulu(H -> Brother, K);
    return H;
}
 

void Print(Node H,int Space)
{
    if(H)
        {
            for(int i=0; i < Space; i++)
            printf(" ");
            printf("%s\n", H -> Name);
            if(H -> EFMulu == 1)
                Print(H -> sMulu,Space+2);
            Print(H -> File,Space+2);
            Print(H -> Brother,Space);
        }
}
Node New(char*K)
{
    Node temp=(Node)malloc(sizeof(struct node));
    temp -> Name = (char*)malloc(sizeof(char)*(strlen(K)+1));
    strcpy(temp->Name,K);
    temp -> Brother = NULL;
    temp -> File = NULL;
    temp -> sMulu = NULL;
    temp -> EFMulu=1;
    return temp;
}
 
