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
    // printf("capacity doubled. new cap: %d.\n", arr->capacity);
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

int sortedArrayRemove(struct dynArr *arr, TYPE value){
    int idx = bSearch(arr->data, arr->size, value);
    if (idx < arr->size && arr->data[idx]==value)
        __removeAt(arr, idx);
}

void mergeArray(struct dynArr *arr1, struct dynArr *arr2, struct dynArr *MergedArr){
    int i=0, j=0, k=0;
    initArr(MergedArr, arr1->size+arr2->size);
    while(i<arr1->size && j<arr2->size){
        MergedArr->size+=1;
        if(arr1->data[i] > arr2->data[j])
        {    
            MergedArr->data[k]=arr2->data[j];
            j++;
        }
        else
        {
            MergedArr->data[k]=arr1->data[i];
            i++;
        }
        k++;
        
    }
    while(j<arr2->size){
        MergedArr->data[k] = arr2->data[j];
        j++; k++;
        MergedArr->size+=1;
    }
    while(i<arr1->size){
        MergedArr->data[k] = arr1->data[i];
        i++; k++;
        MergedArr->size+=1;
    }   
}

void main(){
    struct dynArr array1, array2;
    initArr(&array1, 1);
    addArr(&array1, 1);
    addArr(&array1, 2);
    addArr(&array1, 5);
    addArr(&array1, 10);
    addArr(&array1, 11);
    addArr(&array1, 18);
    sortedAdd(&array1, 6);
    
    initArr(&array2, 20);
    addArr(&array2, 3);
    addArr(&array2, 6);
    addArr(&array2, 17);
    addArr(&array2, 20);
    addArr(&array2, 31);
    addArr(&array2, 38);
    sortedAdd(&array2, 46);

    struct dynArr MergedArr;
    mergeArray(&array1, &array2, &MergedArr);
    printf("Merged Array is: ");
    printArr(&MergedArr);
}