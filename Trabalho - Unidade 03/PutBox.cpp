#include "PutBox.h"

PutBox::PutBox()
{
	x0 = y0 = z0 = 0;
	x1 = y1 = z1 = 1;
	r = g = b = 0;
	a = 1;
}

PutBox::PutBox(int _x0, int _x1, int _y0, int _y1, int _z0, int _z1, float _r, float _g, float _b, float _a)
{
	x0 = _x0;
	y0 = _y0;
	z0 = _z0;
	x1 = _x1;
	y1 = _y1;
	z1 = _z1;
	r = _r;
	g = _g;
	b = _b;
	a = _a;
}

void PutBox::draw(Sculptor& _figura)
{
	_figura.setColor(r, g, b, a);
	_figura.putBox(x0, x1, y0, y1, z0, z1);
}

bool PutBox::operator==(PutBox obj)
{
	return true;
}

bool PutBox::operator==(PutSphere obj)
{
	return false;
}

bool PutBox::operator==(PutEllipsoid obj)
{
	return false;
}

bool PutBox::operator==(CutVoxel obj)
{
	return false;
}

bool PutBox::operator==(CutBox obj)
{
	return false;
}

bool PutBox::operator==(CutSphere obj)
{
	return false;
}

bool PutBox::operator==(CutEllipsoid obj)
{
	return false;
}

void PutBox::setX1(int _x1)
{
	x1 = _x1;
}

void PutBox::setY1(int _y1)
{
	y1 = _y1;
}

void PutBox::setZ1(int _z1)
{
	z1 = _z1;
}

int PutBox::getX1(void)
{
	return x1;
}

int PutBox::getY1(void)
{
	return y1;
}

int PutBox::getZ1(void)
{
	return z1;
}
