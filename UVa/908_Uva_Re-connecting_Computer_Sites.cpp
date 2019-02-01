#include<stdio.h>
#include<stdlib.h>
#include<string>
#define SIZE 1000001

typedef struct {
	int x;
	int y;
	int cost;
}Node;

Node Map[SIZE];

int parent[SIZE];
int T, N, M, K, Ans1, Ans2, index;
char ch;
int isFirst = 1;

void initCase(){
	int i, j;
	for(i = 1; i <= N; i++){
		parent[i] = i;
	}
	Ans1 = Ans2 = 0;
}

int findParent(int x){
	if(parent[x] == x)
		return x;
	return findParent(parent[x]);
}

int join(int x, int y){
	x = findParent(x);
	y = findParent(y);
	
	if(x == y)
		return 0;
	if(x < y){
		parent[y] = x;
		return 1;
	}else{
		parent[x] = y;
		return 1;
	}
}

void readCase(){
	int i, j, a, b, c;
	index = 0;
	for(i = 0; i < N-1; i++){
		scanf("%d %d %d",&a,&b,&c);
		Ans1 +=c;
	}
	scanf("%d",&K);
	for(i = 0; i < K; i ++){
		scanf("%d %d %d",&a, &b, &c);
		Map[index].x = a, Map[index].y = b; Map[index].cost = c;
		index++;
	}
	scanf("%d", &M);
	for(i = 0; i < M; i ++){
		scanf("%d %d %d",&a, &b, &c);
		Map[index].x = a, Map[index].y = b; Map[index].cost = c;
		index++;
	}
}

void sortMap(){
	int i,j;
	Node temp;
	for(i = 0; i < index - 1; i++){
		for(j = i + 1; j < index; j++){
			if(Map[i].cost > Map[j].cost){
				temp = Map[j];
				Map[j] = Map[i];
				Map[i] = temp;
			}
		}
	}
}

void solveCase(){
	sortMap();
	int i,j;
	for(i = 0; i < index; i++){
		if(join(Map[i].x, Map[i].y))
			Ans2 += Map[i].cost;
	}
}

int main(){
	while(1){
		if(isFirst){
			isFirst = 0;
			scanf("%d",&N);
		}
		else{
			ch = getchar();
			if((scanf("%d",&N)!=1))
				break;
			else{
				printf("\n");
			}
		}
	if(N){
		initCase();
		readCase();
		solveCase();
		printf("%d\n%d\n",Ans1,Ans2);
	}
	}
	return 0;
}