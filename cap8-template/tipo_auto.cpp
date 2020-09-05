/*
O tipo automático
Depois de ler a Sect. 8.3 você pode ter acreditado que os modelos são todos dois
pontos duplos e colchetes angulares. Pior ainda, sempre que quiser iterar sobre
um vetor ou conjunto que você criou, você precisará se lembrar da forma exata 
do tipo de iterador. A boa notícia é que grande parte da escrita desses tipos 
agora pode ser simplificada por meio da inferência automática de tipo. Isso 
não apenas economiza na escrita, mas também torna o código modelo mais legível,
removendo alguns dos nomes de tipo longos. Isso se baseia em uma regra simples.
Regra: se o tipo de uma nova variável pode ser inferido pelo compilador no ponto
de sua inicialização, o tipo pode ser substituído por auto. Por exemplo, no 
fragmento de código abaixo, há informações suficientes para o compilador 
inferir que i deveria ser uma variável inteira: na sua inicialização, é dado 
o valor 1 (um inteiro). Enquanto isso, a variável x que é inicializada com um
valor de ponto flutuante recebe o tipo inferido double. Observe que cada uma
dessas duas linhas contém o tipo automático e uma atribuição. Nenhuma dessas
linhas pode ser dividida entre duas linhas, porque se o tipo for separado da 
inicialização, o tipo não pode mais ser inferido.
*/

#include <iostream>

int main(int argc, char* argv[]){
    auto exemplo = 1;
    auto exemplo1 = 1.3;

    std::cout << sizeof(exemplo) << "\n"; // tamanho 4 bytes inteiro
    std::cout << sizeof(exemplo1) << "\n"; // tamanho 8 bytes float

    return 0;
}