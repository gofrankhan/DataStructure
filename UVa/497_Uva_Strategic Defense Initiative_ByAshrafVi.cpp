#include<stdio.h>

#define SIZE 1001

int T;
int N;
int A[SIZE];
int dp[SIZE];
int Max;
int Mark[SIZE];

int toInt(char str[])
{
	int i, num = 0;
	for (i = 0; str[i]; i++)
		num = num * 10 + str[i] - '0';
	return num;
}

void readCase()
{
	char str[20];
	N = 0;
	while (gets(str)) {
		if (str[0] == '\0')
			break;
		A[N] = toInt(str);
		N++;
	}
}

void initDp()
{
	int i;
	for (i = 0; i<N; i++)
		dp[i] = 1;
}

void lis()
{
	int i, j;
	for (i = 0; i<N; i++) for (j = 0; j<i; j++) {
		if (A[j] < A[i] && dp[j] + 1 > dp[i])
			dp[i] = dp[j] + 1;
	}
}

void searchMax()
{
	int i;
	Max = dp[0];
	for (i = 1; i<N; i++) if (dp[i] > Max)
		Max = dp[i];
}

void markList()
{
	int i, temp;
	temp = Max;
	for (i = N - 1; i >= 0; i--) {
		if (dp[i] == temp) {
			Mark[i] = 1;
			temp--;
		}
		else
			Mark[i] = 0;
	}
}

void solveCase()
{
	Max = 0;
	initDp();
	lis();
	searchMax();
	markList();
}

void printCase()
{
	int i;
	printf("Max hits: %d\n", Max);
	for (i = 0; i<N; i++) if (Mark[i])
		printf("%d\n", A[i]);
	if (T)
		printf("\n");
}

int main()
{
	scanf("%d", &T);
	getchar();
	getchar();
	while (T--) {
		readCase();
		solveCase();
		printCase();
	}
	return 0;
}
