#ifndef DADOS_H
#define DADOS_H

#include "FiguraGeometrica.h"
#include "Sculptor.h"

#include "PutVoxel.h"
#include "PutBox.h"
#include "PutSphere.h"
#include "PutEllipsoid.h"

#include "CutVoxel.h"
#include "CutBox.h"
#include "CutSphere.h"
#include "CutEllipsoid.h"

#include <cstring>
#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

class Dados
{
private:
	int num;
	char arqL[100];
	char arqE[100];
	bool vrfLeitura = false, vrfEscrita = true;

	ifstream arqLeitura;
	ofstream arqEscrita;

public:
	Dados();
	Dados(int _num);

	void leitura(char *_arqNome);
	void escrita(char *_arqNome);

	void setNum(int _num);
	int getNum(void);

	void addFigura(PutVoxel obj);
	void addFigura(PutBox obj);
	void addFigura(PutSphere obj);
	void addFigura(PutEllipsoid obj);

	void addFigura(CutVoxel obj);
	void addFigura(CutBox obj);
	void addFigura(CutSphere obj);
	void addFigura(CutEllipsoid obj);

};

#endif;

