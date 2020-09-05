#include <iostream>
#include <fstream>
#include <cassert>

int main(int argc, char * argv[]){
    double x[4] = {0.0, 1.0, 1.0, 0.0};
    double y[4] = {0.0, 0.0, 1.0, 1.0};

    // exerc 1
    // std::ofstream write_output("x_and_y.dat");
    
    std::ofstream write_file("x_and_y.dat");
    
    write_file.setf(std::ios::scientific);
    write_file.precision(10);

    for (int i=0; i<3; i++){
        write_file << x[i] << ", ";
        assert(write_file.good());
    }
    
    write_file << "\n";

    for (int i=0; i<3; i++){
        write_file << y[i] << ", ";
        assert(write_file.good());
    }
    write_file.flush();
    
    write_file.close();

    return 0;
}