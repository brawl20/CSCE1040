#include <iostream>


using namespace std;

void add(int a, int b)
{
    cout << (a+b) << endl;
}
void subtract(int a, int b)
{
    cout << (a-b) << endl;
}
void divide(int a, int b)
{
    cout << (a/b) << endl;
}
void multiply(int a, int b)
{
    cout << (a*b) << endl;
}


int main()
{
    int a,b,userChoice;
    bool fuckWad;

    // Get two numbers from user
    cout << "Please provide two numbers" << endl;
    cout << "Number 1: ";
    cin >> a;
    cout << "Number 2: ";
    cin >> b;

    do{
        fuckWad = false;
        // Ask user what they want to do with the numbers
        cout << "Select what you would like to do" << endl;
        cout << "1. Add\n2. Subtract\n3. Divide\n4. Multiply" << endl;

        cin >> userChoice;

        // Do the calculation
        switch (userChoice)
        {
            case 1:
                add(a,b);
            break;
            case 2:
                subtract(a,b);
            break;
            case 3:
                divide(a,b);
            break;
            case 4:
                multiply(a,b);
            break;
            default:
            cout << "Try again fuckwad" << endl;
            fuckWad = true;
        }
    }while(fuckWad == true);
    
return 0;
}