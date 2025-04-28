#include <stdio.h>
#include <stdlib.h>
#define MAX_TREE_SIZE 100
typedef int Status;
#define OK 1
#define ERROR 0
//一。树的顺序存储


//1.双亲表示法
typedef int TreeElemType;
typedef struct PTNode {
	TreeElemType data;
	int parent;//双亲位置，根节点parent位置为-1
}PTNode;
typedef struct {
	PTNode nodes[MAX_TREE_SIZE];//结点数组
	int r, n;//根的位置和结点数
}PTree;


//2.孩子表示法
typedef struct CTNode {//孩子节点
	int child;
	struct CTNode* next;
}*ChildPtr;
typedef struct {
	TreeElemType data;
	int parent;//双亲表示法与孩子表示法的结合 根节点parent位置为-1
	ChildPtr firstchild;
}CTBox;
typedef struct {
	CTBox nodes[MAX_TREE_SIZE];
	int r, n;//根的位置和结点数
}CTree;


//3.孩子兄弟表示法
typedef struct CSNode {
	TreeElemType data;
	int parent;//双亲表示法与孩子兄弟表示法的结合 根节点parent位置为-1
	struct CSNode* firstchild, * rightchild;
}CSNode,*CStree;


//二。二叉树
//1.满二叉树和完全二叉树适合用顺序存储

//2.二叉链表
typedef struct BiTNode {
	TreeElemType data;
	struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;
//如果有需要还可以加入一个指向双亲的指针域，即三叉链表（struct BiTNode* parent）

//二叉树的遍历方法
//前序遍历
void PreOrderTraverse(BiTree T) {
	if (T == NULL) return;
	printf("%d", T->data);
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);
}
//中序遍历
void InOrderTraverse(BiTree T) {
	if (T == NULL) return;
	InOrderTraverse(T->lchild);
	printf("%d", T->data);
	InOrderTraverse(T->rchild);
}
//后序遍历
void PostOrderTraverse(BiTree T) {
	if (T == NULL) return;
	PostOrderTraverse(T->lchild);
	PostOrderTraverse(T->rchild);
	printf("%d", T->data);
}

//二叉树的建立
//二叉树的前序遍历序列建立
typedef char TElemType;
void CreateBiTree(BiTree* T) {
	TElemType data;
	scanf("%c", &data);
	if (data == '#') *T = NULL;
	else {
		*T = (BiTree)malloc(sizeof(BiTNode));
		(*T)->data = data;//生成根节点
		CreateBiTree(&(*T)->lchild);
		CreateBiTree(&(*T)->rchild);
	}
}

//3。线索二叉树
typedef enum { Link, Thread } PointerTag;
typedef struct BiThrNode {
	TElemType data;
	struct BiThrNode* lchild, * rchild;
	PointerTag LTag;
	PointerTag RTag;
}BiThrNode,*BiThrTree;

BiThrTree pre;//全局变量，始终指向刚刚访问过的节点
//中序遍历进行中序线索化
void InThreading(BiThrTree p) {
	if (p) {
		InThreading(p->lchild);
		if (!p->lchild) {
			p->LTag = Thread;
			p->lchild = pre;
		}
		if (!pre->rchild) {
			pre->RTag = Thread;
			pre->rchild = p;
		}
		pre = p;
		InThreading(p->rchild);
	}
}
//中序遍历
//T指向头节点，头节点左链lchild指向根节点，头节点右链指
//向rchild指向中序遍历的最后一个节点。中序遍历二叉线索链
//表表示二叉树T
Status InOrderTraverse_Thr(BiThrTree T) {
	BiThrTree p;
	p = T->lchild; //p指向头节点
	while (p != T) {//空树或遍历结束时
		while (p->LTag == Link) p = p->lchild;
		printf("%c", p->data);
		while (p->RTag == Thread && p->rchild != T) {
			p = p->rchild;
			printf("%c", p->data);
		}
		p = p->rchild;
	}
	return OK;
}


