#include<stdio.h>
#include<stdlib.h>

int arr[20], N, tracks, Tsum, finalpath[20], finalIndex, max_length;

void doSum(int index, int sum, int last, int length, int path[]){
	if(arr[index] + sum > N)
		return;
	if(sum + arr[index] > Tsum || (sum + arr[index] == Tsum && max_length < length)){
		path[index] = last;
		Tsum = sum + arr[index];
		finalIndex = index;
		max_length = length;
	}
	for(int i = index+1; i < tracks; i++){
			doSum(i, sum+arr[index], index, length+1, path);
		}
}

void printpath(int curr_index){
	if(curr_index == finalpath[curr_index]){
		printf("%d ",arr[curr_index]);
		return;
	}
	printpath(finalpath[curr_index]);
	printf("%d ",arr[curr_index]);

}

int main(){
	while(scanf("%d",&N)!=EOF){
		scanf("%d",&tracks);
		Tsum = 0;
		finalIndex = 0;
		max_length = 0;
		for(int i = 0; i < tracks; i++){
			scanf("%d",&arr[i]);
			finalpath[i] = i;
		}
		int path[20];
		for(int i = 0; i < tracks; i++){
			doSum(i, 0, i, 0, path);
		}
		printpath(finalIndex);
		printf("sum:%d\n", Tsum);
	}
}