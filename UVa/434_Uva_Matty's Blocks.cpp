#include<stdio.h>

int map[8][8], l[8], r[8];
int n, tc, min , max;

void initCase(){
	int i,j;
	for(i = 0; i <n; i++){
		for(j = 0; j < n; j++){
			map[i][j] = 0;
		}
	}
}
void findMin(){
	int i,j;
	for(i = 0; i <n; i++){
		scanf("%d",&r[i]);
		for(j = 0; j <n; j++){
			if(r[i] > l[j]){
				map[j][i];
				min += r[i];
			}
		}
	}
}

int main(){
	scanf("%d",&tc);
	while(tc--){
		int i,j;
		scanf("%d",&n);
		initCase();
		min = 0;
		for(i = 0; i < n; i++){
			scanf("%d",&map[i][i]);
			l[i] = map[i][i];
			min += l[i];
		}
		findMin();
		printf("%d", min);
	}
}
