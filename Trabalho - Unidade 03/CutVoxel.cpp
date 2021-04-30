#include "CutVoxel.h"
#include "Sculptor.h"

CutVoxel::CutVoxel()
{
	x0 = y0 = z0 = -1;
}

CutVoxel::CutVoxel(int _x, int _y, int _z)
{
	x0 = _x;
	y0 = _y;
	z0 = _z;
}

void CutVoxel::draw(Sculptor& _figura)
{
	_figura.cutVoxel(x0, y0, z0);
}

bool CutVoxel::operator==(CutVoxel obj)
{
	return true;
}

bool CutVoxel::operator==(CutBox obj)
{
	return false;
}

bool CutVoxel::operator==(CutSphere obj)
{
	return false;
}

bool CutVoxel::operator==(CutEllipsoid obj)
{
	return false;
}
