#include "CutEllipsoid.h"
#include "Sculptor.h"

CutEllipsoid::CutEllipsoid()
{
	x0 = y0 = z0 = -1;
	rx = ry = rz = 0;
}

CutEllipsoid::CutEllipsoid(int _x0, int _y0, int _z0, int _rx, int _ry, int _rz)
{
	x0 = _x0;
	y0 = _y0;
	z0 = _z0;
	rx = _rx;
	ry = _ry;
	rz = _rz;
}

void CutEllipsoid::draw(Sculptor& _figura)
{
	_figura.cutEllipsoid(x0, y0, z0, rx, ry, rz);
}

bool CutEllipsoid::operator==(CutEllipsoid obj)
{
	return true;
}

void CutEllipsoid::setRx(int _rx)
{
	rx = _rx;
}

void CutEllipsoid::setRy(int _ry)
{
	ry = _ry;
}

void CutEllipsoid::setRz(int _rz)
{
	rz = _rz;
}

int CutEllipsoid::getRx(void)
{
	return rx;
}

int CutEllipsoid::getRy(void)
{
	return ry;
}

int CutEllipsoid::getRz(void)
{
	return rz;
}
