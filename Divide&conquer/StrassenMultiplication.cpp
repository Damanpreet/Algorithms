
// Source: https://www.sanfoundry.com/cpp-program-implement-strassens-algorithm/

#include<iostream>
#include<assert.h>

#define M 2
#define N (1<<M) 
// generates a bit mask in which only Mth bit is set. Here N = 2.

typedef int mat[N][N];
typedef struct
{
    int ra, rb, ca, cb;
} corners;

void printMat(mat arr, std::string mname){
    int i, j;
    std::cout << "Printing " << mname << std::endl;
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            std::cout << arr[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

void set(mat &arr, corners c, int val){
    int i, j;
    for(i=c.ra; i<c.rb; i++){
        for(j=c.ca; j<c.cb; j++){
            arr[i][j] = val;
        }
    }
}

void findCorners(corners c, int i, int j, corners &ci){
    int rn, cn;
    rn=c.ra + (c.rb - c.ra)/2;
    cn=c.ca + (c.cb - c.ca)/2;
    ci=c;

    if(i==0){
        ci.rb = rn;
    }
    else{
        ci.ra = rn;
    }

    if(j==0){
        ci.cb = cn;
    }
    else{
        ci.ca = cn;
    }
}

// Add the matrices
void addmat(mat A, mat B, mat &C, corners ai, corners bi, corners ci){
    int rn, cn, i, j;

    rn = ai.rb - ai.ra;
    cn = ai.cb - ai.ca;

    for(i=0; i<rn; i++){
        for(j=0; j<cn; j++){            
            C[ci.ra+i][ci.ca+j] = A[ai.ra+i][ai.ca+j] + B[bi.ra+i][bi.ca+j]; 
        }
    }
}

// Subtract the matrices
void subtract(mat A, mat B, mat &C, corners ai, corners bi, corners ci){
    int rn, cn, i, j;

    rn = ai.rb - ai.ra;
    cn = ai.cb - ai.ca;

    for(i=0; i<rn; i++){
        for(j=0; j<cn; j++){
            C[ci.ra+i][ci.ca+j] = A[ai.ra+i][ai.ca+j] - B[bi.ra+i][bi.ca+j]; 
        }
    }
}

void Strassen(mat A, mat B, mat &C, corners ai, corners bi, corners ci){
    int m, n, k, i, j;
    corners aii[2][2], bii[2][2], cii[2][2], p;
    mat P[7], S, T;

    // Check if number of rows in A is equal to the number of rows in C.
    // and number of columns in B is equal to the number of columns in C.
    m = (ai.rb - ai.ra);
    assert(m == (ci.rb - ci.ra));

    n = (bi.cb - bi.ca);
    assert(n == (ci.cb - ci.ca));

    k = (ai.cb - ai.ca);
    assert(k == (bi.rb - bi.ra));

    if(n==1){
        C[ci.ra][ci.ca] += (A[ai.ra][ai.ca] * B[bi.ra][bi.ca]);
        return;
    }

    // check the corners after dividing the matrix into half.
    for(i=0; i<2; i++){
        for(j=0; j<2; j++){
            findCorners(ai, i, j, aii[i][j]);
            findCorners(bi, i, j, bii[i][j]);
            findCorners(ci, i, j, cii[i][j]);
        }
    }

    // corner matrix for Product matrices
    p.ra = p.ca = 0;
    p.rb = p.cb = m/2;

    // std::cout << "P corners: " << p.rb << p.cb;

    // Declare 7 product matrices.
    for(i=0; i<7; i++){
        set(P[i], p, 0);
    }

    // Product equations P1 = a*(f-h)
    set(S, p, 0);
    subtract(B, B, S, bii[0][1], bii[1][1], p);
    Strassen(A, S, P[0], aii[0][0], p, p);

    // P2 = (a+b)*h
    set(S, p, 0);
    addmat(A, A, S, aii[0][0], aii[0][1], p);
    Strassen(S, B, P[1], p, bii[1][1], p);

    // P3 = (c+d)*e
    set(S, p, 0);
    addmat(A, A, S, aii[1][0], aii[1][1], p);
    Strassen(S, B, P[2], p, bii[0][0], p);
    
    // P4 = d*(g-e)
    set(S, p, 0);
    subtract(B, B, S, bii[1][0], bii[0][0], p);
    Strassen(A, S, P[3], aii[1][1], p, p);
    
    // P5 = (a+d)*(e+h)
    set(S, p, 0);
    set(T, p, 0);
    addmat(A, A, S, aii[0][0], aii[1][1], p);
    addmat(B, B, T, bii[0][0], bii[1][1], p);
    Strassen(S, T, P[4], p, p, p);
    
    // P6 = (b-d)*(g+h)
    set(S, p, 0);
    set(T, p, 0);
    subtract(A, A, S, aii[0][1], aii[1][1], p);
    addmat(B, B, T, bii[1][0], bii[1][1], p);
    Strassen(S, T, P[5], p, p, p);

    // P7 = (a-c)*(e+f)
    set(S, p, 0);
    set(T, p, 0);
    subtract(A, A, S, aii[0][0], aii[1][0], p);
    addmat(B, B, T, bii[0][0], bii[0][1], p);
    Strassen(S, T, P[6], p, p, p);
    
    // find value of matrix C
    set(S, p, 0);
    set(T, p, 0);
    addmat(P[4], P[3], S, p, p, p);
    addmat(S, P[5], T, p, p, p);
    subtract(T, P[1], C, p, p, cii[0][0]);

    addmat(P[0], P[1], C, p, p, cii[0][1]);

    addmat(P[2], P[3], C, p, p, cii[1][0]);

    set(S, p, 0);
    set(T, p, 0);
    addmat(P[4], P[0], S, p, p, p);
    subtract(S, P[2], T, p, p, p);
    subtract(T, P[6], C, p, p, cii[1][1]);
}


int main()
{   
    corners ai, bi, ci;
    ai = {0, N, 0, N};
    bi = {0, N, 0, N};
    ci = {0, N, 0, N};
    mat C;
    // std::cout << "N: " << N;

    mat A = { {1, 2, 3, 4}, {5, 0, 1, 3}, {0, 6, 3, 7}, {0, 2, 9, 9} };
    printMat(A, "Matrix A");

    mat B = { {0, 1, 3, 4}, {2, 0, 1, 3}, {1, 0, 3, 4}, {1, 2, 3, 0} };
    printMat(A, "Matrix B");

    set(C, ci, 0);
    printMat(C, "Matrix C");

    // Strassen's Matrix Multiplication
    Strassen(A, B, C, ai, bi, ci);
    printMat(C, "Product Matrix C");

    return 0;
}