#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
using namespace std;

int v,e;
int parent[2][301], node[301];
vector<int> tempdata, sortUniqdata;

void initParent(){
	int i;
	for(i = 0; i<v; i++){
		parent[0][i] = i;
		parent[1][i] = node[i];
	}
}
int find(int x){
	if(x == parent[0][x])
		 return x;
	 else{
		 find(parent[0][x]);
	 }
}
int join(int x, int y){
	x = find(x);
	y = find(y);
	 if(parent[0][x] == y){
		 return 0;
	 }
	 if(parent[0][x]<y){
		 parent[0][y] = x;
		 return 1;
	 }else{
		 parent[0][x] = y;
	 }

}
void solveCase(){
	initParent();
	int a,b;
	for(int i = 0; i<2*e; i=i+2){
		//join(tempdata[i],tempdata[i+1]);
		for(int j = 0; j<v; j++){
			if(tempdata[i] == node[j]){
				a = j;
				break;
			}
		}
		for(int j = 0; j<v; j++){
			if(tempdata[i+1] == node[j]){
				b = j;
				break;
			}
		}
		join(a,b);
	}
}
void countPrint(){
	int count = 1;
	for(int i = 0; i<v-1; i++){
		if(parent[0][i]<parent[0][i+1]){
			count++;
		}
	}
	printf("%d\n",count);
}
void sortUniqe(){
	sortUniqdata.clear();
	sortUniqdata.assign(tempdata.begin(),tempdata.end());
	sort(sortUniqdata.begin(),sortUniqdata.end());
	unique(sortUniqdata.begin(),sortUniqdata.end());

	for(int i = 0; i<v; i++){
		node[i] = sortUniqdata[i];
	}
}

void readCase(){
	int i,s,d;
	tempdata.clear();
	scanf("%d %d",&v,&e);
	for(i = 0;i<e; i++){
		scanf("%d %d",&s,&d);
		tempdata.push_back(s);
		tempdata.push_back(d);
	}
	sortUniqe();
}

int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--){
		readCase();
		solveCase();
		countPrint();
	}
	return 0;
}