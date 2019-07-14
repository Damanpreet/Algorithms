#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
#include "linkedlisthelper.c"

struct Node* reverseLL(struct Node *head){
    if (head == NULL)
        return NULL;
    struct Node *curr, *cnext;
    curr = head->next;
    head->next = NULL;

    while(curr){
        cnext = curr->next;
        curr->next = head;
        head = curr; 
        curr = cnext;
    }
    return head;
}

struct Node *recursiveReversal(struct Node *head){
    if(head==NULL)
        return NULL;
    if(!head->next)
        return head;
    struct Node *reverseHead, *cnext = head->next;
    head->next = NULL;
    reverseHead = recursiveReversal(cnext);
    cnext->next = head;
    return reverseHead;
}

void main(){
    struct LinkedList llist;
    /* when there are more than 1 node in the linked list. */
    initLinkedList(&llist);
    addLinkedList(&llist, 10.5, 'f');
    addLinkedList(&llist, 20.2, 'f');
    addLinkedList(&llist, 40.3, 'f');
    addLinkedList(&llist, 120.8, 'b');
    addLinkedList(&llist, -63.1, 'b');
    printf("Linked list before reversal:\n");
    displayLinkedList(&llist);
    llist.head->next = reverseLL(llist.head->next);
    printf("Linked list after reversal.\n");
    displayLinkedList(&llist);

    /* Linked list with a single node. */
    printf("\nLinked list with a single node.\n");
    initLinkedList(&llist);
    addLinkedList(&llist, 1999, 'f');
    printf("Linked list before reversal:\n");
    displayLinkedList(&llist);
    llist.head->next = reverseLL(llist.head->next);
    printf("Linked list after reversal.\n");
    displayLinkedList(&llist);

    /* in case of an empty linked list. */
    printf("\nEmpty Linked list.\n");
    initLinkedList(&llist);
    printf("Linked list before reversal:\n");
    displayLinkedList(&llist);
    llist.head->next = reverseLL(llist.head->next);
    printf("Linked list after reversal.\n");
    displayLinkedList(&llist);

    printf("\nUsing recursion to reverse a linked list.\n");
    /* in case of an empty linked list. */
    printf("Empty Linked list.\n");
    initLinkedList(&llist);
    printf("Linked list before reversal:\n");
    displayLinkedList(&llist);
    llist.head->next = recursiveReversal(llist.head->next);
    printf("Linked list after reversal:\n");
    displayLinkedList(&llist);

    /* Linked list with a single node. */
    printf("\nLinked list with a single node.\n");
    initLinkedList(&llist);
    addLinkedList(&llist, 1999, 'f');
    printf("Linked list before reversal:\n");
    displayLinkedList(&llist);
    llist.head->next = recursiveReversal(llist.head->next);
    printf("Linked list after reversal.\n");
    displayLinkedList(&llist);

    printf("\nLinked list with more than one node.\n");
    addLinkedList(&llist, 10.5, 'f');
    addLinkedList(&llist, 20.2, 'f');
    addLinkedList(&llist, 40.3, 'f');
    addLinkedList(&llist, 120.8, 'b');
    addLinkedList(&llist, -63.1, 'b');
    printf("Linked list before reversal:\n");
    displayLinkedList(&llist);
    llist.head->next = recursiveReversal(llist.head->next);
    printf("Linked list after reversal.\n");
    displayLinkedList(&llist);
}