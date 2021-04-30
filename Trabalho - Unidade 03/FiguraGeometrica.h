#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H
#include "Sculptor.h"

class FiguraGeometrica
{
protected:
	int x0, y0, z0; //COORDENADAS INICIAIS
	float r, g, b; //COR 0->1
	float a; //TRANSPARENCIA 0->1

public:
	FiguraGeometrica();
	virtual void draw(Sculptor &_figura) = 0; //método virtual

	void setX0(int _x0);
	void setY0(int _y0);
	void setZ0(int _z0);
	void setR(float _r);
	void setG(float _g);
	void setB(float _b);
	void setA(float _a);

	int getX0(void);
	int getY0(void);
	int getZ0(void);
	float getR(void);
	float getG(void);
	float getB(void);
	float getA(void);
};

#endif

