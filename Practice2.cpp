#include <iostream>
using namespace std;

int a[12] = { 33,31,20,18,23,22,23,31,10,20,30,40 };
int majority, campus, counter;
int b[4];
int c[3];

void displaymaj()
{
	cout << "Majority of students are ";
}

void displaycamp()
{
	cout << "More students are in ";
}

void freshh()
{
	cout << "Freshmen" << endl; 
}

void sophh()
{
	cout << "Sophomores " << endl;
}

void junn()
{
	cout << " Juinors " << endl;
}

void senn()
{
	cout << "Seniors " << endl; 
}

void Fully()
{
	cout << "Fullerton Campus " << endl; 

}

void Irvine()
{
	cout << "Irvine Campus " << endl;
}

void Garden()
{
	cout << " Gardent Grove campus " << endl;
}

int main()
{
	_asm
	{
		mov eax,0
		mov ebx, 0
		mov counter,0

	forloop1:
		cmp counter, 3
		je freshmen
		add eax,[a+ebx]
		add ebx, 16
		inc counter 
		jmp forloop1

	freshmen: 
		mov ebx, 0
		mov [b+ebx], eax 

		mov eax, 0
		mov ebx,4
		mov counter,0

	forloop2:
		cmp counter, 3 
		je sophomore
		add eax, [a+ebx]
		add ebx,16
		inc counter
		jmp forloop2 

	sophomore: 
		mov ebx, 4
		mov [b + ebx],eax

		mov eax,0 
		mov ebx,8
		mov counter,0

	forloop3:
		cmp counter,3
		je junior
		add eax, [a + ebx]
		add ebx, 16
		inc counter
		jmp forloop3

	junior: 
		mov ebx, 8
		mov [b+ebx], eax

		mov eax,0
		mov ebx,12
		mov counter,0

	forloop4:
		cmp counter, 3
		je senior
		add eax, [a + ebx]
		add ebx, 16
		inc counter
		jmp forloop4

	senior:
		mov ebx, 12
		mov[b + ebx], eax

		mov ebx, 0
		mov counter, 0
		mov edx,0	

	forloopcompare:
		cmp counter, 3
		je question2
		mov eax, [b + ebx];
		mov ecx, [b+ ebx + 4]
		cmp eax,ecx
		jle incre
		inc counter
		jmp forloopcompare

	incre:
		inc edx
		inc counter 
		jmp forloopcompare



	question2: 
		mov majority, edx
		cmp majority,0
		je fresh
		cmp majority, 1
		je soph
		cmp majority,2
		je juniorr
		jmp seniorr 

	fresh: 
		call displaymaj
		call freshh
		jmp q2

	soph:
		call displaymaj
		call sophh
		jmp q2

	juniorr:
		call displaymaj
		call junn
		jmp q2

	seniorr:
		call displaymaj
		call senn
	
	q2: 
		mov eax,0
		mov ebx, 0
		mov counter, 0

	forloopfully:
		cmp counter,4
		je fullerton
		add eax, [a + ebx]
		add ebx, 4
		inc counter 
		jmp forloopfully

	fullerton: 
		mov ebx,0
		mov [c+ebx], eax

		mov eax,0
		mov ebx,16
		mov counter,0

	forloopirvine:
		cmp counter, 4
		je irvine
		add eax, [a + ebx]
		add ebx, 4
		inc counter
		jmp forloopirvine
	
	irvine:
		mov ebx, 4
		mov[c + ebx], eax

		mov eax, 0
		mov ebx, 32
		mov counter, 0

	forloopgarden:
		cmp counter,4
		je garden
		add eax, [a + ebx]
		add ebx, 4
		inc counter	
		jmp forloopgarden

	garden:
		mov ebx, 8
		mov[c + ebx], eax

		mov edx, 0
		mov ebx, 0
		mov counter, 0

	forloopcompare2:
		cmp counter,2
		je done1
		mov eax, [c + ebx]
		mov ecx, [c + ebx + 4]
		cmp eax,ecx
		jle incre2
		inc counter 
		jmp forloopcompare2


	incre2:
		inc edx
		inc counter 
		jmp forloopcompare2

	done1:
		mov campus,edx
		cmp campus,0
		je fullly
		cmp campus,1
		je irvinee
		jmp gardennn

	fullly:
		call displaycamp
		call Fully
		jmp done2

	irvinee:
		call displaycamp
		call Irvine
		jmp done2

	gardennn:
		call displaycamp
		call Garden

	done2:

}
return 0;
}