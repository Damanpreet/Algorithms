#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "LinkedlistStack.h"

void initStack(struct LinkStack *stk){
    struct Link *sentinel = (struct Link *)malloc(sizeof(struct Link));
    assert(sentinel!=0);
    sentinel->next = NULL;
    stk->sentinel = sentinel;
}

void addStack(struct LinkStack *stk, TYPE value){
    struct Link *link = (struct Link *)malloc(sizeof(struct Link));
    assert(link!=NULL);
    link->value = value;
    link->next = stk->sentinel->next;
    stk->sentinel->next = link;
}

void popStack(struct LinkStack *stk){
    // if (stk->sentinel->next == NULL){
    //     printf("No element popped. Stack is empty");
    //     return;
    // }
    // if (stk->sentinel->next->next == NULL){
    //     stk->sentinel->next = NULL;
    //     printf("Only one element was in the stack. The stack is now empty.");
    //     return;
    // }
    // struct Link *l = (struct Link *)malloc(sizeof(struct Link));
    // l->next = stk->sentinel->next;
    // stk->sentinel->next->next=NULL;
    // stk->sentinel->next=l->next;
    // free(l);
    struct Link *link = stk->sentinel->next;
    //check if at least one element is present
    if (isEmpty(stk) == 0){
        stk->sentinel->next=link->next;
        free(link);
    }
    else{
        printf("stack is empty\n");
    }
}

int topStack(struct LinkStack *stk){
    if (stk->sentinel->next!=NULL){
        return stk->sentinel->next->value;
    }
    else
    {
        return -1;
    }   
}

int isEmpty(struct LinkStack *stk){
    if (stk->sentinel->next==NULL) return 1;
    else return 0;
}

void StackFree(struct LinkStack *stk){
    while(isEmpty(stk)!=1){
        popStack(stk);
    }
}

void main(){
    struct LinkStack s;
    int top, e;
    initStack(&s);
    e = isEmpty(&s);
    if (e==1) printf("Stack is empty.\n");
    else printf("Stack is not empty.\n");
    popStack(&s);

    addStack(&s, 1);
    addStack(&s, 2);
    addStack(&s, 3);
    addStack(&s, 6);
    
    top = topStack(&s);
    if (top!=-1) printf("Top element is: %d.\n", top);
    else printf("Stack is empty.\n");
    
    popStack(&s);
    popStack(&s);
    popStack(&s);
    
    top = topStack(&s);
    if (top!=-1) printf("Top element is: %d.\n", top);
    else printf("Stack is empty.\n");
    
    e = isEmpty(&s);
    printf("%s", (e==1?"Stack is empty.\n":"Stack is not empty.\n"));

    StackFree(&s);
    e = isEmpty(&s);
    printf("%s", (e==1?"Stack is empty.\n":"Stack is not empty.\n"));
}
