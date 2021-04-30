#include "Dados.h"

Dados::Dados()
{
	num = 0;
}

Dados::Dados(int _num)
{
	num - _num;
}

void Dados::leitura(char *_arqNome)
{
	arqL[0] = *_arqNome;

	arqLeitura.open(arqL);

	arqLeitura >> fixed >> num;

	arqLeitura.close();

	vrfLeitura = true;
}

void Dados::escrita(char* _arqNome)
{
	arqE[0] = *_arqNome;

	arqEscrita.open(arqE);

	arqEscrita << fixed << num << endl;

	arqEscrita.close();

	vrfEscrita = true;
}

void Dados::setNum(int _num)
{
	num = _num;
}

int Dados::getNum(void)
{
	return num;
}

void Dados::addFigura(PutVoxel obj)
{
	if (vrfEscrita)
	{
		arqEscrita.open(arqE, ios::app);

		arqEscrita << fixed << "ptvx";
	}
	
}

void Dados::addFigura(PutBox obj)
{
}

void Dados::addFigura(PutSphere obj)
{
}

void Dados::addFigura(PutEllipsoid obj)
{
}

void Dados::addFigura(CutVoxel obj)
{
}

void Dados::addFigura(CutBox obj)
{
}

void Dados::addFigura(CutSphere obj)
{
}

void Dados::addFigura(CutEllipsoid obj)
{
}
