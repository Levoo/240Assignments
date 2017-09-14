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

// variables and funtions for question 1
int totalPrice;
int amtDrink, amtFood;
int sodaPrice = 2, waterPrice = 1;
int sub10inchPrice = 3, sub12inchPrice = 5;
int userChoiceSub;
char userChoiceDrink;

void display711Menu()
{
	cout << "--------------------7-11 Convnient Store --------------------------" << endl;
	cout << "Drinks " << endl; 
	cout << "  Soda(S).........................................................$2" << endl;
	cout << "  Water(W)........................................................$1" << endl; 
	cout << "Sandwhiches" << endl; 
	cout << "  10 inches.......................................................$3" << endl; 
	cout << "  12 inches.......................................................$5" << endl; 

}
void get711Order()
{
	cout << "How many drinks? "; 
	cin >> amtDrink; 
	cout << "What kind of drink(S=Soda, W=Water)"; 
	cin >> userChoiceDrink;
	cout << " How many Sandwiches?"; 
	cin >> amtFood;
	cout << "What size of sandwhich(10/12 inches)"; 
	cin >> userChoiceSub;
}
void reciptFor711()
{
	cout << "Your total bill = " << totalPrice << endl; 
}

int main()
{
	_asm {
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
}
/* 
--------------------OUTPUT-----------------------------------------

--------------------7-11 Convnient Store --------------------------
Drinks
Soda(S).........................................................$2
Water(W)........................................................$1
Sandwhiches
10 inches.......................................................$3
12 inches.......................................................$5
How many drinks? 2
What kind of drink(S=Soda, W=Water)S
How many Sandwiches?3
What size of sandwhich(10/12 inches)10
Your total bill = 13
Press any key to continue . . .
----------------------------------------------------------------------


*/