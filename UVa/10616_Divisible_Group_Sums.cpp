#include<stdio.h>
#include<stdlib.h>

int N, Q, D, M, A[200], P[10], count = 0, used[200],set = 1;

void CheckNCount(){
	int sum = 0;
	for(int i = 0; i < N; i++){
		sum += P[i];
	}
	if(sum%D == 0)
		count++;
}

void solve(int index){
	if(index == M){
		CheckNCount();
		return;
	}
	for(int i = 0; i < N; i++){
		if(!used[i]){
			used[i] = 1;
			P[index] = A[i];
			solve(index+1);
		}
	}
}

int main(){
	while(scanf("%d %d",&N,&Q) && (N + Q)){
		for(int i = 0; i < N; i++){
			scanf("%d",&A[i]);
		}
		printf("SET %d:\n", set++);
		for(int i = 1; i <= Q; i++){
		scanf("%d %d",&D,&M);
		count = 0;
		for(int j = 0; j < N; j++)
			used[j] = 0;
		solve(0);
		if(M > 1)
			printf("QUERY %d: %d\n",i,count/2);
		else
			printf("QUERY %d: %d\n",i,count);
		}
	}
	return 0;
}