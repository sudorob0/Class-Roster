#include "Repo.h"
/*method to parse data and seperate by comma*/
void Repo::parse(string bookdata)/*this parses each row in order*/
{
    BookType bt = UNDECIDED;
    if (bookdata.at(0) == 'F') bt = FICTION; /*determine booktype based off the first charactor*/
    else if (bookdata.at(0) == 'N') bt = NONFICTION;

    /*define variable for the location before the comma*/
    int beforeComma = bookdata.find(",");
    string bID = bookdata.substr(0, beforeComma);/*get string before comma*/

    /*define variable for the location after the comma*/
    int afterComma = bookdata.find(",", afterComma);
    /*find the next comma*/
    beforeComma = bookdata.find(",", afterComma);
    /*save string between the commas*/
    string ttl = bookdata.substr(afterComma, beforeComma - afterComma);

    afterComma = beforeComma + 1;
    beforeComma = bookdata.find(",", afterComma);
    string aut = bookdata.substr(afterComma, beforeComma - afterComma);
    /*first price*/
    afterComma = beforeComma + 1;
    beforeComma = bookdata.find(",", afterComma);
    double firstPrice = stod(bookdata.substr(beforeComma, afterComma - beforeComma));
    /*second price*/
    afterComma = beforeComma + 1;
    beforeComma = bookdata.find(",", afterComma);
    double secondPrice = stod(bookdata.substr(beforeComma, afterComma - beforeComma));
    /*third price*/
    afterComma = beforeComma + 1;
    beforeComma = bookdata.find(",", afterComma);
    double thridPrice = stod(bookdata.substr(beforeComma, afterComma - beforeComma));

    /*create an object*/
    add(bID, ttl, aut, firstPrice, secondPrice, thridPrice, bt);
}

/*create an object*/
void Repo::add(string bookID, string title, string author, double firstPrice, double secondPrice, double thirdPrice, BookType bt)
{
    /*put prices into an array*/
    double parr[3] = { firstPrice, secondPrice, thirdPrice };
    bookRepoArray[++lastIndex] = new Book(bookID, title, author, parr, bt);
}

void Repo::printALL()
{
    Book::printHeader();
    for (int i = 0; i <= Repo::lastIndex; i++)
    {
        cout << bookRepoArray[i]->getID(); cout << '\t';
        cout << bookRepoArray[i]->getTitle(); cout << '\t';
        cout << bookRepoArray[i]->getAuthor(); cout << '\t';
        cout << bookRepoArray[i]->getPrices()[0]; cout << '\t';
        cout << bookRepoArray[i]->getPrices()[1]; cout << '\t';
        cout << bookRepoArray[i]->getPrices()[2]; cout << '\t';
        cout << bookTypeStrings[bookRepoArray[i]->getBookType()] << std::endl;
    }
}

void Repo::printByBookType(BookType bt)
{
    Book::printHeader();
    for (int i = 0; i <= Repo::lastIndex; i++) {
        if (Repo::bookRepoArray[i]->getBookType() == bt) bookRepoArray[i]->print();
    }
    cout << std::endl;
}

void Repo::printInvalidIDs()
{
    bool any = false;
    for (int i = 0; i <= Repo::lastIndex; i++)
    {
        string bID = (bookRepoArray[i]->getID());
        if (bID.find('_')) == string::npos || (bID.find('X') == string::npos && bID.find('x') == string )
        {
            any=true;
            cout << bID << ": " << bookRepoArray[i]->
        }
    }
    if (!any) cout << "NONE" << std::endl;
}

void Repo::printAveragePrices()
{
    for (int i = 0; i <= Repo::lastIndex; i++) {
        cout << bookRepoArray[i] ->getID() << ": ";
        cout << (bookRepoArray[i]->getPrices()[0]
        + bookRepoArray[i]->getPrices()[1]
        + bookRepoArray[i]->getPrices9[2])/3.0 << std::endl;
    }
    cout << std::endl;
}

void Repo::removeBookByID(string bookID)/*book to be removed imputed as a prameter*/
{
    bool success = false;
    for (int i = 0; i <= Repo::lastIndex; i++)
    {
        if (bookRepoArray[i]->getID() == bookID)
        {
            success = true;
            if (i < numBooks - 1)
            {
                Book* temp = bookRepoArray[i];
                bookRepoArray[i] = bookRepoArray[numBooks - 1];
                bookRepoArray[numBooks - 1] = temp;
            }
            Repo::lastIndex--;/* last book no longer visible*/
            /*book not deleted, is just invisible now*/
        }
    }
    if (success)
    {
        cout << bookID << " removed from repository." << std::endl << std::endl;
        this->printAll();
    }
    else cout << bookID << " not found." << std::endl << std::endl;
}

Repo::~Repo()
{
    cout << "Destructor Called" << std::endl << std::endl;
    for (int i = 0; i < numBooks; i++)
    {
        cout << "Destroying book " << i + 1 << std::endl;
        delete bookRepoArray[i];
        bookRepoArray[i];
        bookRepoArray[i] = nullptr;
    }
}