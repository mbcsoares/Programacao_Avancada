#ifndef PUTVOXEL_H
#define PUTVOXEL_H
#include "FiguraGeometrica.h"
#include "Sculptor.h"

#include "CutVoxel.h"
#include "CutBox.h"
#include "CutSphere.h"
#include "CutEllipsoid.h"

#include "PutBox.h"
#include "PutSphere.h"
#include "PutEllipsoid.h"

class PutVoxel : public FiguraGeometrica
{
public:
	PutVoxel();
	PutVoxel(int _x0, int _y0, int _z0, float _r, float _g, float _b, float _a);
	void draw(Sculptor &_figura);

	bool operator==(PutVoxel obj);
	bool operator==(PutBox obj);
	bool operator==(PutSphere obj);
	bool operator==(PutEllipsoid obj);

	bool operator==(CutVoxel obj);
	bool operator==(CutBox obj);
	bool operator==(CutSphere obj);
	bool operator==(CutEllipsoid obj);
};

#endif

