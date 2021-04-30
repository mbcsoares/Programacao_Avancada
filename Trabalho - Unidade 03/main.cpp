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


void Exemplo()
{
	Sculptor figura(50, 50, 50);

	PutVoxel voxel01(25, 25, 0, 1, 0, .5, 1);
	PutVoxel voxel02(26, 25, 0, 1, .5, .5, 1);
	PutVoxel voxel03(25, 26, 0, .5, 0, .5, 1);
	PutVoxel voxel04(25,25, 1, 0, 0, .5, 1);
	CutVoxel voxel05(25, 25, 0);

	PutBox box01(25, 25, 2, 30, 32, 5, .8, .5, .1, 1);
	CutBox box02(26, 26, 3, 31, 29, 5);

	PutSphere esfera01(10, 10, 10, 7, .5, .6, .3, 1);
	PutSphere esfera02(10, 10, 10, 6, 1, .6, .3, 1);
	CutSphere esfera03(13, 13, 13, 5);

	PutEllipsoid ellipse01(25, 25, 25, 15, 10, 20, 1, .9, .3, 1);
	PutEllipsoid ellipse02(25, 25, 25, 11, 7, 16, .5, .9, 1, 1);
	CutEllipsoid ellipse03(27, 27, 30, 14, 9, 19);

	voxel01.draw(figura);
	voxel02.draw(figura);
	voxel03.draw(figura);
	voxel04.draw(figura);
	voxel05.draw(figura);
	box01.draw(figura);
	box02.draw(figura);
	esfera01.draw(figura);
	esfera02.draw(figura);
	esfera03.draw(figura);
	ellipse01.draw(figura);
	ellipse02.draw(figura);
	ellipse03.draw(figura);

	figura.writeOFF((char*)"exemplo.off");
}

int main(void)
{
	Exemplo();

	return 0;
}