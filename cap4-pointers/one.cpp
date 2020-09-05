#include <iostream>

int main(int argc, char* argv[]){
    int total_sum = 10;
    
    std::cout << "Endereço de memória eh: " << &total_sum << "\n"; 

    // declarar um ponteiro
    double* p_x;
    int* p_i;

    double y, z;
    
    z = 3.0;
    p_x = &z;
    y = *p_x + 1.0;

    std::cout << y << "\n";
    return 0;
}