#include <iostream>
#include <vector>

int main(int argc, char* argv[]){
    std::vector<std::string> destinations = {"Paris", "New York", "Singapore"};

    // Range-based loop
    for (std::string city : destinations){
        std::cout << city << "\n";
    }

    // Use a reference to alter the members
    for (std::string& r_city : destinations){
        r_city = r_city + " (modified)";
        std::cout << r_city << "\n";
    }

    //A very compact form
    for (auto city:destinations){
        std::cout<<city<<"\n";
    } 

    return 0;
}