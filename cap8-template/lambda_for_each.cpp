#include <iostream> 
#include <vector>
#include <algorithm> // for_each

int main(int argc, char* argv[]){
    std::vector<int> pares = {2,4,6,8};
    std::vector<int> impares = {1,3,5,7};
    
    // void dobro(int& n){
    //     n *= 2;
    // }

    // analogcamente a funcao com lambda se torna:
    auto dobro = [](int& n){n *= 2;};
    std::for_each(pares.begin(), pares.end(), dobro);

    // ou de forma mais compacta
    std::for_each(impares.begin(), impares.end(), [](int& n){n *= 3;});

    std::cout << pares[0] << "\n"; // pode-se acessar vector da mesma forma como arrays
    std::cout << impares[0] << "\n";

    return 0;
}