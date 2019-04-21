#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include "llistqueue.h"


void initQueue(struct LinkQueue *q){
    struct Link *sentinel = (struct Link *)malloc(sizeof(struct Link));
    assert(sentinel!=NULL);
    sentinel->next = NULL;
    q->head = sentinel;
    q->tail = sentinel;
}

void addQueue(struct LinkQueue *q, TYPE val){
    struct Link *new_node = (struct Link *)malloc(sizeof(struct Link));
    assert(new_node!=NULL);
    new_node->value = val;
    new_node->next = NULL;
    q->tail->next = new_node;
    q->tail = new_node;
}

void removeQueue(struct LinkQueue *q){
    if(isEmpty(q)!=1){
        struct Link *curr = q->head->next;
        q->head->next = curr->next;
        if(q->head->next == NULL) q->tail=q->head;
        free(curr);
    }
}

int isEmpty(struct LinkQueue *q){
    int ret_val = (q->head==q->tail)?1:0;
    return ret_val;
}

void printQueue(struct LinkQueue *q){
    struct Link *curr = q->head->next;
    while(curr!=NULL){
        printf("%d\n",curr->value);
        curr = curr->next;
    }
}

void main(){
    struct LinkQueue q;//*q = (struct LinkQueue *)malloc(sizeof(struct LinkQueue));
    // assert(q!=NULL);
    initQueue(&q);
    addQueue(&q, 1);
    addQueue(&q, 3);
    addQueue(&q, 2);
    printQueue(&q);
    removeQueue(&q);
    printQueue(&q);
}