#ifndef PUTSPHERE_H
#define PUTSPHERE_H
#include "FiguraGeometrica.h"
#include "Sculptor.h"

#include "CutVoxel.h"
#include "CutBox.h"
#include "CutSphere.h"
#include "CutEllipsoid.h"

#include "PutEllipsoid.h"

class PutSphere : public FiguraGeometrica
{
private:
	int radius;
	float r, g, b;
	float a;

public:
	PutSphere();
	PutSphere(int _x0, int _y0, int _z0, int _radius, float _r, float _g, float _b, float _a);
	void draw(Sculptor& _figura);

	bool operator==(PutSphere obj);
	bool operator==(PutEllipsoid obj);

	bool operator==(CutVoxel obj);
	bool operator==(CutBox obj);
	bool operator==(CutSphere obj);
	bool operator==(CutEllipsoid obj);
};

#endif

