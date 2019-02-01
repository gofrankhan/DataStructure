#include<stdio.h>

int map[100][100];
int n, x, y, corrupt, count;

int main(){
	int i,j;
	scanf("%d", &n);
	while(n){
		x = -1, y = -1, corrupt = 0;
		for(i = 0; i < n; i++){
			count = 0;
			for(j = 0; j < n; j++){
				scanf("%d", &map[i][j]);
				if(map[i][j])
					count++;
			}
			if(count%2 != 0){
				if(x < 0)
					x = i;
				else{
					corrupt = 1;
				}
			}
		}
		if(!corrupt){
			for(i = 0; i < n; i++){
			count = 0;
			for(j = 0; j < n; j++){
				if(map[j][i])
					count++;
			}
			if(count%2 != 0){
				if(y < 0)
					y = i;
				else{
					corrupt = 1;
					break;
				}
			}
		}
		}
		if(corrupt)
			printf("Corrupt\n");
		else if(x >= 0 && y >= 0){
			printf("Change bit (%d,%d)\n", x+1 , y+1);
		}
		else{
			printf("OK\n");
		}
		scanf("%d", &n);
	}
}