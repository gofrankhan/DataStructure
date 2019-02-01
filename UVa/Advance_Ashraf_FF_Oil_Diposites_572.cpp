#include<stdio.h>
int m,n;
char A[101][101];

void fill(int x, int y){
	A[x][y] = 'x';
	if(x-1 >= 0 && y-1 >= 0 && A[x-1][y-1] == '@')
		fill(x-1, y-1);
	if(x-1 >= 0 && A[x-1][y] == '@')
		fill(x-1, y);
	if(x-1 >= 0 && y+1 < n && A[x-1][y+1] == '@')
		fill(x-1, y+1);
	if( y-1 >= 0 && A[x][y-1] == '@')
		fill(x, y-1);
	if(y+1 < n &&  A[x][y+1] == '@')
		fill(x, y+1);
	if( y-1 >= 0 && x+1 < m && A[x+1][y-1] == '@')
		fill(x+1, y-1);
	if(x+1 < m && A[x+1][y] == '@')
		fill(x+1, y);
	if(y+1 < n && x+1 < m && A[x+1][y+1] == '@')
		fill(x+1, y+1);
}

int main(){
	int i,j,count;
	scanf("%d %d",&m,&n);
	while(m!=0){
		if(n == 0){
			printf("0\n");
			break;
		}
	for(i = 0; i<m; i++)
			scanf("%s", A[i]);
	count = 0;
	for(i = 0; i<m; i++)
		for(j = 0; j<n; j++){
			if(A[i][j] == '@'){
				count++;
				fill(i,j);
			}
		}
	printf("%d\n",count);
	scanf("%d %d",&m,&n);
	}
	return 0;
}