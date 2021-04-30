#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H
#include "Sculptor.h"

class FiguraGeometrica
{
protected:
	int x0, y0, z0; //COORDENADAS INICIAIS

public:
	FiguraGeometrica();
	virtual void draw(Sculptor &_figura) = 0; //método virtual
};

#endif

