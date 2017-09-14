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

int averageScore, scores, scoreCount,totalscore;
int stopLoop = -1;

void getScore()
{
	averageScore = totalscore / scoreCount;
}
void askScore()
{
	cout << "Enter your score (-1) to stop: ";
	cin >> scores; 
}
void displayScore()
{
	cout << "Your average is " << averageScore <<endl;
}
void displaywords()
{
	cout << "Lets compute your score's average: " << endl;
}





int main()
{
	_asm
	{
		call displaywords
	dowhile:
		call askScore
		mov eax,scores
		cmp scores,-1
		Je done 
		add totalscore,eax
		inc scoreCount
		Jmp doWhile
	done:
		mov scores,eax
		call getScore
		call displayScore

	}
}
/*
-------------------OUTPUT--------------------
Lets compute your score's average:
Enter your score (-1) to stop: 70
Enter your score (-1) to stop: 88
Enter your score (-1) to stop: 90
Enter your score (-1) to stop: 77
Enter your score (-1) to stop: -1
Your average is 81
Press any key to continue . . .
--------------------------------------------
*/