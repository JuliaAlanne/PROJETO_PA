#include <iostream>
#include <fstream>
#include "Sculptor.h"

int main()
{
    Voxel ***v;
    Sculptor objeto3d(100,100,100);
    objeto3d.setColor(0.5,0.0,0.0,1.0);
    objeto3d.cutBox(55,65,32,42,58,68);
    objeto3d.writeOFF((const char*) "C:/Users/julia/projeto/.OFF.off");
    return 0;
}
