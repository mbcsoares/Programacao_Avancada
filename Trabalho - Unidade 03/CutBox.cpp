#include "CutBox.h"

CutBox::CutBox()
{
	x0 = y0 = z0 = -1;
	x1 = y1 = z1 = -2;
}

CutBox::CutBox(int _x0, int _x1, int _y0, int _y1, int _z0, int _z1)
{
	x0 = _x0;
	y0 = _y0;
	z0 = _z0;
	x1 = _x1;
	y1 = _y1;
	z1 = _z1;
}

void CutBox::draw(Sculptor& _figura)
{
	_figura.cutBox(x0, x1, y0, y1, z0, z1);
}

bool CutBox::operator==(CutBox obj)
{
	return true;
}

bool CutBox::operator==(CutSphere obj)
{
	return false;
}

bool CutBox::operator==(CutEllipsoid obj)
{
	return false;
}

void CutBox::setX1(int _x1)
{
	x1 = _x1;
}

void CutBox::setY1(int _y1)
{
	y1 = _y1;
}

void CutBox::setZ1(int _z1)
{
	z1 = _z1;
}

int CutBox::getX1(void)
{
	return x1;
}

int CutBox::getY1(void)
{
	return y1;
}

int CutBox::getZ1(void)
{
	return z1;
}
