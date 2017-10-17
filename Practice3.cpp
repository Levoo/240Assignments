#include <iostream>
#include <iomanip>
using namespace std;

short range, counter, customer, ages;
float total, age;
float maleA = 2.75f, femaleA = 1.10f, maleT = 7.20f, femaleT = 6.15f, maleC = 1.10f, femaleC = 2.00f;
char gender;

void getQ()
{
	cout << " Enter the number of customers: ";
	cin >> customer; 
}

void getdata()
{
	cout << "How old are you? " << endl;
	cin >> age;
	ages = age;
	cout << "What is your gender (m/f) ";
	cin >> gender; 
}

void errorMessage()
{
	cout << "Your input is invaild " << endl;
}

void displayResult()
{
	cout << fixed << showpoint << setprecision(2);
	cout << " your membership is : " << total << endl;
}

int main()
{
	_asm
	{
		call getQ
		mov counter, 0

	checkage: 
		mov ax,customer
		cmp counter,ax
		je done
		call getdata
		cmp ages,19
		jng checkteen
		mov range,2
		jmp checkm

	checkteen:
		cmp ages, 13
		jng checkch
		mov range, 1
		jmp checkm;

	checkch:
		mov range, 0
		
	checkm:
			cmp gender,'m'
			jne checkmm
			jmp compareMrange
	checkmm:
			cmp gender,'M'
			jne checkf
			jmp compareMRange
	checkf:
			cmp gender,'f'
			jne checkff
			jmp compareFrange	
	checkff:
			cmp gender,'F'
			jne errormsg
			jmp compareFRange

	compareMRange:	
			cmp range,0
			jne compareMRange2
			fld age
			fld maleC
			fmul
			fstp total
			jmp display
	compareMRange2 :
			cmp range, 1
			jne compareMRange3
			fld age
			fld maleT
			fmul
			fstp total
			jmp display
	compareMRange3 :
			fld age
			fld maleA
			fmul				
			fstp total
			jmp display
	compareFRange :
			cmp range, 0
			jne compareFRange2
			fld age
			fld femaleC
			fmul
			fstp total
			jmp display
	compareFRange2 :
			cmp range, 1
			jne compareFRange3
			fld age
			fld femaleT
			fmul
			fstp total
			jmp display
	compareFRange3 :
			fld age
			fld femaleA
			fmul
			fstp total		
			jmp display
	display:
			call displayResult
			inc counter
			jmp checkage
	errormsg:
			call errorMessage
			jmp checkage
	done:

	}
	return 0;
}