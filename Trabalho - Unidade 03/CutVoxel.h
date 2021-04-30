#ifndef CUTVOXEL_H
#define CUTVOXEL_H
#include "FiguraGeometrica.h"
#include "Sculptor.h"

#include "CutBox.h"
#include "CutSphere.h"
#include "CutEllipsoid.h"

class CutVoxel : public FiguraGeometrica
{
public:
	CutVoxel();
	CutVoxel(int _x, int _y, int _z);
	void draw(Sculptor& _figura);

	bool operator==(CutVoxel obj);
	bool operator==(CutBox obj);
	bool operator==(CutSphere obj);
	bool operator==(CutEllipsoid obj);
};

#endif

