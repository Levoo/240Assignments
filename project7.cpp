/*
	Author:
	CLass
	Project
	Due:
*/

#include <iostream>
#include <iomanip>
using namespace std;

// variables and functions 
float a = 4.3, b = 6.1, c = 9.5, h = 10.7, l = 15.1, w = 10.6, areaT, preT, areaR, preR;
float half = .5, mulTwo = 2.0;
float t = 2;

void displayMathMenu() {

	cout << "    /| \ " << endl;
	cout << "   / |  \ " << endl;
	cout << "a /  |   \ b" << endl;
	cout << " /  h|    \ " << endl;
	cout << "/    |     \ " << endl;
	cout << "____________ " << endl;
	cout << "      c      " << endl;

	cout << " -------------------------- " << endl;
	cout << " |                        |" << endl;
	cout << " |                        | width" << endl;
	cout << " |                        |" << endl;
	cout << " |                        |" << endl;
	cout << " --------------------------" << endl;
	cout << "             length         " << endl;


	/*cout << " Please enter for a,b,c and h" << endl;
	cin >> a;
	cin >> b;
	cin >> c;
	cin >> h;

	cout << " Please enter for length and width " << endl;
	cin >> l;
	cin >> w;*/
}

// raw progrma need to fiz output and presentation 
int main() {

	// number 1
	_asm {
		call displayMathMenu;
		//1/2*(c*h)
		fld half;

		fld c;
		fld h;
		fmul;
		fmul;
		fstp areaT;

		// a  +b + c
		fld a;
		fld b;
		fld c;
		fadd;
		fadd;

		fstp preT;

		//find stuff for rectangle

		fld w;
		fld l;
		fmul;

		fstp areaR;

		// 2 * w + 1

		fld mulTwo;
		fld w;
		fld l;
		fadd;
		fmul;

		fstp preR;


	}

	std::cout << std::fixed << std::setprecision(2);
	//-------------------------------------------
	std::cout << "AREA T " << areaT << std::endl;
	std::cout << "Permi T " << preT << std::endl;
	//-------------------------------------------
	std::cout << "AREA R " << areaR << std::endl;
	std::cout << "Permi R" << preR << std::endl;

	return 0;
}
