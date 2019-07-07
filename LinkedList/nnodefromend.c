#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#define TYPE int
#define MAX_SIZE 100

struct Node{
    int value;
    struct Node *next;
};

struct LinkedList{
    struct Node *head;
};

struct HashVal{
    int val;
    struct Node *loc;
};

struct HashTable{
    struct HashVal *data; 
    int size;
    int tableSize;
};

/* Initialize linked list. */
void initLinkedList(struct LinkedList *llist){
    struct Node *head_node = (struct Node *)malloc(sizeof(struct Node));
    assert(head_node);
    head_node->next = NULL;
    llist->head = head_node;
}

/* insert a node at the end. */
void insertNode(struct LinkedList *llist, TYPE value){
    struct Node *curr, *new_node;
    curr = llist->head;

    /* create a new node */
    new_node = (struct Node *)malloc(sizeof(struct Node));
    assert(new_node);
    new_node->next = NULL;
    new_node->value = value;

    /* Check if the linked list is NULL. */
    while(curr->next){
        curr = curr->next;
    }
    curr->next = new_node;
}

/* Display linked list. */
void displayLinkedList(struct LinkedList *llist){
    struct Node *curr;
    curr = llist->head->next;
    while(curr){
        printf("%d\n", curr->value);
        curr = curr->next;
    }
}

/* Display nth node from the end. */
void displaylastnnode(struct LinkedList *llist, int position){
    assert (llist);
    if(position<=0){
        printf("-1\nPosition should be greater than 0. Error!\n");
        return;
    }
        
    struct Node *curr, *tail;
    int count;
    count = 0;
    curr = tail = llist->head->next;
    // if (curr) count=1;
    while((count<position) && tail){
        tail=tail->next;
        count+=1;
    }
    if(tail || position==count){
        while(tail){
            tail=tail->next;
            curr=curr->next;
        }
        printf("%d\n", curr->value);
        return;
    }
    else{
        printf("-1\nSize of linkedlist is shorter than the requested element fetch location.\n");
    }
}

/* Fetch the size of linked list - helper function. */
int sizeLinkedList(struct LinkedList *llist){
    assert(llist);
    struct Node *curr;
    int count;
    curr = llist->head->next;
    count = 0;

    while(curr){
        curr = curr->next;
        count+=1;
    }
    return count;
}

/* Method 2 - counting the linked list twice. */
void displaylastnnode2(struct LinkedList *llist, int position){
    assert(llist);
    if(position <= 0){
        printf("-1\nError! Specified position should be greater than 0.\n");
        return;
    }
    struct Node *curr;
    int size, pos, count;
    size = sizeLinkedList(llist);
    if(size<position){
        printf("-1\nError! Size of linked list is shorter than the requested element fetch position.\n");
        return;
    }

    curr = llist->head->next;
    pos = size-position+1;
    count = 1;
    while(count<pos){
        curr=curr->next;
        count+=1;
    }
    printf("%d\n", curr->value);
}

/* intialize hash table - helper function. */
void initHashTable(struct HashTable *ht, int size){
    assert(ht && size);
    int i;
    ht->data = (struct HashVal *)malloc(sizeof(struct HashVal)*size);
    assert(ht->data);

    for(i=0; i<size; i++){
        ht->data[i].loc = (struct Node *)malloc(sizeof(struct Node));
    }
    ht->size = 0;               /* no elements in the hash table currently. */
    ht->tableSize = size;
}

/* Method 3 - Using Hash Tables 
    Storing the element no and address in the hash table as value. */
void displaylastnnode3(struct LinkedList *llist, int position){
    assert(llist);
    if(position <= 0){
        printf("-1\nError! Specified position should be greater than 0.\n");
        return;
    }

    struct HashTable ht;
    initHashTable(&ht, 50);

    struct Node *curr;
    curr = llist->head->next;

    while(curr){
        ht.data[ht.size].val = ht.size - 1;
        ht.data[ht.size].loc = curr;
        curr = curr->next;
        ht.size += 1;
    }

    int pos;
    if(position <= ht.size){
        pos = ht.size - position;   /* position_from_front = size - position + 1 (since array starts from 0, size - position) */
        printf("%d\n", ht.data[pos].loc->value);
        return;
    }
    printf("-1\nError! Size of linked list is shorter than the requested element fetch position.\n");
}

/* Method 4 - Brute force method. 
                - Count the number of elements from every node till the end while traversing. 
                - Stop when the count matched the position value. */
void displaylastnnode4(struct LinkedList *llist, int position){
    assert(llist);
    if(position <= 0){
        printf("-1\nError! Specified position should be greater than 0.\n");
        return;
    }
    
    struct Node *curr, *traversenode;
    int count;

    curr = llist->head->next;
    while(curr){
        count = 0;
        traversenode = curr;
        while(traversenode){
            count+=1;
            traversenode = traversenode->next;
        }
        if(count == position){
            printf("%d\n", curr->value);
            return;
        }
        curr = curr->next;
    }
    printf("-1\nError! Size of linked list is shorter than the requested element fetch position.\n");
}


void main(){
    struct LinkedList llist;
    initLinkedList(&llist);
    insertNode(&llist, 2);
    insertNode(&llist, 3);
    insertNode(&llist, 1);
    insertNode(&llist, 4);
    insertNode(&llist, 5);
    insertNode(&llist, 12);
    insertNode(&llist, 11);
    insertNode(&llist, 121311333);
    insertNode(&llist, 15321);
    insertNode(&llist, 12);
    insertNode(&llist, 7);
    insertNode(&llist, 61);
    insertNode(&llist, 101);

    printf("Nodes of linked list: \n");
    displayLinkedList(&llist);

    int pos;
    
    /* Method 1 - best */
    pos = 100;
    printf("\nValue of the node at position %d from the end: ", pos);
    displaylastnnode(&llist, pos);

    pos = 0;
    printf("\nValue of the node at position %d from the end: ", pos);
    displaylastnnode(&llist, pos);

    pos = 13;
    printf("\nValue of the node at position %d from the end: ", pos);
    displaylastnnode(&llist, pos);

    // /* Method 2 - traversing twice */
    printf("\n*******Using Method 2**********");
    pos = 13;
    printf("\nValue of the node at position %d from the end: ", pos);
    displaylastnnode2(&llist, pos);

    pos = -2;
    printf("\nValue of the node at position %d from the end: ", pos);
    displaylastnnode2(&llist, pos);

    pos = 19;
    printf("\nValue of the node at position %d from the end: ", pos);
    displaylastnnode2(&llist, pos);

    /* Method 3 - using hash table */
    printf("\n*********Using Method3*********");
    pos = 13;
    printf("\nValue of the node at position %d from the end: ", pos);
    displaylastnnode3(&llist, pos);

    pos = 0;
    printf("\nValue of the node at position %d from the end: ", pos);
    displaylastnnode3(&llist, pos);

    pos = 1;
    printf("\nValue of the node at position %d from the end: ", pos);
    displaylastnnode3(&llist, pos);

    // /* Method 4 - brute force method. */
    printf("\n*******Using Method 4**********");
    pos = 7;
    printf("\nValue of the node at position %d from the end: ", pos);
    displaylastnnode4(&llist, pos);

    pos = 0;
    printf("\nValue of the node at position %d from the end: ", pos);
    displaylastnnode4(&llist, pos);

    pos = 1;
    printf("\nValue of the node at position %d from the end: ", pos);
    displaylastnnode4(&llist, pos);

    pos = 13;
    printf("\nValue of the node at position %d from the end: ", pos);
    displaylastnnode4(&llist, pos);
}