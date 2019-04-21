#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define TYPE int

struct dynArr{
    TYPE *data;
    int size;
    int capacity;
};

/* Binary search */
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

/* Utility functions */
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
}

void addArr(struct dynArr *arr, TYPE val){
    if (arr->size>=arr->capacity) __doubleArrCapacity(arr);
    arr->data[arr->size] = val;
    arr->size += 1;
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

/* Union of arrays */
void unionArray(struct dynArr *arr1, struct dynArr *arr2, struct dynArr *unionArr){
    initArr(unionArr, arr1->size+arr2->size);
    int i=0, j=0, k=0;
    while(i<arr1->size && j<arr2->size){
        if(arr1->data[i] < arr2->data[j]){
            if((k==0)||(unionArr->data[k-1]!=arr1->data[i])){
                addArr(unionArr, arr1->data[i]);
                k++;
            }
            i++;
        }
        else{
            if((k==0)||(unionArr->data[k-1]!=arr1->data[i])){
                addArr(unionArr, arr2->data[j]);
                k++;
            }
            j++;
        }
    }
    while(i<arr1->size){
        if(unionArr->data[k-1]!=arr1->data[i])
        {
            addArr(unionArr, arr1->data[i]);
            k++;
        }
        i++;
    }
    while(j<arr2->size){
        if(unionArr->data[k-1]!=arr2->data[j])
        {
            addArr(unionArr, arr2->data[j]);
            k++;
        }
        j++;
    }
}

/* Intersection of arrays */
void intersectArray(struct dynArr *arr1, struct dynArr *arr2, struct dynArr *intersectArr){
    initArr(intersectArr, arr1->size<arr2->size?arr1->size:arr2->size);
    int i=0, j=0, k=0;
    while(i<arr1->size && j<arr2->size){
        if(arr1->data[i]<arr2->data[j])
            i++;
        else if(arr1->data[i]>arr2->data[j])
            j++;
        else
        {
            if(k==0 || intersectArr->data[k-1]!=arr1->data[i]){
                addArr(intersectArr, arr1->data[i]);
                k++;
            }
            i++; j++;
        }
    }
}

/* Difference of array */
void diffArray(struct dynArr *arr1, struct dynArr *arr2, struct dynArr *diff){
    initArr(diff, arr1->size);
    int i=0, j=0, k=0;
    while(i<arr1->size && j<arr2->size){
        if(arr1->data[i] < arr2->data[j]){
            if(i==0 || arr1->data[i]!=arr1->data[i-1])
                addArr(diff, arr1->data[i]);
            i++;
        }
        else if(arr1->data[i] > arr2->data[j]){
            j++; 
        }
        else{
            i++;
            j++;
        }
        k++;
    }

    while(i<arr1->size){
        addArr(diff, arr1->data[i]);
        i++;
        k++;
    }
}


void main(){
    struct dynArr array1, array2;
    initArr(&array1, 10);
    addArr(&array1, 1);
    addArr(&array1, 1);
    addArr(&array1, 3);
    addArr(&array1, 5);
    addArr(&array1, 6);
    addArr(&array1, 7);
    addArr(&array1, 10);
    sortedAdd(&array1, 8);
    addArr(&array1, 38);
    
    initArr(&array2, 20);
    addArr(&array2, 1);
    addArr(&array2, 2);
    addArr(&array2, 4);
    addArr(&array2, 9);
    addArr(&array2, 10);
    addArr(&array2, 38);
    sortedAdd(&array2, 46);

    struct dynArr unionArr, intersectArr, diffArr1, diffArr2;
    
    unionArray(&array1, &array2, &unionArr);
    printf("Union Array: \n");
    printArr(&unionArr);
    
    intersectArray(&array1, &array2, &intersectArr);
    printf("Intersected Array: \n");
    printArr(&intersectArr);

    diffArray(&array1, &array2, &diffArr1);
    printf("Difference (Array1 - Array2): \n");
    printArr(&diffArr1);

    diffArray(&array2, &array1, &diffArr2);
    printf("Difference (Array2 - Array1): \n");
    printArr(&diffArr2);
}