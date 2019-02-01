#include<stdio.h>

int A[1100], index;

void printBinary(int n){
	int i;
	i = 31;
	while(((n>>i)&1) == 0)
		i--;
	for(; i>=0; i--)
		A[index++] = ((n>>i)&1);
	printf("%d %d\n",n,index);
}

int main(){
	int n,i;
	index = 0;
	for(i = 1; i<=157; i++)
		printBinary(i);
	return 0;
}