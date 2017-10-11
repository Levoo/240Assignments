#include <iostream>
#include <iomanip>
using namespace std;

float a = 2.1f, b = 4.5f, c = 1.7f,d;
float four = 4.0f, two = 2.0f; 
float negative = -1.0f, nb;
float x1, x2; 

void printRootMenu()
{
	cout << " To see the real roots of aX^2 + bX + c = 0, enter the a, b and c values:" << endl; 
	cin >> a >> b >> c; 
}

void printValues()
{
	cout << fixed << setprecision(2);
	cout << "X1 = " << x1 << "  X2 = " << x2;
}

int main()
{
	_asm 
	{
		//b^2
		fld b
		fld b
		fmul
		// 4ac
		fld four
		fld a
		fld c
		fmul
		fmul
		// sqrt(b^2 - 4ac)
		fsub
		fsqrt

		fstp d; d = sqrt(b ^ 2 - 4ac)

		// -b
		fld b
		fld negative
		fmul
		fstp nb

		// -b + sqrt(b^2 - 4ac)
		fld nb
		fld d
		fadd

		// -b + sqrt(b^2 - 4ac)/2a
		fld a
		fld two
		fmul
		fdiv
		fstp x1; x1 = -b + sqrt(b ^ 2 - 4ac)

		fld nb
		fld d
		fsub

		fld a
		fld two
		fmul
		fdiv
		fstp x2; 

		call printValues

	}
	return 0;
}