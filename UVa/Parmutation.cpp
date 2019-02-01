#include<stdio.h>
int arr[10], used[10];

int check(int value, int pos){
	int i;
	for (i = 0; i < pos; i++){
		if (value == arr[i])
			return 0;
	}
	return 1;
}

void solve(int pos){
	int i, j;
	if (pos == 3){
		for (i = 0; i < 3; i++){
			printf("%d", arr[i]);
		}
		printf("\n");
		return;
	}
	for (j = 0; j < 3; j++){
		if (check(j, pos)){
			arr[pos] = j;
			solve(pos + 1);
		}
	}
}

int main(){
	int i, j;

	solve(0);
	return 0;
}
