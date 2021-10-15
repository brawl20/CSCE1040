#include "Mouse.h"
#include <iostream>

using namespace std;

int main() 
{
    Mouse *Mice; //Save Area for later
    char userInputChar;
    float userInputFloat;
    string userInputString;
    int numMice = 6;

    /*cout << "How many mice?" << endl;
    cin >> numMice;*/

    Mice = new Mouse[numMice]; //GAP THE AREA



    //Get user data
    for (int i = 0; i < numMice; ++i)
    {
        cout << "Breed:" << endl;
        cin >> userInputString;
        Mice[i].SetBreed(userInputString);
        cout << "Weight:" << endl;
        cin >> userInputFloat;
        Mice[i].SetWeight(userInputFloat);
        cout << "Name:" << endl;
        cin >> userInputString;
        Mice[i].SetName(userInputString);
        cout << "Gender:" << endl;
        cin >> userInputChar;
        Mice[i].SetGender(userInputChar);
        cout << "Favorite Food:" << endl;
        cin.ignore();
        getline(cin,userInputString);
        Mice[i].SetFavoriteFood(userInputString);
        cout << "Color Description:" << endl;
        getline(cin,userInputString);
        Mice[i].SetColorDescription(userInputString);
        cout << "Other Comments:" << endl;
        getline(cin,userInputString);
        Mice[i].SetOtherComments(userInputString);
    }

    //Print User Data
    for (int i = 0; i < numMice; ++i)
    {
        cout << "Mouse " << i+1 << ":" << endl;
        Mice[i].printInfo();
    }

}