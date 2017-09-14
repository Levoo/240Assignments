/*
Project: Assignment 3
Class: CPSC 240
Professor: Dr. Ray Ahmadnia
Authors: Cuevas, Fernando
Huang, Justin
Due: 9/14/2017
*/
 
#include <iostream>
#include <string>
using namespace std; 

short int a, b, c, d, e, f;
short int X, Y;

void displayXYMenu()
{
	cout << "This program solves the system\n\taX + bY = c\n\tdX + eY = f\n";

	cout << "Enter the values of a, b and c: ";
	cin >> a >> b >> c;

	cout << "Enter the values of d, e and f: ";
	cin >> d >> e >> f;
}
	void printXYresults() 
	{
		cout << "\tX = " << X << "\n\tY = " << Y << endl;
	}




int main() {
	_asm {
		call displayXYMenu;
	getY:
		// find a*f - c * d
		mov ax, a;
		imul f;
		mov bx, ax;
		mov ax, c;
		imul d;
		sub bx, ax;
		mov cx, bx;
		// find a*e - b * d
		mov ax, a; move a in ax multiply by e
			imul e;
		mov bx, ax; move ax into bx for stroage
			mov ax, b; move b in ax and multiply with d
			imul d;
		sub bx, ax; subtract bx with ax
			mov ax, cx; move result into cx, which is the numerator
			// divide numerator with denominato
			cwd;		convert to double word and then divid
			idiv bx;
		mov Y, ax;
	getX:
		//find c*e - b*f
		mov ax, c;
		imul e;
		mov bx, ax;
		mov ax, b;
		imul f;
		sub bx, ax;
		mov cx, bx;
		//find a*e - b*d
		mov ax, a;
		imul e;
		mov bx, ax;
		mov ax, b;
		imul d;
		sub bx, ax;
		mov ax, cx;
		//divide
		cwd;
		idiv bx;
		mov X, ax;
	display:
		call printXYresults;
	}
	return 0;
}
/*
------------------OUTPUT--------------------

This program solves the system
aX + bY = c
dX + eY = f
Enter the values of a, b and c: 3 1 1
Enter the values of d, e and f: 1 -2 5
X = 1
Y = -2
Press any key to continue . . .
*/