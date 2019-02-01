#include<stdio.h>
#include<stdlib.h>
#include<queue>
#define inf 2048

using namespace std;

int color[8], prev1[8], d[8];
int graph[8][8]={0};

int main(){
	int n = 8;			// n means number of nodes
	for(int i = 0; i<8; i++)
		for(int j = 0; j<8; j++){
			scanf("%d",&graph[i][j]);
		}

	for(int i = 0; i<8; i++){
		color[i]= 0;   //color WHITE == 0, GRAY == 1; BLACK == 2;
		prev1[i] = -1;   //NILL == -1
		d[i]= inf;
	}
	color[0] = 1;
	d[0] = 0;
	prev1[0] = -1;

	queue<int> myque;
	myque.push(0);

	while(!myque.empty()){
		int u;
		u = myque.front();
		myque.pop();
		for(int j = 0; j<8; j++){
			int v;
			if(graph[u][j] == 1){
			v = j;
			if(color[v] == 0){
				color[v] = 1;
				d[v] = d[u]+1;
				prev1[v] = u;
				myque.push(v);
			}
		}
		}
		color[u] = 2;	
	}
	for(int i = 0; i<8; i++){
			printf("%d   %d   %d\n",color[i], d[i], prev1[i]);
		}
	system("pause");
	return 0;
}

