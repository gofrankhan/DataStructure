#include <stdio.h>
int N,Count,M;
int data[26][26];
void search(int i, int j){
    data[i][j]=2;
    Count++;
    if((i+1)<=N && data[i+1][j]==1)
        search(i+1,j);
    if((j+1)<=N && data[i][j+1]==1)
        search(i,j+1);
    if((i-1)>=1 && data[i-1][j]==1)
        search(i-1,j);
    if((j-1)>=1 && data[i][j-1]==1)
        search(i,j-1);
}
int main(void){
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &T);
	for(test_case = 0; test_case < T; test_case++)
	{
		int i,j;
		int S,C;
		scanf("%d", &N);
		for(i=1; i<=N; i++) {
			for(j=1; j<=N; j++) {
				scanf("%d", &data[i][j]);
			}
		}
        S = 0;   //Set
		C = 0;	 //Concatinates
		M = 0;   //Maximum

		for(i=1; i<=N; i++) {
			for(j=1; j<=N; j++) {
				if(data[i][j]==1){
                    Count=0;
                    S++;
                    search(i,j);
				}
				if(Count>M){
                    M=Count;
                    Count=0;
				}
			}
		}
		C=M;
		// Print the answer to standard output(screen).
		printf("%d %d\n", S, C);

	}

	return 0;
	//Your program should return 0 on normal termination.
}