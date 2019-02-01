//http://www.geeksforgeeks.org/union-find-algorithm-set-2-union-by-rank/

#include<stdio.h>
#include<stdlib.h>

struct Edge
{
    int src, dest;
};
struct Graph
{
    int V, E;
    struct Edge* edge;
};

struct subset
{
    int parent;
    int rank;
};

struct Graph* createGraph(int V, int E)
{
    struct Graph* graph = (struct Graph*) malloc( sizeof(struct Graph) );
    graph->V = V;
    graph->E = E;

    graph->edge = (struct Edge*) malloc( graph->E * sizeof( struct Edge ) );

    return graph;
}

int find(struct subset subsets[], int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}

void Union(struct subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;

    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}
int isCycle( struct Graph* graph )
{
    int V = graph->V;
    int E = graph->E;
    struct subset *subsets =
        (struct subset*) malloc( V * sizeof(struct subset) );

    for (int v = 1; v <= V; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    for(int e = 0; e < E; ++e)
    {
        int x = find(subsets, graph->edge[e].src);
        int y = find(subsets, graph->edge[e].dest);

        if (x == y)
            continue;

        Union(subsets, x, y);
    }
	int max = 0,val, count = 0;
	val = subsets[1].parent;
	for(int e = 1; e <= V; ++e){
		
		if(subsets[e].parent == val){
			count++;
		}else{
			val = subsets[e].parent;
			count = 0;
		}
		if(count>max)
				max = count;
	}
	printf("%d\n",max);
    return 0;
}
int main()
{
	int V, E, s,d, tc;
	scanf("%d",&tc);
	while(tc--){
	scanf("%d %d", &V, &E);
	struct Graph* graph = createGraph(V, E);
	for(int i = 0; i < E; i++){
		scanf("%d %d", &s, &d);
		if(s > d){
			s = s+d;
			d = s-d;
			s = s-d;
		}
		graph->edge[i].src = s;
		graph->edge[i].dest = d;
	}
	isCycle(graph);
	}
	return 0;
}