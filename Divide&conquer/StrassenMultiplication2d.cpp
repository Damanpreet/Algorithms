#include<iostream>
#include<array>

template<size_t SIZE>
void strassenMatrixMul2D(std::array<std::array<int, SIZE>, SIZE> arr1,std::array<std::array<int, SIZE>, SIZE> arr2, std::array<std::array<int, SIZE>, SIZE> &productarr){
    int P1, P2, P3, P4, P5, P6, P7;
    
    P1 = arr1[0][0] * (arr2[0][1] - arr2[1][1]);
    P2 = (arr1[0][0] + arr1[0][1]) * arr2[1][1];
    P3 = (arr1[1][0] + arr1[1][1]) * arr2[0][0];
    P4 = arr1[1][1] * (arr2[1][0] - arr2[0][0]);
    P5 = (arr1[0][0] + arr1[1][1]) * (arr2[0][0] + arr2[1][1]);
    P6 = (arr1[0][1] - arr1[1][1]) * (arr2[1][0] + arr2[1][1]);
    P7 = (arr1[0][0] - arr1[1][0]) * (arr2[0][0] + arr2[0][1]);

    productarr[0][0] = P4 + P5 + P6 - P2;
    productarr[0][1] = P1 + P2;
    productarr[1][0] = P3 + P4;
    productarr[1][1] = P1 + P5 - P3 - P7;
}


int main(){
    std::array<std::array<int, 2>, 2> arr1 = {{{1, 2}, {3, 4}}};
    std::array<std::array<int, 2>, 2> arr2 = {{{5, 6}, {7, 8}}}, productarr;
    strassenMatrixMul2D(arr1, arr2, productarr);

    int i, j;
    for(i=0; i<2; i++){
        for(j=0; j<2; j++){
            std::cout << productarr[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    return 0;
}