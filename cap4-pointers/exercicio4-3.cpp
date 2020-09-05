#include <iostream>

int main(int argc, char* argv[]){
    int rows = 5, cols = 3;
    double** A;
    double** B;
    
    A = new double* [rows];
    for (long int i=0; i<1000000000; i++){
        A[i] = new double [cols];
        std::cout << A[i] << "\n";
        delete[] A;
    }

    B = new double* [rows];
    for (long int i=0; i<1000000000; i++){
        B[i] = new double [cols];
        std::cout << B[i] << "\n";
        delete[] B;
    }

    return 0;
}