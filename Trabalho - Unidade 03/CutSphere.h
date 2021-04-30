#ifndef CUTSPHERE_H
#define CUTSPHERE_H
#include "FiguraGeometrica.h"
#include "Sculptor.h"

#include "CutEllipsoid.h"

class CutSphere : public FiguraGeometrica
{
private:
	int radius;

public:
	CutSphere();
	CutSphere(int _x0, int _y0, int _z0, int _radius);
	void draw(Sculptor& _figura);

	bool operator==(CutSphere obj);
	bool operator==(CutEllipsoid obj);
};

#endif

