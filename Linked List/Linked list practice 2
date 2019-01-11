#include<stdio.h>
#include<malloc.h>

typedef struct Node{
	int n;
	struct Node* next;
}Node;

Node* createNode(int n){
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->n = n;
	new_node->next = NULL;
	return new_node;
}

void printList(Node* root){
	Node* curr = root;
	if (curr == NULL)
	{
		printf("Empty!");
		return;
	}
	while (curr != NULL){
		printf("%d ", curr->n);
		curr = curr->next;
	}
}

Node* add_first(Node* root, int n){
	Node* new_root;
	new_root = createNode(n);
	new_root->next = root;
	return new_root;
}

Node* append(Node* root, int n){
	Node* itr = root;
	while (itr->next != NULL)
		itr = itr->next;
	itr->next = createNode(n);
	return root;
}

Node* delete_last(Node* root){
	Node* itr = root;
	Node* prev;
	if (root == NULL) return NULL;
	if (root->next == NULL)
		return NULL;
	while (itr->next->next != NULL){
		itr = itr->next;
	}
	itr->next = NULL;
	return root;
}

Node* delete_first(Node* root){
	if (root != NULL){
		return root->next;
	}
	else return NULL;
}

Node* add_in_position(Node* root, int p, int value){
	Node* itr = root;
	Node* next = root;

	if (p < 0){
		printf("\nInvalid index!\n");
		return root;
	}
	if (p == 0) return add_first(root, value);
	while (p-- && next){
		itr = next;
		next = next->next;
	}
	if (p < 0){
		itr->next = createNode(value);
		itr->next->next = next;
	}
	else{
		printf("\nInvalid Index!\n");
	}
	return root;
}

Node* delete_in_position(Node* root, int p){
	if (p == 0) return delete_first(root);
	if (p < 0){
		printf("\nInvalid Index!\n");
		return root;
	}
	Node* prev = root;
	Node* next = root;
	while (p-- && next->next){
		prev = next;
		next = next->next;
	}
	if (p < 0)
	{
		prev->next = prev->next->next;
	}
	else{
		printf("\nInvalid Index!\n");
		return root;
	}
	return root;
}

int main(){

	int N, n, p, value, isFirst = 1;
	Node* root = NULL;
	do{
		printf("Current List Data : ");
		printList(root);
		printf("\nEnter - \n\t(1) append \n\t(2) add first \n\t(3) delete from last \n\t(4) delete from first \n\t(5) add in position \n\t(6) delete in position \n\t(0) Exit \n\t");
		scanf("%d", &N);
		switch (N){
			case 1:
				{
					printf("\nEnter value: ");
					scanf("%d", &n);
					if (isFirst){
						root = createNode(n);
						isFirst = 0;
						break;
					}
					root = append(root, n);
					printList(root);
					break;
				}
			case 2:
				{
					printf("\nEnter value: ");
					scanf("%d", &n);
					if (isFirst){
						root = createNode(n);
						isFirst = 0;
						break;
					}
					root = add_first(root, n);
					printList(root);
					break;
				}
			case 3:
				{
					root = delete_last(root);
					if (root == NULL) isFirst = 1;
					break;
				}
			case 4:
				{
					root = delete_first(root);
					if (root == NULL) isFirst = 1;
					break;
				}
			case 5:
				{
					printf("\nEnter position: ");
					scanf("%d", &p);
					printf("\nEntre Value: ");
					scanf("%d", &value);
					root = add_in_position(root, p, value);
					break;
				}
			case 6:
				{
					printf("\nEnter position: ");
					scanf("%d", &p);
					root = delete_in_position(root, p);
					break;
				}
		}

	} while (N);

	return 0;
}
