// Programa teste que assume alguns valores para a simulação da representação pretendida.
#include <iostream>
#include "Escultor3D.h"

using namespace std;

int main(){
//int nx,ny,nz;

//cout<<"Digite as dimensoes do cubo (x,y,z) respectivamente:"<<endl;
//cin>>nx>>ny>>nz;

//cout<<"A matriz 3D eh dada por:"<<nx<<" X "<< ny<< "X" <<nz<<endl;

// Valores aleatórios atribuidos para teste

Sculptor esc(2,2,2);
esc.putBox(1,1,1,1,1,1);
  esc.cutBox(0,1,0,1,0,1);
  esc.setColor(0, 1, 0, 0.8);
  esc.putSphere(3,3,3,2);
  esc.cutSphere(3,3,3,2);
  esc.putEllipsoid(6,6,6,3,3,3);
  esc.cutEllipsoid(6,6,6,3,3,3);
  esc.writeOFF("C:/Users/Ricardo Varela/Downloads/UFRN C&T/6º Semestre/Programação Avançada/Projeto-Escultor/escultor-voxel.off");
  esc.writeVECT("C:/Users/Ricardo Varela/Downloads/UFRN C&T/6º Semestre/Programação Avançada/Projeto-Escultor/escultor-voxel.vetc");


return 0;
}
