#include<stdio.h>
int N,count = 0;
char A[100][100];

void fill(int x, int y){
	A[x][y] = 2;
	count++;
	if(x-1 >= 0 && y-1 >= 0 && A[x-1][y-1] == 'W'){
		fill(x-1, y-1);
	}
	if(x-1 >= 0 && A[x-1][y] == 'W'){
		fill(x-1, y);
	}
	if(x-1 >= 0 && y+1 < N && A[x-1][y+1] == 'W'){
		fill(x-1, y+1);
	}
	if( y-1 >= 0 && A[x][y-1] == 'W'){
		fill(x, y-1);
	}
	if(y+1 < N &&  A[x][y+1] == 'W'){
		fill(x, y+1);
	}
	if( y-1 >= 0 && x+1 < N && A[x+1][y-1] == 'W'){
		fill(x+1, y-1);
	}
	if(x+1 < N && A[x+1][y] == 'W'){
		fill(x+1, y);
	}
	if(y+1 < N && x+1 < N && A[x+1][y+1] == 'W'){
		fill(x+1, y+1);
	}
}

int main(){
	int i,j, tc;
	scanf("%d ",&tc);
	while(tc--){
	N = 0;
	//scanf("\n");
	scanf("%s", A[0]);
	while(A[N][0]== 'L' || A[N][0]== 'W'){
			scanf("%s", A[++N]);
	}
	i = 0;
		for(int x = 0; A[N][x]; x++){
			i = i*10 + A[N][x] - '0';
		}
	scanf("%d",&j);
	while(1){
	i--; j--;
	if(A[i][j] == 'W'){
			fill(i,j);
		}
	printf("%d\n",count);
	count = 0;
	if(scanf("%d %d",&i, &j) == EOF){
		printf("\n");
		break;
	}
	}
	}
	return 0;
}
/*int T, n,m;
char st[101][101], used[101][101];
int main(){
	freopen("input.txt","r",stdin);
	scanf("%d",&T);
	int x, y;
	while(T--){
		n = 0;
		m = 0;
		while(1 ==scanf("%s",st[n])){
			if(st[n][0] !='W' && st[n][0]!='L')
				break;
			n++;
		}
		x = 0;
		for(int i = 0; st[n][i]; i++){
			x = x*10 + st[n][i] - '0';
		}
		scanf("%d",&y);
	}
	return 0;
}*/