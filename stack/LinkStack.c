#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 20
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
typedef int ElemType;
typedef int Status;
typedef struct StackNode {
	ElemType data;
	struct StackNode* next;
}StackNode, * StackNodePtr;
typedef struct LinkStack {
	StackNodePtr top;
	int count;
}LinkStack;

Status push(LinkStack* S, ElemType data) {
	StackNodePtr s = (StackNodePtr)malloc(sizeof(StackNode));
	s->data = data;
	s->next = S->top->next;
	S->top = s;
	S->count++;
	return OK;
}

Status pop(LinkStack* S, ElemType* data) {
	StackNodePtr s = (StackNodePtr)malloc(sizeof(StackNode));
	s = S->top;
	*data = s->data;
	S->top = S->top->next;
	free(s);
	S->count--;
	return OK;
}