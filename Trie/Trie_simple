#include<stdio.h>
#include<malloc.h>

#define SIZE 26

typedef struct trieNode{
	int leaf;
	int childCount;
	struct trieNode *child[SIZE];
}Node;

Node *createNode(){
	Node *newNode;
	newNode = (Node *)malloc(sizeof(Node));
	newNode->leaf = 0;
	newNode->childCount = 0;
	for (int i = 0; i < SIZE; i++){
		newNode->child[i] = NULL;
	}
	return newNode;
}

void insertNode(Node *root, char input[]){
	Node *cur = root;
	for (int i = 0; input[i]; i++){
		int index = input[i] - 'a';
		cur->childCount++;
		if (NULL == cur->child[index]){
			cur->child[index] = createNode();
		}
		cur = cur->child[index];
	}
	cur->leaf++;
}

void printTrie(Node *root, char output[], int index){
	if (root->leaf > 0){
		int count = root->leaf;
		output[index] = '\0';
		while (count--){
			printf("%s\n", output);
		}
	}
	for (int i = 0; i < SIZE; i++){
		if (NULL != root->child[i]){
			output[index] = i + 'a';
			printTrie(root->child[i], output, index + 1);
		}
	}
}

int searchTrie(Node *root, char input[]){
	for (int i = 0; input[i]; i++){
		int index = input[i] - 'a';

		if (NULL != root->child[index]){
			root = root->child[index];
		}
		else
			return 0;
	}
	if (root->leaf > 0)
		return 1;
	else
		return 0;
}

void deleteTrie(Node *root, char input[]){
	for (int i = 0; input[i]; i++){
		int index = input[i] - 'a';

		if (NULL != root->child[index]){
			root = root->child[index];
		}
		else
			return;
	}
	if (root->leaf > 0)
		root->leaf--;
}

int main(){
	Node *root = createNode();
	char output[1001];
	insertNode(root,"aaabbbcc");
	insertNode(root, "hello");
	insertNode(root, "gofran");
	insertNode(root, "srbd");
	insertNode(root, "srbd");
	insertNode(root, "srb");
	printTrie(root, output, 0);
	printf("%d\n", searchTrie(root, "hello"));
	printf("%d\n", searchTrie(root, "srb"));
	printf("%d\n", searchTrie(root, "srbe"));
	printf("%d\n", searchTrie(root, "sri"));
	deleteTrie(root, "srbe");
	deleteTrie(root, "hello");
	printTrie(root, output, 0);
	printf("%d\n", searchTrie(root, "hello"));
	printf("%d\n", searchTrie(root, "srb"));
	
	return 0;
}
