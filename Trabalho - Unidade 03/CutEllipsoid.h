#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H
#include "FiguraGeometrica.h"
#include "Sculptor.h"

class CutEllipsoid : public FiguraGeometrica
{
private:
	int rx, ry, rz;

public:
	CutEllipsoid();
	CutEllipsoid(int _x0, int _y0, int _z0, int _rx, int _ry, int _rz);
	void draw(Sculptor& _figura);

	bool operator==(CutEllipsoid obj);
};

#endif