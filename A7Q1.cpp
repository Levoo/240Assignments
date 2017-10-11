#include <iostream>
#include <iomanip>
using namespace std;

float Tarea, TPerimeter, Rarea, RPerimeter;
float a = 4.3f, b = 6.1f, c = 9.5f, h = 10.7f;
float l = 15.1f, w = 10.6f;
float half = .5f, timesTwo = 2.0f;

void printShapes()
{
	cout << "    /| \\ " << endl;
	cout << "   / |  \\ " << endl;
	cout << "a /  |   \\ b" << endl;
	cout << " /  h|    \\ " << endl;
	cout << "/    |     \\ " << endl;
	cout << "____________ " << endl;
	cout << "      c      " << endl;

	cout << " -------------------------- " << endl;
	cout << " |                        |" << endl;
	cout << " |                        | width" << endl;
	cout << " |                        |" << endl;
	cout << " |                        |" << endl;
	cout << " --------------------------" << endl;
	cout << "             length         " << endl;

	cout << "What is the vaule of a?" << endl; 
	cin >> a; 
	cout << "What is the vaule of b?" << endl;
	cin >> b;
	cout << "What is the vaule of c?" << endl;
	cin >> c;
	cout << "What is the vaule of h?" << endl;
	cin >> h;
	cout << "What is the vaule of length?" << endl;
	cin >> l;
	cout << "What is the vaule of width?" << endl;
	cin >> w; 

}

void printVaules()
{
	cout << fixed << setprecision(2);
	cout << "Triangle" << endl;
	cout << "Area................" << Tarea << endl;
	cout << "Permeter............" << TPerimeter << endl;
	cout << "Rectangle" << endl;
	cout << "Area................" << Rarea << endl;
	cout << "Permeter............" << RPerimeter << endl;

}

int main()
{
	_asm
	{
		call printShapes

		fld a;
		fld b;
		fld c;
		fadd;
		fadd;
		fstp TPerimeter;

		fld half;
		fld c;
		fld h;
		fmul;
		fmul;
		fstp Tarea;

		fld w
			fld l
			fmul;

		fstp Rarea;

		fld timesTwo;
		fld l;
		fld w;
		fadd;
		fmul;

		fstp RPerimeter;

		call printVaules

	}
	return 0;
}

