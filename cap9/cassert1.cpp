#include <cassert>

void RenderAnnulus(double innerRadius, double outerRadius, int slices, int segments);

int main(int argc, char* argv[]){
    RenderAnnulus(1.0, 0.0, 30, 3);
    return 0;
}

void RenderAnnulus(double innerRadius, double outerRadius, int slices, int segments){
    //Another implementation only checks the input
    //so RenderAnnulus(1.0, 0.0, 30, 3); trips an assertion
    assert (innerRadius < outerRadius);
    //...then render the annulus    
}