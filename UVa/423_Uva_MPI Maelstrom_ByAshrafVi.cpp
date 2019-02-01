#include<stdio.h>

#define SIZE 101
#define INF 0xFFFFFFF

int N;
int Path[SIZE][SIZE];
int Max;

void initCase()
{
	int i;
	for (i = 0; i<N; i++)
		Path[i][i] = INF;
}
void readCase()
{
	int i, j, x;
	for (i = 1; i<N; i++) {
		for (j = 0; j<i; j++) {
			if (1 == scanf("%d", &x))
				Path[i][j] = Path[j][i] = x;
			else {
				Path[i][j] = Path[j][i] = INF;
				scanf("%*c");
			}
		}
	}
}
void shortestPath()
{
	int i, j, k;
	for (k = 0; k<N; k++) {
		for (i = 0; i<N; i++) {
			for (j = 0; j<N; j++) {
				if (Path[i][j] > Path[i][k] + Path[k][j])
					Path[i][j] = Path[i][k] + Path[k][j];
			}
		}
	}
}
void printPath()
{
	int i, j;
	for (i = 1; i<N; i++) {
		for (j = 0; j<i; j++)
			printf("%5d", Path[i][j]);
		printf("\n");
	}
}
void solveCase()
{
	int i, j;
	//printPath();
	shortestPath();
	//printPath();
	Max = 0;
	for (i = 1; i<N; i++) {
		if (Path[0][i] > Max)
			Max = Path[0][i];
	}
}
void printCase()
{
	printf("%d\n", Max);
}

int main()
{
	//freopen("input.txt", "r", stdin);
	while (1 == scanf("%d", &N)) {
		initCase();
		readCase();
		solveCase();
		printCase();
	}
	return 0;
}
