#include<stdio.h>

char code[11][11];
int N, found, Case;
 
int search(int n)
{
    int i, j;
    for (i=0; i<n; i++) {
         for (j=0; code[i][j] && code[n][j] && code[i][j]==code[n][j]; j++);
         if (!code[i][j] || !code[n][j])
             return 1;
    }
    return 0;
}

void solveCase()
{
    int i;
    found = 0;
	for (i=1; i<N; i++) if (search(i)) {
         found = 1;
         return;
    }
}

void printCase(){
    if (!found)
         printf("Set %d is immediately decodable\n", Case);
    else
         printf("Set %d is not immediately decodable\n", Case);
}

int main(){
    Case = 0;
    while(1 == scanf("%s", code[0])){
         N = 0;
         while(code[N][0] != '9'){
			 N++;
             scanf("%s", code[N]);
         }
         Case++;
         solveCase();
         printCase();
    }
    return 0;
}
