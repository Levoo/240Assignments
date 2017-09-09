/* 
Project: Assignment 3
Class: CPSC 240
Professor: Dr. Ray Ahmadnia
Authors: Cuevas, Fernando
		 Huang, Justin
Due: 9/14/2017
*/

#include "stdafx.h" //take out after done with project
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

//variables for question 2

//variables for question 3

//variables for question 4

int main() {

	//-----------------------------------QUESTION 1--------------------------------------------------------
	__asm {
	entry:
		call display711Menu;  display the menu to console
			call get711Order;
		whatDrinkType:
			mov  eax, amtDrink; move the total drinks to eax
			mov  bl, 'S'; move S into al, this is to not have another variable to compare
			cmp  userChoiceDrink, bl;  compare what the user entered
			jne  choiceWater;  if the user entered S then keep going though else go to choiceWater

		choiceSoda : //go here is user chooses soda
			imul sodaPrice;
			mov totalPrice, eax;
			jmp whatSubSize;

		choiceWater: // else choose water
			imul waterPrice;
			mov totalPrice, eax;

		whatSubSize: //next part will handle what sub size
			mov eax, amtFood;
			mov  ebx, 10;
			cmp  userChoiceSub, ebx;
			jne  subChoice12;

		subChoice10:
			imul sub10inchPrice;
			add totalPrice, eax;
			jmp displayRecipte;

		subChoice12:
			imul sub12inchPrice;
			add totalPrice, eax;

		displayRecipte:
			call reciptFor711;

	}

	return 0;
}

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

//-----------------------------------QUESTION 1--------------------------------------------------------
