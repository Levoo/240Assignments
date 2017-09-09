/* 
Project: Assignment 3
Class: CPSC 240
Professor: Dr. Ray Ahmadnia
Authors: Cuevas, Fernando
		 Huang, Justin
Due: 9/14/2017
*/

#include "stdafx.h" //take out after done with project, only need it cus my visual studio neeeds it.
#include <iostream>
#include <string>

// variables and funtions for question 1
int totalPrice;
int amtDrink, amtFood;
int sodaPrice = 2, waterPrice = 1;
int sub10inchPrice = 3, sub12inchPrice = 5;
int userChoiceSub;
char userChoiceDrink;

void display711Menu();
void get711Order();
void reciptFor711();

//variables and functions for question 2
int averageScore, scores, scoreCount;
int stopLoop = -1;

void getScore();
//variables for question 3

//variables for question 4
short int a, b, c, d, e, f;
short int X, Y;

void displayXYMenu();
void printXYresults();

int main() {

	//-----------------------------------QUESTION 1--------------------------------------------------------
	
	//__asm {
	//entry:
	//	call display711Menu;  display the menu to console
	//		call get711Order;
	//	whatDrinkType:
	//		mov  eax, amtDrink; move the total drinks to eax
	//		mov  bl, 'S'; move S into al, this is to not have another variable to compare
	//		cmp  userChoiceDrink, bl;  compare what the user entered
	//		jne  choiceWater;  if the user entered S then keep going though else go to choiceWater
	//
	//	choiceSoda : //go here is user chooses soda
	//		imul sodaPrice;
	//		mov totalPrice, eax;
	//		jmp whatSubSize;
	//
	//	choiceWater: // else choose water
	//		imul waterPrice;
	//		mov totalPrice, eax;
	//
	//	whatSubSize: //next part will handle what sub size
	//		mov eax, amtFood;
	//		mov  ebx, 10;
	//		cmp  userChoiceSub, ebx;
	//		jne  subChoice12;
	//
	//	subChoice10:
	//		imul sub10inchPrice;
	//		add totalPrice, eax;
	//		jmp displayRecipte;
	//
	//	subChoice12:
	//		imul sub12inchPrice;
	//		add totalPrice, eax;
	//
	//	displayRecipte:
	//		call reciptFor711;
	//
	//}

	//-----------------------------------QUESTION 2--------------------------------------------------------

	/*todo*/

	//-----------------------------------QUESTION 3--------------------------------------------------------

	/*todo*/
	//-----------------------------------QUESTION 4--------------------------------------------------------
	/*
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
	*/
	return 0;
}

// functions for question 1
void display711Menu() {
	std::cout << "-----------------------------7-11 Convienient Store------------------------------\n";
	std::cout << " Drinks\n\tSoda(S)...................................$2\n";
	std::cout << "\tWater(W).....................................$1\n";
	std::cout << " Sandwiches\n\t10 inches.............................$3\n";
	std::cout << "\t12 inches......................................$5\n\n";
}

void get711Order() {

	std::cout << "  How many drinks? ";
	std::cin >> amtDrink;

	std::cout << "\tWhat kind of drink?(S=Soda, W=Water) ";
	std::cin >> userChoiceDrink;

	std::cout << "\n  How many sandwiches? ";
	std::cin >> amtFood;

	std::cout << "\tWhat size of sandwich(10/12 inches)? ";
	std::cin >> userChoiceSub;
}

void reciptFor711() {
	std::cout << " Your total bill = " << totalPrice << std::endl;
}


//function for question 4
void displayXYMenu() {
	std::cout << "This program solves the system\n\taX + bY = c\n\tdX + eY = f\n";

	std::cout << "Enter the values of a, b and c: ";
	std::cin >> a >> b >> c;

	std::cout << "Enter the values of d, e and f: ";
	std::cin >> d >> e >> f;
}

void printXYresults() {
	std::cout << "\tX = " << X << "\n\tY = " << Y << std::endl;
}
