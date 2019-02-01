// http://www.c-program-example.com/2011/10/c-program-to-find-minimum-spanning-tree.html
#include<stdio.h>
#include<stdlib.h>

int main(){
	int a,b, n, u,v,min, mincost =0, cost[10][10],visited[10]={},ne = 1;
	scanf("%d",&n);  //number of nodes
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=n; j++){
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0){
				cost[i][j] = 999;
			}
		}
	}
	visited[1] = 1;
	while(ne<n){
		min = 999;
		for(int i = 1; i<=n; i++){
			for(int j = 1; j<=n; j++){
				if(cost[i][j]<min)
					if(visited[i]!=0){
						min = cost[i][j];
						a=u=i;
						b=v=j;
					}
			}
		}
		if(visited[u] == 0 || visited[v] == 0){
			mincost+=min;
			visited[b] = 1;
			ne++;
		}
		cost[a][b] = 999;
		cost[b][a] = 999;
	}
	printf("%d\n",mincost);
	return 0;
}