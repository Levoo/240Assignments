/*
Author:
CLass
Project
Due:
*/

#include <iostream>
#include <iomanip>
using namespace std;

// NOTE: make sure to uncomment the cin's so the user can test and remove any values given.

// variables and functions 
float a = 4.3f, b = 6.1f, c = 9.5f, h = 10.7f, l = 15.1f, w = 10.6f, areaT, preT, areaR, preR;
float half = .5f, mulTwo = 2.0f;
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

void displayResults() {
	std::cout << std::fixed << std::setprecision(2);
	//-------------------------------------------
	std::cout << "Triangle\n";
	std::cout << "\tArea...................... " << areaT << std::endl;
	std::cout << "\tPerimeter................. " << preT << std::endl;
	//-------------------------------------------
	std::cout << "Rectangle\n";
	std::cout << "\tArea...................... " << areaR << std::endl;
	std::cout << "\tPerimeter................. " << preR << std::endl;
	//-------------------------------------------
}

// question 2 stuff
float rA = 2.1f, rB = 4.5f, rC = 1.7f, rD, x1, x2, four = 4.0f, two = 2.0f;
float negative = -1.0f, nrB;

void displayRootsMenu() {
	std::cout << "\nTo see the real roots of aX^2 + bX + c = 0, enter the a, b and c values:" << std::endl;
	//std::cin >> rA >> rB >> rC;
}

void displayRoots() {
	std::cout << "\tx1 = " << x1 << "  x2 = " << x2 << std::endl;
}

//question 3 stuff 

float totalPrice;
float amtDrink = 2, amtFood = 3;
float sodaPrice = 2.25f, waterPrice = 1.75f;
float sub10inchPrice = 3.45f, sub12inchPrice = 5.25f;
int userChoiceSub = 10;
float temp;
char userChoiceDrink = 'S';

void displayMenuStore() {
	std::cout << "-----------------------------7-11 Convienient Store------------------------------\n";
	std::cout << " Drinks\n\tSoda(S)...................................$2.25\n";
	std::cout << "\tWater(W).....................................$1.75\n";
	std::cout << " Sandwiches\n\t10 inches.............................$3.45\n";
	std::cout << "\t12 inches......................................$5.25\n\n";
}

void getStoreOrder() {
	std::cout << "  How many drinks? ";
	std::cin >> amtDrink;

	std::cout << "\tWhat kind of drink?(S=Soda, W=Water) ";
	std::cin >> userChoiceDrink;

	std::cout << "\n  How many sandwiches? ";
	std::cin >> amtFood;

	std::cout << "\tWhat size of sandwich(10/12 inches)? ";
	std::cin >> userChoiceSub;
}

void totalBill() {
	std::cout << " Your total bill = " << totalPrice << std::endl;
}

// raw progrma need to fix output and presentation 
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

		call displayResults;


	}

	//part 2
	_asm {
		call displayRootsMenu;
		// have d equal sqrt(b^2 - 4ac)
		fld rB;
		fld rB;

		fmul;

		fld four;
		fld rA;
		fld rC;

		fmul;
		fmul;
		fsub;
		fsqrt;

		fstp rD;
		// turn b to negative 
		fld rB;
		fld negative;
		fmul;
		fstp nrB;

		// do -b + d / 2a

		fld nrB;
		fld rD;

		fadd;
		fld two;
		fld rA;
		fmul;
		fdiv;
		fstp x1;

		// -b-d / 2a
		fld nrB;
		fld rD;

		fsub;
		fld two;
		fld rA;
		fmul;
		fdiv;
		fstp x2;

		call displayRoots;
	}

	//part 3 
	_asm {
		call displayMenuStore;
		//call getStoreOrder;
	whatDrinkType:
				fld amtDrink;
				mov  bl, 'S'; move S into al, this is to not have another variable to compare
				cmp  userChoiceDrink, bl;  compare what the user entered
				jne  choiceWater;  if the user entered S then keep going though else go to choiceWater
		
			choiceSoda : //go here is user chooses soda
				fld sodaPrice;

				jmp whatSubSize;
		
			choiceWater: // else choose water
				fld waterPrice;
		
			whatSubSize: //next part will handle what sub size
				fld amtFood;
				mov  ecx, 10;
				cmp  userChoiceSub, ecx;
				jne  subChoice12;
		
			subChoice10:
				fld sub10inchPrice;
				fmul;

				fstp totalPrice;

				fmul;
				fstp temp;

				fld totalPrice;
				fld temp;

				fadd;
				fstp totalPrice;

				jmp displayRecipte;
		
			subChoice12:
				fld sub12inchPrice;
				fmul;

				fstp totalPrice;

				fmul;
				fstp temp;

				fld totalPrice;
				fld temp;

				fadd;
				fstp totalPrice;
		
			displayRecipte:
				call totalBill;

	}
	return 0;
}
