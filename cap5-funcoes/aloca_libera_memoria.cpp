#include <iostream>

double** AlocaMemoriaParaMatriz(int numLinhas, int numColunas);
void LiberaMemoriaAlocadaMatriz(int numLinhas, double** matrix);

int main(int argc, char* argv[]){
    double** A;
    A = AlocaMemoriaParaMatriz(5, 3);
    
    A[0][1] = 2.0;
    A[4][2] = 4.0;
    
    LiberaMemoriaAlocadaMatriz(5, A);
    return 0;
}
   
double** AlocaMemoriaParaMatriz(int numLinhas, int numColunas){
    double** matrix;
    matrix = new double* [numLinhas];
    
    for (int i=0; i<numLinhas; i++){
        matrix[i] = new double [numColunas];
    }
    return matrix;
}
    

void LiberaMemoriaAlocadaMatriz(int numLinhas, double** matrix){
    for (int i=0; i<numLinhas; i++){
        delete[] matrix[i];
    }
    delete[] matrix;
}