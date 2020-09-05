#include <iostream>

int main(int argc, char* argv[]){
    double* x;
    x = new double[10];
    // x armazena a primeira posicao do array

    std:: cout << x << "\n";
    std:: cout << &x[0] << "\n";

    //  desaloca o endereço para ser usado posteriormente
    delete[] x;
    return 0;
}