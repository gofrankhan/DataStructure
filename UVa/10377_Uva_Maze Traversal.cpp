#include<stdio.h>

char map[61][61], face, ch;
int tc, n, m, r,c;

void readCase(){
	int i, j;
	ch = getchar();
	scanf("%d %d",&n, &m);
	ch = getchar();
	for(i = 0; i < n; i++){
		gets(map[i]);
	}
	scanf("%d %d",&r,&c);
	ch = getchar();
	r--;
	c--;
	face = 'N';
}

void solveCase(){
	while(ch = getchar()){
		if(ch == 'Q')
			break;
		if(ch == 'R'){
			switch(face){
			case 'N':
				face = 'E';
				break;
			case 'E':
				face = 'S';
				break;
			case 'S':
				face = 'W';
				break;
			case 'W':
				face = 'N';
				break;
			}
		}
		if(ch == 'L'){
			switch(face){
			case 'N':
				face = 'W';
				break;
			case 'E':
				face = 'N';
				break;
			case 'S':
				face = 'E';
				break;
			case 'W':
				face = 'S';
				break;
			}
		}
		if(ch == 'F'){
			switch(face){
			case 'N':
				if(map[r-1][c] != '*')
					r--;
				break;
			case 'E':
				if(map[r][c+1] != '*')
					c++;
				break;
			case 'S':
				if(map[r+1][c] != '*')
					r++;
				break;
			case 'W':
				if(map[r][c-1] != '*')
					c--;
				break;
			}
		}
	}
}

int main(){
	scanf("%d",&tc);
	while(tc--){
		readCase();
		solveCase();
		printf("%d %d %c\n",++r,++c, face);
		if(tc)
			printf("\n");
	}
	return 0;
}