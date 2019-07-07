#include "Customer.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void dequeInit(struct Deque *d, int initcap){
    assert(initcap>0);
    d->capacity = initcap;
    d->data = (TYPE *)malloc(sizeof(TYPE)*d->capacity);
    assert(d->data != 0);
    d->size = 0;
    d->start = 0;
}

int dequeSize(struct  Deque *d){
    return d->size;
}

void _dequeDoubleCapacity(struct Deque *d){
    printf("Doubling the capacity to %d.\n", 2*d->capacity);
    TYPE * deq;
    int currCap = d->capacity;
    int i=d->start;

    deq = (TYPE *) malloc(2*currCap*sizeof(TYPE));
    assert(deq!=0);
    
    for(int k=0; k<d->size; k++){
        deq[k] = d->data[i];
        i=i+1;
        if (i>= d->capacity) i=0;
    }
    free(d->data);
    d->data =  deq;
    d->capacity = 2*currCap;
    d->start = 0;
    printf("copied elements in the new array. \n");
    dequePrint(d);
}

void dequeAddBack(struct Deque *d, TYPE value){
    int back_idx;
    if (d->size==d->capacity) _dequeDoubleCapacity(d);
    back_idx = (d->start+d->size)%d->capacity;
    d->data[back_idx].ID = value.ID;
    d->data[back_idx].time = value.time;
    d->size++;
}

void dequeAddFront(struct Deque *d, TYPE value){
    if (d->size == d->capacity) _dequeDoubleCapacity(d);
    d->start--;
    if(d->start < 0) d->start= d->start+d->capacity;
    d->data[d->start].ID = value.ID;
    d->data[d->start].time = value.time;
    d->size++;
}

void dequeDelFront(struct Deque *d){
    if (d->size == 0) return;
    // d->data[d->start] = NULL;
    d->start++;
    if (d->start>=d->capacity) d->start = 0;
    d->size--;   
}

void dequeDelBack(struct Deque *d){
    int back_idx;
    if (d->size == 0) return;
    // back_idx = (d->start+d->size)%d->capacity;
    // d->data[back_idx-1] = NULL;
    d->size--;
}

int dequeFront(struct Deque *d){
    if (d->size==0) return -9999;
    return d->data[d->start].ID;
}

int dequeBack(struct Deque *d){
    if (d->size==0) return -9999;
    int back_idx;
    back_idx = (d->start+d->size)%d->capacity;
    return d->data[back_idx-1].ID;
}

void dequeFree(struct  Deque *d){
    free(d->data);
    d->capacity = d->size = d->start = 0;
}

void dequePrint(struct Deque *d){
    if (d->size==0) printf("No elements");
    int i=d->start;
    for(int k=0; k<d->size; k++){
        printf("%d,",d->data[i].ID);
        printf("%d\n",d->data[i].time);
        i=i+1;
        if (i>=d->capacity) i=0; 
    }
    printf("\n");
}