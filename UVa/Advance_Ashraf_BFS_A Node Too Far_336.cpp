#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int N, A[32],size, Path[32][32], rank[32];

int search(int n){
	int i;
	for(i = 0; i<size; i++)
		if(A[i] == n)
			return i;
	return -1;
}

void fill(int n, int value){
	int i;
	if(rank[n]>value)
		rank[n] = value;
	else 
		return;
	for(i = 0;i<size;i++){
		if(Path[n][i] == 1)
			fill(i, value +1);
	}
}

int main(){
	//freopen("input.txt","r",stdin);
	int x, y, i,j, pos1, pos2, Ans, T = 1;
	while(1 == scanf("%d",&N) && N){
		size = 0;
		memset(Path,0,sizeof(Path));
		while(N--){
			scanf("%d %d", &x,&y);
			pos1 = search(x);
			if(pos1 == -1)
				pos1 = size, A[size++] = x;
			//if(search(x) == 0)
				//A[size++] = x;
			pos2 = search(y);
			if(pos2 == -1)
				pos2 = size, A[size++] = y;
			//if(search(y) == 0)
				//A[size++] = y;
			Path[pos1][pos2] = 1;
			Path[pos2][pos1] = 1;
		}
		/*for(i = 0; i<size; i++){
			for(j = 0; j<size; j++){
				printf("%d ",Path[i][j]);
			}
			printf("\n");
		}
		for(i = 0; i<size; i++){
			printf("%d ", A[i]);
		}*/
		while(2 == scanf("%d %d",&x,&y)){
			if(!x && !y)
				break;
			for(i = 0; i<size; i++)
				rank[i] = 100;
			fill(search(x),0);
			/*for(i = 0; i<size; i++){
				printf("%d %d\n",A[i], rank[i]);
			}*/
			Ans = 0;
			for(i = 0; i<size; i++) 
				if(rank[i]>y)
					Ans++;
			printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",T++,Ans,x,y);
		}
	}
	system("pause");
}