#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXSIZEOFNODE 10
typedef struct Node {
	int data;
	int rtag, ltag; //1.thread 0.edge
	struct Node* lchild, * rchild;
}Node;

Node* getNewNode(int data) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = data;
	p->lchild = p->rchild = NULL;
	p->ltag = p->rtag = 0;
	return p;
}
Node* Insert(Node* root, int data) {
	if (root == NULL) return getNewNode(data);
	if (rand() % 2)root->lchild = Insert(root->lchild, data);
	else root->rchild = Insert(root->rchild, data);
	return root;
}
void preOrder(Node* root) {
	if (root == NULL) return;
	printf("%d ", root->data);
	if(root->ltag==0) preOrder(root->lchild);
	if(root->rtag==0) preOrder(root->rchild);
}
void inOrder(Node* root) {
	if (root == NULL) return;
	if(root->ltag==0) inOrder(root->lchild);
	printf("%d ", root->data);
	if(root->rtag==0) inOrder(root->rchild);
}
void postOrder(Node* root) {
	if (root == NULL) return;
	if(root->ltag==0) postOrder(root->lchild);
	if(root->rtag==0) postOrder(root->rchild);
	printf("%d ", root->data);
}

Node* preNode = NULL, * inOrder_root = NULL;
void _Build_inOrderThread(Node* root) {
	if (root == NULL) return;
	if (root->ltag == 0) _Build_inOrderThread(root->lchild);
	if (inOrder_root == NULL) inOrder_root = root;
	if (root->lchild==NULL) {
		root->lchild = preNode;
		root->ltag = 1;
	}
	if (preNode && preNode->rchild==NULL) {
		preNode->rchild = root;
		preNode->rtag = 1;
	}
	preNode = root;
	if (root->rtag == 0) _Build_inOrderThread(root->rchild);
	return;
}
void Build_inOrderThread(Node* root) {
	_Build_inOrderThread(root);
	preNode->rchild == NULL;
	preNode->rtag = 1;
	return;
}

Node* inOrderTraverse_getNext(Node* node) {
	if (node->rtag == 1) return node->rchild;
	node = node->rchild;
	while (node->ltag == 0) node = node->lchild;
	return node;
}
void Clear(Node* root) {
	if (root == NULL) return;
	if(root->ltag==0) Clear(root->lchild);
	if(root->rtag==0) Clear(root->rchild);
	free(root);
}
int main() {
	srand(time(0));
	Node* root = NULL;
	for (int i = 0; i < MAXSIZEOFNODE; i++) {
		root = Insert(root, rand() % 100);
	}
	preNode = inOrder_root = NULL;
	Build_inOrderThread(root);

	preOrder(root); printf("\n");
	inOrder(root); printf("\n");
	postOrder(root); printf("\n");

	//Traverse like linklist
	Node* node = inOrder_root;
	while (node) {
		printf("%d ", node->data);
		node = inOrderTraverse_getNext(node);
	}
	printf("\n");
	Clear(root);
	return 0;
}