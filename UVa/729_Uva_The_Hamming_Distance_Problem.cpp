#include<stdio.h>
#include<stdlib.h>

int arr[16],tc, n, h;

char ch;

void fill(int index, int one, int ziro){

	if(one > h || ziro > n-h)
		return;

	if(index == n){
		if(one == h){
		for(int i = 0; i < n; i++)
			printf("%d",arr[i]);
		printf("\n");
		}
		return;
	}

		arr[index] = 0;
		fill(index+1, one, ziro+1);
		arr[index] = 1;
		fill(index+1, one+1, ziro);
}

int main(){
	scanf("%d",&tc);
	ch = getchar();
	while(tc--){
		scanf("%d %d",&n,&h);
		if(tc)
			ch = getchar();
		fill(0, 0, 0);
		if(tc)
			printf("\n");
	}
}