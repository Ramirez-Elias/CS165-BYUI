/***********************************************************************
* Program:
* Assignment Assign03 - DIGITAL FORENSICS WITH CORRUPT FILES
* Brother      , CS165
* Author:
* Elias Ramirez
*
* ACME Widget Corporation had another break in. They loved the work you
* did last time, so they've come to you again. Unfortunately, this time,
* their log file was corrupted, so your program from before crashes when
* run on the log.
************************************************************************/
#include <iomanip>
#include <iostream>
#include <string>
#include<fstream>
#include<sstream>

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
//int readFile(std::string &filename, AccessRecord record[]);
void promptTime(long &startTime, long &endTime);
void display(AccessRecord record[], int size, long &startTime, long &endTime);
int parseFile(std::string &filename, std::string line, AccessRecord record[]);
void parseLine(std::string &filename, std::string line, AccessRecord record[], int location);
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
	std::string line = {};
	int size = parseFile(filename, line, record);
	long startTime(0);
	long endTime(0);
	promptTime(startTime, endTime);
	display(record, size,  startTime, endTime);
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
* Function: parseLine
* 3 - Create a function, parseLine that accepts a line(a string) and 
* populates a struct for the AccessRecord.
 ***********************************************************************/
void parseLine(std::string line, AccessRecord record[], int location)
{
	try {
	std::stringstream ss(line);
	ss >> record[location].filename >> record[location].username >> record[location].timestamp;

	if (ss.fail())
	{
		std::cin.clear();
		throw std::string(line);
	}
	else if (record[location].timestamp < 1000000000 || record[location].timestamp > 10000000000)
	{
		std::cin.clear();
		throw std::string(line);
	}
	else if (record[location].filename.empty() || record[location].username.empty())
	{
		std::cin.clear();
		throw std::string(line);
	}
	}
	catch (const std::string message)
	{
		std::cout << "Error parsing line: " << message << std::endl;
	}
}

/***********************************************************************
* Function: parseFile
* 5 - Use a stringstream to parse the line into a book, chapter, verse.
*  Store it in a Scripture struct, and pass that struct to the display
* function.
 ***********************************************************************/
int parseFile(std::string &filename, std::string line, AccessRecord record[])
{
	
	std::ifstream fin(filename);
	//check errors
	if (fin.fail())
	{
		std::cout << "Error reading file\n";
		
	}

	//read through file
	int i(0);
	while (!fin.eof())
	{
		std::getline(fin, line);
		parseLine(line, record, i);
		i++;
	}

	//close file
	fin.close();
	return i;
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
