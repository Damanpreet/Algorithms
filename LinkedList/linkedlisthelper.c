#define TYPE int

struct Node{
    int val;
    struct Node *next;
};

struct LinkedList{
    struct Node *head;
    struct Node *tail;
    int count;
};

void initLinkedList(struct LinkedList *llist){
    assert(llist);
    struct Node * headSentinel = (struct Node *)malloc(sizeof(struct Node));
    struct Node * tailSentinel = (struct Node *)malloc(sizeof(struct Node));
    assert(headSentinel && tailSentinel);
    headSentinel->next = tailSentinel->next = NULL;
    llist->head = headSentinel;
    llist->tail = tailSentinel;
    llist->count = 0;
}

void addLinkedList(struct LinkedList *llist, TYPE value, char loc){
    assert(llist);

    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    assert(new_node);
    new_node->val = value;
    new_node->next = NULL;

    /* add to the front of the linked list. */
    if(loc == 'f'){
        if(llist->tail->next==NULL) {
            llist->tail->next = new_node;
        }
        new_node->next = llist->head->next; 
        llist->head->next = new_node;
        llist->count += 1;
    }
    /* add to the back of the linked list. */
    if(loc == 'b'){
        if(llist->head->next==NULL) llist->head->next = new_node;
        else{
            new_node->next = llist->tail->next->next;
            llist->tail->next->next = new_node;
        }
        llist->tail->next = new_node;
        llist->count += 1;
    }

    /* add in circular fashion. */
    if(loc == 'c'){
        if(llist->head->next==NULL){
            llist->head->next = new_node;
        }
        else{
            llist->tail->next->next = new_node;
        }
        llist->tail->next = new_node;
        new_node->next = llist->head->next;
        llist->count += 1;
    }
}

/* Helper function - to copy null-terminated list to another list */
void copyLinkedList(struct LinkedList *llist, struct LinkedList *mlist){
    assert(llist && mlist);
    
    struct Node *curr;
    curr = llist->head->next;
    while(curr){
        addLinkedList(mlist, curr->val, 'b');
        curr = curr->next;
    }
}

/* Helper function - Merge the linked list with the circular linked list. */
void mergeLinkedList(struct LinkedList *llist, struct LinkedList *clist, struct LinkedList *mlist){
    assert(llist && clist && mlist);
    copyLinkedList(llist, mlist);
    mlist->tail->next->next = clist->head->next;
    mlist->count += clist->count;
}

void displayLinkedList(struct LinkedList *llist){
    int count = 0;
    struct Node *curr;
    curr = llist->head->next;
    
    while(count<llist->count+1 && curr){
        printf("%d\n", curr->val);
        curr = curr->next;
        count += 1;
    }
}