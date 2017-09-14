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

char c;
int lCount, uCount;

void getNextChar()
{
	cin.get(c);
}
void displayCount() 
{
	cout << "\nTotal Upper == " << uCount << endl;
	cout << "Total Lower == " << lCount << endl; 
		
}


int main() {
	cout << "Enter a sentence: ";

	_asm {
	whileLoop:
		call getNextChar

			cmp c, '\n'
			je done
			cmp c, 'A'
			jle whileLoop
			jge isUpper
	isUpper :
		cmp c, 'Z'
			jge possibleLower
			inc uCount
			jmp whileLoop

	possibleLower :
		cmp c, 'a'
			jle whileLoop
			cmp c, 'z'
			jle isLower
			jge whileloop
	isLower:
		inc lCount
		jmp whileLoop

	done :
		call displayCount
	}
}
/*
--------------------OUTPUT---------------------
Enter a sentence: Project No Three

Total Upper == 3
Total Lower == 11
Press any key to continue . . .
-----------------------------------------------
*/