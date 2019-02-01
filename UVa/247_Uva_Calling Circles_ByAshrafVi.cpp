#include<stdio.h>
#define SIZE 26

int n, m;
char Name[SIZE][SIZE];
int Len;
int Call[SIZE][SIZE];
int Case;


int strcmp(char name1[], char name2[]){
	int i;
	for(i = 0; name1[i] && name2[i]; i++)
		if(name1[i] != name2[i])
			return 0;
	if(name1[i] == name2[i])
		return 1;
	return 0;
}

int search(char name[]){
	int i;
	for(i = 0; i<Len; i++)
		if(strcmp(Name[i],name) == 1)
			return i;
	return -1;
}

void strcpy(char dest[], char src[]){
	int i;
	for(i = 0; src[i]; i++)
		dest[i] = src[i];
	dest[i] = '\0';
}


void initCase(){
	int i,j;
	Len = 0;
	for(i = 0; i<n; i++){
		for(j = 0; j < n; j++){
			if(i == j)
				Call[i][j] = 1;
			else
				Call[i][j] = 0;
		}
	}
}

void readCase(){
	int i, x, y;
	char name1[SIZE], name2[SIZE];
	initCase();
	for(i = 0; i<m; i++){
		scanf("%s %s",name1,name2);
		x = search(name1);
		if(-1 == x){
			strcpy(Name[Len],name1);
			x = Len;
			Len++;
		}
		y = search(name2);
		if(-1 == y){
			strcpy(Name[Len],name2);
			y = Len;
			Len++;
		}
		Call[x][y] = 1;
	}
}

void printCall(){ 
	int i,j;
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			printf("%d ",Call[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void findAllPath(){
	int i,j, k;
	for(k = 0; k < n; k++)for(i = 0; i < n; i++)for(j = 0; j < n; j++){
		if(Call[i][k] && Call[k][j])
			Call[i][j] = 1;
	}
}

void solveCase(){
	findAllPath();
}

void printCase(){
	int i, j, used[SIZE];
	if(Case)
		printf("\n");
	printf("Calling circles for data set %d:\n",++Case);
	for(i = 0; i < n; i++)
		used[i] = 0;
	for(i = 0; i < n; i++)if(used[i]==0){
		printf("%s",Name[i]);
		used[i] = 1;
		for(j = i+1; j < n; j++) if(used[j] == 0 && Call[i][j] && Call[j][i]){
			printf(", %s",Name[j]);
			used[j] = 1;
		}
		printf("\n");
	}
}

int main(){
	Case  = 0;
	while(2 == scanf("%d %d",&n,&m)){
		if(!n && !m)
			break;
		readCase();
		solveCase();
		printCase();
	}
	return 0;
}
