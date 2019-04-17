#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include "utility.c"

void initQueue(struct Deque *d, int capacity){
    dequeInit(d, capacity);
}

void addQueue(struct Deque *d, TYPE value){
    dequeAddBack(d, value);
}

void _doubleCapacity(struct Deque *d){
    _dequeDoubleCapacity(d);
}

void printQueue(struct Deque *d){
    dequePrint(d);
}

TYPE addCustomer(struct Customer c, int ID, int time){
    c.ID = ID;
    c.time = time;
    return c;
}

void freeQueue(struct Deque *d){
    dequeFree(d);
}

void removeQueue(struct Deque *d){
    dequeDelFront(d);
}

int firstQueue(struct Deque *d)
{
    dequeFront(d);
}

void mergeQueue(struct Deque *q3, struct Deque *q1, struct Deque *q2)
{
    assert(q1!=NULL);
    assert(q2 && q3);
    int initCap = (q1->capacity > q2->capacity)?q1->capacity:q2->capacity;
    // printf("capacity: %d\n",initCap);
    initQueue(q3, initCap);
    int i = 0, j = 0, q1_idx, q2_idx;
    while(i<q1->size && j<q2->size){
        q1_idx = (q1->start+i)%q1->capacity;
        q2_idx = (q2->start+j)%q2->capacity;
        if(q1->data[q1_idx].time < q2->data[q2_idx].time){
            addQueue(q3, q1->data[q1_idx]);
            i++;
        }
        else
        {
            addQueue(q3, q2->data[q2_idx]);
            j++;
        }   
    }
    
    if (i==q1->size){
        while(j<q2->size){
            q2_idx = (j+q2->start)%q2->capacity;
            addQueue(q3, q2->data[q2_idx]);
            j++;
        }
    }
    else{
        while(i<q1->size){
            q1_idx = (i+q1->start)%q1->capacity;
            addQueue(q3, q1->data[q1_idx]);
            i++;
        }
    }

    printf("Merged list: ");
    printQueue(q3);
}

void removeDup(struct Deque *d, TYPE value)
{   
    int i=0, q1_idx, q2_idx;
    while(i<d->size){
        q2_idx = (i+d->start)%d->capacity;
        if(value.ID==d->data[q2_idx].ID){
            // printf("duplicate index: %d\n", value.ID);
            for(int j=i; j<d->size-1; j++){
                q1_idx = (j+d->start)%d->capacity;
                d->data[q1_idx] = d->data[(q1_idx+1)%d->capacity];
            }
            d->size--;
            i--;    
        }
        i++;
    }
}

/* remove all elements from q1 present in q2 */
void removeDupQueue1(struct Deque *q1, struct Deque *q2)
{   
    int q2_idx, i;
    printf("original size of q1: %d\n", q1->size);
    for(i=0; i<q2->size; i++){
        q2_idx = (i+q2->start)%q2->capacity;
        removeDup(q1, q2->data[q2_idx]);
    }
    printf("size of q1 after removing duplicates: %d\n", q1->size);
}


void main(){
    struct Deque q1, q2, q3;
    initQueue(&q1, 4);
    initQueue(&q2, 5);

    struct Customer c, c1, c2, c3, c4, c5, c6, c7, c8, c9, c10;
    c1=addCustomer(c1, 1, 17);
    c2=addCustomer(c2, 2, 18);
    c3=addCustomer(c3, 3, 20);
    c4=addCustomer(c4, 4, 35);
    c5=addCustomer(c5, 5, 45);
    c6=addCustomer(c6, 6, 45);
    c7=addCustomer(c7, 7, 70);
    c8=addCustomer(c8, 8, 71);
    c9=addCustomer(c9, 9, 80);
    c10=addCustomer(c10, 10, 100);

    addQueue(&q1, c1);
    addQueue(&q1, c3);
    addQueue(&q1, c4);
    addQueue(&q1, c5);
    addQueue(&q1, c6);
    addQueue(&q1, c7);
    addQueue(&q1, c8);
    addQueue(&q1, c9);
    addQueue(&q1, c10);

    c3=addCustomer(c3, 3, 21);
    addQueue(&q2, c2);
    addQueue(&q2, c3);
    addQueue(&q2, c6);
    addQueue(&q2, c10);
    
    mergeQueue(&q3, &q1, &q2);
    printf("\nFirst element in the queue: %d\n", firstQueue(&q3));

    /* remove duplicate elements from q1 */
    removeDupQueue1(&q1, &q2);
    mergeQueue(&q3, &q1, &q2);
    
    /* remove q1 and q2 from memory */
    freeQueue(&q1);
    freeQueue(&q2);   
}