#include "llistbag.h"

void initBag(struct LlistBag *db){
    db->frontSentinel = (struct dlink *)malloc(sizeof(struct dlink));
    assert(db->frontSentinel!=0);
    db->backSentinel = (struct dlink *)malloc(sizeof(struct dlink));
    assert(db->backSentinel!=0);
    db->frontSentinel->next = db->backSentinel;
    db->backSentinel->prev = db->frontSentinel;
    db->size = 0;
}

void __addDlist(struct LlistBag *db, struct dlink *lnk, struct dlink *new_node){
    new_node->next = lnk;
    new_node->prev = lnk->prev;
    lnk->prev->next = new_node;
    lnk->prev = new_node;
    db->size += 1;
}

void addBag(struct LlistBag *db, TYPE val){
    assert(db);
    
    struct dlink *new_node = (struct dlink *)malloc(sizeof(struct dlink));
    assert(new_node!=NULL);
    new_node->value = val;

    __addDlist(db, db->frontSentinel->next, new_node);
    printf("added into bag!\n");
}


void removeBag(struct LlistBag *db, TYPE val){
    assert(!isEmpty(db)==1);
    struct dlink *current;
    current = db->frontSentinel->next;
    while(current!=db->backSentinel){
        if(current->value==val){
            current->prev->next = current->next;
            current->next->prev = current->prev;
        }
        current=current->next;
    }
    db->size -= 1;
}

int isEmpty(struct LlistBag *db){
    return (db->size==0)?1:0;
}

int containsBag(struct LlistBag *db, TYPE val){
    assert(!isEmpty(db)==1);
    struct dlink *current; 
    current = db->frontSentinel->next;
    assert(current!=0);
    while(current != db->backSentinel){
        if(current->value == val){
            return 1;
        }
        current=current->next;
    }
    return 0;
}

void main(){
    struct LlistBag listbag;
    int ret_val;
    
    initBag(&listbag);
    addBag(&listbag, 1);
    addBag(&listbag, 10);
    addBag(&listbag, 9);
    addBag(&listbag, 4);
   
    ret_val = containsBag(&listbag, 9);
    if (ret_val == 1) printf("9 is in bag.\n");
    else printf("9 is not in bag.\n");

    removeBag(&listbag, 4);
    ret_val = containsBag(&listbag, 4);
    if (ret_val == 1) printf("4 is in bag.\n");
    else printf("4 is not in bag.\n");
}