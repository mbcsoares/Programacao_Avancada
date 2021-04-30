#include "Dados.h"

Dados::Dados()
{
	num = 0;
	nx = ny = nz = 0;
}

Dados::Dados(int _num, int _nx, int _ny, int _nz)
{
	num = _num;
	nx = _nx;
	ny = _ny;
	nz = _nz;
}

void Dados::leitura(char *_arqNome)
{
	if (!vrfEscrita)
	{
		arqL = _arqNome;

		arqLeitura.open(arqL);

		arqLeitura >> fixed >> num >> nx >> ny >> nz;

		Sculptor figura(nx, ny, nz);

		char tipo[5];
		int i;
		float f;

		PutVoxel pvoxel;
		PutBox pbox;
		PutSphere psphere;
		PutEllipsoid pellipsoid;

		CutVoxel cvoxel;
		CutBox cbox;
		CutSphere csphere;
		CutEllipsoid cellipsoid;

		for (int j = 0; j < num; j++)
		{
			arqLeitura >> tipo;

			if (!strcmp(tipo, "ptvx"))
			{
				arqLeitura >> fixed >> i; pvoxel.setX0(i);
				arqLeitura >> fixed >> i; pvoxel.setY0(i);
				arqLeitura >> fixed >> i; pvoxel.setZ0(i);

				arqLeitura >> fixed >> f; pvoxel.setR(f);
				arqLeitura >> fixed >> f; pvoxel.setG(f);
				arqLeitura >> fixed >> f; pvoxel.setB(f);
				arqLeitura >> fixed >> f; pvoxel.setA(f);

				pvoxel.draw(figura);
			}
			else if (!strcmp(tipo, "ctvx"))
			{
				arqLeitura >> fixed >> i; cvoxel.setX0(i);
				arqLeitura >> fixed >> i; cvoxel.setY0(i);
				arqLeitura >> fixed >> i; cvoxel.setZ0(i);

				cvoxel.draw(figura);
			}
			else if (!strcmp(tipo, "ptbx"))
			{
				arqLeitura >> fixed >> i; pbox.setX0(i);
				arqLeitura >> fixed >> i; pbox.setY0(i);
				arqLeitura >> fixed >> i; pbox.setZ0(i);

				arqLeitura >> fixed >> i; pbox.setX1(i);
				arqLeitura >> fixed >> i; pbox.setY1(i);
				arqLeitura >> fixed >> i; pbox.setZ1(i);

				arqLeitura >> fixed >> f; pbox.setR(f);
				arqLeitura >> fixed >> f; pbox.setG(f);
				arqLeitura >> fixed >> f; pbox.setB(f);
				arqLeitura >> fixed >> f; pbox.setA(f);

				pbox.draw(figura);
			}
			else if (!strcmp(tipo, "ctbx"))
			{
				arqLeitura >> fixed >> i; cbox.setX0(i);
				arqLeitura >> fixed >> i; cbox.setY0(i);
				arqLeitura >> fixed >> i; cbox.setZ0(i);

				arqLeitura >> fixed >> i; cbox.setX1(i);
				arqLeitura >> fixed >> i; cbox.setY1(i);
				arqLeitura >> fixed >> i; cbox.setZ1(i);

				cbox.draw(figura);
			}
			else if (!strcmp(tipo, "ptsp"))
			{
				arqLeitura >> fixed >> i; psphere.setX0(i);
				arqLeitura >> fixed >> i; psphere.setY0(i);
				arqLeitura >> fixed >> i; psphere.setZ0(i);

				arqLeitura >> fixed >> i; psphere.setRadius(i);

				arqLeitura >> fixed >> f; psphere.setR(f);
				arqLeitura >> fixed >> f; psphere.setG(f);
				arqLeitura >> fixed >> f; psphere.setB(f);
				arqLeitura >> fixed >> f; psphere.setA(f);

				psphere.draw(figura);
			}
			else if (!strcmp(tipo, "ctsp"))
			{
				arqLeitura >> fixed >> i; csphere.setX0(i);
				arqLeitura >> fixed >> i; csphere.setY0(i);
				arqLeitura >> fixed >> i; csphere.setZ0(i);

				arqLeitura >> fixed >> i; csphere.setRadius(i);

				csphere.draw(figura);
			}
			else if (!strcmp(tipo, "ptel"))
			{
				arqLeitura >> fixed >> i; pellipsoid.setX0(i);
				arqLeitura >> fixed >> i; pellipsoid.setY0(i);
				arqLeitura >> fixed >> i; pellipsoid.setZ0(i);

				arqLeitura >> fixed >> i; pellipsoid.setRx(i);
				arqLeitura >> fixed >> i; pellipsoid.setRy(i);
				arqLeitura >> fixed >> i; pellipsoid.setRz(i);

				arqLeitura >> fixed >> f; pellipsoid.setR(f);
				arqLeitura >> fixed >> f; pellipsoid.setG(f);
				arqLeitura >> fixed >> f; pellipsoid.setB(f);
				arqLeitura >> fixed >> f; pellipsoid.setA(f);

				pellipsoid.draw(figura);
			}
			else if (!strcmp(tipo, "ctel"))
			{
				arqLeitura >> fixed >> i; cellipsoid.setX0(i);
				arqLeitura >> fixed >> i; cellipsoid.setY0(i);
				arqLeitura >> fixed >> i; cellipsoid.setZ0(i);

				arqLeitura >> fixed >> i; cellipsoid.setRx(i);
				arqLeitura >> fixed >> i; cellipsoid.setRy(i);
				arqLeitura >> fixed >> i; cellipsoid.setRz(i);

				cellipsoid.draw(figura);
			}
		}

		figura.writeOFF((char*) "FiguraFinal.off");

		arqLeitura.close();

		vrfLeitura = true;
	}
}

