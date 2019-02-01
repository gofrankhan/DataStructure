#include<stdio.h>

#define SIZE 21

int N;
int A[SIZE], B[SIZE];
int dp[SIZE][SIZE];

void init()
{
	int i, temp;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%d", &temp);
		A[temp] = i;
	}
	for (i = 0; i<SIZE; i++)
		dp[i][0] = dp[0][i] = 0;
}

int readCase()
{
	int i, temp;
	if (1 != scanf("%d", &temp))
		return 0;
	B[temp] = 1;
	for (i = 2; i <= N; i++) {
		scanf("%d", &temp);
		B[temp] = i;
	}
	return 1;
}

int max(int x, int y)
{
	if (x > y)
		return x;
	return y;
}

int lcs()
{
	int i, j;
	for (i = 1; i <= N; i++) for (j = 1; j <= N; j++) {
		if (A[i] == B[j])
			dp[i][j] = dp[i - 1][j - 1] + 1;
		else
			dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
	}
	return dp[N][N];
}

int main()
{
	init();
	while (readCase())
		printf("%d\n", lcs());
	return 0;
}


