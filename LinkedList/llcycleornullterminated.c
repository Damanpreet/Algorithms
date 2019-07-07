#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define TYPE int
#include "linkedlisthelper.c"
#include "hashtablehelper.c"
#include<time.h>

/* Floyd Cycle Detection */
void floydCycleDetection(struct LinkedList *mergedList){
    assert(mergedList);
    struct Node *fptr, *sptr;
    if (mergedList->head->next && mergedList->head->next->next)
    {
        sptr = mergedList->head->next;
        fptr = sptr->next;
    }    
    while(sptr && fptr && fptr->next){
        sptr = sptr->next;
        fptr = fptr->next->next;
        if(sptr==fptr){
            printf("Meeting at value: %d.\n", sptr->val);
            printf("Cycle found.\n");
            return;
        }
    }
    printf("NULL-terminated list.\n");
}

/* Helper function for method 2 - checks if the address is already stored in the hashTable. */
int checkHashTable(struct HashTable *ht, struct Node *curr){
    if(ht->size != 0){
        int count = 0;
        while(count < ht->size){
            if (ht->data[count].loc == curr)
                return 1;
            count+=1;
        }
    } 
    insertHashTable(ht, curr);
    return 0;
}

/* Using Hash Table for Cycle Detection */
void hashCycleDetection(struct LinkedList *llist){
    assert(llist);
    struct Node *curr;
    
    curr = llist->head;
    struct HashTable ht;
    initHashTable(&ht, llist->count);

    while(curr){
        if (checkHashTable(&ht, curr)==1){
            printf("Cycle detected.\n");
            return;
        }
        curr = curr->next;
    }
    printf("NULL-terminated list.\n");
}

/* Method 3 - Cycle Detection in linked list.
            - Loop over every node until the node is not null or a cycle is detected. keep a counter.
                - Run another loop from the beginning until the inner count matches the outer.
                - if the address of any node on the way matches the address of the node of the outer loop, then the cycle is detected.  
                  else, continue. */
void cycleDetectionMethod3(struct LinkedList *llist){
    assert(llist);
    
    struct Node *curr, *innerptr;
    curr = llist->head->next;
    int count_outer, count_inner;
    count_outer = 0;

    while(curr){
        count_outer += 1;
        innerptr = llist->head->next;
        count_inner = 1;

        while(count_inner < count_outer){
            count_inner+=1;
            if(curr == innerptr){
                printf("Cycle detected.\n");
                return;
            }
            innerptr = innerptr->next;
            
        }
        curr = curr->next;
    }
    printf("NULL-terminated list.\n");
}

void cycleDetectionBySorting(struct LinkedList *llist){
    /* Yet to be implemented. */
}

void main(){
    struct LinkedList llist, clist, mlist;
    clock_t start;

    initLinkedList(&llist);
    addLinkedList(&llist, 1, 'b');
    addLinkedList(&llist, 10, 'f');
    addLinkedList(&llist, 5, 'b');
    addLinkedList(&llist, 12, 'f');
    addLinkedList(&llist, 0, 'b');
    addLinkedList(&llist, -9, 'b');
    addLinkedList(&llist, 124, 'f');
    addLinkedList(&llist, 20, 'b');
    addLinkedList(&llist, 192, 'f');
    addLinkedList(&llist, 54, 'b');

    initLinkedList(&clist);
    for(int i=0; i<200; i++){
        addLinkedList(&clist, 11, 'c');
        addLinkedList(&clist, 6, 'c');
        addLinkedList(&clist, 19, 'c');
        addLinkedList(&clist, 16, 'c');
    }
    
    initLinkedList(&mlist); 
    mergeLinkedList(&llist, &clist, &mlist);
    
    printf("size of linked list: %d\n", llist.count);
    printf("size of linked list: %d\n", clist.count);
    printf("size of linked list: %d\n", mlist.count);
    // displayLinkedList(&mlist);

    /* ********** To check if there is a loop. ************* */
    /* Method 1 - Floyd Cycle Detection Algorithm */
    printf("\n*** Method 1 - Using Floyd Cycle Detection Algorithm ***");
    printf("\n*** Merged List ***\n");
    start = clock();
    floydCycleDetection(&mlist);
    printf("Time taken by floyd method to detect loop: %.3f clocks.\n", (double)(clock()-start));
    printf("\n*** Null terminated list ***\n");
    floydCycleDetection(&llist);
    printf("\n*** Circular list ***\n");
    floydCycleDetection(&clist);

    printf("\n*** Method 2 - Using Hash Tables ***");
    printf("\n*** Merged List ***\n");
    start = clock();
    hashCycleDetection(&mlist);
    printf("Time taken by hashTable approach to detect loop: %.3f clocks.\n", (double)(clock()-start));
    printf("\n*** Null terminated list ***\n");
    hashCycleDetection(&llist);
    printf("\n*** Circular list ***\n");
    hashCycleDetection(&clist);

    printf("\n*** Method 3 - Keeping counts and using an inner loop. ***");
    printf("\n*** Merged List ***\n");
    start = clock();
    cycleDetectionMethod3(&mlist);
    printf("Time taken by method 3 to detect loop: %.3f clocks.\n", (double)(clock()-start));
    printf("\n*** Null terminated list ***\n");
    cycleDetectionMethod3(&llist);
    printf("\n*** Circular list ***\n");
    cycleDetectionMethod3(&clist);

    printf("\n*** Method 4 - by sorting ***");
    printf("\nTo be implemented.\n");
}