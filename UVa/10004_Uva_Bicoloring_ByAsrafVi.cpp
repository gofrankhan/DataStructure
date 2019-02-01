#include<stdio.h>
#include<stdlib.h>

int map[200][200], n, l;
int Dist[200], visit[200];


void readCase(){
	int i,j, x, y;
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			map[i][j] = 0;
	for(i = 0; i < n; i++)
		visit[i] = 0, Dist[i] = 0;
	scanf("%d",&l);
	for(i = 0; i < l; i++){
		scanf("%d %d",&x,&y);
		map[x][y] = 1;
		map[y][x] = 1;
	}	
}

int fill(int pos, int val){
	int i;
	if(!visit[pos]){
		visit[pos] = val;
		for(i = 0; i<n; i++)if(map[i][pos] && !fill(i, 3-val))
			return 0;
	}
		else if(visit[pos] != val)
			return 0;
 return 1;
}

void solveCase(){
	if(fill(0,1)){
		printf("BICOLORABLE.\n");
	}else{
		printf("NOT BICOLORABLE.\n");
	}
}

int main()
{
	scanf("%d",&n);
	while(n){
	readCase();
	solveCase();
	scanf("%d",&n);
	}
	return 0;
}