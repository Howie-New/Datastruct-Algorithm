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

void SimpleSelectionSort_1(Sqlist* L) {
    int min;
    for(int i = 1;i < L->length;i++) {
        min = i;
        for(int j = i + 1;j <= L->length;j++){
            if(L->r[min] > L->r[j]){
                min = j;
            }
        }
        if (i != min){
            swap(L,min,i);
        }
    }
}


int main() {
    srand(time(0));
    int arr[11] = {0,9,1,5,8,3,7,4,6,2,10};
    Sqlist* L = (Sqlist*)malloc(sizeof(Sqlist));
    L->r = (int*)malloc(sizeof(int)*(MAXSIZE+1));
    L->r = arr;
    L->length = 10;
    output(L);
    SimpleSelectionSort(L);
    output(L);
    free(L); 
    return 0;
}