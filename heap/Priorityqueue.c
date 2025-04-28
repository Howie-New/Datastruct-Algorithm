#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define	SIZEOF_PRIORITYQUEUE 20
#define ROOT 1
#define GREATER >
#define FATHER(i) ((i) / 2)
#define LEFT(i) ((i) * 2)
#define RIGHT(i) ((i) * 2 + 1)
void swap(int* data, int i, int j) {
	int temp = data[i];
	data[i] = data[j];
	data[j] = temp;
	return;
}
typedef struct Priorityqueue {
	int* __data, * data;
	int n, size;
}Priorityqueue;

Priorityqueue* Init_Priorityqueue(int size) {
	Priorityqueue* p = (Priorityqueue*)malloc(sizeof(Priorityqueue));
	p->__data = (int*)malloc(sizeof(int) * size);
	p->data = p->__data - 1;
	p->size = size;
	p->n = 0;
	return p;
}

int empty(Priorityqueue* p) {
	return p->n == 0;
}

int full(Priorityqueue* p) {
	return p->n == p->size;
}

int top(Priorityqueue* p) {
	return p->data[ROOT];
}

void clear(Priorityqueue* p) {
	if (p == NULL) return;
	free(p->__data);
	free(p);
	return;
}

void up_update(int* data, int i) {
	if (i == ROOT) return;
	if (data[i] GREATER data[FATHER(i)]) {
		swap(data, i, FATHER(i));
		up_update(data, FATHER(i));
	}
	else {
		return;
	}
}

void down_update(int* data, int i, int n) {
	while (LEFT(i) <= n) {
		int ind = i, left = LEFT(i), right = RIGHT(i);
		if (data[left] GREATER data[i]) ind = left;
		if (right <= n && data[right] GREATER data[ind]) ind = right;
		if (ind == i) break;
		swap(data, i, ind);
		i = ind;
	}
	return;
}

int push(Priorityqueue* p, int x) {
	if (full(p)) return 0;
	p->n += 1;
	p->data[p->n] = x;
	up_update(p->data, p->n);
	return 1;
}

int pop(Priorityqueue* p) {
	if (empty(p)) return 0;
	p->data[ROOT] = p->data[p->n];
	p->n -= 1;
	down_update(p->data, ROOT, p->n);
	return 1;
}

void output_Priorityqueue(Priorityqueue* p) {
	printf("Priotityqueue(%d)\n", p->n);
	for (int i = 1; i <= p->n; i++) {
		printf("%d ", p->data[i]);
	}
	printf("\n\n");
}

int main() {
	Priorityqueue* p = Init_Priorityqueue(SIZEOF_PRIORITYQUEUE);
	srand(time(0));
	int val;
	//for (int i = 0; i < 20; i++) {
	//	if (rand() % 2 == 1) {
	//		val = rand() % 100;
	//		printf("insert %d into Priorityqueue\n",val);
	//		push(p, val);
	//		output_Priorityqueue(p);
	//	}
	//	else {
	//		printf("pop %d from Priorityqueue\n", top(p));
	//		pop(p);
	//		output_Priorityqueue(p);
	//	}
	//}
	for (int i = 0; i < 10; i++) {
		val = rand() % 100;
		printf("insert %d into Priorityqueue\n", val);
		push(p, val);
		output_Priorityqueue(p);
	}		
	for (int i = 0; i < 5; i++) {
		printf("pop %d from Priorityqueue\n", top(p));
		pop(p);
		output_Priorityqueue(p);
	}
	clear(p);
	return 0;
}