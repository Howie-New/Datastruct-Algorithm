#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef int Status;
#define MAXSIZE 10
#define TRUE 1
#define FALSE 0

typedef struct 
{
    int *r;
    int length;
}Sqlist;

void swap (Sqlist* L,int i,int j) {
    int temp = L->r[i];
    L->r[i] = L->r[j];
    L->r[j] = temp;
    return;
}

void output(Sqlist* L){
    for(int i = 1;i <= L->length;i++) {
        printf("%d ",L->r[i]);
    }
    printf("\n");
}



void BubbleSort0(Sqlist* L) {
    for(int i = 1;i < L->length;i++){
        for(int j = i + 1;j <= L->length;j++) {
            if(L->r[i] > L->r[j]) {
                swap(L,i,j);
            }
        }
    }
    return;
}

void BubbleSort1(Sqlist* L) {
    for(int i = 1;i < L->length;i++) {
        for(int j = L->length-1;j >= i;j--){
            if(L->r[j] > L->r[j+1]){
                swap(L,j,j+1);
            }
        }
    }
}

void BubbleSort2(Sqlist* L) {
    Status Flag = TRUE;
    for(int i = 1;i < L->length && Flag;i++) {
        Flag = FALSE;
        for(int j = L->length-1;j >= i;j--){
            if(L->r[j] > L->r[j+1]){
                Flag = TRUE;
                swap(L,j,j+1);
            }
        }
    }
}



int main() {
    srand(time(0));
    int arr[11] = {0,45,84,59,85,68,57,12,35,54,65};
    Sqlist* L = (Sqlist*)malloc(sizeof(Sqlist));
    L->r = (int*)malloc(sizeof(int)*(MAXSIZE+1));
    L->r = arr;
    L->length = 10;
    output(L);
    // BubbleSort0(L);
    // BubbleSort1(L);
    BubbleSort2(L);
    output(L);
    free(L);
    return 0;
}