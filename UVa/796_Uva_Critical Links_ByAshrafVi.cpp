#include<stdio.h>
#define SIZE 101

int N;
int path[SIZE][SIZE], visited[SIZE], critical[SIZE][SIZE];
int Total;

void initCase()
{
    int i, j;
    for (i=0; i<N; i++) {
         for (j=0; j<N; j++) {
             path[i][j] = 0;
             critical[i][j] = 0;
         }
    }
}

void readCase()
{
    int i, j, x, y, M;
    for (i=0; i<N; i++) {
         scanf("%d (%d)", &x, &M);
         for (j=0; j<M; j++) {
             scanf("%d", &y);
             path[x][y] = 1;
             path[y][x] = 1;
         }
    }
}
 
void printPath()
{
    int i, j;
    for (i=0; i<N; i++) {
         for (j=0; j<N; j++)
             printf("%d ", path[i][j]);
         printf("\n");
    }
    printf("\n");
}

void fill(int x)
{
    int i;
    visited[x] = 1;
    for (i=0; i<N; i++) if (path[x][i] && !visited[i])
		fill(i);
}

void printVisited()
{
    int i;
    for (i=0; i<N; i++) 
         printf("%d ", visited[i]);
    printf("\n");
}

void resetVisited()
{
    int i;
    for (i=0; i<N; i++)
         visited[i] = 0;
}

void solveCase()
{
    int i, j;
    Total = 0;
    for (i=0; i<N; i++) for (j=i+1; j<N; j++) if (path[i][j]){ 
         path[i][j] = 0;
         path[j][i] = 0;
         resetVisited();
         fill(i);
         if (!visited[j]) {
             critical[i][j] = 1;
             Total++;
         }
         path[i][j] = 1;
         path[j][i] = 1;
    }
}

void printCase()
{
    int i, j;
    printf("%d critical links\n", Total);
    for (i=0; i<N; i++) for (j=i+1; j<N; j++) if (critical[i][j])
         printf("%d - %d\n", i, j);
    printf("\n");
}

int main()
{
    while (1 == scanf("%d", &N)) {
         initCase();
         readCase();
         solveCase();
         printCase();
    }
    return 0;
}
