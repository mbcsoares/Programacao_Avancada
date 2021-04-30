#pragma once

struct Voxel
{
private:
	float r, g, b; //Cores
	float a; //Transparencia
	bool isOn; //=True -> Incluir elemento no desenho

public:
	Voxel();

	void setR(float intensidade, bool max255);
	float getR(void);

	void setG(float intensidade, bool max255);
	float getG(void);

	void setB(float intensidade, bool max255);
	float getB(void);

	void setA(float a_);
	float getA(void);

	void setIsOn(bool isOn_);
	bool getIsOn(void);
};

