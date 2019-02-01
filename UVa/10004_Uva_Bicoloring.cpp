#include<stdio.h>
#include<stdlib.h>
#include<queue>
#include<string>

using namespace std;

queue<int> myQ;
int map[200][200], n, l;
int Dist[200], visit[200];
int bfs(){
	int i, j, u, v;
	while(!myQ.empty()){
		u = myQ.front();
		myQ.pop();
		for(i = 0; i < n; i++){
			if(map[u][i] == 1){
			if(!visit[i]){
				Dist[i] = 1 - Dist[u];
				visit[i] = 1;
				myQ.push(i);
			}else if(Dist[u] == Dist[i]){
				return 0;
			}
		}
		}
	}
	return 1;
}

int main(){
	scanf("%d",&n);
	while(n){
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
		myQ.push(0);
		Dist[0] = 0;
		visit[0] = 1;
		if(bfs()){
			printf("BICOLORABLE.\n");
		}else{
			printf("NOT BICOLORABLE.\n");
		}
		scanf("%d",&n);
	}
	return 0;
}