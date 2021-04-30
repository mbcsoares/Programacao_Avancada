#include "CutSphere.h"
#include "Sculptor.h"

CutSphere::CutSphere()
{
	x0 = y0 = z0 = -1;
	radius = 0;
}

CutSphere::CutSphere(int _x0, int _y0, int _z0, int _radius)
{
	x0 = _x0;
	y0 = _y0;
	z0 = _z0;
	radius = _radius;
}

void CutSphere::draw(Sculptor& _figura)
{
	_figura.cutSphere(x0, y0, z0, radius);
}

bool CutSphere::operator==(CutSphere obj)
{
	return true;
}

bool CutSphere::operator==(CutEllipsoid obj)
{
	return false;
}

void CutSphere::setRadius(int _radius)
{
	radius = _radius;
}

int CutSphere::getRadius(void)
{
	return radius;
}
