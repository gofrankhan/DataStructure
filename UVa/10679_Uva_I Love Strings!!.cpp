#include<stdlib.h>
#include<stdio.h>
#include<string>

char M[100001], sub[1001];
int T, q, len, lens, count;

int match(){
	char ch = sub[0];
	int i , j;
	count = 0;
	for(i = 0; M[i]!= '\0'; i++){
		if(ch == M[i]){
			for(j = 0;; j++){
				if(sub[j] != M[i]){
					break;
				}
				i++;
			}
			if(sub[j] == '\0')
				return 1;
			i--;
		}
	}
	return 0;
}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%s",M);
		scanf("%d",&q);
		while(q--){
			scanf("%s",sub);
			if(match()){
				printf("y\n");
			}else{
				printf("n\n");
			}
		}
	}
	return 0;
}