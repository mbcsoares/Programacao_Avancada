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
	if (_x > 0 || _x < nx)
	{
		if (_y > 0 || _y < ny)
		{
			if (_z > 0 || _z < nz)
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


//-----FEUNÇÕES SECUNDÁRIAS-----//


//---ESCULTURA DE UM FOGUETE---//


void Sculptor::DesenhoFoguete(void)
{
	int x, y, z;
	float yDelta, zDelta;
	int xo, yo, zo;
	int r1, r2;

	r2 = ny / 2;
	r1 = r2 / 2;

	if (nx < ny) //menor valor entre nx e ny
	{
		r2 = nx / 2;
		r1 = r2 / 2;
	}

	xo = nx / 2;
	yo = ny / 2;
	zo = nz / 4;

	cout << "r2 = " << r2 << endl;
	cout << "r1 = " << r1 << endl;

	for (x = xo - r1; x <= xo + r1; x++) //semi-esfera
	{
		yDelta = sqrt(pow(r1, 2) - pow(1.0 * (x - xo), 2));

		cout << "x = " << x << endl;

		for (y = round(yo - yDelta); y <= round(yo + yDelta); y++)
		{
			if (pow(r1, 2) >= pow(x - xo, 2) + pow(y - yo, 2) && pow(0.5 * r1, 2) <= pow(x - xo, 2) + pow(y - yo, 2))
			{
				zDelta = sqrt(pow(r1, 2) - pow(1.0 * (x - xo), 2) - pow(1.0 * (y - yo), 2));

				cout << "y = " << y << endl;

				for (z = zo - round(zDelta); z <= zo; z++)
				{
					if (pow(r1, 2) >= (pow(x - xo, 2) + pow(y - yo, 2) + pow(z - zo, 2)) && pow(0.8*r1, 2) <= (pow(x - xo, 2) + pow(y - yo, 2) + pow(z - zo, 2)) && pow(r1, 2))
					{
						setColor(.20, 0.20, 0.20, 1);

						putVoxel(x, y, z);

						cout << "z = " << z << endl;
					}
				}
			}
		}

	}

	for (x = xo - r2; x <= xo + r2; x++) //corpo do foguete - tronco de cone mais cone da ponta
	{
		yDelta = sqrt(pow(r2, 2) - pow(1.0 * (x - xo), 2));

		cout << "x2 = " << x << endl;


		for (y = round(yo - yDelta); y <= round(yo + yDelta); y++) //tronco de cone
		{
			if (pow(r2, 2) >= (pow(x - xo, 2) + pow(y - yo, 2)) && pow(0.8 * r1, 2) <= (pow(x - xo, 2) + pow(y - yo, 2)))
			{
				zDelta = 10 * (sqrt(pow(1.0 * (x - xo), 2) + pow(1.0 * (y - yo), 2)) - r1);

				cout << "y2 = " << y << endl;

				for (z = zo + round(zDelta); z <= zo + round(zDelta) + 1.2 * r2; z++)
				{
					if (z >= zo && z <= round(7.5 * r2))
					{
						setColor(.75, 0.75, .75, 1);

						if (z >= 7.05 * r2 && z <= 7.15 * r2)
						{
							setColor(1.0, 0, 0, 1);
						}

						putVoxel(x, y, z);

						cout << "z2 = " << z << endl;
					}
					
				}
			}

			zDelta = 3.5 * (sqrt(pow(1.0 * (x - xo), 2) + pow(1.0 * (y - yo), 2)));

			cout << "zDelta3 = " << zDelta << endl;

			for (z = nz - round(zDelta) - 0.425 * r2; z <= nz - round(zDelta); z++) //cone
			{
				if (z < nz && z > round(7.5 * r2))
				{
					setColor(.75, 0.75, .75, 1);

					if (z >= 8.05 * r2 && z <= 8.15 * r2)
					{
						setColor(1.0, 0, 0, 1);
					}

					putVoxel(x, y, z);

					cout << "z3 = " << z << endl;
				}

			}
		}



	}

	for (y = yo - .05 * r2; y <= yo + .05 * r2; y++)
	{
		for (x = xo - r2; x < xo + r2; x++)
		{
			if (pow(x - xo, 2) >= pow(0.265 * r2, 2) && pow(x - xo, 2) <= pow(nx / 2, 2))
			{
				zDelta = 3.4 * (sqrt(pow(x - xo, 2)) - 0.265 * r2);

				for (z = round(zDelta); z <= 5.0 * r2 - round(zDelta); z++)
				{
					if (z <= 3.75 * r2)
					{
						setColor(.40, .40, .40, 1);

						if (z >= 2.45 * r2 && z <= 2.55 * r2)
						{
							setColor(1.0, 0, 0, 1);
						}

						putVoxel(x, y, z);
						cout << "z4 = " << z << endl;
					}


				}
			}

		}
	}

	for (x = xo - .05 * r2; x <= xo + .05 * r2; x++)
	{
		for (y = yo - r2; y < yo + r2; y++)
		{
			if (pow(y - yo, 2) >= pow(0.265 * r2, 2) && pow(y - yo, 2) <= pow(ny / 2, 2))
			{
				zDelta = 3.4 * (sqrt(pow(y - yo, 2)) - 0.265 * r2);

				for (z = round(zDelta); z <= 5.0 * r2 - round(zDelta); z++)
				{
					if (z <= 3.75 * r2)
					{
						setColor(.40, .40, .40, 1);

						if (z >= 2.45 * r2 && z <= 2.55 * r2)
						{
							setColor(1.0, 0, 0, 1);
						}

						putVoxel(x, y, z);
						cout << "z4 = " << z << endl;
					}


				}
			}

		}
	}
}