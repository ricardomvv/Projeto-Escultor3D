#include <iostream>
#include <fstream>
#include <cstdlib>
#include <math.h>
#include "Escultor3D.h"


Sculptor::Sculptor(int _nx, int _ny, int _nz) //Construtor da classe
{
    int i,j,k;
    int nx = _nx, ny = _ny, nz = _ny;

    // Para realizar a alocação dinâmica de memória (usando "new" em C++) e gerar a matriz3D.

    matriz3D = new Voxel**[nx];
    matriz3D[0] = new Voxel*[nx*ny];
    matriz3D[0][0] = new Voxel[nx*ny*nz];

    for(i=0; i< nx; i++)
    {

        matriz3D[i+1] = matriz3D[i] + ny;

        for(j=0; j< ny; j++)
        {
            matriz3D[i][j+1] = matriz3D[i][j] + nz;
        }

    }

    for(int i = 0; i < nx; i++)
    {
        for(int j = 0; j < ny; j++)
        {
            for(int k = 0; k < nz; k++)
            {
                matriz3D[i][j][k].isOn = false;
            }
        }
    }
}

Sculptor::~Sculptor()
{
    //Destrutor de Classes

    delete [] matriz3D[0][0];
    delete [] matriz3D[0];
    delete [] matriz3D;
}

void Sculptor::setColor(float r, float g, float b, float alpha)
{

    //Definir as cores, fazendo com que o valores das cores (R,G,B) fiquem entre 0 e 1.

    // Para RED:
    if(r >1)
    {
        R = 1;
    }
    else if(r <0)
    {
        R = 0;
    }
    else
    {
        R = r;
    }

    // Para GREEN:
    if(g >1)
    {
        G = 1;
    }
    else if(g <0)
    {
        G = 0;
    }
    else
    {
        G = g;
    }

    // Para BLUE:
    if(b >1)
    {
        B = 1;
    }
    else if(b <0)
    {
        B = 0;
    }
    else
    {
        B = b;
    }

    //Para Alpha:
    if(alpha >1)
    {
        A = 1;
    }
    else if(alpha <0)
    {
        A = 0;
    }
    else
    {
        A = alpha;
    }

}

void Sculptor::putVoxel(int x, int y, int z)
{

    //Ativa o voxel na posição (x,y,z),fazendo isOn = true e atribuindo a cor atual de desenho

    matriz3D[x][y][z].isOn = true;
    matriz3D[x][y][z].r = R;
    matriz3D[x][y][z].g = G;
    matriz3D[x][y][z].b = B;
    matriz3D[x][y][z].a = A;
}

void Sculptor::cutVoxel(int x, int y, int z)
{

    //Desativa o voxel na posição (x,y,z),fazendo isOn = false

    matriz3D[x][y][z].isOn = false;


}

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    int i,j,k;
    //Ativa todos os voxels no intervalo [x0,x1], [y0,y1], [z0,z1] e atribui aos mesmos a cor atual de desenho

    for (i = x0; i<x1; i++)
    {
        for (j = y0; j<y1; j++)
        {
            for (k = z0; i<z1; k++)
            {
                matriz3D[i][j][k].isOn = true;
                matriz3D[i][j][k].r = R;
                matriz3D[i][j][k].g = G;
                matriz3D[i][j][k].b = B;
                matriz3D[i][j][k].a = A;
            }
        }
    }
}
void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    int i,j,k;
    //Desativa todos os voxels no intervalo x[x0,x1], y[y0,y1], z[z0,z1] e atribui aos mesmos a cor atual de desenho

    for (int i = x0; i<=x1; i++)
    {
        for (int j = y0; j<=y1; j++)
        {
            for (int k = z0; i<=z1; k++)
            {
                matriz3D[i][j][k].isOn = false;
                matriz3D[i][j][k].r = R;
                matriz3D[i][j][k].g = G;
                matriz3D[i][j][k].b = B;
                matriz3D[i][j][k].a = A;
            }
        }
    }
}

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    int i,j,k;
    //Ativa todos os voxels que satisfazem à equação da esfera e atribui aos mesmos a cor atual de desenho

    for(i=0; i<= xcenter; i++)
    {
        for(j=0; j<= ycenter; j++)
        {
            for(k=0; k<= zcenter; k++)
            {
                if ((pow((i-xcenter),2)) + (pow((j-ycenter),2)) + (pow((k-zcenter),2)) <= (pow(radius,2)))
                {
                    matriz3D[i][j][k].isOn = true;
                    matriz3D[i][j][k].r = R;
                    matriz3D[i][j][k].g = G;
                    matriz3D[i][j][k].b = B;
                    matriz3D[i][j][k].a = A;
                }
            }
        }
    }
}
void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    int i,j,k;
    //Desativa todos os voxels que satisfazem à equação da esfera

    for(i=0; i< xcenter; i++)
    {
        for(j=0; j< ycenter; j++)
        {
            for(k=0; k< zcenter; k++)
            {
                if ((pow((i-xcenter),2)) + (pow((j-ycenter),2)) + (pow((k-zcenter),2)) <= (pow(radius,2)))
                {
                    matriz3D[i][j][k].isOn = false;
                    matriz3D[i][j][k].r = R;
                    matriz3D[i][j][k].g = G;
                    matriz3D[i][j][k].b = B;
                    matriz3D[i][j][k].a = A;
                }
            }
        }
    }
}

