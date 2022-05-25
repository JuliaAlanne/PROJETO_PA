#include "Sculptor.h"
#include <cmath>
//#include <>
//construtor padrão
Sculptor::Sculptor(int nx_, int ny_, int nz_)
{
    nx=nx_;
    ny=ny_;
    nz=nz_;
    v= new voxel***[nx]
    for (int i=0;i<nx;i++) {
        v[i]=new Voxel[nx];
    }
    for (int j=0;j<ny;j++) {
        for (int k=0;k<nz;k++) {
            v[j][k]= new Voxel[ny][nz]

        }
    }
    //ctor
}

void Sculptor::setColor(float r, float g, float b, float alpha){
    r=r_;
    g=g_;
    b=b_;
    a=a_;
}
void Sculptor::cutVoxel(int x, int y,int z){
    x=x_;
    y=y_;
    z=z_;

}

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1){
    x0=x0_; x1=x1_;
    y0=y0_; y1=y1_;
    z0=z0_; zq1-z1_;
}
void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){


}
void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius){


}
void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius){


}
void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    /*float  xelp,yelp, raiox, raioy;
    int start_ang=0, end_ang=360;



    */

}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){


}
void Sculptor:: writeOFF(const char* filename){


}

//destrutor
Sculptor::~Sculptor()
{
    //dtor
}
