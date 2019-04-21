#include "llistdeque.h"

void initDeque(struct listDeque *deque){
    deque->frontSentinel = (struct dlink *)malloc(sizeof(struct dlink));
    deque->backSentinel = (struct dlink *)malloc(sizeof(struct dlink));
    assert(deque->frontSentinel != NULL);
    assert(deque->backSentinel != NULL);
    deque->frontSentinel->next = deque->backSentinel;
    deque->backSentinel->prev = deque->frontSentinel;
    deque->size=0;
}

void __addDeque(struct listDeque *deque, struct dlink *link, struct dlink *node){
    node->next = link;
    node->prev = link->prev;
    link->prev->next = node;
    link->prev = node;
    deque->size += 1;
}

void __removeDeque(struct listDeque *deque, struct dlink *link){
    link->next->prev = link->prev;
    link->prev->next = link->next;
    free(link);
    deque->size -= 1;
}

void addFrontDeque(struct listDeque *deque, TYPE value){
    struct dlink *node = (struct dlink *)malloc(sizeof(struct dlink));
    assert(node!=NULL);

    node->value = value;
    __addDeque(deque, deque->frontSentinel->next, node);
    printf("added into the front!\n");
}

void addBackDeque(struct listDeque *deque, TYPE value){
    struct dlink *node = (struct dlink *)malloc(sizeof(struct dlink));
    assert(node!=NULL);

    node->value = value;
    __addDeque(deque, deque->backSentinel, node);
    printf("added into the back!\n");
}

void removeFrontDeque(struct listDeque *deque){
    if (isEmpty(deque)!=1){
        __removeDeque(deque, deque->frontSentinel->next);
        printf("removed from the front!\n");
    }
}

void removeBackDeque(struct listDeque *deque){
    if (isEmpty(deque)!=1){
        __removeDeque(deque, deque->backSentinel->prev);
        printf("removed from the back!\n");
    }
}

TYPE frontDeque(struct listDeque *deque){
    if (isEmpty(deque)!=1){
        return deque->frontSentinel->next->value;
    }
    return -1;
}

TYPE backDeque(struct listDeque *deque){
    if(isEmpty(deque)!=1){
        return deque->backSentinel->prev->value;
    }
    return -1;
}

int isEmpty(struct listDeque *deque){
    return (deque->size == 0)?1:0;
}

void freeDeque(struct listDeque *deque){
    while(isEmpty(deque))
        removeFrontDeque(deque);

    free(deque->frontSentinel);
    free(deque->backSentinel);
    deque->frontSentinel = deque->backSentinel = NULL;
}

void main(){
    struct listDeque deque;
    TYPE ret_val;

    initDeque(&deque);    
    ret_val = backDeque(&deque);
    if (ret_val != -1){
        printf("Element from the back is : %d.\n", ret_val);
    } 
    else
    {
        printf("Deque is empty.\n");
    }

    addFrontDeque(&deque, 1);
    addBackDeque(&deque, 10);
    addFrontDeque(&deque, 12);

    ret_val = backDeque(&deque);
    if (ret_val != -1){
        printf("Element from the back is : %d.\n", ret_val);
    } 
    else
    {
        printf("Deque is empty.\n");
    }

    removeBackDeque(&deque);
    ret_val = backDeque(&deque);
    if (ret_val != -1){
        printf("Element from the back is : %d.\n", ret_val);
    } 
    else
    {
        printf("Deque is empty.\n");
    }
    freeDeque(&deque);
}