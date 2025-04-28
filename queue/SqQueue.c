// #include <stdio.h>
// #include <stdlib.h>
// #define MAXSIZE 20
// #define TRUE 1
// #define FALSE 0
// #define OK 1
// #define ERROR 0
// typedef int ElemType;
// typedef int Status;
// typedef struct SqQueue {
// 	ElemType data[MAXSIZE];
// 	int front;
// 	int rear;
// }SqQueue;

// Status initSqQueue(SqQueue* Q) {
// 	Q->front = 0;
// 	Q->rear = 0;
// 	return OK;
// }

// int SqQueue_length(SqQueue Q) {
// 	return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
// }

// Status EnQueue(SqQueue* Q, ElemType data) {
// 	if ((Q->rear + 1) % MAXSIZE == Q->front) return ERROR;
// 	Q->data[Q->rear] = data;
// 	Q->rear = (Q->rear + 1) % MAXSIZE;
// 	return OK;
// }

// Status DeQueue(SqQueue* Q, ElemType* data) {
// 	if (Q->front == Q->rear) return ERROR;
// 	*data = Q->data[Q->front];
// 	Q->front = (Q->front + 1) % MAXSIZE;
// 	return OK;
// }




#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct vector {
   int* data;
   int size;
} vector;

vector* initVector(int n) {
   vector* v = (vector*)malloc(sizeof(vector));
   v->size = n;
   v->data = (int*)malloc(sizeof(int) * n);
   return v;
}

int vectorSeek(vector* v, int pos) {
   if (pos < 0 || pos >= v->size) return -1;
   return v->data[pos];
}

int insertVector(vector* v, int pos, int val) {
   if (pos < 0 || pos >= v->size) return 0;
   v->data[pos] = val;
   return 1;
}

void clearVector(vector* v) {
   if (v == NULL) return;
   free(v->data);
   free(v);
   return;
}

typedef struct Queue {
   vector* data;
   int size, head, tail, count;
} Queue;

Queue* initQueue(int n) {
   Queue* q = (Queue*)malloc(sizeof(Queue));
   q->data = initVector(n);
   q->size = n;
   q->head = q->tail = q->count = 0;
   return q;
}

int empty(Queue* q) {
   return q->count == 0;
}

int front(Queue* q) {
   return vectorSeek(q->data, q->head);
}

int push(Queue* q, int val) {
   if (q->count == q->size) return 0;
   insertVector(q->data, q->tail, val);
   q->tail = (q->tail + 1) % q->size;
   q->count += 1;
   return 1;
}

int pop(Queue* q) {
   if (empty(q)) return 0;
   q->head = (q->head + 1) % q->size;
   q->count -= 1;
   return 1;
}

void clearQueue(Queue* q) {
   if (q == NULL) return;
   clearVector(q->data);
   free(q);
   return;
}

void outputQueue(Queue* q) {
   printf("Queue : ");
   for (int i = 0; i < q->count; i++) {
       printf("%4d", vectorSeek(q->data, (q->head + i) % q->size));
   }
   printf("\n\n");
   return;
}

int main() {
   srand(time(0));
#define MAX_OP 10
   Queue* q = initQueue(5);
   for (int i = 0; i < MAX_OP; i++) {
       int op = rand() % 5, val = rand() % 100; // 0,1 : pop | 2,3,4 : push
       switch (op) {
       case 0:
       case 1:
           printf("front of queue : %d\n", front(q));
           printf("pop %d from queue\n", front(q));
           pop(q);
           break;
       case 2:
       case 3:
       case 4:
           printf("push %d to queue\n", val);
           push(q, val);
           break;
       }
       outputQueue(q);
   }
   clearQueue(q);
   return 0;
}