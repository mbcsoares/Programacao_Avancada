#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H
#include "FiguraGeometrica.h"
#include "Sculptor.h"

#include "CutVoxel.h"
#include "CutBox.h"
#include "CutSphere.h"
#include "CutEllipsoid.h"

class PutEllipsoid : public FiguraGeometrica
{
private:
	int rx, ry, rz;

public:
	PutEllipsoid();
	PutEllipsoid(int _x0, int _y0, int _z0, int _rx, int _ry, int _rz, float _r, float _g, float _b, float _a);
	void draw(Sculptor& _figura);

	bool operator==(PutEllipsoid obj);

	bool operator==(CutVoxel obj);
	bool operator==(CutBox obj);
	bool operator==(CutSphere obj);
	bool operator==(CutEllipsoid obj);

	void setRx(int _rx);
	void setRy(int _ry);
	void setRz(int _rz);

	int getRx(void);
	int getRy(void);
	int getRz(void);
};

#endif

