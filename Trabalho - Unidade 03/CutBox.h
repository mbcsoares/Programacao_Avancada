#ifndef CUTBOX_H
#define CUTBOX_H
#include "FiguraGeometrica.h"
#include "Sculptor.h"

#include "CutSphere.h"
#include "CutEllipsoid.h"

class CutBox : public FiguraGeometrica
{
private:
	int x1, y1, z1;

public:
	CutBox();
	CutBox(int _x0, int _x1, int _y0, int _y1, int _z0, int _z1);
	void draw(Sculptor& _figura);

	bool operator==(CutBox obj);
	bool operator==(CutSphere obj);
	bool operator==(CutEllipsoid obj);

	void setX1(int _x1);
	void setY1(int _y1);
	void setZ1(int _z1);

	int getX1(void);
	int getY1(void);
	int getZ1(void);
	
};

#endif


