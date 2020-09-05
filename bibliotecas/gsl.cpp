#include <gsl/gsl_matrix.h>
#include <iostream>

int main(int argc, char* argv[]){
    gsl_matrix* myMatr = gsl_matrix_alloc(10,20);

    // matrix of 8s
    for (int i=0; i < 10; i++)
        for (int j=0; j < 20; j++)
            gsl_matrix_set(myMatr, i, j, 8);

    int elem = gsl_matrix_get(myMatr, 3, 4);

    std::cout << elem << "\n";

    gsl_matrix_free(myMatr);

    return 0;
}