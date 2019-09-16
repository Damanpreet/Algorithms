#include<iostream>
#include<array>

template<std::size_t SIZE>

void insertionSort(std::array<int, SIZE> &A, int len){
    int i, j, key;

    for(j=1; j<len; j++){
        key = A[j];
        i = j-1;
        while (i>=0 and A[i] > key){
            A[i+1] = A[i];
            i--;
        }
        A[i+1] = key;
    }
}

int main(){
    
    // int A[] = {10, 15, 2, 4, 8};
    // std::cout << "Length of array: " << sizeof(A) / sizeof(*A);

    std::array<int, 10> A;
    A = {10, 15, 2, 4, 8, 0, -1, 89};
    int Alen = A.size();
    std::cout << "Length of array: " << Alen;
    std::cout << "Unsorted array: \n";
    int i;
    for(i=0; i<Alen; i++){
        std::cout << A[i] << "\t";
    }
    std::cout << "\n";

    insertionSort(A, Alen);
    
    for(i=0; i<Alen; i++){
        std::cout << A[i] << "\t";
    }
    std::cout << "\n";

    return 0;
}