#include <iostream>
#include <cmath>

void FacaAlgumaCoisa(double* u, double** A);

int main(int argc, char* argv[]){

    // alocando memoria para o vetor 
    double* u = new double [10];
    double** A = new double* [10]; // alocando memoria para as linhas

    for (int i=0; i<10; i++){
        A[i] = new double [10]; // alocando memoria para as colunas
    }

    FacaAlgumaCoisa(u, A);
  
    std::cout << u[2] << "\n";
    std::cout << A[2][3] << "\n";
    
    delete[] u; // desaloca ponteiro para vetor

    for (int i=0; i<10; i++){
        delete[] A[i]; // desaloca ponteiro para colunas
    }

    delete[] A; // desaloca ponteiro para linhas

    return 0;
}

void FacaAlgumaCoisa(double* u, double** A){
    u[2] = 1.0;
    A[2][3] = 4.0;
}