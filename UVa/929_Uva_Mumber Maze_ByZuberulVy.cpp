#include <stdio.h>
#include <algorithm>
#include <limits.h>
#include <queue>

typedef struct
{
	int value;
	int cost;
	int final;
	int x;
	int y;
}Node;

Node G[1001][1001];
int M, N;


bool operator<(const Node &a, const Node &b) {
	if (a.cost != b.cost)
		return b.cost < a.cost;
	return false;
}

void dijkstra()
{
	G[0][0].cost = G[0][0].value;

	std::priority_queue<Node> Q;
	Q.push(G[0][0]);

	while (G[M - 1][N - 1].final != 1)
	{
		Node p = Q.top();
		Q.pop();

		int qI = p.x;
		int qJ = p.y;

		G[qI][qJ].final = 1;

		//south
		if (qI > 0)
		{
			if (G[qI - 1][qJ].cost > G[qI][qJ].cost + G[qI - 1][qJ].value)
			{
				G[qI - 1][qJ].cost = G[qI][qJ].cost + G[qI - 1][qJ].value;
				Q.push(G[qI - 1][qJ]);
			}
		}
		//north
		if (qI < M - 1)
		{
			if (G[qI + 1][qJ].cost > G[qI][qJ].cost + G[qI + 1][qJ].value)
			{
				G[qI + 1][qJ].cost = G[qI][qJ].cost + G[qI + 1][qJ].value;
				Q.push(G[qI + 1][qJ]);
			}
		}
		//east
		if (qJ < N - 1)
		{
			if (G[qI][qJ + 1].cost > G[qI][qJ].cost + G[qI][qJ + 1].value)
			{
				G[qI][qJ + 1].cost = G[qI][qJ].cost + G[qI][qJ + 1].value;
				Q.push(G[qI][qJ + 1]);
			}
		}
		//west
		if (qJ > 0)
		{
			if (G[qI][qJ - 1].cost > G[qI][qJ].cost + G[qI][qJ - 1].value)
			{
				G[qI][qJ - 1].cost = G[qI][qJ].cost + G[qI][qJ - 1].value;
				Q.push(G[qI][qJ - 1]);
			}
		}


	}


}

int main()
{
	int nCases;

	scanf("%d", &nCases);

	while (nCases--)
	{
		scanf("%d %d", &M, &N);
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				G[i][j].cost = INT_MAX;
				G[i][j].final = 0;
				G[i][j].x = i;
				G[i][j].y = j;
				scanf("%d", &G[i][j].value);
			}
		}

		dijkstra();
		printf("%d\n", G[M - 1][N - 1].cost);
	}

	return 0;
}