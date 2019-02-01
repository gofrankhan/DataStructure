#include<stdio.h>
#define SIZE 1001

int N, A[SIZE];
int dp[SIZE];
int Case, Max;

void readCase()
{
	N = 1;
	while (1 == scanf("%d", &A[N])) {
		if (-1 == A[N])
			break;
		N++;
	}
}

void initCase()
{
	int i;
	for (i = 0; i<N; i++)
		dp[i] = 1;
}

void lis()
{
	int i, j;
	for (i = 1; i<N; i++) for (j = 0; j<i; j++) {
		if (A[j] > A[i] && dp[j] + 1 > dp[i])
			dp[i] = dp[j] + 1;
	}
}

void solveCase()
{
	int i;
	lis();
	Max = 0;
	for (i = 0; i<N; i++) if (dp[i] > Max)
		Max = dp[i];
}

void printCase()
{
	if (Case)
		printf("\n");
	printf("Test #%d:\n", ++Case);
	printf("  maximum possible interceptions: %d\n", Max);
}

int main()
{
	Case = 0;
	while (1 == scanf("%d", &A[0])) {
		if (-1 == A[0])
			break;
		readCase();
		initCase();
		solveCase();
		printCase();
	}
	return 0;
}
