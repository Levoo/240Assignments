

// put names and such
// include libs

#include <iostream>

// variables and funtions for question 1
int totalPrice;
int amtDrink, amtFood;
int sodaPrice = 2, waterPrice = 1; 
int sub10inchPrice = 3, sub12inchPrice = 5;
char userChoiceDrink, userChoiceSub;

void display711Menu();
void get711Order();
void reciptFor711();

//variables for question 2

//variables for question 3

//variables for question 4

int main(){

	//assembly for question 1
	__asm{
	entry:
			call display711Menu;  display the menu to console
			call get711Order;
	whatDrinkType:
			mov  eax, amtDrink; move the total drinks to eax
			mov  al, 'S'; move S into al, this is to not have another variable to compare
			cmp  userChoiceDrink, al;  compare what the user entered
			jne  choiceWater;  if the user entered S then keep going though else go to choiceWater
	
	choiceSoda: //go here is user chooses soda
			imul sodaPrice;
			mov totalPrice, eax;
			jmp whatSubSize;
			
	choiceWater: // else choose water
			imul waterPrice;
			mov totalPrice, eax;
			
	whatSubSize: //next part will handle what sub size
			mov eax, amtFood;
			mov  al, '10';
			cmp  userChoiceSub, al;
			//jne  subChoice12;
			
	
			
	displayRecipte:
			call reciptFor711;
	
	}

	return 0;
}

void display711Menu(){
	std::cout << "-----------------------------7-11 Convienient Store------------------------------\n";
	std::cout << " Drinks\n\tSoda(S)...................................$2\n";
	std::cout << "\tWater(W).....................................$1\n";
	std::cout << "Sandwiches\n\t10 inches.............................$3\n";
	std::cout << "\t12 inches......................................$5\n\n";
}

void get711Order(){
	
	std::cout << "How many drinks? ";
	std::cin >> amtDrink;
	
	std::cout << "\tWhat kind of drink?(S=Soda, W=Water) ";
	std::cin>> userChoiceDrink;
	
	std::cout << "\nHow many sandwiches? ";
	std::cin >> amtFood;
	
	std::cout << "\tWhat size of sandwich(10/12 inches)? ";
	std::cin >> userChoiceSub;
}

void reciptFor711(){
	std::cout << "Your total bill = " << totalPrice << std::endl;
}
