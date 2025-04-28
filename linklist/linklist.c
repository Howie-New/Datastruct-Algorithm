// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>
// #define MAXSIZE 20
// #define TRUE 1
// #define FALSE 0
// #define OK 1
// #define ERROR 0
// typedef int ElemType;
// typedef int Status;

// typedef struct Node {   //结点
// 	ElemType data;
// 	struct Node* next;
// }Node;
// typedef struct Node* LinkList; //头结点

// Status GetElem(LinkList L, int i, ElemType* e) {		//查找链表中第i个元素（结点），用e返回L中第i个数据元素的值
// 	LinkList p;//p为第i个节点
// 	int j = 1;
// 	p = L->next;
// 	while (p && j < i)
// 	{
// 		p = p->next;
// 		j++;
// 	}
// 	if (!p || j > i)return ERROR;
// 	*e = p->data;
// 	return OK;
// }

// Status Insert(LinkList* L, int i, ElemType e) {
// 	LinkList s, p;//p是要插入节点的前一个节点
// 	p = *L;
// 	int j = 1;
// 	while (p && j < i)
// 	{
// 		p = p->next;
// 		j++;
// 	}
// 	if (!p || j > i)return ERROR;
// 	s = (LinkList)malloc(sizeof(Node));
// 	s->data = e;
// 	s->next = p->next;
// 	p->next = s;
// 	return OK;
// }

// Status Delete(LinkList* L, int i, ElemType* e) {
// 	LinkList q,p;//p是待删除节点的前一个节点，q为要删除的节点
// 	p = *L;
// 	int j = 1;
// 	while (p->next && j < i)
// 	{
// 		p = p->next;
// 		j++;
// 	}
// 	if (!(p->next) || j > i)return ERROR;
// 	q = p->next;
// 	p->next = q->next;
// 	*e = q->data;
// 	free(q);
// 	return OK;
// }

// Status Clear(LinkList* L) {
// 	LinkList p, q;
// 	p = (*L)->next;
// 	while (p)
// 	{
// 		q = p->next;
// 		free(p);
// 		p = q;
// 	}
// 	(*L)->next = NULL;
// 	return OK;
// }
// //整表创建
// void CreateLinkList_Head(LinkList* L, int n) {
// 	LinkList p;
// 	*L = (LinkList)malloc(sizeof(Node));
// 	(*L)->next = NULL;
// 	srand(time(0));
// 	for (int i = 0; i < n; i++) {
// 		p = (LinkList)malloc(sizeof(Node));
// 		p->data = rand() % 100 + 1;
// 		p->next = (*L)->next;
// 		(*L)->next = p;
// 	}

// }

// void CreateLinkList_Tail(LinkList* L, int n) {
// 	LinkList p,t;//t为最后一个节点
// 	*L = (LinkList)malloc(sizeof(Node));
// 	t = (*L);
// 	srand(time(0));
// 	for (int i = 0; i < n; i++) {
// 		p = (LinkList)malloc(sizeof(Node));
// 		p->data = rand() % 100 + 1;
// 		t->next = p;
// 		p = t;
// 	}
// 	t->next = NULL;

// }




// //有头链表
// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>

// #define DL 3
// #define STR(n) #n
// #define DIGIT_LEN_STR(n) "%" STR(n) "d"

// typedef struct Node {
//    int data;
//    struct Node* next;
// } Node;

// Node* getNewNode(int val) {
//    Node* p = (Node*)malloc(sizeof(Node));
//    p->data = val;
//    p->next = NULL;
//    return p;
// }

// Node* insert(Node* head, int pos, int val) {
//    Node new_head, * p = &new_head, * node = getNewNode(val);
//    new_head.next = head;
//    for (int i = 0; i < pos; i++) p = p->next;
//    node->next = p->next;
//    p->next = node;
//    return new_head.next;
// }

// void clear(Node* head) {
//    if (head == NULL) return;
//    for (Node* p = head, *q; p; p = q) {
//        q = p->next;
//        free(p);
//    }
//    return;
// }

// void output_linklist(Node* head, int flag = 0) {
//    int n = 0;
//    for (Node* p = head; p; p = p->next) n += 1;
//    for (int i = 0; i < n; i++) {
//        printf(DIGIT_LEN_STR(DL), i);
//        printf("  ");
//    }
//    printf("\n");
//    for (Node* p = head; p; p = p->next) {
//        printf(DIGIT_LEN_STR(DL), p->data);
//        printf("->");
//    }
//    printf("\n");
//    if (flag == 0) printf("\n\n");
//    return;
// }

// int find(Node* head, int val) {
//    Node* p = head;
//    int n = 0;
//    while (p) {
//        if (p->data == val) {
//            output_linklist(head, 1);
//            int len = n * (DL + 2) + 2;
//            for (int i = 0; i < len; i++) printf(" ");
//            printf("^\n");
//            for (int i = 0; i < len; i++) printf(" ");
//            printf("|\n");
//            return 1;
//        }
//        n += 1;
//        p = p->next;
//    }
//    return 0;
// }

// int main() {
//    srand(time(0));
// #define MAX_OP 7
//    Node* head = NULL;
//    for (int i = 0; i < MAX_OP; i++) {
//        int pos = rand() % (i + 1), val = rand() % 100;
//        printf("insert %d at %d to linklist\n", val, pos);
//        head = insert(head, pos, val);
//        output_linklist(head);
//    }
//    int val;
//    while (~scanf("%d", &val)) {
//        if (!find(head, val)) {
//            printf("not found\n");
//        }
//    }
//    clear(head);
//    return 0;
// }








//无头链表
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//此链表中所有的关于节点位置都是从1开始的
typedef struct Node {
	int data;
	struct Node* next;
}Node;

Node* createNewNode(int data) {
	Node* n = (Node*)malloc(sizeof(Node));
	n->data = data;
	n->next = NULL;
	return n;
}

Node* insert(Node* head, int data, int pos) {  //返回链表的第一个节点
	Node new_head, * p = &new_head;
	new_head.next = head;
	for (int i = 1; i < pos; i++) {
		p = p->next;
	}
	Node* n = createNewNode(data);
	n->next = p->next;           //p为待插入节点的前一个节点
	p->next = n;
	return new_head.next;
}



void clear(Node* head) {
	if (head == NULL)return;
	for (Node* p = head, *q; p; p = q) {
		q = p->next;
		free(p);
	}
	return;
}

void output_LinkList(Node* head) {
	int length=0;
	for (Node* p = head; p; p = p->next) {
		length += 1;
	}
	for (int i = 1; i <= length; i++) {
		printf("%3d", i);
		printf("  ");
	}
	printf("\n");
	for (Node* q = head; q; q = q->next) {
		printf("%3d", q->data);
		printf("->");
	}
	printf("\n\n");
	return;
}
int main()
{
	srand(time(0));
#define TIMES 10
	Node* head = NULL;
	for (int i = 1; i <= TIMES; i++) {
		int pos = rand() % i + 1, data = rand() % 100;
		head = insert(head, data, pos);
		printf("insert %d at %d to LinkList\n", data, pos);
		output_LinkList(head);
	}
	return 0;
}