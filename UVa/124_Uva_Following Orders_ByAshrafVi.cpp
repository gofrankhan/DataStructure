#include<stdio.h>

#define SIZE1 26
#define SIZE2 1201

char line[SIZE2];
int variable[SIZE1], used[SIZE1], path[SIZE1][SIZE1];
int N;
char output[SIZE1];
int isFirst;

void initCase(){
	int i, j;
    for (i=0; i < SIZE1; i++) for (j=0; j < SIZE1; j++)
         path[i][j] = 0;
    for (i=0; i < SIZE1; i++)
         variable[i] = 0;
    for (i=0; i < SIZE1; i++)
         used[i] = 0;
}

void readCase(){
	int i,j, index1, index2;
	for(i = 0; line[i];i++) if(line[i]>='a' && line[i]<='z'){
		index1 = line[i] - 'a';
		variable[index1] = 1;
	}
	gets(line);
	for(i = 0; line[i]; i++){
		while(line[i] == ' ')
			i++;
		index1 = line[i] - 'a';
		i++;
		while(line[i] == ' ')
			i++;
		index2 = line[i] - 'a';
		path[index1][index2] = 1;
	}
}

void countVariable(){
	int i;
	N = 0;
	for(i = 0; i < SIZE1; i++)if(variable[i])
		N++;
}

void solve(int index){
	int i, j;
	if(index == N){
		output[index] = '\0';
		printf("%s\n",output);
		return;
	}
	for(i = 0; i < SIZE1; i++)if(variable[i] && used[i] == 0){
		for(j = 0; j < SIZE1; j++)if(path[i][j] && used[j])
			return;
		used[i] = 1;
		output[index] = i + 'a';
		solve(index + 1);
		used[i] = 0;
	}
}

void solveCase(){
	int i;
	if(isFirst)
		isFirst = 0;
	else
		printf("\n");
	countVariable();
	solve(0);
}

int main(){
	isFirst = 1;
	while(gets(line)){
		initCase();
		readCase();
		solveCase();
	}
}