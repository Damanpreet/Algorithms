#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include "Deque.h"

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
    d->data[back_idx] = value;
    d->size++;
}

void dequeAddFront(struct Deque *d, TYPE value){
    if (d->size == d->capacity) _dequeDoubleCapacity(d);
    d->start--;
    if(d->start < 0) d->start= d->start+d->capacity;
    d->data[d->start] = value;
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

TYPE dequeFront(struct Deque *d){
    if (d->size==0) return -9999;
    return d->data[d->start];
}

TYPE dequeBack(struct Deque *d){
    if (d->size==0) return -9999;
    int back_idx;
    back_idx = (d->start+d->size)%d->capacity;
    return d->data[back_idx-1];
}

void dequeFree(struct  Deque *d){
    free(d->data);
    d->capacity = 0;
    d->size = 0;    
    d->start = 0;
}

void dequePrint(struct Deque *d){
    if (d->size==0) printf("No elements");
    int i=d->start;
    for(int k=0; k<d->size; k++){
        printf("%d  ",d->data[i]);
        i=i+1;
        if (i>=d->capacity) i=0; 
    }
    printf("\n");
}

void main(){
    struct Deque q1;
    dequeInit(&q1, 1); //initializing deque
    printf("current size of queue: %d\n", dequeSize(&q1));
    
    /* adding elements to the deque */
    dequeAddBack(&q1, 3); 
    dequeAddFront(&q1, 2);
    dequeAddFront(&q1, 1);
    dequeAddBack(&q1, 5);
    dequeAddFront(&q1, 2);
    dequeAddBack(&q1, 6);
    dequeAddFront(&q1, 5);
    dequeAddFront(&q1, 1000);
    dequeAddFront(&q1, 12);
    
    //Printing elements 
    printf("printing queue: ");
    dequePrint(&q1);
    printf("\ncurrent size of queue: %d\n", dequeSize(&q1));
    printf("Element in the front of the queue: %d\n", dequeFront(&q1));
    printf("Element at the end of the queue: %d\n", dequeBack(&q1));
    
    //Delete one element each from back and front
    dequeDelBack(&q1);
    dequeDelFront(&q1);
    printf("\n1 element deleted each from front and end of the deque.\n");
    printf("Element in the front of the queue: %d\n", dequeFront(&q1));
    printf("Element at the end of the queue: %d\n", dequeBack(&q1));
    dequeDelBack(&q1);
    dequeDelBack(&q1);
    dequeDelFront(&q1);
    printf("\n1, 2 elements deleted from front and end of the deque respectively.\n");
    printf("Element at the end of the queue: %d\n", dequeBack(&q1));
    printf("Element in the front of the queue: %d\n", dequeFront(&q1));
    
    //Free up space
    dequeFree(&q1);
    printf("\ncurrent size of queue: %d\n", dequeSize(&q1));
    printf("Printing queue: ");
    dequePrint(&q1);
}

