#include "Book.h"
/*Parameterless constructor sets to default values*/
Book::Book()
{
    this->bookID = "";
    this->title = "";
    this->author = "";
    for (int i = 0; i < priceArraySize; i++) this->prices[i] = 0;
    this->bookType = BookType::UNDECIDED;
}
 /*full constructor with parameters*/
Book::Book(string bookID, string title, string author, double prices[], BookType bookType)
{
    this->bookID = bookID;
    this->title = title;
    this->author = author;
    for (int i=0; i < priceArraySize; i++) this->prices[i] = prices[i];
    this->bookType = bookType;
}

/* destructor */
Book::~Book() {}

/* getters */
string Book::getID() { return this->bookID;}
string Book::getAuthor() { return this->author; }
string Book::getTitle() {return this->title; }
double* Book::getPrices(){return this->prices; }
BookType Book::getBookType() { return this->bookType; }

/*setters*/
void Book::setID(string ID) { this->bookID = ID; }
void Book::setTitle(string title) { this->title = title; }
void Book::setAuthor(string author) { this->author = author; }
void Book::setPrices(double prices[])
{
    for (int i = 0; i < priceArraySize; i++) this->prices[i];
}
void Book::setBookType(BookType bt) { this->bookType = bt; }

void Book::print()
{
    cout << "Output format: ID|Title|Author|Prices|Type\n";
    cout << this->getID() << '-\t';
    cout << this->getTitle() << '-\t';
    cout << this->getAuthor() << '-\t';
    cout << this->getPrices()[0] << '-\t';
    cout << this->getPrices()[1] << '-\t';
    cout << this->getPrices()[2] << '-\t';
    cout << bookTypeStrings[this->getBookType()] << '\n';

}