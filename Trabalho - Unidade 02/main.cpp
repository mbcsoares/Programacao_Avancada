#include <iostream>
#include <cstdlib>
#include <fstream>
#include "Sculptor.h"

using namespace std;

void ExemplosTestes(void)
{
	Sculptor exemplo01(10, 10, 10); //trono azul

	exemplo01.setColor(0, 0, 1, .1);
	exemplo01.putBox(0, 9, 0, 9, 0, 9);
	exemplo01.cutBox(1, 8, 1, 9, 1, 9);
	exemplo01.writeOFF((char*) "exemplo01.off");

	Sculptor exemplo02(31, 31, 51);
	exemplo02.setColor(0, 1, 0, 1);
	exemplo02.putEllipsoid(15, 15, 15, 10, 10, 15);
	exemplo02.setColor(1, 0, 0, 1);
	exemplo02.putEllipsoid(15, 15, 15, 9, 9, 14);
	exemplo02.cutEllipsoid(15, 15, 15, 8, 8, 13);
	exemplo02.cutBox(0, 30, 0, 30, 0, 5);
	exemplo02.writeOFF((char*)"exemplo02.off");

	Sculptor exemplo03(31, 31, 31);
	exemplo03.setColor(1, 1, 0, 1);
	exemplo03.putSphere(0, 0, 0, 10);
	exemplo03.putVoxel(30, 30, 30);
	exemplo03.writeOFF((char*)"exemplo03.off");
}


int main(void)
{
	//ExemplosTestes();

	Sculptor foguete(40, 40, 220);

	foguete.setColor(1.0, 0, 0, 1);
	foguete.DesenhoFoguete();

	foguete.writeOFF((char*)"foguete.off");
}