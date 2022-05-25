#include "Sculptor.h"
#include <cmath>
//#include <>
//construtor padrão
Sculptor::Sculptor(int nx_, int ny_, int nz_)
{
    nx=nx_;
    ny=ny_;
    nz=nz_;
    r=0.0;
    g=0.0;
    b=0.0;
    a=0.0;
    v= new voxel**[nx]
    for (int i=0;i<nx;i++) {
        v[i]=new Voxel *[ny];
    }
    for (int j=0;j<ny;j++) {
        v[i][j]= new Voxel[nz]
        for (int k=0;k<nz;k++) {
            this ->v[i][j][k].r=0.0;
            this ->v[i][j][k].g=0.0;
            this ->v[i][j][k].b=0.0;
            this ->v[i][j][k].a=0.0;
            this ->v[i][j][k].isOn=false;

    }
    }
    //ctor
}

void Sculptor::setColor(float r, float g, float b, float alpha){
    this ->r=r;
    this ->g=g;
    this ->b=b;
    this ->a=alpha;
}
void Sculptor::cutVoxel(int x, int y,int z){
    this ->v[x][y][z].isOn=true;
    this ->v[x][y][z].r= this->r;
    this ->v[x][y][z].g= this->g;
    this ->v[x][y][z].b= this->b;
    this ->v[x][y][z].a= this->a;

}
void Sculptor::putVoxel(int x, int y,int z){
    this ->v[x][y][z].isOn=false;

}
/*
void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1){
    this ->v[x][y][z].isOn=false;

}
}
void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius){


}
void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius){


}
void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    /*float  xelp,yelp, raiox, raioy;
    int start_ang=0, end_ang=360;


}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){


}
void Sculptor:: writeOFF(const char* filename){


}
*/
//destrutor
Sculptor::~Sculptor()
{
   for (int i=0;i<nx;i++)
    {
        for (int j=0;j<ny;j++) {
            delete[] v[i][j];
        }
        delete[] v[i];
        }
    delete[] v;
}
