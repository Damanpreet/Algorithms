#define TYPE int
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

struct dynArr{
    TYPE *data;
    int size;
    int capacity;
};


void initArr(struct dynArr *arr, int cap){
    assert(cap>0);
    arr->size = 0;
    arr->capacity = cap;
    arr->data = (TYPE *)malloc(sizeof(TYPE)*arr->capacity);
    assert(arr!=NULL);
}

void printArr(struct dynArr *arr){
    int i;
    printf("Array: ");
    for(i=0; i<arr->size; i++)
        printf("%d\n", arr->data[i]);
}

void __doubleArrCapacity(struct dynArr *arr){
    TYPE *oldbuffer;
    oldbuffer = arr->data;
    int oldsize = arr->size;
    initArr(arr, 2*arr->capacity);
    for(int i=0; i<oldsize; i++){
        arr->data[i] = oldbuffer[i];
    }   
    arr->size = oldsize;
    free(oldbuffer);
    printf("capacity doubled. new cap: %d.\n", arr->capacity);
}

void addArr(struct dynArr *arr, TYPE val){
    if (arr->size>=arr->capacity) __doubleArrCapacity(arr);
    arr->data[arr->size] = val;
    arr->size += 1;
}

int bSearch(TYPE *data, int size, TYPE value){
    int low = 0;
    int high = size;
    int mid;
    while(low < high){
        mid = (low+high)/2;
        if(data[mid] < value)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

int containsArr(struct dynArr *arr, TYPE value){
    printArr(arr);
    int idx = bSearch(arr->data, arr->size, value);
    if (idx<arr->size && arr->data[idx]==value)
        return idx;
    return -1;
}

void __addAt(struct dynArr *arr, int pos, TYPE value){
    if(arr->size >= arr->capacity) __doubleArrCapacity(arr);
    arr->size+=1;
    for(int i=arr->size-2; i>=pos; i--)
        arr->data[i+1] = arr->data[i];   
    arr->data[pos] = value;
}

void sortedAdd(struct dynArr *arr, TYPE value){
    int idx = bSearch(arr->data, arr->size, value);
    __addAt(arr, idx, value);
}

void __removeAt(struct dynArr *arr, int index){
    for(int i=index; i<arr->size-1; i++)
        arr->data[i] = arr->data[i+1];
    arr->size-=1;
}

int sortedRemoveArr(struct dynArr *arr, TYPE value){
    int idx = bSearch(arr->data, arr->size, value);
    if (idx < arr->size && arr->data[idx]==value)
        __removeAt(arr, idx);
}

void main(){
    struct dynArr array;
    initArr(&array, 1);
    addArr(&array, 1);
    addArr(&array, 2);
    addArr(&array, 5);
    addArr(&array, 10);
    addArr(&array, 11);
    addArr(&array, 18);
    int idx = containsArr(&array, 14);
    if (idx!=-1)     printf("found at index: %d.\n", idx);
    else     printf("not found in the array.\n");
    
    sortedAdd(&array, 6);
    // printArr(&array);
    idx = containsArr(&array, 6);
    if (idx!=-1)     printf("found at index: %d.\n", idx);
    else     printf("not found in the array.\n");

    sortedRemoveArr(&array, 10);
    printf("Removed 10 from array. New array: \n");
    printArr(&array);
}