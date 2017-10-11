#include <iostream>
#include <iomanip>
using namespace std;

float sodaCost = 2.25f, waterCost = 1.75f, tenInchesCost = 3.45f, twelveInchesCost = 5.25f;
float amountDrinks, amountSand;
float totalPrice,temp;
char choiceDrink;
int choiceSand;


void printMenu()
{
	cout << "-----------------------------7-11 Convienient Store------------------------------\n";
	cout << " Drinks\n\tSoda(S)...................................$2.25\n";
	cout << "\tWater(W).....................................$1.75\n";
	cout << " Sandwiches\n\t10 inches.............................$3.45\n";
	cout << "\t12 inches......................................$5.25\n\n";
}

void getOrder()
{
	cout << "How many drinks? ";
	cin >> amountDrinks;

	cout << "\tWhat kind of drink?(S=Soda, W=Water) ";
	cin >> choiceDrink;

	cout << "How many Sandwhiches?";
	cin >> amountSand; 

	cout << "\tWhat kind of Sandwhiches?( 10 inces or 12 inches) ";
	cin >> choiceSand;
}

void PrintTotal()
{
	cout << "Your total bill = " << totalPrice << endl;
}

int main()
{
	_asm
	{
		call printMenu
		call getOrder 

		DrinkType: 
			fld amountDrinks
			mov bl, 'S'
			cmp choiceDrink,bl
			jne Water

		Soda: 
			fld sodaCost
			jmp SandType

		Water: 
			fld waterCost
			
		SandType:
			fld amountSand
			mov eax, choiceSand
			cmp choiceSand,eax
			jne Sand12

		Sand10:
			fld tenInchesCost
			fmul; tenInchCost * amountSand
			fstp totalPrice; totalPrice = sand cost

			fmul; drinkchoice * amount
			fstp temp; temp = drink cost

			fld totalPrice
			fld temp

			fadd
			fstp totalPrice; totalprice = drinkcost + sand cost
			jmp printtotal

		Sand12: 
			fld twelveInchesCost
			fmul; ten12Cost * amountSand
			fstp totalPrice; totalPrice = sand cost

			fmul; drinkchoice * amount
			fstp temp; temp = drink cost

			fld totalPrice
			fld temp

			fadd
			fstp totalPrice; totalprice = drinkcost + sand cost

		printtotal:
			call PrintTotal
			



	}
	return 0;
}