
#ifndef MATRIZ_H
#define MATRIZ_H
#include <iostream>
// Header para extra��o das declarac�es dos m�todos, struct, classes.
using namespace std;

struct Voxel {
  float r,g,b;
  float a;
  bool isOn;

};
    class Sculptor
    {
    protected:

        Voxel ***matriz3D; // Matriz 3D (S� foi trocado o nome da vari�vel de "v" para "matriz3D")
        int nx,ny,nz; // Dimens�es
        float R,G,B,A; // Cores: RED, GREEN, BLUE, TRANSPARENTE

    public:
        // M�todos abaixo:

        Sculptor(int _nx, int _ny, int _nz);
        ~Sculptor();
        void setColor(float r, float g, float b, float alpha);
        void putVoxel(int x, int y, int z);
        void cutVoxel(int x, int y, int z);
        void putBox(int x0, int x1, int y0, int y1, int z0, int z1);
        void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
        void putSphere(int xcenter, int ycenter, int zcenter, int radius);
        void cutSphere(int xcenter, int ycenter, int zcenter, int radius);
        void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
        void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
        void writeOFF(string filename);
        void writeVECT(string filename);

    };

#endif // MATRIZ_H
