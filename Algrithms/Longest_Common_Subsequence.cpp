#include<stdio.h>
#include<stdlib.h>

char X[100],Y[100];
int b[101][101], c[101][101], m,n;

void LCS_Length();
void print(int, int);

int main(){
	scanf("%d %d",&m,&n);
	for(int i = 0; i<=m; i++){
		scanf("%c",&X[i]);
	}
	for(int i = 0; i<=n; i++){
		scanf("%c",&Y[i]);
	}
	for(int i = 0; i<=m; i++){
		for(int j = 0; j<=n; j++){
			b[i][j] = 0;
			c[i][j] = 0;
		}
	}
	LCS_Length();
	print(m,n);
	printf("\n");
	return 0;
}

void LCS_Length(){
	for(int i = 1; i<=m; i++){
		for(int j = 1; j<=n; j++){
			if(X[i] == Y[j]){
				c[i][j] = c[i-1][j-1] + 1;
				b[i][j] = 0;
			}
			else if(c[i-1][j] >= c[i][j-1]){
				c[i][j] = c[i-1][j];
				b[i][j] = 1;
			}
			else{
				c[i][j] = c[i][j-1];
				b[i][j] = 2;
			}
		}
	}
}
void print(int i, int j){
	if(i==0 || j==0){
		return;
	}
	if(b[i][j] == 0){
		print(i-1,j-1);
		printf("%c",X[i]);
	}
	else if(b[i][j] == 1){
		print(i-1,j);
	}
	else{
		print(i,j-1);
	}
}