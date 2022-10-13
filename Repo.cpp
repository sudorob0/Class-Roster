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




}