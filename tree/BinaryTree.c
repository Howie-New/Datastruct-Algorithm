#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define	MAXSIZEOFNODE 10
typedef struct Node {
	int data;
	struct Node* lchild, * rchild;
}Node;

Node* getNewNode(int data){
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = data;
	p->lchild = p->rchild = NULL;
	return p;
}

Node *insert(Node *root, int data) {
	if (root == NULL) return getNewNode(data);
	if (rand() % 2) root->lchild = insert(root->lchild, data);
	else root->rchild = insert(root->rchild, data);
	return root;
}
int head, tail;
Node* queue[MAXSIZEOFNODE + 5];
void bfs(Node* root) {
	head = tail = 0;
	queue[tail++] = root;
	while (head < tail) {
		Node* node = queue[head];
		printf("\nnode= %d\n", node->data);
		if (node->lchild) {
			queue[tail++] = node->lchild;
			printf("\tnode= %d lchild= %d\n", node->data, node->lchild->data);
		}
		if (node->rchild) {
			queue[tail++] = node->rchild;
			printf("\tnode= %d rchlid= %d\n", node->data, node->rchild->data);
		}
		head++;
	}
	return;
}
int tot = 0;
void dfs(Node* root) {
	if (root == NULL) return;
	int start, end;
	tot += 1;
	start = tot;
	if (root->lchild) dfs(root->lchild);
	if (root->rchild) dfs(root->rchild);
	tot += 1;
	end = tot;
	printf("%d : [%d,%d]\n", root->data, start, end);
	return;
}
void ClearNode(Node* node) {
	if (node == NULL)return;
	ClearNode(node->lchild);
	ClearNode(node->rchild);
	free(node);
	return;
}


int main() {
	srand(time(0));
	Node* root = NULL;
	for (int i = 0; i < MAXSIZEOFNODE; i++) {
		root = insert(root, rand() % 100);
	}
	bfs(root);
	dfs(root);
	ClearNode(root);
	return 0;
}