void Dados::escrita(char* _arqNome)
{
	if (!vrfLeitura)
	{
		arqE = _arqNome;

		arqEscrita.open(arqE);

		arqEscrita << fixed << num << endl;
		arqEscrita << fixed << nx << " " << ny << " " << nz << endl;

		arqEscrita.close();

		vrfEscrita = true;
	}
}

void Dados::setNum(int _num)
{
	num = _num;
}

int Dados::getNum(void)
{
	return num;
}

//------------//

void Dados::addFigura(PutVoxel obj)
{
	if (vrfEscrita && !vrfLeitura)
	{
		arqEscrita.open(arqE, ios::app);

		arqEscrita << fixed << "ptvx" << " " 
			<< obj.getX0() << " " 
			<< obj.getY0() << " " 
			<< obj.getZ0() << " " 
			<< obj.getR() << " " 
			<< obj.getG() << " " 
			<< obj.getB() << " " 
			<< obj.getA() << endl;

		arqEscrita.close();
	}
}

void Dados::addFigura(PutBox obj)
{
	if (vrfEscrita && !vrfLeitura)
	{
		arqEscrita.open(arqE, ios::app);

		arqEscrita << fixed << "ptbx" << " "
			<< obj.getX0() << " "
			<< obj.getY0() << " "
			<< obj.getZ0() << " "
			<< obj.getX1() << " "
			<< obj.getY1() << " "
			<< obj.getZ1() << " "
			<< obj.getR() << " "
			<< obj.getG() << " "
			<< obj.getB() << " "
			<< obj.getA() << endl;

		arqEscrita.close();
	}
}

void Dados::addFigura(PutSphere obj)
{
	if (vrfEscrita && !vrfLeitura)
	{
		arqEscrita.open(arqE, ios::app);

		arqEscrita << fixed << "ptsp" << " "
			<< obj.getX0() << " "
			<< obj.getY0() << " "
			<< obj.getZ0() << " "
			<< obj.getRadius() << " "
			<< obj.getR() << " "
			<< obj.getG() << " "
			<< obj.getB() << " "
			<< obj.getA() << endl;

		arqEscrita.close();
	}
}

void Dados::addFigura(PutEllipsoid obj)
{
	if (vrfEscrita && !vrfLeitura)
	{
		arqEscrita.open(arqE, ios::app);

		arqEscrita << fixed << "ptel" << " "
			<< obj.getX0() << " "
			<< obj.getY0() << " "
			<< obj.getZ0() << " "
			<< obj.getRx() << " "
			<< obj.getRy() << " "
			<< obj.getRz() << " "
			<< obj.getR() << " "
			<< obj.getG() << " "
			<< obj.getB() << " "
			<< obj.getA() << endl;

		arqEscrita.close();
	}
}

//------------//

void Dados::addFigura(CutVoxel obj)
{
	if (vrfEscrita && !vrfLeitura)
	{
		arqEscrita.open(arqE, ios::app);

		arqEscrita << fixed << "ctvx" << " "
			<< obj.getX0() << " "
			<< obj.getY0() << " "
			<< obj.getZ0() << endl;

		arqEscrita.close();
	}
}

void Dados::addFigura(CutBox obj)
{
	if (vrfEscrita && !vrfLeitura)
	{
		arqEscrita.open(arqE, ios::app);

		arqEscrita << fixed << "ctbx" << " "
			<< obj.getX0() << " "
			<< obj.getY0() << " "
			<< obj.getZ0() << " "
			<< obj.getX1() << " "
			<< obj.getY1() << " "
			<< obj.getZ1() << endl;

		arqEscrita.close();
	}
}

void Dados::addFigura(CutSphere obj)
{
	if (vrfEscrita && !vrfLeitura)
	{
		arqEscrita.open(arqE, ios::app);

		arqEscrita << fixed << "ctsp" << " "
			<< obj.getX0() << " "
			<< obj.getY0() << " "
			<< obj.getZ0() << " "
			<< obj.getRadius() << endl;

		arqEscrita.close();
	}
}

void Dados::addFigura(CutEllipsoid obj)
{
	if (vrfEscrita && !vrfLeitura)
	{
		arqEscrita.open(arqE, ios::app);

		arqEscrita << fixed << "ctel" << " "
			<< obj.getX0() << " "
			<< obj.getY0() << " "
			<< obj.getZ0() << " "
			<< obj.getRx() << " "
			<< obj.getRy() << " "
			<< obj.getRz() << endl;

		arqEscrita.close();
	}
}
