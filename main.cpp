#include <iostream>
#include <fstream>
#include "Sculptor.h"

int main()
{
    Voxel ***v;
    Sculptor objeto3d(150,150,150);
    objeto3d.setColor(0.0,0.0,0.0,0.0);
    objeto3d.putBox(50,60,30,65,85,88);
    objeto3d.setColor(1.0,1.0,1.0,1.0);
    objeto3d.putSphere(10,20,25,5);

    objeto3d.writeOFF((const char*) "C:/Users/julia/projeto/.teste.off");
    std::cout << "ta rodando gata bjs";
    return 0;
}
