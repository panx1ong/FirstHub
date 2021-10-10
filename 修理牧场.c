Problem Description
农夫要修理牧场的一段栅栏，他测量了栅栏，发现需要N块木头，每块木头长度为整数Li个长度单位，于是他购买了一条很长的、能锯成N块的木头，即该木头的长度是Li的总和。

但是农夫自己没有锯子，请人锯木的酬金跟这段木头的长度成正比。为简单起见，不妨就设酬金等于所锯木头的长度。例如，要将长度为20的木头锯成长度为8、7和5的三段，第一次锯木头花费20，将木头锯成12和8；第二次锯木头花费12，将长度为12的木头锯成7和5，总花费为32。如果第一次将木头锯成15和5，则第二次锯木头花费15，总花费为35（大于32）。

请编写程序帮助农夫计算将木头锯成N块的最少花费。

Input Description
输入首先给出正整数N（≤10^4），表示要将木头锯成NN块。第二行给出N个正整数（≤50），表示每段木块的长度。
Output Description
输出一个整数，即将木头锯成N块的最少花费。
Sample Input
8
4 5 1 2 1 3 1 1
Sample Output
49
Hint
哈夫曼树




#include<stdio.h>
#include<stdlib.h>

typedef struct HNode * Heap; 
struct HNode{
	int * Data;
	int Size;
};
typedef Heap MinHeap;
void Insert(Heap H,int m);
int Del(Heap H);	
Heap CreateHeap(int n);
int main(){
	int n,m,i,sum=0,a,b;
	scanf("%d",&n);
	Heap H=CreateHeap(n);
	
	for(i=1;i<=n;i++){
		scanf("%d",&m);
		Insert(H,m);
	}
	while(H->Size!=1){
		a=Del(H);
		b=Del(H);
		b=a+b;
		sum+=b;
		Insert(H,b);
	}
	printf("%d",sum);
}
Heap CreateHeap(int n)
{
	MinHeap H=(MinHeap)malloc(sizeof(struct HNode));
	H->Data=(int *)malloc((n+1)*sizeof(int));
	H->Size=0;
	H->Data[0]=-1;
	
	return H; 
}
void Insert(Heap H,int m) 
{
	int i;
	
	i=++H->Size ;
	for(;H->Data[i/2]>m;i/=2){
		H->Data [i]=H->Data [i/2];
	}
	H->Data [i]=m;
}

int Del(Heap H)
{
	int parent,child;
	int min,x;
	
	min=H->Data [1];
	x=H->Data [H->Size --];
	
	for(parent=1;parent*2<=H->Size ;parent=child){
		child=parent*2;
		if((child!=H->Size )&&(H->Data [child]>H->Data [child+1])) child++;
		
		if(H->Data [child]>=x) break;
		else H->Data [parent]=H->Data [child];
	}
	H->Data [parent]=x;
	
	return min;
}