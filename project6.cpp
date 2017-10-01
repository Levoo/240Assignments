/*
Author: Cuevas, Fernando
Huang,  Justin
Class: 240
Project: 6 (ARRAYS)
Due: 10/05/2017
*/

#include <iostream>

// question 1 variable and functions
//  s    m   l   xl
int b[4][4] = { 10, 20, 30, 40,      //  red
				20, 10, 40, 30,      //  green
				5,  15, 20, 25,      //  blue	
				30, 25, 20, 15 };    //  black

int totalShirtCount = 0, totalLargeCount = 0, totalBlackSHirtCount = 0;
int arrayLoc;

void displayTotalShirt() {
	std::cout << "a.) Total # of shirts is:    " << totalShirtCount << std::endl;
}

void displayTotalLargeShirt() {
	std::cout << "b.) Total # of large shirts: " << totalLargeCount << std::endl;
}

void displayBlackCount() {
	std::cout << "c.) Total # of black shirts: " << totalBlackSHirtCount << std::endl;
}

// ------------ QUESTION 2 Stuff ------------------------

int aa[5] = {9, 3, 22, 8, 1};

int loop1Count = 0, loop2Count, index, nextIndex, element;

void displayArrayElement() {
	std::cout << element << " ";
}

void displayMsg_Original() {
	std::cout << "Original Array: ";
}


int main() {
	//part a of 1

	/*std::cout << "T-shirt Company\n";
	_asm {
		mov ecx, 0;
		mov arrayLoc, 0;

	looper:
		cmp arrayLoc, 16;  compare to see if it has reached the end of the array aka the last element which is 16th element
		je done;

		mov ebx, [b + ecx];			move the value at that index into ebx
		add totalShirtCount, ebx;	add it to the total 
		add ecx, 4;					add for to ecx which is like the index for the array 
		inc arrayLoc;
		jmp looper;

	done:
		call displayTotalShirt;

		mov ecx, 8;
		mov arrayLoc, 0;
	looper2:
		cmp arrayLoc, 4;
		je done2;

		mov ebx, [b + ecx];
		add totalLargeCount, ebx;
		add ecx, 16;
		inc arrayLoc;
		jmp looper2;

	done2:
		call displayTotalLargeShirt;

		mov ecx, 48;
		mov arrayLoc, 0;
	Looper3:
		cmp arrayLoc, 4;
		je done3;

		mov ebx, [b + ecx];
		add totalBlackSHirtCount, ebx;
		add ecx, 4;
		inc arrayLoc;
		jmp looper3;

	done3:
		call displayBlackCount;
	}*/


	//----------------------------------------------------

	//part 2, having an error displaying the array need to figure out. Ecx value changes # > array size and crashes the program
  //        removing the 
	_asm {
		mov ecx, 0;
		mov index, 0;

	forLoopers:
		add eax, 4;
		cmp index, 5;
		je donner;

		mov ebx, [aa + ecx];
		mov element, ebx;
		jmp displayy;

	displayy:
		call displayArrayElement;
		add ecx, 4;
		inc index;
		jmp forLoopers;


	donner:


	}

	return 0;
}
