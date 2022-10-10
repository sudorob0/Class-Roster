#pragma once
#include <iostream>
#include <iomanip>
#include "BookType.h"

using std::string;
using std::cout;

class Book
{
public:
    const static int priceArraySize = 3;
private:
    string bookID;
    string title;
    string author;
    double prices[priceArraySize];
    BookType bookType;
public:
    Book();/*parameterless constructor - sets to defalt values*/
    Book(string bookID, string title, string author, double prices[], BookType bookType);/*Full constructure*/
    ~Book();/*destructors*/

    /*getters aka accessors*/
    string getID();
    string getTitle();
    string getAuthor();
    double* getPrices();
    BookType getBookType();

    /*setters aka mutators*/
    void setID(string ID);
    void setTitle(string title);
    void setAuthor(string author);
    void setPrices(double prices[]);
    void setBookType(BookType bt);

    /*display a header for the data to followU*/
    static void printHeader();

    /*displays 'this' student's data*/
    void print();
};