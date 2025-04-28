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

void InsertSort(Sqlist* L) {
    int i,j;
    for(i = 2;i <= L->length;i++){
        if(L->r[i-1] > L->r[i]){
            L->r[0] = L->r[i];
            for(j = i - 1;L->r[j] >L->r[0];j--){
                L->r[j + 1] = L->r[j];
            }
            L->r[j + 1] = L->r[0];
        }
    }
    return;
}

int main() {
    srand(time(0));
    int arr[11] = {0,9,1,5,8,3,7,4,6,2,10};
    Sqlist* L = (Sqlist*)malloc(sizeof(Sqlist));
    L->r = (int*)malloc(sizeof(int)*(MAXSIZE+1));
    L->r = arr;
    L->length = 10;
    output(L);
    InsertSort(L);
    output(L);
    free(L); 
    return 0;
}