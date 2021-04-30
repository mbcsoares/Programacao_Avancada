#include "PutEllipsoid.h"
#include "Sculptor.h"

PutEllipsoid::PutEllipsoid()
{
	x0 = y0 = z0 = 1;
	rx = ry = rz = 1;
	r = g = b = 0;
	a = 1;
}

PutEllipsoid::PutEllipsoid(int _x0, int _y0, int _z0, int _rx, int _ry, int _rz, float _r, float _g, float _b, float _a)
{
	x0 = _x0;
	y0 = _y0;
	z0 = _z0;
	rx = _rx;
	ry = _ry;
	rz = _rz;
	r = _r;
	g = _g;
	b = _b;
	a = _a;
}

void PutEllipsoid::draw(Sculptor& _figura)
{
	_figura.setColor(r, g, b, a);
	_figura.putEllipsoid(x0, y0, z0, rx, ry, rz);
}

bool PutEllipsoid::operator==(PutEllipsoid obj)
{
	return true;
}

bool PutEllipsoid::operator==(CutVoxel obj)
{
	return false;
}

bool PutEllipsoid::operator==(CutBox obj)
{
	return false;
}

bool PutEllipsoid::operator==(CutSphere obj)
{
	return false;
}

bool PutEllipsoid::operator==(CutEllipsoid obj)
{
	return false;
}

void PutEllipsoid::setRx(int _rx)
{
	rx = _rx;
}

void PutEllipsoid::setRy(int _ry)
{
	ry = _ry;
}

void PutEllipsoid::setRz(int _rz)
{
	rz = _rz;
}

int PutEllipsoid::getRx(void)
{
	return rx;
}

int PutEllipsoid::getRy(void)
{
	return ry;
}

int PutEllipsoid::getRz(void)
{
	return rz;
}
