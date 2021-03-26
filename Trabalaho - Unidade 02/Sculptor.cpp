#include "Sculptor.h"
#include "Voxel.h"
#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

//----------FUNÇÕES PRINCIPAIS---------//

//----1-----//

Sculptor::Sculptor(int _nx, int _ny, int _nz)
{
	nx = ny = nz = 1;

	if (!(_nx < 0 || _ny < 0 || nz < 0))
	{
		nx = _nx;
		ny = _ny;
		nz = _nz;
	}

	rxMax = nx / 2;
	ryMax = ny / 2;
	rzMax = nz / 2;

	alocarMatriz();
}

Sculptor :: ~Sculptor()
{
	liberarMemoria();
}

//----2-----//

void Sculptor::setColor(float _r, float _g, float _b, float alpha)
{
	r = _r;
	g = _g;
	b = _b;
	a = alpha;
}

//----3-Funções PUT-----//

void Sculptor::putVoxel(int _x, int _y, int _z)
{
	if (!(_x < 0 || _x > nx))
	{
		if (!(_y < 0 || _y > nx))
		{
			if (!(_z < 0 || _z > nx))
			{
				matriz[_x][_y][_z].setIsOn(true);

				matriz[_x][_y][_z].setR(r, false);
				matriz[_x][_y][_z].setG(g, false);
				matriz[_x][_y][_z].setB(b, false);
				matriz[_x][_y][_z].setA(a);
			}
		}
	}
}

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
	int x, y, z;

	if ((x1 - x0) > nx || (y1 - y0) > ny || (z1 - z0) > nz)
	{
		return;
	}

	for (x = x0; x <= x1; x++)
	{
		for (y = y0; y <= y1; y++)
		{
			for (z = z0; z <= z1; z++)
			{
				putVoxel(x, y, z);
			}
		}
	}
}

void Sculptor::putSphere(int xCenter, int yCenter, int zCenter, int radius)
{
	int x, y, z;
	float yDelta, zDelta;

	if (radius > rxMax || radius > ryMax || radius > rzMax)
	{
		return;
	}

	for (x = xCenter - radius; x <= xCenter + radius; x++)
	{
		yDelta = sqrt(pow(1.0*radius, 2) - pow(1.0*(x - xCenter), 2));

		for (y = round(yCenter - yDelta); y <= round(yCenter + yDelta); y++)
		{
			zDelta = sqrt(pow(1.0*radius, 2) - pow(1.0*(x - xCenter), 2) - pow(1.0*(y - yCenter), 2));

			for (z = round(zCenter - zDelta); z <= round(zCenter + zDelta); z++)
			{
				putVoxel(x, y, z);
			}
		}
	}
}


void Sculptor::putEllipsoid(int xCenter, int yCenter, int zCenter, int rx, int ry, int rz)
{
	int x, y, z;
	float yDelta, zDelta;

	if (rx > rxMax || ry > ryMax || rz > rzMax)
	{
		return;
	}

	for (x = xCenter - rx; x <= xCenter + rx; x++)
	{
		yDelta = ry * sqrt(1.0 - pow(1.0*(x - xCenter)/rx, 2));

		for (y = round(yCenter - yDelta); y <= round(yCenter + yDelta); y++)
		{
			zDelta = rz * sqrt(1.0 - pow(1.0 * (x - xCenter) / rx, 2) - pow(1.0 * (y - yCenter) / ry, 2));

			for (z = round(zCenter - zDelta); z <= round(zCenter + zDelta); z++)
			{
				putVoxel(x, y, z);
			}
		}
	}
}

//----4-Funções CUT-----//

void Sculptor::cutVoxel(int _x, int _y, int _z)
{
	if (!(_x < 0 || _x > nx))
	{
		if (!(_y < 0 || _y > nx))
		{
			if (!(_z < 0 || _z > nx))
			{
				matriz[_x][_y][_z].setIsOn(false);
			}
		}
	}
}

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
	int x, y, z;

	if ((x1 - x0) > nx || (y1 - y0) > ny || (z1 - z0) > nz)
	{
		return;
	}

	for (x = x0; x <= x1; x++)
	{
		for (y = y0; y <= y1; y++)
		{
			for (z = z0; z <= z1; z++)
			{
				cutVoxel(x, y, z);
			}
		}
	}
}

void Sculptor::cutSphere(int xCenter, int yCenter, int zCenter, int radius)
{
	int x, y, z;
	float yDelta, zDelta;

	if (radius > rxMax || radius > ryMax || radius > rzMax)
	{
		return;
	}

	for (x = xCenter - radius; x <= xCenter + radius; x++)
	{
		yDelta = sqrt(pow(radius, 2) - pow(x - xCenter, 2));

		for (y = round(yCenter - yDelta); y <= round(yCenter + yDelta); y++)
		{
			zDelta = sqrt(pow(radius, 2) - pow(x - xCenter, 2) - pow(y - yCenter, 2));

			for (z = round(zCenter - zDelta); z <= round(zCenter + zDelta); z++)
			{
				cutVoxel(x, y, z);
			}
		}
	}
}

