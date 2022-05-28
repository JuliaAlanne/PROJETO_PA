#include "Sculptor.h"
#include <cmath>
#include <iostream>
#include <fstream>
#include <iomanip>
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
    // alocando a matriz
    v = new Voxel **[nx];
    for (int i=0;i<nx;i++) {
        v[i]=new Voxel *[ny];
        for (int j=0;j<ny;j++) {
            v[i][j]= new Voxel[nz];
            for (int k=0;k<nz;k++) {
                this ->v[i][j][k].r=0.0;
                this ->v[i][j][k].g=0.0;
                this ->v[i][j][k].b=0.0;
                this ->v[i][j][k].a=0.0;
                this ->v[i][j][k].isOn=false;
            }
        }
    }
}
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

void Sculptor::setColor(float r, float g, float b, float alpha){
    this ->r=r;
    this ->g=g;
    this ->b=b;
    this ->a=alpha;
}
void Sculptor::putVoxel(int x, int y,int z){
    this ->v[x][y][z].isOn=true;
    this ->v[x][y][z].r= this->r;
    this ->v[x][y][z].g= this->g;
    this ->v[x][y][z].b= this->b;
    this ->v[x][y][z].a= this->a;

}
void Sculptor::cutVoxel(int x, int y,int z){
    this ->v[x][y][z].isOn=false;

}

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1){
    //USO DE OPERADORES TERNARIOS (substituindo if/else)
   /* x0=(x0<0) ? 0: x0;
    x1= (x1> this->nx) ? this -> nx : x1);
    y0=(y0<0) ? 0:y0;
    y1= (x1> this->ny) ? this -> ny : y1);
    z0=(z0<0) ? 0 : z0;
    z1= (z1> this->nz )? this -> nz : z1);*/
    for (int i=x0;i<x1;i++){
        for (int j=y0;j<y1;j++){
            for (int k=z0;k<z1;k++){
                    this ->putVoxel(i,j,k);
            }
        }

    }

}
void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){
    /*x0=(x0<0) ? 0: x0;
    x1= (x1> this->nx ? this nx=x1);
    y0=(y0<0) ? 0:y0;
    y1= (x1> this->ny ? this ny=y1);
    z0=(z0<0) ? 0 : z0;
    z1= (z1> this->nz ? this nz=z1);*/
    for (int i=0;i<x0;i++){
        for (int j=0;j<y0;j++){
            for (int k=0;k<z0;k++){
                    this ->cutVoxel(i,j,k);
            }
        }

    }

}

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int r){
    for (int i=xcenter-r;i<xcenter+r;i++){
        for (int j=ycenter-r;j<ycenter+r;j++){
            for (int k=zcenter-r;k<zcenter+r;k++){
                 if(pow(k - zcenter, 2) + pow(j - ycenter, 2) + pow(i - xcenter, 2) < pow(r, 2)){
                    this ->putVoxel(i,j,k);
                 }
            }
        }

    }

}


void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int r){
    for (int i=xcenter-r;i<xcenter+r;i++){
        for (int j=ycenter-r;j<ycenter+r;j++){
            for (int k=zcenter-r;k<zcenter+r;k++){
                 if(pow(k - zcenter, 2) + pow(j - ycenter, 2) + pow(i - xcenter, 2) < pow(r, 2)){
                    this ->cutVoxel(i,j,k);
                 }
            }
        }

    }

}
void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    /*float  xelp,yelp, raiox, raioy;
    int start_ang=0, end_ang=360;*/
    for(int i = xcenter - rx; i < xcenter + rx; i++){
        for(int j = ycenter - ry; j < ycenter + ry; j++){
            for(int k = zcenter - rz; k < zcenter + rz; k++){
                if(pow(k - zcenter, 2)/pow(rz, 2) + pow(i - ycenter, 2)/pow(ry, 2) + pow(j - xcenter, 2)/pow(rx, 2) < 1){
                    this -> putVoxel(i,j,k);
                }
            }
        }
    }
}
void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){    for(int i = xcenter - rx; i < xcenter + rx; i++){
    for(int j = ycenter - ry; j < ycenter + ry; j++){
            for(int k = zcenter - rz; k < zcenter + rz; k++){
                if(pow(k - zcenter, 2)/pow(rz, 2) + pow(i - ycenter, 2)/pow(ry, 2) + pow(j - xcenter, 2)/pow(rx, 2) < 1){
                    this -> cutVoxel(i,j,k);
                }
            }
        }
    }
}
void Sculptor::writeOFF( char* f){
    std::ofstream fl;
    fl.open(f);
    fl<< "OFF\n";
    fl.close();
}

//destrutor

