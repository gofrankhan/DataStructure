#include<stdio.h>

int tc, level, time, val;

int main(){
	
	while(1 == scanf("%d",&tc) && tc != -1){
		while(tc--){
			scanf("%d %d",&level,&time);
			int i,num;
			num = 1;
			for(i = 0; i<level-1; i++){
				if(time%2 == 0 && time){
					num = num*2 + 1;
					time = time/2;
				}else{
					num = num*2;
					time = (time+1)/2;
				}
			}
			printf("%d\n",num);
		}

	}
	return 0;
}