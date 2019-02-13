#include<stdio.h>

int H[101], n, val, N, size;

void swap(int *x, int  *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

void heapify(){
	int cur = size - 1;
	int parent = (cur - 1) / 2;
	while (cur != 0 && H[parent] > H[cur]){
		swap(&H[parent], &H[cur]);
		cur = parent;
		parent = (cur - 1) / 2;
	}
}

void printHeap(){
	printf("\n\tHeap: ");
	for (int i = 0; i < size; i++){
		printf("%d ", H[i]);
	}
	printf("\n");
}

void add(){
	printf("\n\tAdd Number: ");
	scanf("%d", &n);
	H[size] = n;
	size++;
}

void heapifyMin(int i, int n){
	int l = i * 2 + 1;
	int r = i * 2 + 2;
	int smallest = i;
	if (l < n && H[l] < H[i])
		smallest = l;
	if (r < n && H[r] < H[smallest])
		smallest = r;
	if (smallest != i){
		swap(&H[smallest], &H[i]);
		heapifyMin(smallest, n);
	}
}

int extract_Min(){
	if (size <= 0)
		return -1;
	int min = H[0];
	swap(&H[0], &H[size - 1]);
	heapifyMin(0, size -1);
	size--;
	return min;
}

void sortHeap(){
	for (int i = size - 1; i >= 0; i--){
		swap(&H[0], &H[i]);
		heapifyMin(0, i);
	}
}

int main(){
	size = 0;
	do{
		printf("Enter - \n\t1. Add\n\t2. Extract Min\n\t3. Sort \n\t0. Exit\n\t");
		scanf("%d", &N);
		switch (N){
		case 1:
			add();
			heapify();
			printHeap();
			break;
		case 2:
			printf("\n\tMin value: %d", extract_Min());
			printHeap();
			break;
		case 3:
			sortHeap();
			printHeap();
			break;
		}
	} while (N);
}
