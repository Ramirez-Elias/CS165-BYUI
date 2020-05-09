/***********************************************************************
* Program:
* Assignment check08a
* Brother      , CS165
* Author:
* Elias Ramirez
*
* This checkpoint is intended to help you practice the syntax of basic
* inheritance.
************************************************************************/
#include <iostream>
#include <string>
using namespace std;

// For this assignment, for simplicity, you may put all of your classes
// in this file.

// TODO: Define your Book class here
class Book
{
public:
	Book() {};
	~Book() {};
	//5- In the base Book class, create a method promptBookInfo that prompts the user for the title, 
	//   author, and publicationYear, and also a method displayBookInfo that displays the title, author
	//   and publication year in the format: "Title (publicationYear) by Author".
	void promptBookInfo();
	void displayBookInfo();

private:
	//2- Create a class for a Book that has the following member variables:
	//   title : string - author : string - publicationYear : int
	string title;
	string author;
	int publicationYear;
};


void Book::promptBookInfo()
{
	
	cout << "Title: ";
	getline(cin, this->title);
	cout << "Author: ";
	getline(cin, this->author);
	cout << "Publication Year : ";
	cin >> this->publicationYear;
	cin.ignore();
}
void Book::displayBookInfo()
{
	//"Title (publicationYear) by Author".
	//The Miracle of Forgiveness (1969) by Spencer W. Kimball
	cout << this->title << " (" << this->publicationYear << ") " << this->author << endl;
}

// TODO: Define your TextBook class here
//3- Next, create a class for a TextBook that extends a Book and adds the following member variable:
//   subject: string
class TextBook : public Book
{
public:
	TextBook() {};
	~TextBook() {};
	//6 - In the TextBook class, create methods promptSubject and displaySubject that prompt and 
	//    display the subject of the book.
	void promptSubject();
	void displaySubject();

private:
	string subject;
};

void TextBook::promptSubject()
{
	//Subject: Computer Science
	cout << "Subject: ";
	getline(cin, this->subject);
}

void TextBook::displaySubject()
{
	//Subject: Computer Science
	cout << "Subject: " << this->subject << endl;
}

// TODO: Add your PictureBook class here
//4- Finally, create a class for a PictureBook that that extends a Book and adds the following member variable:
//   illustrator: string
class PictureBook : public Book
{
public:
	PictureBook() {};
	~PictureBook() {};
	//7 - In the PictureBook class, create methods promptIllustrator and displayIllustrator that prompt and 
	//    display the Illustrator of the book.
	void promptIllustrator();
	void displayIllustrator();
private:
	string illustrator;
};

void PictureBook::promptIllustrator()
{
	//Illustrator: Betsy Lewin
	cout << "Illustrator: ";
	getline(cin, this->illustrator);
}

void PictureBook::displayIllustrator()
{
	//Illustrated by Betsy Lewin
	cout << "Illustrated by " << this->illustrator << endl;
}


/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
	// Declare a Book object here and call its methods
	// 8- In main, first create a Book object and call the following methods:
	//    promptBookInfo - displayBookInfo
	Book book;
	book.promptBookInfo();
	cout << endl;
	book.displayBookInfo();
	cout << endl;
	// Declare a TextBook object here and call its methods
	//9 - Next, create a TextBook object and call the following methods:
	//    promptBookInfo - promptSubject - displayBookInfo - displaySubject
	TextBook textBook;
	textBook.promptBookInfo();
	textBook.promptSubject();
	cout << endl;
	textBook.displayBookInfo();
	textBook.displaySubject();
	cout << endl;
	// Declare a PictureBook object here and call its methods
	//10- Finally, create a PictureBook object and call the following methods:
	//    promptBookInfo - promptIllustrator - displayBookInfo - displayIllustrator
	PictureBook pictureBook;
	pictureBook.promptBookInfo();
	pictureBook.promptIllustrator();
	cout << endl;
	pictureBook.displayBookInfo();
	pictureBook.displayIllustrator();
	cout << endl;
	return 0;
}


