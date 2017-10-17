#include <iostream>
using namespace std; 

short n, x, m, q, counter, bin, input;

void display1() {
	cout << "a. " << n << " bits are ON " << endl; 
}

void display2() {
	cout << "b. This is the current condition of all bits after bits 7 and 8 turned off: ";
}

void display3() {
	cout << "c. " << m << " sprinklers are watering front yard and " << q << " sprinklerse water the backyard " << endl;
}

void displayBIN() {
	short y = 1 << 15, t; 
	for (int i = 1; i <= 16; i++)
	{
		t = bin&y;
		if (t == 0)
		{
			cout << 0;
		}
		else
		{
			cout << 1;
		}
		if (i % 4 == 0)
		{
			cout << " ";
		}
		bin = bin << 1;
	}
	cout << endl; 
}

int main()
{
	_asm
	{
		mov input, 1100111110011100b
		mov n, 0
		mov counter, 0
		mov x, 1

		forloop:
		cmp counter, 16
			je question2
			mov ax, input
			and ax, x
			cmp ax, 0
			jne itson
			inc counter
			shl x, 1
			jmp forloop

			itson :
		inc n
			inc counter
			shl x, 1
			jmp forloop

			question2 :
			call display1
			mov input, 1100111110011100b
			mov ax, input
			mov x, 1
			shl x, 7
			xor ax, x
			shl x, 1
			xor ax, x
			mov bin, ax
			call display2
			call displayBIN

			question3 :
		mov input, 1100111110011100b
			mov ax, input
			shl ax, 8
			shr ax, 13
			mov x, 111b
			and ax, x
			mov m, ax

			mov input, 1100111110011100b
			mov ax, input
			shl ax, 3
			shr ax,13
			mov x, 111b
			and ax, x
			mov q, ax
			call display3
	}
	return 0;
}

