#include<stdio.h>
#include<stdlib.h>

int arr[5], N = 0, sum, isPossible;
int A[5], used[5] = {0};
int count = 0;

void find(int index, int total){
	if(index == 5){
		count++;
		if(total == 23)
			isPossible = 1;
		return;
	}
	for(int i = 0; i < 5; i++){
		if(!used[i]){
			used[i] = 1;
			A[index] = arr[i];

			if(index)
				find(index+1, total + A[index]);
			else
				find(index+1, A[index]);

			if(index)
				find(index+1, total - A[index]);
			else
				find(index+1, A[index]);

			if(index)
				find(index+1, total * A[index]);
			else
				find(index+1, A[index]);
			used[i] = 0;
		}
	}
}

int main(){
	for(int i = 0; i < 5; i++){
		scanf("%d",&arr[i]);
	}
	while(1 ){
		if(arr[0] == 0 && arr[1] == 0 && arr[2] == 0 && arr[3] == 0 && arr[4]== 0)
			break;
		isPossible = 0;
		find(0, 0);
		if(isPossible)
			printf("Possible\n");
		else
			printf("Impossible\n");

		N = 0;
		for(int i = 0; i < 5; i++){
			scanf("%d",&arr[i]);
		}
	}
	return 0;
}