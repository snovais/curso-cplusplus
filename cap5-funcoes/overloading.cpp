#include <iostream>

void Multiply(double scalar, double* u, double* v, int n); // multiplica vetor por escalar 
void Multiply(double scalar, double** A, double** B, int n);  // multiplica matriz por escalar

int main(int argc, char* argv[]){
    int n = 2;
    
    // aloca memoria para o vetor
    double* u = new double [n];
    double* v = new double [n];

    // aloca memoria para as linhas da matriz
    double** A = new double* [n];
    double** B = new double* [n];
    
    // aloca memoria para as colunas da matriz
    for (int i=0; i<n; i++){
        A[i] = new double [n];
        B[i] = new double [n];
    }

    u[0] = -8.7; u[1] = 3.2;
    A[0][0] = 2.3; A[0][1] = -7.6;
    A[1][0] = 1.3; A[1][1] = 45.3;

    double s = 2.3, t = 4.8;

    // multiplicacao no vetor
    Multiply(s, u, v, n);

    // multiplicacao na matriz com o overloading
    Multiply(t, A, B, n);

    //  desaloca vetor
    delete[] u;
    delete[] v;
    
    // desaloca as colunas da matriz
    for (int i=0; i<n; i++){
        delete[] A[i];
        delete[] B[i];
    }

    // desaloca as linhas da matriz
    delete[] A;
    delete[] B;

    return 0;
}

void Multiply(double scalar, double* u, double* v, int n){
    
    // v = scalar*u (scalar by vector)
    for (int i=0; i<n; i++){
        v[i] = scalar*u[i];
        std::cout << "v: " << v[i] << "\n";
    }
}

void Multiply(double scalar, double** A, double** B, int n){
    // B = scalar*A (scalar by matrix)
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            B[i][j] = scalar*A[i][j];
            std::cout << "B: " << B[i][j] << "\n";
        }
    }
}