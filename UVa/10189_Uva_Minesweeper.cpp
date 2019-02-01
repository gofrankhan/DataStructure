#include<stdio.h>

char map[101][101];
int n, m, num, tc = 1, isFirst = 1;

void fill(int x,int y){
	int i,j;
	num = 0;
	for(i = x-1; i < x + 2; i++){
		for(j = y-1; j < y + 2; j++){
			if(i < 0 || j < 0 || i > n-1 || j > m-1 || (i == x && y == j))
				continue;
			if(map[i][j] == '*')
				num++;
		}
	}
	map[x][y] = 48 + num;
}

int main(){
	int i,j;
	scanf("%d %d", &n,&m);
	while((n+m)>0){

		if(isFirst)
			isFirst = 0;
		else
			printf("\n");

	for(i = 0; i < n; i++){
		scanf("%s",map[i]);
	}
	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			if(map[i][j] != '*')
				fill(i,j);
		}
	}
	printf("Field #%d:\n",tc++);
	for(i = 0; i < n; i++)
		printf("%s\n",map[i]);
	scanf("%d %d", &n,&m);
	}
	return 0;
}