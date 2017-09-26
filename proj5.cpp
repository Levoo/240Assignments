// assi5.cpp : Defines the entry point for the console application.
//

#include <iostream>

//q1
short rightMove = 14;
short cPrinter, cFloppy, cRAM;

void printCompInfo() {
	std::cout << "\nPrinters: " << cPrinter
		      << "\nFloppy drives: " << cFloppy
		      << "\nRAM: "             << cRAM     
		      << std::endl;
}

//q2

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

//q3
short totalOn;

void displayAX() {

}

void howManyOn() {

}

void defectiveSprinkler() {

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
		shr cFloppy, 7;
	grtRAM:
		mov cRAM, 0000000000001100b;
		and cRAM, ax;
		shr cRAM, 1;

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
	_asm{
	// display binary in notes
	// in notes, check each bit if 1 inc on if 0 print pos and then sub pos, say pos = 16
	// and if 0 not pos amd sub pos
	}
	
	//q4  same but with elevator

    return 0;
}

