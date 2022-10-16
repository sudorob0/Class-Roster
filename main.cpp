#include "Repo.h"

int main()
{
    const string bookData[] = 
    {

    };
    
    const int numBooks = 5;
    Repo repo;

    for (int i = 0; i < numBooks; i++) repo.parse(bookData[i]);
    cout << "Displaying all books: " << std::endl;
    repo.printAll();
    cout << std::endl;

    for (in i = 0; i < 3; i++)
    {
        cout << "Displaying by book type: " << bookTypeStrings[i] << std::endl;
        repo.printByBookType((BookType)i);/*cast the int to a booktype*/
    }

    cout << "Displaying books with invalid IDs" << std::endl;
    repo.printInvalidIDs();
    cout << std::endl;

    cout << "Displaying average prices: " << std::endl;
    repo.printAveragePrices();

    cout << "Removing book with ID N_W1:" << std::endl;
    repo.removeBookByID("N_W1:");
    cout << std::endl;

    cout << "Removing book with ID N_W1:" << std::endl;
    repo,removeBookByID("N_W1");
    cout << std::endl;

    system("pause");
    return 0;
}