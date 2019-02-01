#include<stdio.h>
#include<stdlib.h>

int main(){
	int f, s, l,d;
	while(scanf("%d",&f)!=EOF){
		scanf("%d",&s);
		d =  s-f;
		if(s%d == 0)
			l = s/d;
		else
			l = (s/d) +1;
		printf("%d\n",l);
	}
	return 0;
}