#include<stdio.h>
#include<stdlib.h>
#include<vector>

using namespace std;

int arr[20], N, tracks, Tsum, max_length;

vector<int> path;

void doSum(int index, int sum, vector<int> tpath){
	sum += arr[index];
	tpath.push_back(arr[index]);
	if(sum > Tsum || (sum == Tsum && path.size() < tpath.size())){
		Tsum = sum;
		path = tpath;
	}
	for(int i = index+1; i < tracks; i++){
		if(sum + arr[i] <= N)
			doSum(i, sum, tpath);
	}
}

int main(){
	while(scanf("%d",&N)!=EOF){
		scanf("%d",&tracks);
		Tsum = 0;
		max_length = 0;
		for(int i = 0; i < tracks; i++){
			scanf("%d",&arr[i]);
		}
		for(int i = 0; i < tracks; i++){
			vector<int> tmp;
			doSum(i, 0, tmp);
		}

		for(int i=0; i < path.size(); i++)
			printf("%d ",path[i]);
		printf("sum:%d\n", Tsum, max_length);
	}
}