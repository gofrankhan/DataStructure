#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	int tc, x, y, r;
	float dis00, shot_dis, long_dis;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d %d",&x,&y,&r);
		dis00 = sqrtl((x*x)+(y*y));
		shot_dis = r - dis00;
		long_dis = dis00 + r;
		printf("%.2f %.2f\n",shot_dis,long_dis);
	}
	return 0;
}