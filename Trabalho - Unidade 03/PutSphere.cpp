#include "PutSphere.h"
#include "Sculptor.h"

PutSphere::PutSphere()
{
	x0 = y0 = z0 = 1;
	radius = 1;
	r = g = b = 0;
	a = 1;
}

PutSphere::PutSphere(int _x0, int _y0, int _z0, int _radius, float _r, float _g, float _b, float _a)
{
	x0 = _x0;
	y0 = _y0;
	z0 = _z0;
	radius = _radius;
	r = _r;
	g = _g;
	b = _b;
	a = _a;
}

void PutSphere::draw(Sculptor& _figura)
{
	_figura.setColor(r, g, b, a);
	_figura.putSphere(x0, y0, z0, radius);
}

bool PutSphere::operator==(PutSphere obj)
{
	return true;
}

bool PutSphere::operator==(PutEllipsoid obj)
{
	return false;
}

bool PutSphere::operator==(CutVoxel obj)
{
	return false;
}

bool PutSphere::operator==(CutBox obj)
{
	return false;
}

bool PutSphere::operator==(CutSphere obj)
{
	return false;
}

bool PutSphere::operator==(CutEllipsoid obj)
{
	return false;
}
