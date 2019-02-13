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
	while (cur != 0 && H[parent] < H[cur]){
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

void heapifyMax(int i, int n){
	int l = i * 2 + 1;
	int r = i * 2 + 2;
	int largest = i;
	if (l < n && H[l] > H[i])
		largest = l;
	if (r < n && H[r] > H[largest])
		largest = r;
	if (largest != i){
		swap(&H[largest], &H[i]);
		heapifyMax(largest, n);
	}
}

int extract_Max(){
	if (size <= 0)
		return -1;
	int min = H[0];
	swap(&H[0], &H[size - 1]);
	heapifyMax(0, size - 1);
	size--;
	return min;
}

void sortHeap(){
	for (int i = size - 1; i >= 0; i--){
		swap(&H[0], &H[i]);
		heapifyMax(0, i);
	}
}

int main(){
	size = 0;
	do{
		printf("Enter - \n\t1. Add\n\t2. Extract Max\n\t3. Sort \n\t0. Exit\n\t");
		scanf("%d", &N);
		switch (N){
		case 1:
			add();
			heapify();
			printHeap();
			break;
		case 2:
			printf("\n\tMax value: %d", extract_Max());
			printHeap();
			break;
		case 3:
			sortHeap();
			printHeap();
			break;
		}
	} while (N);
}
