#pragma once
#include "Voxel.h"

class Sculptor
{
private:
	Voxel ***matriz; //Matriz 3D
	int nx, ny, nz; //Dimensões
	float r, g, b, a; //Cores atuais do desenho

	int rxMax, ryMax, rzMax;

	//FUNÇÕES SECUNDÁRIAS
	void alocarMatriz(void);
	void liberarMemoria(void);
	int numberActiveVoxels(void);

public:
	//FUNÇÕES PRINCIPAIS
	Sculptor(int _nx, int _ny, int _nz);
	~Sculptor();

	void setColor(float _r, float _g, float _b, float alpha);

	void putVoxel(int _x, int _y, int _z);
	void putBox(int x0, int x1, int y0, int y1, int z0, int z1);
	void putSphere(int xCenter, int yCenter, int zCenter, int radius);
	void putEllipsoid(int xCenter, int yCenter, int zCenter, int rx, int ry, int rz);

	void cutVoxel(int _x, int _y, int _z);
	void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
	void cutSphere(int xCenter, int yCenter, int zCenter, int radius);
	void cutEllipsoid(int xCenter, int yCenter, int zCenter, int rx, int ry, int rz);

	void writeOFF(char* filename);

	//FUNÇÕES SECUNDÁRIAS

	void DesenhoFoguete(void);
};

