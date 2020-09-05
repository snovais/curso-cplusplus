#include <iostream>

int main(int argc, char* argv[]){
    double** A;
    for (int i=0; i<10000; i++){
        A = new double* [50];
        for (int j=0; j<50; j++){
            A[j] = new double [50];
            delete[] A;
        }
    }
    A = NULL;
    

    return 0;
}