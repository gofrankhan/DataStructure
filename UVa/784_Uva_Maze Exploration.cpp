#include<stdio.h>
#include<string>

char Map[31][81],ch;
int n, a, b, index, len;

void fill(int x, int y){
	int i, j;
	Map[x][y] = '#';
	if(Map[x+1][y] == ' ')
		fill(x+1,y);
	if(Map[x-1][y] == ' ')
		fill(x-1,y);
	if(Map[x][y+1] == ' ')
		fill(x,y+1);
	if(Map[x][y-1] == ' ')
		fill(x,y-1);
}

void inputLine(int indx){
	int i = 0;
	ch = getchar();
	Map[indx][i++] = ch;
	while(ch != '\n'){
		ch = getchar();
		Map[indx][i++] = ch;
	}
	Map[indx][--i] = '\0';
	len = i;
}

int main(){
	scanf("%d",&n);
	ch=getchar();
	while(n--){
		index = 0;
		inputLine(0);
		//ch=getchar();
		while(Map[index][0] != '_'){
			inputLine(++index);
			for(int i = 0; i < len; i++)
				if(Map[index][i] == '*')
					a = index, b = i;
		}
		fill(a,b);
		for(int i = 0; i <=index; i++){
			printf("%s\n",Map[i]);
		}
	}
	return 0;
}