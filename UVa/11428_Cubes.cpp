#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	int n, x, y,x3,y3;
	scanf("%d",&n);
	while(n){
		x = sqrtl(n);
		y = sqrtl(n);
		int i, j, flag = 0;
		for(j = 0; j <= y; j++){
		for(i = x; i > 0; i--){
			x3 = i*i*i;
			y3 = j*j*j;
			if(n ==(x3-y3)){
				printf("%d %d\n",i,j);
				flag = 1;
				break;
			}
			if(flag){
				break;
			}
		}
		}
		if(!flag)
			printf("No solution\n");
		scanf("%d",&n);
	}
	return 0;
}