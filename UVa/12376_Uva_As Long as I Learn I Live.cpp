#include<stdio.h>
#include<queue>

using namespace std;

int map[100][100], d[100];
int tc, n, m, u, v, max1, index;

void initCase(){
	int i,j;
	for(i = 0; i< n; i++){
		for(j = 0; j< n; j++){
			map[i][j] = 0;
		}
	}
	max1 = 0, index = 0;
}

void readCase(){
	int i,j,k;
	char ch;
	ch = getchar();
	scanf("%d %d",&n,&m);
	initCase();
	for(i = 0; i< n; i++)
		scanf("%d",&d[i]);
	for(i = 0; i < m; i++){
		scanf("%d %d",&u,&v);
		map[u][v] = d[v];
	}
}

void fill(int x){
	int i, maxId, maxVal;
	maxVal = 0;
	maxId = -1;
	for(i = 0; i < n; i++){
		if(maxVal < map[x][i]){
			maxVal = map[x][i];
			maxId = i;
		}
	}
	if(maxId < 0)
		return;
	max1 += maxVal;
	index = maxId;
	fill(maxId);
}

void solveCase(){
	fill(0);
}

int main(){
	scanf("%d",&tc);
	for(int T = 1; T <= tc; T++){
		readCase();
		solveCase();
		printf("Case %d: %d %d\n",T, max1, index);
	}
	return 0;
}