//http://www.cplusplus.com/forum/beginner/97982/

#include<iostream>
#include<string>

using namespace std;

#define GRAPHSIZE 2048
#define INFINITY GRAPHSIZE*GRAPHSIZE
#define MAX(a,b)((a>b)?(a):(b))

int e;
int n;
int dist[GRAPHSIZE][GRAPHSIZE];
int d[GRAPHSIZE];

void output(){
	int i;
	for(i = 1; i<=n; ++i)
		cout<<i;
	cout<<endl;
	for(i = 1; i<=n; ++i)
		cout<<d[i];
	cout<<endl;
}
void dijkstra(int x){
	int i,k, small;
	int visited[GRAPHSIZE];
	for(i = 1; i <= n; ++i){
		d[i] = INFINITY;
		visited[i]=0;
	}
	d[x] = 0;
	for(k = 1; k<=n; ++k){
		small = -1;
		for(i = 1; i <= n; ++i)
			if(!visited[i] && ((small == -1) || (d[i] < d[small])))
				small = i;

		visited[small] = 1;

		for(i = 1; i <= n; ++i)
			if(dist[small][i])
				if(d[small] + dist[small][i] < d[i])
					d[i] = d[small] + dist[small][i];
	}
}

int main(){
	int i, j;
	int a, b, c;

	FILE *fin = fopen("dist.txt","r");
	fscanf(fin,"%d",&e);
	//scanf("%d",&e);
	for(i = 0; i < e; ++i)
		for(j = 0; j < e; ++j)
			dist[i][j] = 0;
	n = -1;
	for(i = 0; i < e; ++i){
		fscanf(fin,"%d%d%d",&a,&b,&c);
		//scanf("%d%d%d",&a,&b,&c);
		dist[a][b] = c;
		n = MAX(a, MAX(b,n));
	}
	fclose(fin);
	dijkstra(1);
	output();
	cin>>j;
	return 0;
}