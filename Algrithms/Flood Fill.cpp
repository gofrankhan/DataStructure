#include<stdio.h>
int N, A[26][26];

void fill(int x, int y){
	A[x][y] = 2;
	if(x-1 >= 0 && y-1 >= 0 && A[x-1][y-1] == 1)
		fill(x-1, y-1);
	if(x-1 >= 0 && A[x-1][y] == 1)
		fill(x-1, y);
	if(x-1 >= 0 && y+1 < N && A[x-1][y+1] == 1)
		fill(x-1, y+1);
	if( y-1 >= 0 && A[x][y-1] == 1)
		fill(x, y-1);
	if(y+1 < N &&  A[x][y+1] == 1)
		fill(x, y+1);
	if( y-1 >= 0 && x+1 < N && A[x+1][y-1] == 1)
		fill(x+1, y-1);
	if(x+1 < N && A[x+1][y] == 1)
		fill(x+1, y);
	if(y+1 < N && x+1 < N && A[x+1][y+1] == 1)
		fill(x+1, y+1);
}

int main(){
	int i,j,count;
	scanf("%d",&N);

	for(i = 0; i<N; i++)
		for(j = 0; j<N;j++){
			scanf("%d", &A[i][j]);
		}
	count = 0;
	for(i = 0; i<N; i++)
		for(j = 0; j<N; j++){
			if(A[i][j] == 1){
				count++;
				fill(i,j);
			}
		}
	printf("%d",count);
	return 0;
}