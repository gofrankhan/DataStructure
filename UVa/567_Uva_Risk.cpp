#include<stdio.h>
#include<stdlib.h>
#define INF 99999999

int Map[21][21];
int T = 1, isFirst = 1;

void initCase(){
	int i,j;
	for(i = 0; i < 21; i++)
		for(j = 0; j < 21; j++)
			Map[i][j] = INF;
}

void fill(){
	int i,j,k;
	for(k = 1; k < 21; k++)
		for(i = 1; i < 21; i++)
			for(j = 1; j < 21; j++)
				if(Map[i][j] > Map[i][k] + Map[k][j])
					Map[i][j] = Map[i][k] + Map[k][j];
}

int main(){
	int i,j, n, v, a , b;
	while(scanf("%d",&n)==1){

		/*if(isFirst)		  ///to print the new line at the end of 
			isFirst = 0;
		else
			printf("\n");*/

		initCase();
		for(i = 0; i < n; i++){
			scanf("%d",&v);
			Map[1][v] = 1;
			Map[v][1] = 1;
		}
		for(i = 2; i < 20; i++){
			scanf("%d",&n);
			for(j = 0; j < n; j++){
				scanf("%d",&v);
				Map[i][v] = 1;
				Map[v][i] = 1;
			}
		}
		fill();
		scanf("%d",&n);
		printf("Test Set #%d\n",T++);
		for(i = 0; i < n; i++){
			scanf("%d %d",&a,&b);
			printf("%2d to %2d: %d\n",a, b, Map[a][b]);
		}
		printf("\n");
	}

}
