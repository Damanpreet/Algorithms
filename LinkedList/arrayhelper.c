#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
// #include "linkedlisthelper.c"
#define TYPE_NODE struct Node


/* 
    Merge operation in merge sort algorithm.
    Compare the elements and merge them in ascending order.
*/
void merge(TYPE_NODE *arr[], int l, int m, int r){
    int i, j, k, nl, nr;
    nl = m-l+1;
    nr = r-m;
    TYPE_NODE *left[nl], *right[nr];

    // Create two temporary arrays to hold left and right subarrays.
    for(i=0; i<nl; i++){
        left[i] = arr[l+i];
    }
    for(j=0; j<nr; j++){
        right[j] = arr[m+1+j];
    }

    i=0, j=0, k=l;
    while(i<nl && j<nr){
        if(left[i] > right[j]){
            arr[k] = right[j];
            j++;
        }
        else{
            arr[k] = left[i];
            i++;
        }
        k++; 
    }

    while(i < nl){
        arr[k] = left[i];
        k++; i++;
    }

    while(j < nr){
        arr[k] = right[j];
        j++; k++;
    }
}

/* 
    Merge sort
    Inputs - 1. Array to be sorted
    2. position of the leftmost element
    3. position of the rightmost element
*/
void mergeSort(TYPE_NODE *arr[], int l, int r){
    int mid;
    mid = (l+r)/2;

    if(l<r){
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
    }
    merge(arr, l, mid, r);    
}

/* For testing */
// void main(){
//     TYPE_NODE arr[20];
//     int j=50;
//     for(int i=0; i<10; i++){
//         arr[i]=j;
//         j-=3;
//     }
//     mergeSort(arr, 0, 9);
    
//     for(int i=0; i<10; i++){
//         printf("%d\n", arr[i]);
//     }
// }
