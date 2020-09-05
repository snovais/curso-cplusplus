/*
Escreva um código que aloque dinamicamente a memória para três matrizes 2 × 2 de
números de ponto flutuante de precisão dupla, A, B, C, e atribua valores às 
entradas de A e B. Seja C = A + B. Estenda seu código para que ele calcule as 
entradas de C e, em seguida, imprime as entradas de C na tela. Finalmente, 
desalocar a memória. Novamente, verifique se você desalocou a memória 
corretamente usando um loop for como no exercício anterior.
*/

#include <iostream>

int main(int argc, char* argv[]){
    int rows = 2, cols = 2;

    // ponteiros para as matrizes
    double** A;
    double** B;
    double** C;

    // aloca posicoes para as linhas
    A = new double* [rows];
    B = new double* [rows];
    C = new double* [rows];

    // aloca posicoes
    for (int i=0; i<rows; i++){
        A[i] = new double [cols];
        B[i] = new double [cols];
        C[i] = new double [cols];
    }

    A[0][0] = B[0][0] = 2;
    A[0][1] = B[0][1] = 3;
    A[1][0] = B[1][0] = 4;
    A[1][1] = B[1][1] = 5;
    // preenche as matrizes com valores e depois multiplica para obter C
    for (int i=0; i<rows; i++){
        for(int j=0;j<cols; j++){
            C[i][j] = A[i][j] + B[i][j];
            std::cout << "C: " << C[i][j] << "\n";          
        }

        // desaloca ponteiro para colunas
        delete[] A;
        delete[] B;
        delete[] C;
    }

    //desaloca ponteiro para linhas
    A = B = C = NULL;
    
    return 0;
}