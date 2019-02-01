#include<stdio.h>
#include<stdlib.h>

int a[17], N, used[17], Case = 1, flag = 1;

void print(){
	printf("1");
	for(int i = 2; i <= N; i++){
		printf(" %d",a[i]);
	}
	printf("\n");
}

bool isPrime(int num){
	for(int i = 2; i < 6; i++){
		if(num <= i)
			break;
		if(num%i == 0)
			return false;
	}
	return true;
}

void solve(int index, int prev){
	if(index == N+1){
		print();
		return;
	}
	for(int i = 2; i <= N; i++){
		if(!used[i]){
			if(isPrime(i+prev)){
			if(index == N){
				if(isPrime(i+1)){
					used[i] = 1;
					a[index] = i;
					solve(index+1, i);
					used[i] = 0;
				}
			}else{
			used[i] = 1;
			a[index] = i;
			solve(index+1, i);
			used[i] = 0;
			}
			}
		}
	}
}

int main(){
	while(scanf("%d",&N)!= EOF){
		used[1] = 1;
		a[1] = 1;
		for(int i = 2; i <= N; i++){
			used[i] = 0;
		}
		if(flag)
			flag = 0;
		else
			printf("\n");
		printf("Case %d:\n", Case++);
		solve(2,1);
	}
	return 0;
}