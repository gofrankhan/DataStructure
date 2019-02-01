#include<stdio.h>
#include<stdlib.h>

int P[27], a, b,Set,n;
char buf[10],N[2],AB[3];

void intPar(){
	int i;
	for(i = 0; i < n; i++)
		P[i] = i;
}

int findP(int x){
	if(x == P[x])
		return x;
	return findP(P[x]);
}

int joint(int x, int y){
	x = findP(x);
	y = findP(y);
	if(x == y)
		return 0;
	if(x < y){
		P[y] = x;
		return 1;
	}else{
		P[x] = y;
		return 1;
	}
}


int main(){
	int Tc,i;
	scanf("%d",&Tc);
	gets(buf);
	while(Tc--){
		scanf("%s",N);
		gets(buf);
		n = N[0] - 64;
		Set = n;
		intPar();
		while(gets(AB) && AB[0] != '\0'){
			a = AB[0] - 65;
			b = AB[1] - 65;
			if(joint(a,b)){
				Set--;
			}
		}
		if(Tc)
			printf("%d\n\n",Set);
		else
			printf("%d\n",Set);
	}
	return 0;
}