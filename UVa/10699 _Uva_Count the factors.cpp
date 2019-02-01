#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<math.h>

using namespace std;

vector<int> myVect;

int Search(int x){
	int i;
	for(i = 0; i < myVect.size(); i++)
		if(x == myVect[i])
			return 0;
	return 1;
}

//void print(){
//	int i;
//	for(i = 0; i < myVect.size(); i++)
//		printf("%d ",myVect[i]);
//	printf("\n");
//}

int main(){
	int n, count, fact;
	scanf("%d",&n);
	while(n){
		count = n;
		myVect.clear();
		fact = sqrtl(n);
		for(int i = 2; i <= fact; ){
			if(n%i == 0){
				n /= i;
				fact = sqrtl(n);
				if(Search(i))
					myVect.push_back(i);
			}else{
				i++;
			}
		}
		if(n != 1)
			myVect.push_back(n);
		//print();
		printf("%d : %d\n",count,myVect.size());
	scanf("%d",&n);
	}
	return 0;
}