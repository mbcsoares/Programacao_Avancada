#include "Voxel.h"
#include <iostream>


Voxel::Voxel()
{
	r = g = b = 0.0;
	a = 1.0;
	isOn = false;
}

void Voxel:: setR(float intensidade, bool max255)
{
	if (intensidade >= 0)
	{
		r = intensidade;

		if (max255)
		{
			r = intensidade / 255.0;
		}
	}
}
float Voxel::getR(void)
{
	return r;
}

void Voxel::setG(float intensidade, bool max255)
{
	if (intensidade >= 0)
	{
		g = intensidade;

		if (max255)
		{
			g = intensidade / 255.0;
		}
	}
}
float Voxel::getG(void)
{
	return g;
}

void Voxel::setB(float intensidade, bool max255)
{
	if (intensidade >= 0)
	{
		b = intensidade;

		if (max255)
		{
			b = intensidade / 255.0;
		}
	}
}
float Voxel::getB(void)
{
	return b;
}

void Voxel::setA(float opacidade)
{
	if (opacidade <= 1.0 || opacidade >= 0.0)
	{
		a = opacidade;
	}
}
float Voxel::getA(void)
{
	return a;
}

void Voxel::setIsOn(bool isOn_)
{
	isOn = isOn_;
}
bool Voxel::getIsOn(void)
{
	return isOn;
}