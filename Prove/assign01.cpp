/***********************************************************************
* Program:
* Assignment assign01
* Brother      , CS165
* Author:
* Elias Ramirez
*
* Instructions:
* 
* Write a C++ program to do the following:
* Prompt the user for a 10 character DNA marker sequence.
* Prompt the user for a number of potential relatives.
* Prompt for the names of each of these potential relatives and store 
*   them in an array of strings.
* Prompt for the 10 character DNA marker sequence of each of the 
*   potential relatives.
* Display each potential relative along with the percentage that their
*   sequence matched the target user.
* In this assignment, DNA marker sequences will be restricted to the 
*   standard nucleotide base symbols: A, T, C, and G. No error checking 
*   is required for this assignment.
* You may assume that no more than 50 relatives will be entered.
*
* SAMPLE OUTPUT
*
* Enter your DNA sequence: ATTCGACTGA
* Enter the number of potential relatives: 3
*
* Please enter the name of relative #1: Peter
* Please enter the name of relative #2: James
* Please enter the name of relative #3: John
*
* Please enter the DNA sequence for Peter: TTTCGACTGA
* Please enter the DNA sequence for James: AAACGTCAGT
* Please enter the DNA sequence for John: ATTGCAGTCA
* 
* Percent match for Peter: 90%
* Percent match for James: 50%
* Percent match for John: 60%
************************************************************************/
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
#define SIZE 50

//prototyping
void getSequence(string &userSequence);
int getRelativeNum();
void getRelativeNames(string relNames[], int relNum);
void getRelSequence(string relNames[], string relSequence[], int relNum);
void display(int potRelatives[], int relNum, string relNames[]);
void compareDNA(string &userSequence, string relSequence[], int relNum,
	int potRelatives[]);
int getLetterNum(string &userSequence, char letter);

/***********************************************************************
* MAIN:
************************************************************************/
int main()
{
	string userSequence;
	getSequence(userSequence);
	
	string relNames[SIZE];
	int relNum = getRelativeNum();
	getRelativeNames(relNames, relNum);
	string relSequence[SIZE];
	
	getRelSequence(relNames, relSequence, relNum);

	int percentRel[SIZE] = {};
	compareDNA(userSequence, relSequence,
		relNum, percentRel);
	display(percentRel, relNum, relNames);

	return 0;
}

/***********************************************************************
* getSequence(string userSequence[])
* Prompt the user for a 10 character DNA marker sequence.
************************************************************************/
void getSequence(string &userSequence)
{
	cout << "Enter your DNA sequence : ";
	cin >> userSequence;
}

/***********************************************************************
* getRelativeNum()
* Prompt the user for a number of potential relatives.
************************************************************************/
int getRelativeNum()
{
	int relNum(0);
	cout << "Enter the number of potential relatives: ";
	cin >> relNum;
	cout << endl;
	return relNum;
}

/***********************************************************************
* getRelativeNames(string relNames[], int relNum)
* Prompt for the names of each of these potential relatives and store 
* them in an array of strings.
************************************************************************/
void getRelativeNames(string relNames[], int relNum)
{
	for (int i(0); i < relNum; i++)
	{
		cout << "Please enter the name of relative #" << i + 1<< ": ";
		cin >> relNames[i];
	}
	cout << endl;
}

/***********************************************************************
* getRelSequence(string relNames[], string relSequence[], int relNum)
* Prompt for the 10 character DNA marker sequence of each of the 
* potential relatives.
************************************************************************/
void getRelSequence(string relNames[], string relSequence[], int relNum)
{
	for (int i(0); i < relNum; i++)
	{
		cout << "Please enter the DNA sequence for " << relNames[i] 
			<< ": ";
		cin >> relSequence[i];
	}
	cout << endl;
}

/***********************************************************************
* display(string potRelatives[][SIZE], int potNum):
************************************************************************/
void display(int percentRel[], int relNum, string relNames[])
{
	for (int i(0); i < relNum; i++)
	{
		cout << "Percent match for " << relNames[i] << " : " 
			<< percentRel[i] << "%" << endl;
	}
}

/***********************************************************************
* compareDNA()
* In this assignment, DNA marker sequences will be restricted to the 
* standard nucleotide base symbols: A, T, C, and G. No error checking is
* required for this assignment
************************************************************************/
void compareDNA(string &userSequence, 
	string relSequence[], int relNum, int percentRel[])
{	
	int counter(0);
	do
	{
		string relSeq = relSequence[counter];
		for (int i(0); i < 10; i++)
		{
			if (userSequence[i] == relSeq[i])
				percentRel[counter] += 10;
		}
		counter++;
	} while (counter < relNum);
}
