/*******************
Assignment 2 (ADD, SUB, IMUl, IDIV instructions)

Cuevas, Fernando 
Huang, Justin

*****************/

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
//	//-------------------START QUESTION 1-------------------------------------------------
//	// must use short for this question
//	//variables that will store the amount the user specifies for each option
//	short int drinkAmount, sanwichAmount, drinksCost = 2, foodCost  = 4, totalCost;
//	//main menu of program
//	cout << "---------------MENU---------------" << endl;
//	cout << " Drinks.....................$2 \n";
//	cout << " Sandwiches.................$4 " << endl;
//
//	cout << "  How many drinks: ";
//	cin >> drinkAmount;
//
//	cout << "  How many sandwiches: ";
//	cin >> sanwichAmount;
//
//	// aritmatic operations will take place using assembly...
//	_asm 
//	{
//		// calculate how much it will cost for the drinks 
//		// first by putting the user amount in ax (short int is 2 bytes so we use ax which is 2 bites or 16 bits) and then multiplying it by the drink value
//
//		mov ax, drinkAmount; ax now have the value from drinka mount
//		imul drinksCost; multiple what is in ax and store it in ax
//		mov drinkAmount, ax;
//
//		//now do the same thing for the sandwiches 
//
//		mov bx, sanwichAmount; move value in sanwichAmount into bx
//		imul foodCost;
//		mov sanwichAmount, bx;
//
//		//fianally add together
//		add cx, drinkAmount;
//		add cx, sanwichAmount;
//
//		mov totalCost, cx;
//	}
//
//	// dispplay information
//
//	cout << "\t Your total bill $" << totalCost << endl;
//
	//-------------------END QUESTION 1------------------------

	//-------------------START QUESTION 2----------------------
	
	#include <iostream>
using namespace std;



int main()
{
	int a, b, c, h, l, w, areaT, preT, areaR, preR;
	int t = 2;
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
	

	cout << " Please enter for a,b,c and h" << endl;
	cin >> a;
	cin >> b;
	cin >> c;
	cin >> h; 

	cout << " Please enter for length and width " << endl;
	cin >> l; 
	cin >> w; 

	_asm
	{
		mov eax,c 
		imul h
		idiv t 
		mov areaT,eax

		mov eax,c 
		add eax,a 
		add eax,b 
		mov preT,eax

		mov eax,l 
		imul w 
		mov areaR, eax

		mov eax,l 
		add eax,w
		add eax,eax
		mov preR,eax
			}

	cout << "triangle " << endl;
	cout << "Area............." << areaT << endl;
	cout << "Perimeter........" << preT << endl;

	cout << "Rectangle " << endl;
	cout << " Area............" << areaR << endl; 
	cout << " Perimeter......." << preR << endl; 



	return 0;
}


//-------------------------------OutPut---------------------------------------------

//      / |
//     /  |
//  a /   | b
//   / h  |
//  /     |
//  ____________
//          c
//--------------------------
//|                        |
//|                        | width
//|                        |
//|                        |
//--------------------------
//length
//Please enter for a, b, c and h
//4
//6
//9
//10
//Please enter for length and width
//15
//10
//
//triangle
//Area.............45
//Perimeter........19
//Rectangle
//Area............150
//Perimeter.......50
//Press any key to continue . . .


//---------------------------------------------------------------------------------
	
//-------------------QUESTION 3------------------------------------------------------
	/*******************
Assignment 2 (ADD, SUB, IMUl, IDIV instructions)

Cuevas, Fernando
Huang, Justin

*****************/
#include <iostream>
using namespace std; 

int main()
{
	short F, C,b=9,d=5;

	cout << " Enter temperature in Fahrenheight: ";
	cin >> F; 
	_asm
	{
		mov ax, F
		sub ax, 32
		imul b
		idiv d
		mov c,ax 

	}
	cout << F << "F " << C << "C " << endl; 

		return 0; 




}
	
// -----------------------------------------------------------------------------------------------

	 
//-------------------------------QUESTION 4-----------------------------------------------
	int number, total, hun = 100, t = 10, r;

	std::cout << "Enter a 3 digit number: ";
	std::cin >> number;

	_asm {
		mov eax, number;
		cdq;

		idiv hun;

		mov total, eax;

		mov r, edx;
		mov eax, r
			cdq;

		idiv t;

		add total, eax;

		add total, edx;

	}

	std::cout << "The total of the digits in " << number << " is " << total << "\n";


    return 0;
}



