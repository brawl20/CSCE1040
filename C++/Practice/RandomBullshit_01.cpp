#include <iostream>
using namespace std;

int global (5);

class Library
{
    public:
    string bookName;
    int bookQuantity;
    int ISBN;
    void get();
    private:
};
void Library::get(enum )
{
    
}
struct bookCase
{
    string title;
    int ISBN;
    int quantity;
    void printBookCase()
    {
        cout << quantity << endl;
        cout << title << endl;
        cout << ISBN << endl; 
    };
};
int main()
{
    Library libraryBook[10];
    bookCase book1,book2,book3,book4,book5;

    libraryBook[1].bookName = "Crackhead Harry";
    libraryBook[1].ISBN = 456789;
    libraryBook[1].bookQuantity = 8;
    libraryBook[1].get();

    book1.title = "Harry Potter";
    book1.ISBN = 123456;
    book1.quantity = 8;
    book5 = book1;

    book1.printBookCase();

    cout << book1.quantity << endl;
    cout << book1.title << endl;
    cout << global << endl;
    cout << book5.title << endl;
}

