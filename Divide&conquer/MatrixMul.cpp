#include<iostream>
#include<array>

template<std::size_t SIZE>
void matrixmul(std::array<std::array<int, SIZE>, SIZE>arr1, std::array<std::array<int, SIZE>, SIZE>arr2, std::array<std::array<int, SIZE>, SIZE> &productarr){
    int i, j, k, n;
    n = arr1.size();

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            for(k=0; k<n; k++){
                productarr[i][j] += (arr1[i][k] * arr2[k][j]);
            }
        }
    }
}

// template<size_t SIZE>
// void matrixmulsquarematrix(std::array<std::array<int, SIZE>, SIZE>arr1, std::array<std::array<int, SIZE>, SIZE>arr2, std::array<std::array<int, SIZE>, SIZE> &productarr){
//     int n;
//     n = arr1.size();

//     if(n=1)
//         productarr = arr1*arr2;
//     else{
//         for(int )
//     }    
// }

int main(){
    std::array<std::array<int, 2>, 2> arr1 = {{{1, 2}, {3, 4}}};
    std::array<std::array<int, 2>, 2> arr2 = {{{5, 6}, {7, 8}}};
    std::array<std::array<int, 2>, 2> productarr = {{{0, 0}, {0, 0}}};

    matrixmul(arr1,arr2,productarr);

    int i, j;
    for(i=0; i<2; i++){
        for(j=0; j<2; j++){
            std::cout << productarr[i][j] << "\t";
        }
        std::cout << std::endl;
    } 

    // std::array<std::array<int, 2>, 2> productarr = {{{0, 0}, {0, 0}}};
    // matrixmulsquarematrix(arr1, arr2, productarr);

    return 0;
}