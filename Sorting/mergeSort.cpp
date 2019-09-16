#include<iostream>
#include<array>
#include<vector>

template<std::size_t SIZE>

void merge(std::array<int, SIZE> &A, int p, int q, int r){
    
    int n1, n2, i, j, k;
    n1 = q-p+1;
    n2 = r-q;
    std::vector<int> L(n1+1);
    std::vector<int> R(n2+1);

    for(i=0; i<n1; i++){
        L[i] = A[p+i];
    }
    L[i] = 999999;
    for(i=0; i<n2; i++){
        R[i] = A[q+i+1];
    }
    R[i] = 999999;

    i=0, j=0;
    for(k=p; k<=r; k++){
        if(L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }
        else{
            A[k] = R[j];
            j++;
        }
    }
}

template<std::size_t SIZE>

void mergeSort(std::array<int, SIZE> &A, int p, int r){
    int q;
    if(p<r){
        q = (p+r)/2;
        std::cout << "q:" << q << std::endl;
        mergeSort(A, p, q);
        mergeSort(A, q+1, r);
        merge(A, p, q, r);
    }
}

int main(){
    std::array<int, 10> A;
    int i;
    A = {13, 14, 1, 199, -200, 37, 8, 3, 4, -44};

    std::cout << "After sorting: ";
    for(i=0; i<10; i++){
        std::cout << A[i] << "\t";
    }
    std::cout << std::endl;

    mergeSort(A, 0, 9);
    
    std::cout << "After sorting: ";
    for(i=0; i<10; i++){
        std::cout << A[i] << "\t";
    }
    std::cout << std::endl;

    return 0;
}