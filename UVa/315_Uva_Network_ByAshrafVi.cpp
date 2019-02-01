#include<stdio.h>

#define SIZE 101

int N;
int path[SIZE][SIZE], visited[SIZE];
int critical;

void initCase()
{
    int i, j;
    for (i=1; i<=N; i++) for (j=1; j<=N; j++)
         path[i][j] = 0;
}

 

void readCase()
{
    int x, y;
    char ch;
    while (1 == scanf("%d", &x)) {
	if (0 == x)
             break;
         while (2 == scanf("%d%c", &y, &ch)) {
             path[x][y] = 1;
             path[y][x] = 1;
             if (ch == '\n')
                 break;
		 }
    }
}

void fill(int x)
{
    int i;
    visited[x] = 1;
    for (i=1; i<=N; i++) if (path[x][i] && !visited[i])
         fill(i);
}

int isCritical(int x)
{
    int i;
    for (i=1; i<=N; i++)
         visited[i] = 0;
    for (i=1; i<=N; i++) if (path[x][i]) {
         visited[x] = 1;
         fill(i);
         break;
    }
    for (i++; i<=N; i++) if (path[x][i] && !visited[i])
         return 1;
    return 0;
}

void solveCase()
{
    int i;
    critical = 0;
    for (i=1; i<=N; i++) if (isCritical(i))
         critical++;
}

void printCase()
{
    printf("%d\n",critical);
}

int main()
{
    while (1 == scanf("%d", &N)) {
        if (0 == N)
             break;
         initCase();
         readCase();
         solveCase();
         printCase();
    }
 return 0;
}

 
