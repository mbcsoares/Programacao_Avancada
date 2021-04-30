#include "PutVoxel.h"
#include "Sculptor.h"

PutVoxel::PutVoxel()
{
	x0 = y0 = z0 = 0;
	r = g = b = 0;
	a = 1;
}

PutVoxel::PutVoxel(int _x0, int _y0, int _z0, float _r, float _g, float _b, float _a)
{
	x0 = _x0;
	y0 = _y0;
	z0 = _z0;
	r = _r;
	g = _g;
	b = _b;
	a = _a;
}

void PutVoxel::draw(Sculptor &_figura)
{
	_figura.setColor(r, g, b, a);
	_figura.putVoxel(x0, y0, z0);
}

bool PutVoxel::operator==(PutVoxel obj)
{
	return true;
}

bool PutVoxel::operator==(PutBox obj)
{
	return false;
}

bool PutVoxel::operator==(PutSphere obj)
{
	return false;
}

bool PutVoxel::operator==(PutEllipsoid obj)
{
	return false;
}

bool PutVoxel::operator==(CutVoxel obj)
{
	return false;
}

bool PutVoxel::operator==(CutBox obj)
{
	return false;
}

bool PutVoxel::operator==(CutSphere obj)
{
	return false;
}

bool PutVoxel::operator==(CutEllipsoid obj)
{
	return false;
}
