#include<stdio.h>

#define SIZE 11
#define INF ((1<<31) - 1)

int N;
int Map[SIZE][SIZE];
int Start, End;
int Path[SIZE], Used[SIZE], FinalPath[SIZE];
int MinDelay, Len, Case;

void initCase()
{
    int i, j;
    for (i=1; i<=N; i++) for (j=1; j<=N; j++)
         Map[i][j] = -1;
	for (i=1; i<=N; i++)
         Used[i] = 0;
    MinDelay = INF;
}

void readCase()
{
    int i, j, m, delay;
    for (i=1; i<=N; i++) {
         scanf("%d", &m);
         while (m--){
			 scanf("%d %d", &j, &delay);
             Map[i][j] = delay;
		 }
    }
    scanf("%d %d", &Start, &End);
}

void printPath(int index)
{
    int i;
    printf("Path =");
    for (i=1; i<=index; i++)
         printf(" %d", Path[i]);
    printf("\n");
}

void updateResult(int index, int delay)
{
    int i;
    for (i=1; i<=index; i++)
         FinalPath[i] = Path[i];
    MinDelay = delay;
    Len = index;
}

void createAllPath(int index, int value, int delay)
{
    int i;
    Path[index] = value;
    Used[value] = 1;
	if (value == End && delay < MinDelay) {
         updateResult(index, delay);
    }
    for (i=1; i<=N; i++) if (Map[value][i] >= 0 && !Used[i])
         createAllPath(index+1, i, delay+Map[value][i]);
    Used[value] = 0;
}

void solveCase()
{
    createAllPath(1, Start, 0);
}

void printCase()
{
    int i;
    printf("Case %d: Path =", Case++);
    for (i=1; i<=Len; i++)
         printf(" %d", FinalPath[i]);
    printf("; %d second delay\n", MinDelay);
}

 

int main()
{
    Case = 1;
    while (1 == scanf("%d", &N)) {
         if (!N)
             break;
         initCase();
         readCase();
		 solveCase();
         printCase();
    }
    return 0;
}