void Sculptor::cutEllipsoid(int xCenter, int yCenter, int zCenter, int rx, int ry, int rz)
{
	int x, y, z;
	float yDelta, zDelta;

	if (rx > rxMax || ry > ryMax || rz > rzMax)
	{
		return;
	}

	for (x = xCenter - rx; x <= xCenter + rx; x++)
	{
		yDelta = ry * sqrt(1.0 - pow(1.0 * (x - xCenter) / rx, 2));

		for (y = round(yCenter - yDelta); y <= round(yCenter + yDelta); y++)
		{
			zDelta = rz * sqrt(1.0 - pow(1.0 * (x - xCenter) / rx, 2) - pow(1.0 * (y - yCenter) / ry, 2));

			for (z = round(zCenter - zDelta); z <= round(zCenter + zDelta); z++)
			{
				cutVoxel(x, y, z);
			}
		}
	}
}

//----4------//

void Sculptor::writeOFF(char *filename)
{
	int x, y, z, n = 0, nVoxels = numberActiveVoxels();
	ofstream arquivo;

	arquivo.open(filename);

	if (!arquivo.is_open())
	{
		exit(0);
	}

	arquivo << "OFF\n";
	arquivo << (8 * nVoxels) << " " << (6 * nVoxels) << " " << "0\n";

	for (x = 0; x < nx; x++)
	{
		for (y = 0; y < ny; y++)
		{
			for (z = 0; z < nz; z++)
			{
				if (matriz[x][y][z].getIsOn() == true)
				{
					arquivo << fixed << (1.01 * x / 1.01) - 0.5 << " " << (1.01 * y / 1.01) + 0.5 << " " << (1.01 * z / 1.01) - 0.5 << "\n"; //P0
					arquivo << fixed << (1.01 * x / 1.01) - 0.5 << " " << (1.01 * y / 1.01) - 0.5 << " " << (1.01 * z / 1.01) - 0.5 << "\n"; //P1
					arquivo << fixed << (1.01 * x / 1.01) + 0.5 << " " << (1.01 * y / 1.01) - 0.5 << " " << (1.01 * z / 1.01) - 0.5 << "\n"; //P2
					arquivo << fixed << (1.01 * x / 1.01) + 0.5 << " " << (1.01 * y / 1.01) + 0.5 << " " << (1.01 * z / 1.01) - 0.5 << "\n"; //P3
					arquivo << fixed << (1.01 * x / 1.01) - 0.5 << " " << (1.01 * y / 1.01) + 0.5 << " " << (1.01 * z / 1.01) + 0.5 << "\n"; //P4
					arquivo << fixed << (1.01 * x / 1.01) - 0.5 << " " << (1.01 * y / 1.01) - 0.5 << " " << (1.01 * z / 1.01) + 0.5 << "\n"; //P5
					arquivo << fixed << (1.01 * x / 1.01) + 0.5 << " " << (1.01 * y / 1.01) - 0.5 << " " << (1.01 * z / 1.01) + 0.5 << "\n"; //P6
					arquivo << fixed << (1.01 * x / 1.01) + 0.5 << " " << (1.01 * y / 1.01) + 0.5 << " " << (1.01 * z / 1.01) + 0.5 << "\n"; //P7
				}
			}
		}
	}

	for (x = 0; x < nx; x++)
	{
		for (y = 0; y < ny; y++)
		{
			for (z = 0; z < nz; z++)
			{
				if (matriz[x][y][z].getIsOn() == true)
				{
					//Face 1
					arquivo << 4 << " " << 0 + n * 8 << " " << 3 + n * 8 << " " << 2 + n * 8 << " " << 1 + n * 8 << " "; //Vertices
					arquivo << fixed << (1.01 * matriz[x][y][z].getR() / 1.01) << " " << (1.01 * matriz[x][y][z].getG() / 1.01) << " " << (1.01 * matriz[x][y][z].getB() / 1.01) << " " << (1.01 * matriz[x][y][z].getA() / 1.01) << "\n"; //Cores
					//Face 2
					arquivo << 4 << " " << 4 + n * 8 << " " << 5 + n * 8 << " " << 6 + n * 8 << " " << 7 + n * 8 << " "; //Vertices
					arquivo << fixed << (1.01 * matriz[x][y][z].getR() / 1.01) << " " << (1.01 * matriz[x][y][z].getG() / 1.01) << " " << (1.01 * matriz[x][y][z].getB() / 1.01) << " " << (1.01 * matriz[x][y][z].getA() / 1.01) << "\n"; //Cores
					//Face 3
					arquivo << 4 << " " << 0 + n * 8 << " " << 1 + n * 8 << " " << 5 + n * 8 << " " << 4 + n * 8 << " "; //Vertices
					arquivo << fixed << (1.01 * matriz[x][y][z].getR() / 1.01) << " " << (1.01 * matriz[x][y][z].getG() / 1.01) << " " << (1.01 * matriz[x][y][z].getB() / 1.01) << " " << (1.01 * matriz[x][y][z].getA() / 1.01) << "\n"; //Cores
					//Face 4
					arquivo << 4 << " " << 0 + n * 8 << " " << 4 + n * 8 << " " << 7 + n * 8 << " " << 3 + n * 8 << " "; //Vertices
					arquivo << fixed << (1.01 * matriz[x][y][z].getR() / 1.01) << " " << (1.01 * matriz[x][y][z].getG() / 1.01) << " " << (1.01 * matriz[x][y][z].getB() / 1.01) << " " << (1.01 * matriz[x][y][z].getA() / 1.01) << "\n"; //Cores
					//Face 5
					arquivo << 4 << " " << 3 + n * 8 << " " << 7 + n * 8 << " " << 6 + n * 8 << " " << 2 + n * 8 << " "; //Vertices
					arquivo << fixed << (1.01 * matriz[x][y][z].getR() / 1.01) << " " << (1.01 * matriz[x][y][z].getG() / 1.01) << " " << (1.01 * matriz[x][y][z].getB() / 1.01) << " " << (1.01 * matriz[x][y][z].getA() / 1.01) << "\n"; //Cores
					//Face 6
					arquivo << 4 << " " << 1 + n * 8 << " " << 2 + n * 8 << " " << 6 + n * 8 << " " << 5 + n * 8 << " "; //Vertices
					arquivo << fixed << (1.01 * matriz[x][y][z].getR() / 1.01) << " " << (1.01 * matriz[x][y][z].getG() / 1.01) << " " << (1.01 * matriz[x][y][z].getB() / 1.01) << " " << (1.01 * matriz[x][y][z].getA() / 1.01) << "\n"; //Cores

					n++;
				}
			}
		}
	}
}