void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
    int i,j,k;
    //Ativa todos os voxels que satisfazem à equação do elipsóide e atribui aos mesmos a cor atual de desenho

    for(i=0; i<= xcenter; i++)
    {
        for(j=0; j<= ycenter; j++)
        {
            for(k=0; k<= zcenter; k++)
            {
                if ((pow((i - xcenter),2)/(pow(rx,2))) + ((pow((j - ycenter),2))/(pow(ry,2))) + ((pow((k - zcenter),2))/(pow(rz,2))) <= 1.0)
                {
                    matriz3D[i][j][k].isOn = true;
                    matriz3D[i][j][k].r = R;
                    matriz3D[i][j][k].g = G;
                    matriz3D[i][j][k].b = B;
                    matriz3D[i][j][k].a = A;
                }
            }
        }
    }
}

void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
    int i,j,k;
    // Esse método desativa todos os voxels que satisfazem à equação do elipsóide

    for(i=0; i<= xcenter; i++)
    {
        for(j=0; j<= ycenter; j++)
        {
            for(k=0; k<= zcenter; k++)
            {
                if ((pow((i - xcenter),2)/(pow(xcenter,2))) + ((pow((j - ycenter),2))/(pow(ycenter,2))) + ((pow((k - zcenter),2))/(pow(zcenter,2))) <= 1.0)
                {
                    matriz3D[i][j][k].isOn = false;
                    matriz3D[i][j][k].r = R;
                    matriz3D[i][j][k].g = G;
                    matriz3D[i][j][k].b = B;
                    matriz3D[i][j][k].a = A;
                }
            }
        }
    }
}
void Sculptor::writeOFF(string filename)
{
    int esp[nx][ny][nz];
    int i,j,k;
    int Nvoxels = 0; // Variavel que contabiliza o numero de Voxels.
    int Nvar;

    ofstream fout;

    fout.open("./"+filename+".off");
    if(fout.is_open() == false)
    {
        cout << "arquivo nao foi aberto\n";
        exit(1);

    }

    fout<<"OFF"<<endl;

    for(i = 0; i < nx; i++)
    {
        for(j = 0; j < ny; j++)
        {
            for(k = 0; k < nz; k++)
            {
                esp[i][j][k] = 0; //Inicialmente preenchemos a matriz com 0
            }
        }
    }

    for(i = 0; i < nx; i++)
    {

        for(j = 0; j < ny; j++)
        {

            for(k = 0; k < nz; k++)
            {

                Nvoxels++; // Essa parte que vai permitir encontrar a quantidade de voxels, por exemplo: na dimenssão 2x2x2 existem 24 Voxels.

            }
        }
    }

    fout<<Nvoxels*8<<" "<<Nvoxels*6<<" 0"<<endl;//SEGUNDA LINHA

    for(j=0; j<ny; j++)
    {
        for (i=0; i<nx; i++)
        {
            for(int k=0; k<nz; k++)
            {
                fout<<-0.5+i<<" "<<0.5+j<<" "<<-0.5+k<<endl; //TERCEIRA LINHA EM DIANTE
                fout<<-0.5+i<<" "<<-0.5+j<<" "<<-0.5+k<<endl;
                fout<<0.5+i<<" "<<-0.5+j<<" "<<-0.5+k<<endl;
                fout<<0.5+i<<" "<<0.5+j<<" "<<-0.5+k<<endl;
                fout<<-0.5+i<<" "<<0.5+j<<" "<<0.5+k<<endl;
                fout<<-0.5+i<<" "<<-0.5+j<<" "<<0.5+k<<endl;
                fout<<0.5+i<<" "<<-0.5+j<<" "<<0.5+k<<endl;
                fout<<0.5+i<<" "<<0.5+j<<" "<<0.5+k<<endl; //DÉCIMA LINHA

            }
        }
    }



    for(k=0; k<nz; k++)
    {
        for(j=0; j<ny; j++)
        {
            for (i=0; i<nx; i++)
            {

                fout<<"4 "<<0+Nvar*8<<" "<<3+Nvar*8<<" "<<2+Nvar*8<<" "<<1+Nvar*8<<" "<<matriz3D[i][j][k].r<<" "<<matriz3D[i][j][k].g<<" "<<matriz3D[i][j][k].b<<" "<<matriz3D[i][j][k].a<<endl;
                fout <<"4 "<<4+Nvar*8<<" "<<5+Nvar*8<<" "<<6+Nvar*8<<" "<<7+Nvar*8<<" "<<matriz3D[i][j][k].r<<" "<<matriz3D[i][j][k].g<<" "<<matriz3D[i][j][k].b<<" "<<matriz3D[i][j][k].a<<endl;
                fout <<"4 "<<0+Nvar*8<<" "<<1+Nvar*8<<" "<<5+Nvar*8<<" "<<4+Nvar*8<<" "<<matriz3D[i][j][k].r<<" "<<matriz3D[i][j][k].g<<" "<<matriz3D[i][j][k].b<<" "<<matriz3D[i][j][k].a<<endl;
                fout <<"4 "<<0+Nvar*8<<" "<<4+Nvar*8<<" "<<7+Nvar*8<<" "<<3+Nvar*8<<" "<<matriz3D[i][j][k].r<<" "<<matriz3D[i][j][k].g<<" "<<matriz3D[i][j][k].b<<" "<<matriz3D[i][j][k].a<<endl;
                fout<<"4 "<<3+Nvar*8<<" "<<7+Nvar*8<<" "<<6+Nvar*8<<" "<<2+Nvar*8<<" "<<matriz3D[i][j][k].r<<" "<<matriz3D[i][j][k].g<<" "<<matriz3D[i][j][k].b<<" "<<matriz3D[i][j][k].a<<endl;
                fout<<"4 "<<1+Nvar*8<<" "<<2+Nvar*8<<" "<<6+Nvar*8<<" "<<5+Nvar*8<<" "<<matriz3D[i][j][k].r<<" "<<matriz3D[i][j][k].g<<" "<<matriz3D[i][j][k].b<<" "<<matriz3D[i][j][k].a<<endl;
                Nvar++;

            }
        }

    }

}

