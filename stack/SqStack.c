#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 20
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
typedef int ElemType;
typedef int Status;
typedef struct SqStack {
	ElemType data[MAXSIZE];
	int top;
}SqStack;

Status push(SqStack* S, ElemType data) {
	if (S->top == MAXSIZE - 1)return ERROR;
	S->top++;
	S->data[S->top] = data;
	return OK;
}

Status pop(SqStack* S, ElemType* data) {
	if (S->top == -1)return ERROR;
	data = S->data[S->top];
	S->top--;
	return OK;
}

#define DOUBLEMAXSIZE 40
typedef struct DoubleSqStack {
	ElemType data[DOUBLEMAXSIZE];
	int top1, top2;
}DoubleSqStack;

Status push(DoubleSqStack* S, ElemType data, int stackNumber) {
	if (S->top1 + 1 == S->top2)return ERROR;
	if (stackNumber == 1) {
		S->data[++S->top1] = data;
		return OK;
	}
	if (stackNumber == 2) {
		S->data[--S->top2] = data;
		return OK;
	}
	else
		return ERROR;
}

Status pop(DoubleSqStack* S, ElemType* data, int stackNumber) {
	if (S->top1 == -1 || S->top2 == DOUBLEMAXSIZE)return ERROR;
	if (stackNumber == 1) {
		data = S->data[S->top1--];
		return OK;
	}
	if (stackNumber == 2) {
		data = S->data[S->top2++];
		return OK;
	}
	else
		return ERROR;
}


