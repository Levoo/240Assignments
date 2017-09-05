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

	//print the menu
	 

    return 0;
}

void part2() {
	
	int number, total, h = 100, t = 10, r;

	std::cout << "Enter a 3 digit number: ";
	std::cin >> number;

	_asm {
		mov eax, number;
		cdq;

		idiv h;

		mov total, eax;

		mov r, edx;
		mov eax, r
		cdq;

		idiv t;

		add total, eax;

		add total, edx;

	}

	std::cout << total;
}

