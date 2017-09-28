// assi5.cpp : Defines the entry point for the console application.
//

#include <iostream>

//q1 variables and functions 
short rightMove = 14;
short cPrinter, cFloppy, cRAM;

void printCompInfo() {
	std::cout << "\nPrinters: " << cPrinter
		      << "\nFloppy drives: " << cFloppy
		      << "\nRAM: "             << cRAM     
		      << std::endl;
}

//q2 variables and functions 

short beefCount, fadeCount, cabeCount, isEven = 2;
short checkBeef, checkFade, checkCabe;

void displayBeefEven() {
	std::cout << "BEEF is a Valid ID for the Family" << std::endl;
}

void displayBeefNot() {
	std::cout << "BEEF is not a Valid ID for the Family" << std::endl;
}

void displayFadeEven() {
	std::cout << "FADE is a Valid ID for the Family" << std::endl;
}

void displayFadeNot() {
	std::cout << "FADE is not a Valid ID for the Family" << std::endl;
}

void displayCabeEven() {
	std::cout << "CABE is a Valid ID for the Family" << std::endl;
}

void displayCabeNot() {
	std::cout << "CABE is not a Valid ID for the Family" << std::endl;
}

//q3 variables and functions 
short totalOn = 0, bitCount = 15;
short t, n;

void displayAX() { //used for both 3 and 4
	std::cout << "AX = ";
	unsigned short x = 1 << 15; //x = 1000 0000 0000 0000
	for (int i = 1; i <= 16; ++i) {
		t = n & x;
		if (t == 0) 
			std::cout << '0';
		else  
			std::cout << '1';

		if (i % 4 == 0) 
			std::cout << ' ';

		n = n << 1;
	}
	std::cout << std::endl;
}

void howManyOn() {
	std::cout << totalOn << " sprinklers are ON\n";
}

void defectiveSprinkler() {
	std::cout << "Defective Sprinklers: ";
}

void getDefectiveSprinkler() {
	std::cout << bitCount + 1 << " ";
}


//q4
short floorStops = 15;
void eleStop() {
	std::cout << "Elevator will stop at floors No. ";
}

void getFloor() {
	std::cout << floorStops + 1 << " ";
}


