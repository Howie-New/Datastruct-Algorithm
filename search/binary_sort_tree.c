#include <stdio.h>
#include <stdlib.h>
typedef int Status;
#define true 1
#define false 0

typedef struct BiTNode {
    int data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

Status SearchBST(BiTree T, int key, BiTree father, BiTree *p) {
    if(!T) {
        *p = father;
        return false;
    }
    else if (key == T->data) {
        *p = T;
        return true;
    }
    else if (key < T->data) {
        return SearchBST(T->lchild,key,T,p);
    }
    else {
        return SearchBST(T->rchild,key,T,p);
    }
}

Status InsertBST(BiTree *T, int key) {
    BiTree p,s;
    if (!SearchBST(*T,key,NULL,&p)) {
        s=(BiTree)malloc(sizeof(BiTNode));
        s->data = key;
        s->lchild = s->rchild = NULL;
        if (!p) 
            *T = s;
        else if (key < p->data)
            p->lchild = s;
        else
            p->rchild = s;
        return true;
    }
    else {
        return false;
    }
}

Status DeleteBST (BiTree *T,int key) {
    if (!*T) {
        return false;
    }
    else {
        if (key == (*T)->data) {
            return Delete(T);
        }
        else if (key <(*T)->data) {
            return DeleteBST(&(*T)->lchild,key);
        }
        else {
            return DeleteBST(&(*T)->rchild,key);
        }
    }
}

Status Delete (BiTree *p) {
    BiTree q,s;
    if((*p)->rchild == NULL) {
        q = *p;
        (*p) = (*p)->lchild;
        free(q);
    }
    else if((*p)->lchild == NULL) {
        q = *p;
        (*p) = (*p)->rchild;
        free(q);
    }
    else {
        q = *p;
        s = (*p)->lchild;
        while (s->rchild) {
            q = s;
            s = s->rchild;
        }
        (*p)->data = s->data;
        if(q!=*p) {
            q->rchild = s->lchild;
        }
        else {
            q->lchild = s->lchild;
        }
        free(s);
    }
    return true;
}

void output(BiTree T) {
    if(T == NULL) return ;
    output(T->lchild);
    printf("%d ", T->data);
    output(T->rchild);
    return;
}
int main() {
    int arr[10] = {62,88,58,47,35,73,51,99,37,53};
    BiTree T = NULL;
    for (int i=0;i < 10; i++) {
        InsertBST(&T, arr[i]);
    }
    DeleteBST(&T,51);
    output(T);
    return 0;
}