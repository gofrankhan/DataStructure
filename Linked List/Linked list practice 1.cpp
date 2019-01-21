#include<stdio.h>
#include<malloc.h>


typedef struct Node{
	int data;
	struct Node* next;
}Node;

Node* createNode(int n){
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = n;
	newNode->next = NULL;
	return newNode;
}

void printNodes(Node *root){
	printf("\nList Output: ");
	while (root){
		printf("%d ", root->data);
		root = root->next;
	}
	printf("\n");
}

Node* append(int n, Node *list){
	Node *itr = (Node*)malloc(sizeof(Node));
	if (list == NULL){
		list = createNode(n);
			itr = list;
	}
	else{
		itr = list;
		while (list->next != NULL){
			list = list->next;
		}
		list->next = createNode(n);
	}

	return itr;
}

Node* add_front(int n, Node* list){
	Node *root = createNode(n);
	root->next = list;

	return root;
}

Node* delete_last(Node* root){
	Node* newLast = root;
	while (root->next != NULL){
		newLast = root;
		root = root->next;
	}
	newLast->next = NULL;
	return newLast;
}

Node* delete_front(Node *root){
	if (root->next != NULL){
		root = root->next;
		return root;
	}
}

Node* delete_by_position(Node* root, int p){
	if (0 == p)
		return delete_front(root);
	Node* curr = root;
	Node* prev = root;
	while (p-- && curr->next != NULL){
		prev = curr;
		curr = curr->next;
	}
	if (curr->next == NULL)
		printf("position not found!\n");
	else
		prev->next = curr->next;
	return root;
}

Node* add_by_position(Node* root, int p, int value){
	if (p < 0){
		printf("\nInvalid position");
		return root;
	}
	if (p == 0)
		return add_front(value, root);
	Node* prev = root;
	Node* next = root;
	while (p-- &&  next != NULL){
		prev = next;
		next = prev->next;
	}
	if (p < 0){
		prev->next = createNode(value);
		prev->next->next = next;
	}
	else{
		printf("\n Invalid position!");
	}
	return root;
}

int main(){

	//freopen("input.txt", "r", stdin);
	Node *root = NULL;
	Node *last = NULL;

	int N, n, value;
	scanf("%d", &N);
	while (N--){
		scanf("%d", &n);
		if (root == NULL){
			root = createNode(n);
			last = root;
		}
		else{
			last->next = createNode(n);
			last = last->next;
		}
	}
	printNodes(root);
	
	while (N){
		printf("Select your option:\n");
		printf("1(append), 2(add_front), 3(delete_last), 4(delete_front), 5(delete_by_position), 6(add_by_position)\n");
		scanf("%d", &N);
		switch (N){
			case 1:
			{
				printf("Enter Value: ");
				scanf("%d", &n);
				root = append(n, root);
				printNodes(root);
				break;
			}
			case 2:
			{
				printf("Enter Value: ");
				scanf("%d", &n);
				root = add_front(n, root);
				printNodes(root);
				break;
			}
			case 3:
			{
				last = delete_last(root);
				printNodes(root);
				break;
			}
			case 4:
			{
				root = delete_front(root);
				printNodes(root);
				break;
			}
			case 5:
			{
				printf("Enter Position: ");
				scanf("%d", &n);
				root = delete_by_position(root, n);
				printNodes(root);
				break;
			}
			case 6:
			{
				printf("Enter Position:");
				scanf("%d", &n);
				printf("\nEnter Value:");
				scanf("%d", &value);
				root = add_by_position(root, n, value);
				printNodes(root);
				break;
			}
		}
	}

	return 0;
}
