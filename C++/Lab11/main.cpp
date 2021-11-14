#include "Book.h"
#include "Encyclopedia.h"
#include <string>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
   Book myBook;
   Encyclopedia myEncyclopedia;

   string title, author, publisher, publicationDate;
   string eTitle, eAuthor, ePublisher, ePublicationDate, edition;
   int numVolumes;

   getline(cin, title);
   getline(cin, author);
   getline(cin, publisher);
   getline(cin, publicationDate);

   getline(cin, eTitle);
   getline(cin, eAuthor);
   getline(cin, ePublisher);
   getline(cin, ePublicationDate);
   getline(cin, edition);
   cin >> numVolumes;

   myBook.SetTitle(title);
   myBook.SetAuthor(author);
   myBook.SetPublisher(publisher);
   myBook.SetPublicationDate(publicationDate);
   myBook.PrintInfo();

   myEncyclopedia.SetTitle(eTitle);
   myEncyclopedia.SetAuthor(eAuthor);
   myEncyclopedia.SetPublisher(ePublisher);
   myEncyclopedia.SetPublicationDate(ePublicationDate);
   myEncyclopedia.SetEdition(edition);
   myEncyclopedia.SetNumVolumes(numVolumes);
   myEncyclopedia.PrintInfo();

   return 0;
 }