void Sculptor::writeVECT(string filename)
{

    char esp[nx][ny][nz];
    int Nvoxels;
    int i,j,k;

    for(i = 0; i < nx; i++)
    {
        for(j = 0; j < ny; j++)
        {
            for(k = 0; k < nz; k++)
            {
                esp[i][j][k] = 0;
            }
        }
    }
    int nvox = 0;

    ofstream fout;

    fout.open("./"+filename+".off");
    if(fout.is_open() == false)
    {
        cout << "arquivo nao foi aberto\n";
        exit(1);
    }

    fout << "VECT" << endl;

    for(i = 0; i < nx; i++)
    {
        for(j = 0; j < ny; j++)
        {
            for(k = 0; k < nz; k++)
            {

                Nvoxels++;

            }
        }
    }

    fout << Nvoxels << " " << Nvoxels << " " << Nvoxels << endl;

    for (i =0; i<Nvoxels; i++)
    {
        fout << "1" <<" ";
    }
    fout << endl;
    for (i =0; i<Nvoxels; i++)
    {
        fout << "1" <<" ";
    }
    fout << endl;
    for(i = 0; i < nx; i++)
    {
        for(j = 0; j < ny; j++)
        {
            for(k = 0; k < nz; k++)
            {

                fout << i <<" "<< j <<" "<< k << endl;

            }
        }
    }
    for(i = 0; i < nx; i++)
    {
        for(j = 0; j < ny; j++)
        {
            for(k = 0; k < nz; k++)
            {

                fout << matriz3D[i][j][k].r <<" "<< matriz3D[i][j][k].g <<" "<< matriz3D[i][j][k].b <<" "<< matriz3D[i][j][k].a << endl;

            }
        }
    }

}
