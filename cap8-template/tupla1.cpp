#include <iostream>
#include <tuple>

// tupla é um estrutura de dados que permite inserir mais de um tipo na mesma estrutura

int main(int argc, char* argv[]){
    std::tuple<std::string, std::string, int> explorer = 
                    std::make_tuple("The explorer", "Katherine Rundell", 2017);
    std::cout<<"Title is "<<std::get<0>(explorer)<<"\n";
    std::cout<<"Published: "<<std::get<2>(explorer)<<"\n";

    auto h=std::make_tuple("The hobbit", "JRR Tolkien", 1937);

    return 0;
}