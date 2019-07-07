#define TYPE int

struct HashVal{
    TYPE val;
    struct Node *loc;
};

struct HashTable{
    struct HashVal *data; 
    int size;
    int tableSize;
};

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


void insertHashTable(struct HashTable *ht, struct Node * curr){
    assert(ht);
    ht->data[ht->size].loc = curr;
    ht->size++;
}