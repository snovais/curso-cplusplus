#include <iostream>

int main(int argc, char* argv[]){
    for(int even : {2,4,6,8}){
        std::cout << even << "\n";
    }

    return 0;
}