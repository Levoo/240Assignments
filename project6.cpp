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

// to display the array i get an error when i try to display within assembly after moving the first value into element the value 
// of ecx changes dramatically which leads to a crash, possible somthing with the call.
void displayArray() {
	for (int i = 0; i < 5; i++) {
		std::cout << aa[i] << " ";
	}
	std::cout << std::endl;
}

void displayMsg_Original() {
	std::cout << "Original Array: ";
}

//-------------------------QUESTION 3 stuff---------------------
int aaa[3][3][2] = { 1, 2, 3,
					 4, 5, 6,
					 7, 8, 9,
					 10, 11, 12,
					 13, 14, 15,
					 16, 17, 18 };
int arrayPos = 0, total3DShirtCount = 0, total3DMediumCount = 0, total3DShortSleeve = 0, total3DReadShirtCount = 0;
int countJump = 4;
//functsa 

void displayTotal3DCount() {
	std::cout << "a.) Total # of shirts is: " << total3DShirtCount << std::endl;
}

void displayTOtalMed() {
	std::cout << "b.) Total # of shirts is: " << total3DMediumCount << std::endl;
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

	//part 2
	
	/*_asm {
		call displayArray;
		mov ecx, 0;
		mov loop1Count, 0;
		mov loop2Count, 0;
		jmp b_Sort;
	
	swapNums:
		mov [aa + ecx], ebx; this is a=b
		mov[aa + ecx + 4], eax; this is b = temp, where temp is techinically a
		jmp inc_Counts;


	b_Sort:
		cmp loop1Count, 4;  loop to only go 4 times since array is of size 5 (0-4)
		je display; display array

		mov edx, 4; this seats up the stoping point for the check loop
		sub edx, loop1Count; using bubble sort the second loo goes to n-i-1 
		sub edx, 1;		where n is the array size, subtracted by i (value of first loop) amd then subbed by 1

	check:; check if aa[i] is greater than aa[i+1] if it is then swap else increment values for check loop and continue
		cmp loop2Count, edx; reachs end of loop go back to b_sort loop
		je inc_Counts2;
		mov eax, [aa + ecx]; temp
		mov ebx, [aa + ecx + 4]; this is b

		cmp eax, ebx; compare if it is greater 
		jle inc_Counts;
		jge swapNums;
	
	inc_Counts:; increment values ofr second check loop
		inc loop2Count;
		add ecx, 4;
		jmp check;
	
	inc_Counts2:; updated values for loop 1 aka b_sort 
		inc loop1Count;
		mov loop2Count, 0;
		mov ecx, 0;
		jmp b_Sort;
		
	display:
		call displayArray;
	}*/

	//part 3
	// a./ total shirts
	// b.) medium size shirts
	// c.) short sleeve shirts
	// d.) red shirts

	//part a
	_asm {
		mov ecx, 0;

	loopi:
		cmp arrayPos, 18;
		je donney;

		mov ebx, [aaa + ecx];
		add total3DShirtCount, ebx;

		add ecx, 4;
		inc arrayPos;
		jmp loopi;

	donney:
		call displayTotal3DCount;


	}

	//part b
	_asm {
		mov ecx, 8;
		mov arrayLoc, 0;

	loppi:
		cmp arrayLoc, 3;
		je doobi;

		mov ebx, [aaa + ecx];
		add total3DMediumCount, ebx;

		mov ebx, [aaa + ecx + 4];
		add total3DMediumCount, ebx;

		mov eax, 8; 
		imul countJump;

		mov ecx, eax;
		inc arrayLoc;
		add countJump, 3;
		jmp loppi;

	doobi:
		call displayTOtalMed;

	}
	return 0;
}