int main()
{
	//q1
	/*_asm {
		mov ax, 1100111010011100b;
	getPrinter:
		mov cPrinter,  1100000000000000b;
		and cPrinter, ax;
		shr cPrinter, 14;
	getFloppy:
		mov cFloppy, 0000000001100000b;
		and cFloppy, ax;
		shr cFloppy, 6;
		add cFloppy, 1;
	grtRAM:
		mov cRAM, 0000000000001100b;
		and cRAM, ax;
		shr cRAM, 2;

		cmp cRAM, 00b;
		je sixteenRAM;

		cmp cRAM, 01b;
		je thirtytwoRAM;

		cmp cRAM, 10b;
		je fourtyeightRAM;

		cmp cRAM, 11b;
		je sixtyfourRAM;
	
	sixteenRAM:
		mov cRAM, 16;
		jmp done;

	thirtytwoRAM:
		mov cRAM, 32;
		jmp done;
	fourtyeightRAM:
		mov cRAM, 48;
		jmp done;
	sixtyfourRAM:
		mov cRAM, 64;
	done:
		call printCompInfo;
	}*/

	//q2
	/*_asm {
	checkBEEF:;
		mov ax, 1111000000000000b; 
		mov checkBeef, 0xbeef;
		and ax, checkBeef;
		shr ax, 12;
		mov beefCount, ax;

		mov ax, 0000111100000000b;
		and ax, checkBeef;
		shr ax, 8;
		add beefCount, ax;

		mov ax, 0000000011110000b;
		and ax, checkBeef;
		shr ax, 4;
		add beefCount, ax;

		mov ax, 0000000000001111b;
		and ax, checkBeef;
		add beefCount, ax;
		mov ax, beefCount;
		cwd;
		idiv isEven;
		cmp dx, 0;
		jne beefNotEven;
	beefEven:
		call displayBeefEven;

	checkFADE:;
		mov ax, 1111000000000000b;
		mov checkFade, 0xfade;
		and ax, checkBeef;
		shr ax, 12;
		mov fadeCount, ax;

		mov ax, 0000111100000000b;
		and ax, checkFade;
		shr ax, 8;
		add fadeCount, ax;

		mov ax, 0000000011110000b;
		and ax, checkFade;
		shr ax, 4;
		add fadeCount, ax;

		mov ax, 0000000000001111b;
		and ax, checkFade;
		add fadeCount, ax;
		mov ax, beefCount;
		cwd;
		idiv isEven;
		cmp dx, 0;
		jne fadeNotEven;
	fadeEven:
		call displayFadeEven;

	checkCABE:;
		mov ax, 1111000000000000b;
		mov checkCabe, 0xcabe;
		and ax, checkCabe;
		shr ax, 12;
		mov cabeCount, ax;

		mov ax, 0000111100000000b;
		and ax, checkCabe;
		shr ax, 8;
		add cabeCount, ax;

		mov ax, 0000000011110000b;
		and ax, checkCabe;
		shr ax, 4;
		add cabeCount, ax;

		mov ax, 0000000000001111b;
		and ax, checkCabe;
		add cabeCount, ax;
		mov ax, cabeCount;
		cwd;
		idiv isEven;
		cmp dx, 0;
		jne cabeNotEven;
	cabeEven:
		call displayCabeEven;
		jmp done;

	beefNotEven:
		call displayBeefNot;
	    jmp checkFADE;
	fadeNotEven:
		call displayFadeNot;
		jmp checkCABE;
	cabeNotEven:
		call displayCabeNot;

	done:
	}*/

	//q3
	/*_asm {
		mov n, 0110101000101111b; 
		call displayAX;

		mov n, 0110101000101111b;
		mov ax, 1;
		shl ax, 15;

	forLoop:
		cmp bitCount, -1;
		je done;

		and ax, n;
		cmp ax, 0;
		jne isOn;
		jmp isOff;

	isOn:
		inc totalOn;
		shl n, 1;
		dec bitCount;
		mov ax, 1;
		shl ax, 15;
		jmp forLoop;
	
	isOff:
		dec bitCount;
		shl n, 1;
		mov ax, 1;
		shl ax, 15;
		jmp forLoop;

	done:
		call howManyOn;
	}

	_asm {

		mov n, 0110101000101111b;
		mov bx, 1;
		shl bx, 15;
		mov bitCount, 15;
		call defectiveSprinkler;

	forLoop2:

		cmp bitCount, -1;
		je done2;

		and bx, n;
		cmp bx, 0;
		jne isOn2;
		jmp isOff2;

	isOn2:
		shl n, 1;
		dec bitCount;
		mov bx, 1;
		shl bx, 15;
		jmp forLoop2;

	isOff2:
		call getDefectiveSprinkler;
		dec bitCount;
		shl n, 1;
		mov bx, 1;
		shl bx, 15;
		jmp forLoop2;

	done2:
	}
	std::cout << std::endl;*/
	
	//q4
	_asm{
		mov n, 1001000100001100b;
		call displayAX;
		call eleStop;
		mov n, 1001000100001100b;
		mov ax, 1;
		shl ax, 15;
	forLoop:
		cmp floorStops, -1;
		je done;

		and ax, n;
		cmp ax, 0;
		jne stopOnThisFloor;
		jmp notThisFloor;

	stopOnThisFloor:
		call getFloor;
		dec floorStops;
		shl n, 1;
		mov ax, 1;
		shl ax, 15;
		jmp forLoop;
	
	notThisFloor:
		dec floorStops;
		shl n, 1;
		mov ax, 1;
		shl ax, 15;
		jmp forLoop;

	done:
	}
	std::cout << std::endl;

    return 0;
}

