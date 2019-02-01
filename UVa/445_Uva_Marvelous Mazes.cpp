#include<stdio.h>

char ch;
int n;

int main(){
	n = 0;
	while(ch = getchar()){
		if(ch == EOF)
			break;
		if(ch >= 48 && ch <= 57)
			n += ch - 48;
		else if(ch == '!' || ch == '\n')
			printf("\n");
		else if(ch == 'b')
			while(n){
				printf(" ");
				n--;
			}
		else{
			while(n){
				printf("%c",ch);
				n--;
			}
		}
	}
	return 0;
}