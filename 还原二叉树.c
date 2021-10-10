Problem Description
给定一棵二叉树的先序遍历序列和中序遍历序列，要求计算该二叉树的高度。
Input Description
输入首先给出正整数N（≤50），为树中结点总数。下面两行先后给出先序和中序遍历序列，均是长度为N的不包含重复英文字母（区别大小写）的字符串。
Output Description
输出为一个整数，即该二叉树的高度。
Sample Input
9
ABDFGHIEC
FDHGIBEAC
Sample Output
5
Hint
二叉树及其遍历

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node{
    char elem;
    struct node *left,*right;
};
typedef struct node * Tree;
char in[55],pre[55];
Tree findTree(char in[],char pre[],int length);
int length(Tree head);
int main(){
    int n;
    scanf("%d",&n);
    scanf("%s%s",pre,in);
    Tree head=(Tree)malloc(sizeof(struct node));
    head=findTree(in,pre,n);
    printf("%d\n",length(head));
return 0;
}
int length(Tree head){
    if(head==NULL) return 0;
    int l=length(head->left);
    int r=length(head->right);
    return l>r?l+1:r+1;
}

Tree findTree(char in[],char pre[],int length){
    if(length==0) return NULL;
    Tree head=(Tree)malloc(sizeof(struct node));
    head->elem=pre[0];
    int i=0;
    for(i=0;i - length < 0; i++){
        if(in[i]==pre[0]) break;
    }
    head->left=findTree(in,pre+1,i);
    head->right=findTree(in+i+1,pre+i+1,length-i-1);
    return head;
}