//----------FUNÇÕES SECUNDÁRIAS---------//

void Sculptor::alocarMatriz()
{
	int x, y;

	matriz = new Voxel**[nx];

	for (x = 0; x < nx; x++)
	{
		matriz[x] = new Voxel * [ny];

		for (y = 0; y < ny; y++)
		{
			matriz[x][y] = new Voxel[nz];
		}
	}
}

void Sculptor::liberarMemoria()
{
	int x, y;

	for (x = 0; x < nx; x++)
	{
		for (y = 0; y < ny; y++)
		{
			delete[] (matriz[x][y]);
		}

		delete[] matriz[x];
	}

	delete[] matriz;
}

int Sculptor::numberActiveVoxels(void)
{
	int x, y, z, cont = 0;

	for (x = 0; x < nx; x++)
	{
		for (y = 0; y < ny; y++)
		{
			for (z = 0; z < nz; z++)
			{
				if (matriz[x][y][z].getIsOn())
				{
					cont++;
				}
			}
		}
	}

	return cont;
}



//int coordY(int _x)
//{
//	int y;
//
//	if (0 <= _x && _x < 10)
//	{
//		return y = 1.7321 * _x;
//	}
//	else if (10 <= _x && _x <= 20)
//	{
//		return y = sqrt(400 - (_x) * (_x));
//	}
//
//	return 0;
//}
//
//int coordZ1(int _x, int _y)
//{
//	int z;
//
//	if ((_x * _x + _y * _y) <= 94.35)
//	{
//		return z = 51.98 - sqrt(94.35 - _x * _x - _y * _y);
//	}
//	if ((_x * _x + _y * _y) <= 400)
//	{
//		return z = 10.0 * sqrt(_x * _x + _y * _y) + 51.98;
//	}
//
//	return 0;
//}
//
//int coordZ2(int _x, int _y)
//{
//	int z;
//
//	return z = 3.50 * sqrt(_x * _x + _y * _y) + 150;
//}


//void Sculptor::FogueteP01(int r1, int r2)
//{
//	int x, y, z;
//	float yDelta, zDelta;
//	int xo, yo, zo;
//
//	xo = nx / 2;
//	yo = ny / 2;
//	zo = 0;
//
//	for (x = xo - r1; x <= xo + r1; x++)
//	{
//		yDelta = sqrt(pow(r1, 2) - pow(1.0 * (x - xo), 2));
//
//		for (y = round(yo - yDelta); y <= round(yo + yDelta); y++)
//		{
//			zDelta = sqrt( pow(r1, 2) - pow(1.0 * (x - xo), 2) - pow(1.0 * (y - yo), 2) );
//
//			for (z = 42 + round(zDelta); z <= 52; z=z+1)
//			{
//				cout << zDelta << endl;
//				//cutVoxel(x, y, z);
//			}
//		}
//
//	}



	/*int x, y, z;
	float yDelta, zDelta;

	if (radius > rxMax || radius > ryMax || radius > rzMax)
	{
		return;
	}

	for (x = xCenter - radius; x <= xCenter + radius; x++)
	{
		yDelta = sqrt(pow(radius, 2) - pow(x - xCenter, 2));

		for (y = round(yCenter - yDelta); y <= round(yCenter + yDelta); y++)
		{
			zDelta = sqrt(pow(radius, 2) - pow(x - xCenter, 2) - pow(y - yCenter, 2));

			for (z = round(zCenter - zDelta); z <= round(zCenter + zDelta); z++)
			{
				cutVoxel(x, y, z);
			}
		}
	}*/




