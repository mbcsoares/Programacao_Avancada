#include "FiguraGeometrica.h"
#include "PutBox.h"


FiguraGeometrica::FiguraGeometrica()
{
	x0 = y0 = z0 = 0;
	r = g = b = 0;
	a = 1;
}

void FiguraGeometrica::setX0(int _x0)
{
	x0 = _x0;
}

void FiguraGeometrica::setY0(int _y0)
{
	y0 = _y0;
}

void FiguraGeometrica::setZ0(int _z0)
{
	z0 = _z0;
}

void FiguraGeometrica::setR(float _r)
{
	r = _r;
}

void FiguraGeometrica::setG(float _g)
{
	g = _g;
}

void FiguraGeometrica::setB(float _b)
{
	b = _b;
}

void FiguraGeometrica::setA(float _a)
{
	a = _a;
}

int FiguraGeometrica::getX0(void)
{
	return x0;
}

int FiguraGeometrica::getY0(void)
{
	return y0;
}

int FiguraGeometrica::getZ0(void)
{
	return z0;
}

float FiguraGeometrica::getR(void)
{
	return r;
}

float FiguraGeometrica::getG(void)
{
	return g;
}

float FiguraGeometrica::getB(void)
{
	return b;
}

float FiguraGeometrica::getA(void)
{
	return a;
}
