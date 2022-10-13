#pragma once
#include "Book.h"
class Repo
{
private:
    int lastIndex = -1;
    const static int numBooks = 5;
    Book* bookRepoArray[numBooks];

public:
    /* extract data from a book*/
    void parse(string row);
    /*all the data from parse is entered into an object*/
    void add(string bID,
        string bTitle,
        string bAuthor,
        double bprice1,
        double bprice2,
        double bprince3,
        BookType bt);
    void printALL(); /*uses the print method for the book class for each book*/
    void printByBookType(BookType bt);/*booktype is passed in*/
    void printInvalidIDs();/*verify booktypes are entered in the correct format*/
    void printAveragePrices();
    void removeBookByID(string bookID);/*takes an string id argument and deletes the book*/
    ~Repo();
};
