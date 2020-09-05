#include <iostream>
#include <cmath>

double minhaFuncao(double x);
double minhaOutraFuncao(double x);

int main(int argc, char* argv[]){
    double (*p_funcao)(double x);

    p_funcao = &minhaFuncao;
    std::cout << p_funcao(2.0) << "\n";

    p_funcao = &minhaOutraFuncao;
    std::cout << p_funcao(2.0) << "\n";

    return 0;
}

double minhaFuncao(double x){
    return x*x;
}

double minhaOutraFuncao(double x){
    return x*x*x;
}