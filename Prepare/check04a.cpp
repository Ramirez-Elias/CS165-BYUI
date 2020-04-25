/***********************************************************************
* Program:
* Assignment check04a
* Brother      , CS165
* Author:
* Elias Ramirez
*
* This checkpoint is intended to help you practice the syntax of creating
* your own class. For this checkpoint, you need not put your class in its
* own file, but rather can put all of the code together in one file.
*
* Write a C++ program that has a class for a book, prompts the user for 
* the book's information, and then displays it back.
************************************************************************/
#include <iostream>
#include <string>

//1- Create a class called "Book" with the following private data members:
// title - author
class Book
{
//2- Add a prompt method (function) to your class, which asks the user to
//   enter a title and an author and stores them in the member variables. 
//   (Don't forget to use getline here to allow for spaces.)
public:
	//Prompt method will ask user for input
	void prompt();
	//While display will output it
	void display();
	//getter and setters
	void getTitle();
	void setTitle(std::string title); //it takes an string as it would be used
	void getAuthor();				  // to set the Title	
	void setAuthor(std::string author);//Similar as above
private:
	//Private member variables
	std::string title;
	std::string author;
};

void Book:: prompt()
{
	//Prompt will call the getters and setters 
	getTitle();
	setTitle(title);
	getAuthor();
	setAuthor(author);
}

// 3. Add a display method to your class, which displays the member
//    variables in the format: "the book title" by the author.
void Book::display()
{
	//"This" will access private member variable and display them
	std::cout << "\"" << this->title << "\" by " << this->author << std::endl;
}

//Getter getFile will ask for Title input
void Book::getTitle()
{
	std::cout << "Title: ";
	std::getline(std::cin, title);
}

//Setter setFile will 
void Book::setTitle(std::string title)
{
	//using this as the member variable is being accessed and modified
	this->title = title;
}
//Getter getAuthor will ask for Author input
void Book::getAuthor()
{
	std::cout << "Author: ";
	std::getline(std::cin, author);
}
void Book::setAuthor(std::string author)
{
	//using this as the member variable is being accessed and modified
	this->author = author;
}


/***********************************************************************
* MAIN:
* 4- For this assignment, you may use only one file and put the class and
*    it's methods (functions) at the top of the file.
* 5- Have main: A. Create a Book object B. Call its prompt method
*    C. Call its display method
************************************************************************/
int main()
{
	Book book;
	book.prompt();
	book.display();
	return 0;
}

