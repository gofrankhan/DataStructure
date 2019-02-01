#include<stdio.h>
#include<stdlib.h>

int A[100], N, M, sum, record[100][100];

int solve(int pos, int t_sum){
	if(pos == M){
		int d = sum - t_sum;
		d = t_sum - d;
		if(d < 0)
			d = -d;
		return d;
	}

	//if(record[pos][sum]>0)
		//return record[pos][sum];

	int left = solve(pos+1, t_sum + A[pos]);
	//record[pos+1][sum+A[pos]] = left;

	int right = solve(pos+1, t_sum);
	//record[pos+1][sum] = right;

	if(left < right)
		return left;
	else
		return right;
	
}

int main(){
	scanf("%d",&N);
	while(N--){
		scanf("%d",&M);
		sum = 0;
		for(int i = 0; i < M; i++){
			scanf("%d",&A[i]);
			sum = sum + A[i];
		}
		printf("%d\n",solve(0,0));
	}
return 0;
}