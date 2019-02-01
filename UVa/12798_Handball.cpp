#include<stdio.h>
#include<stdlib.h>


int main(){
	int N,M;
	while(scanf("%d",&N)!=EOF){
		scanf("%d",&M);
		int v, Count = N,chk;
		for(int i = 0; i<N; i++){
			chk = 0;
			for(int j = 0; j<M; j++){
					scanf("%d",&v);
					if(!v && !chk){
						Count--;
						chk = 1;
					}
			}
		}
		printf("%d\n",Count);
	}
	return 0;
}