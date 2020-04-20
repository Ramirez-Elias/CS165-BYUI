/***********************************************************************
* Program:
* Assignment Assign02 - DIGITAL FORENSICS
* Brother      , CS165
* Author:
* Elias Ramirez
*
* ACME Widget Corporation just experienced their first digital security
* breach. One of their secret widget designs just appeared on the 
* Internet. Now they've hired you as a digital forensics investigator 
* to help determine what additional data might have been involved in 
* the breach.
* Write a program to scan through that log to identify users who accessed
* files in a particular window of time.
************************************************************************/
#include <iomanip>
#include <iostream>
#include <string>
#include<fstream>

//For this assignment, you may assume that there will never be more than 
//500 lines in a file (so you can declare your array accordingly).
#define SIZE 500

//1- Create a struct for an Access Record that contains a username, 
//   a filename, and a long (e.g. very large integer) timestamp.
struct AccessRecord
{
	std::string username;
	std::string filename;
	long timestamp;
};

//prototyping
void getFile(std::string &filename);
int readFile(std::string &filename, AccessRecord record[]);
void promptTime(long &startTime, long &endTime);
void display(AccessRecord record[], int size, long &startTime, long &endTime);

/***********************************************************************
* MAIN:
* Write a program to scan through that log to identify users who accessed
* files in a particular window of time.
************************************************************************/
int main()
{
	std::string filename = {};
	AccessRecord record[SIZE];
	getFile(filename);
	int size = readFile(filename, record);
	long startTime(0);
	long endTime(0);
	promptTime(startTime, endTime);
	display(record, size, startTime, endTime);
	return 0;
}

/***********************************************************************
* getFile(string userSequence[])
* 2- Prompt the user for the name of a file.
************************************************************************/
void getFile(std::string &filename)
{
	std::cout << "Enter the access record file : ";
	std::getline(std::cin, filename);
	std::cout << std::endl;
}

/***********************************************************************
* readFile()
* 3- Read in a list of Access Records from the file and store it in an 
array of structs.
************************************************************************/
int readFile(std::string &filename, AccessRecord record[])
{
	//openFile
	std::ifstream fin(filename);

	//check errors
	if (fin.fail())
	{
		std::cout << "Error reading file\n";
		return 1;
	}
	int counter(0);
	//read through file
	while (!fin.eof())
	{
		fin >> record[counter].filename >> record[counter].username 
			>> record[counter].timestamp;
		counter++;
	}
	
	//close file
	fin.close();

	return counter;
}

/***********************************************************************
* promptTime()
* 4- Prompt the user for a start time and an end time for consideration.
************************************************************************/
void promptTime(long &startTime, long &endTime)
{
	std::cout << "Enter the start time: ";
	std::cin >> startTime;
	std::cout << "Enter the end time: ";
	std::cin >> endTime;
	std::cout << std::endl;
}

/***********************************************************************
* display()
* 5- Display a list of all files that were accessed during that period
* along with the users that accessed them.
************************************************************************/
void display(AccessRecord record[], int size, long &startTime, long &endTime)
{
	std::cout << "The following records match your criteria:" << std::endl;
	std::cout << std::endl;
	std::cout << "      TimeStamp                File                User\n";
	std::cout << "--------------- ------------------- -------------------\n";
	for (int i = 0; i < size; i++)
	{
		// 5- Display a list of all files that were accessed during 
		//that period along with the users that accessed them..
		if (record[i].timestamp >= startTime && record[i].timestamp <= endTime)
		{
			std::cout << std::setw(15) << record[i].timestamp
				<< std::setw(20) << record[i].filename << std::setw(20)
				<< record[i].username << std::endl;
		}
	}
	std::cout << "End of records" << std::endl;
}
