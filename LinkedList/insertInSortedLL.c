#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define TYPE float
#include "linkedlisthelper.c"


struct Node* insertNode(struct Node *head, struct Node* new_node){

    struct Node *curr, *prev;
    prev = curr = head; 

    if(!curr){
        return new_node;
    }

    while(curr && curr->val < new_node->val){
        prev = curr;
        curr = curr->next;
    }
    new_node->next = curr;
    prev->next = new_node;
    return head; 
}

void insertSortedLList(struct LinkedList *llist, int val){
    assert(llist);
    
    struct Node *new_node; 
    new_node = (struct Node *)malloc(sizeof(struct Node));
    assert(new_node);
    new_node->val=val;
    new_node->next=NULL;

    llist->head = insertNode(llist->head, new_node);
    llist->count++;
}

void main(){
    struct LinkedList llist;
    initLinkedList(&llist);
    insertSortedLList(&llist, 5);
    insertSortedLList(&llist, 15);
    insertSortedLList(&llist, 1);
    insertSortedLList(&llist, 18);
    insertSortedLList(&llist, 2);
    displayLinkedList(&llist);
}