#ifndef PUTBOX_H
#define PUTBOX_H
#include "FiguraGeometrica.h"
#include "Sculptor.h"

#include "CutVoxel.h"
#include "CutBox.h"
#include "CutSphere.h"
#include "CutEllipsoid.h"

#include "PutSphere.h"
#include "PutEllipsoid.h"

class PutBox : public FiguraGeometrica
{
private:
	int x1, y1, z1;
	float r, g, b;
	float a;

public:
	PutBox();
	PutBox(int _x0, int _x1, int _y0, int _y1, int _z0, int _z1, float _r, float _g, float _b, float _a);
	void draw(Sculptor& _figura);

	bool operator==(PutBox obj);
	bool operator==(PutSphere obj);
	bool operator==(PutEllipsoid obj);

	bool operator==(CutVoxel obj);
	bool operator==(CutBox obj);
	bool operator==(CutSphere obj);
	bool operator==(CutEllipsoid obj);
};

#endif

