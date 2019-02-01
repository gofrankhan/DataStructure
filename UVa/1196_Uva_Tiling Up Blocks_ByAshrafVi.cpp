#include<stdio.h>

#define SIZE 101

int N;
int dp[SIZE][SIZE], block[SIZE][SIZE];

void initCase()
{
	int i, j;
	for (i = 0; i<SIZE; i++) for (j = 0; j<SIZE; j++)
		dp[i][j] = block[i][j] = 0;
}

void readCase()
{
	int i, l, m;
	for (i = 0; i<N; i++) {
		scanf("%d %d", &l, &m);
		block[l][m]++;
	}
}

int max(int x, int y)
{
	if (x > y)
		return x;
	return y;
}

void solveCase()
{
	int i, j;
	for (i = 1; i<SIZE; i++) for (j = 1; j<SIZE; j++) {
		dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		dp[i][j] += block[i][j];
	}
}

void printCase()
{
	printf("%d\n", dp[SIZE - 1][SIZE - 1]);
}

int main()
{
	while (1 == scanf("%d", &N)) {
		if (!N)
			break;
		initCase();
		readCase();
		solveCase();
		printCase();
	}
	printf("*\n");
	return 0;
}


