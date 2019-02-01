#include<stdio.h>

int map[3][3];

int main(){
	int a,b,c,d,i, x,y;
	scanf("%d %d %d",&a,&b,&d);
	map[1][1] = 0;
	for(i = 0; i < 8; i++){
		scanf("%d %d %d",&x,&y,&c);
		map[1 + x - a][1 + y - b] = c;
	}
	return 0;
}