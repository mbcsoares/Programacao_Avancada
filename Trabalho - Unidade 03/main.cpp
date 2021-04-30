#include <iostream>
#include <cstdlib>
#include <fstream>

#include "Sculptor.h"

#include "FiguraGeometrica.h"

#include "CutVoxel.h"
#include "CutBox.h"
#include "CutSphere.h"
#include "CutEllipsoid.h"

#include "PutVoxel.h"
#include "PutBox.h"
#include "PutSphere.h"
#include "PutEllipsoid.h"

#include "Dados.h";

using namespace std;


void ExemploBase()
{
	Sculptor figura(50, 50, 50);

	for (int i = 0; i < 50; i = i + 5)
	{
		for (int j = 0; j < 50; j = j + 3)
		{
			PutVoxel voxel01(i, j, 0, 1, 0, .5, 1);
			PutVoxel voxel02(i, j, 2, 1, .5, .5, 1);
			PutVoxel voxel03(i, j, 49, .5, 0, .5, 1);
			PutVoxel voxel04(i, j, 48, 0, 0, .5, 1);

			voxel01.draw(figura);
			voxel02.draw(figura);
			voxel03.draw(figura);
			voxel04.draw(figura);
		}
	}

	PutBox box01(15, 35, 15, 35, 15, 35, .8, .1, .7, 1);
	CutBox box02(17, 31, 17, 31, 17, 31);

	PutSphere esfera01(25, 5, 25, 5, 1, .5, .7, 1);
	PutSphere esfera02(5, 25, 25, 5, 1, .3, .5, 1);
	PutSphere esfera03(44, 25, 25, 5, 1, .5, .3, 1);
	PutSphere esfera04(25, 44, 25, 5, 1, .3, .1, 1);
	CutSphere esfera05(25, 25, 25, 13);

	PutEllipsoid ellipse01(25, 25, 25, 6, 6, 13, .6, .9, .3, 1);
	PutEllipsoid ellipse02(25, 25, 25, 6, 13, 6, .4, .1, .3, 1);
	PutEllipsoid ellipse03(25, 25, 25, 13, 6, 6, .5, .9, .1, 1);

	//----CRIAÇÃO DA FIGURA BASE----//

	box01.draw(figura);
	box02.draw(figura);

	esfera01.draw(figura);
	esfera02.draw(figura);
	esfera03.draw(figura);
	esfera04.draw(figura);
	esfera05.draw(figura);

	ellipse01.draw(figura);
	ellipse02.draw(figura);
	ellipse03.draw(figura);

	figura.writeOFF((char*)"FiguraBase.off");
}

void ExemploTeste(void)
{
	Dados dados(690, 50, 50, 50);
	dados.escrita((char*)"ExemploTeste.txt");

	for (int i = 0; i < 50; i = i + 5)
	{
		for (int j = 0; j < 50; j = j + 3)
		{
			PutVoxel voxel01(i, j, 0, 1, 0, .5, 1);
			PutVoxel voxel02(i, j, 2, 1, .5, .5, 1);
			PutVoxel voxel03(i, j, 49, .5, 0, .5, 1);
			PutVoxel voxel04(i, j, 48, 0, 0, .5, 1);

			dados.addFigura(voxel01);
			dados.addFigura(voxel02);
			dados.addFigura(voxel03);
			dados.addFigura(voxel04);
		}
	}

	PutBox box01(15, 35, 15, 35, 15, 35, .8, .1, .7, 1);
	CutBox box02(17, 31, 17, 31, 17, 31);

	PutSphere esfera01(25, 5, 25, 5, 1, .5, .7, 1);
	PutSphere esfera02(5, 25, 25, 5, 1, .3, .5, 1);
	PutSphere esfera03(44, 25, 25, 5, 1, .5, .3, 1);
	PutSphere esfera04(25, 44, 25, 5, 1, .3, .1, 1);
	CutSphere esfera05(25, 25, 25, 13);

	PutEllipsoid ellipse01(25, 25, 25, 6, 6, 13, .6, .9, .3, 1);
	PutEllipsoid ellipse02(25, 25, 25, 6, 13, 6, .4, .1, .3, 1);
	PutEllipsoid ellipse03(25, 25, 25, 13, 6, 6, .5, .9, .1, 1);

	dados.addFigura(box01);
	dados.addFigura(box02);

	dados.addFigura(esfera01);
	dados.addFigura(esfera02);
	dados.addFigura(esfera03);
	dados.addFigura(esfera04);
	dados.addFigura(esfera05);


	dados.addFigura(ellipse01);
	dados.addFigura(ellipse02);
	dados.addFigura(ellipse03);
}

int main(void)
{
	ExemploBase();
	ExemploTeste();

	Dados dados;

	dados.leitura((char*)"ExemploTeste.txt");

	return 0;
}