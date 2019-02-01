#include<stdio.h>
#include<string.h>
int T,N, Path[201][201],rank[201];
char dict[201][11];

int find(char* n){
	int i;
	for(i = 0; i<N; i++)
		if(!strcmp(n,dict[i]))
			return i;
	return -1;
}

void fill(int n, int value){
	int i;
	if(rank[n]>value)
		rank[n] = value;
	else 
		return;
	for(i = 0;i<N;i++){
		if(Path[n][i] == 1)
			fill(i, value +1);
	}
}

int search(int x, int y){
	int i;
	for(i = 0; dict[x][i] && dict[y][i] && dict[x][i] == dict[y][i]; i++);
	if(dict[x][i] == '\0')
		return 0;
	if(dict[y][i] == '\0')
		return 0;
	i++;
	for(; dict[x][i] && dict[y][i] && dict[x][i] == dict[y][i]; i++);
	if(dict[x][i] == '\0' && dict[y][i] == '\0')
		return 1;
	return 0;
}

void readCase(){
	int i, j;
	N = 0;
	//printf("\n");
	while(1){
		scanf("%s",dict[N]);
		if(dict[N][0] == '*')
			break;
		N++;
	}
	memset(Path,0,sizeof(Path));
	for(i = 0; i<N; i++) for(j = i+1; j<N; j++){
		Path[i][j] = search(i,j);
		Path[j][i] = Path[i][j];
		/*if(Path[i][j])
			printf("%s %s\n",dict[i],dict[j]);*/
	}
}

void solveCase(){
	char st[25], st1[11], st2[11];
	int i,j,Ans;
	getchar();
	while(gets(st)){
		Ans = 0;
		if(st[0] == '\0')
			break;
		for(i = 0, j = 0; st[i] !=' '; i++,j++){
			st1[j] = st[i];
		}
		st1[j] = '\0';
		for(i++,j = 0; st[i]; i++,j++)
			st2[j] = st[i];
		st2[j] = '\0';

		for(i = 0; i<N; i++)
			 rank[i] = 100;
		fill(find(st1),0);
		Ans = rank[find(st2)];
		printf("%s %s %d\n", st1,st2,Ans);
	}
}

int main(){
	int i;
	//freopen("input.txt","r",stdin);
	scanf("%d",&T);
	while(T--){
		readCase();
		solveCase();
		if(T)
		printf("\n");
	}
	return 0;
}