#include<stdio.h>
#include<math.h>
#include<stdlib.h>

 struct {
	double x,y;
}P[101];

int Parent[101];
typedef struct {
	 int x, y;
	 double dist;
 }Link;
Link D[10001];

 int N, T, Dlen;
 float Ans;
 void readCase(){
	 int i;
	 getchar();
	 scanf("%d",&N);
	 for(i = 0; i<N; i++)
		 scanf("%lf %lf",&P[i].x,&P[i].y);
 }
 int cmp(const void *a, const void *b){
	 Link *p = (Link*) a;
	 Link *q = (Link*) b;
	 if(p->dist < q->dist){
		 return -1;
	 }else
		 return 1;
 }
 void makeDistance(){
	 int i,j;
	 Dlen = 0;
	 for(i = 0; i<N; i++){
		 for(j = i+1; j<N; j++){
			 D[Dlen].x = i;
			 D[Dlen].y = j;
			 D[Dlen].dist  = sqrt((P[i].x - P[j].x)*(P[i].x - P[j].x)
				 +(P[i].y - P[j].y)*(P[i].y - P[j].y));
			 Dlen++;
		 }
	 }
	/* for(i = 0; i<Dlen; i++){
		 printf("%d %d %lf\n",D[i].x,D[i].y,D[i].dist);
	 }*/
 }
 void initParent(){
	 int i;
	 for(i = 0; i<N; i++){
		 Parent[i] = i;
	 }
 }
 int findParent(int x){
	 if(x == Parent[x])
		 return x;
	 else
		 findParent(Parent[x]);
 }
 int joint(int x,int y){
	 x = findParent(x);
	 y = findParent(y);
	 if(x == y){
		 return 0;
	 }
	 if(x<y){
		 Parent[y] = x;
		 return 1;
	 }else{
		 Parent[x] = y;
		 return 1;
	 }
 }
 void solveCase(){
	 int i;
	 makeDistance();
	 qsort(D,Dlen,sizeof(Link),cmp);
	 /*for(i = 0; i<Dlen; i++){
		 printf("%d %d %lf\n",D[i].x,D[i].y,D[i].dist);
	 }*/
	 initParent();
	 Ans = 0.0;
	 for(i = 0; i<Dlen; i++){
		 if(joint(D[i].x,D[i].y)){
			 Ans += D[i].dist;
		 }
	 }
 }
 void printCase(){
	 printf("%.2lf\n",Ans);
	 if(T){
		 printf("\n");
	 }
 }
 int main(){
	// freopen("input.txt","r",stdin);
	 scanf("%d",&T);
	 while(T--){
		 readCase();
		 solveCase();
		 printCase();
	 }
	 return 0; 
 }