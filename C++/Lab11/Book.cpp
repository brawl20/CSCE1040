#include "Book.h"
#include <iostream>

void Book::SetTitle(string userTitle) {
   title = userTitle;
}

string Book::GetTitle() {
   return title;
}

void Book::SetAuthor(string userAuthor) {
   author = userAuthor;
}

string Book::GetAuthor() {
   return author;
}

void Book::SetPublisher(string userPublisher) {
   publisher = userPublisher;
}

string Book::GetPublisher() {
   return publisher;
}

void Book::SetPublicationDate(string userPublicationDate) {
   publicationDate = userPublicationDate;
}

string Book::GetPublicationDate() {
   return publicationDate;
}

void Book::PrintInfo() {
   cout << "Book Information: " << endl;
   cout << "   Book Title: " << title << endl;
   cout << "   Author: " << author << endl;
   cout << "   Publisher: " << publisher << endl;
   cout << "   Publication Date: " << publicationDate << endl;
}