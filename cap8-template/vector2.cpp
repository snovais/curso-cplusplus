#include <iostream>
#include <vector>
#include <set>
#include <cassert>
#include <array>

int main(int argc, char* argv[]){
    std::array<int, 4> num_array = {1, 3, 5, 3};

    std::vector<int> num_vector(num_array.begin(), num_array.end());

    std::set<int> num_set(num_array.begin(), num_array.end());
    
    assert( num_set.size() < num_vector.size() );

    return 0;
}

