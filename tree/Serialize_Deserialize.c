#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX_NODE 10
#define DATA(n) (n ? n->data : -1)
typedef struct Node {
	int data;
	struct Node* lchild, * rchild;
}Node;

Node* getNewNode(int data) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = data;
	p->lchild = p->rchild = NULL;
	return p;
}

Node* insert(Node* root,int data) {
	if (root == NULL)
		return getNewNode(data);
	if (rand() % 2)
		root->rchild = insert(root->rchild, data); 
	else
		root->lchild = insert(root->lchild, data);
	return root;
}

void clear(Node* root) {
	if (root == NULL) return;
	clear(root->lchild);
	clear(root->rchild);
	free(root);
	return;
}

Node* getRandomBinaryTree(int n) {
	Node* root = NULL;
	for (int i = 0; i < n; i++) {
		root = insert(root, rand() % 100);
	}
	return root;
}

char buff[1000];
int len = 0;

void __serialize(Node* root) {
	if (root == NULL) return;
	len += snprintf(buff + len, 100, "%d", root->data);
	if (root->lchild == NULL && root->rchild == NULL) return;
	len += snprintf(buff + len, 100, "(");
	__serialize(root->lchild);
	if (root->rchild) {
		len += snprintf(buff + len, 100, ",");
		__serialize(root->rchild);
	}
	len += snprintf(buff + len, 100, ")");
	return;
}

void serialize(Node* root) {
	memset(buff, 0, sizeof(buff));
	len = 0;
	__serialize(root);
	return;
}

void print(Node* node) {
	printf("%d(%d,%d) \n", DATA(node), DATA(node->lchild), DATA(node->rchild));
	return;
}

void output(Node* root) {
	if (root == NULL) return;
	print(root);
	output(root->lchild);
	output(root->rchild);
	return;
}

Node* deserialize(char* buff, int len) {
	Node** stack = (Node**)malloc(sizeof(Node*) * MAX_NODE);
	int top = -1, scode = 0, flag = 0;
	Node* p = NULL, * root = NULL;
	for (int i = 0; buff[i]; i++) {
		switch (scode)
		{
		case 0: {
			if (buff[i] >= '0' && buff[i] <= '9') scode = 1;
			else if (buff[i] == '(') scode = 2;
			else if (buff[i] == ',') scode = 3;
			else scode = 4;
			i -= 1;
		}break;
		case 1: {
			int data = 0;
			while (buff[i] >= '0' && buff[i] <= '9') {
				data = data * 10 + (buff[i] - '0');
				i += 1;
			}
			p = getNewNode(data);
			if (top >= 0) {
				if (flag == 0) stack[top]->lchild = p;
				if (flag == 1) stack[top]->rchild = p;
			}
			i -= 1;
			scode = 0;
		}break;
		case 2: {
			stack[++top] = p;
			flag = 0;
			scode = 0;
		}break;
		case 3: {
			flag = 1;
			scode = 0;
		}break;
		case 4: {
			root = stack[top];
			top -= 1;
			scode = 0;
		}break;
		}
	}
	return root;
}

int main() {
	srand(time(0));
	Node* root = getRandomBinaryTree(MAX_NODE);
	serialize(root);
	output(root);
	printf("%s \n", buff);
	Node* new_root = deserialize(buff, len);
	output(new_root);
	return 0;
}
