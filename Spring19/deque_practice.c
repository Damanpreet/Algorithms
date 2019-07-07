// #include "Deque.h"
#include "Deque.c"
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

void initQueue(struct Deque *q, int capacity){
    dequeInit(q, capacity);
}

void addQueue(struct Deque *q, TYPE value){
    dequeAddBack(q, value);
}

void printQueue(struct Deque *q){
    dequePrint(q);
}

void removeQueue(struct Deque *q){
    dequeDelFront(q);
}

int frontElement(struct Deque *q){
    return dequeFront(q);
}

void freeQueue(struct Deque *q){
    dequeFree(q);
}

int dequeSize(struct Deque *q){
    return dequeSize(&q);
}

void main(){
    /*Implementing Queue using Deque*/
    struct Deque q1;
    initQueue(&q1, 10);
    addQueue(&q1, 10);
    addQueue(&q1, 11);
    addQueue(&q1, 12);
    printQueue(&q1);
    removeQueue(&q1);
    printQueue(&q1);
    printf("First element of the queue: %d\n", frontElement(&q1));
    freeQueue(&q1);
}
