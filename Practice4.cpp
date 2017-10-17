#include <iostream>
#include <iomanip>
using namespace std;

float r, four = 4.00f, three = 3.00f, pi = 3.14f, surface, volume;

void getinfo()
{
	cout << "Enter the value of the radius: ";
	cin >> r;
}

void displayresult()
{
	cout << fixed << showpoint << setprecision(2);
	cout << "Surface area = " << surface << endl;
	cout <<" volume = "<< volume << endl;
}

int main()
{
	_asm
	{
		call getinfo
		fld four 
		fld pi 
		fmul
		fld r
		fld r
		fld r
		fmul
		fmul
		fmul
		fld three
		fdiv
		fstp surface 

		fld four 
		fld pi 
		fmul
		fld r
		fld r
		fmul
		fmul
		fstp volume

		call displayresult
	}
	return 0;
}