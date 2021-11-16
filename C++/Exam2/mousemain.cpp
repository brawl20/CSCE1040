#include "mouse.h"
#include <iostream>
#include <vector>


using namespace std;




int main()
{
    int numMice = 6;
    string userInput;
    float userFloat;
    char userChar;
    bool loop = false;

    vector<Mouse> Mice;
    vector<Mouse>::iterator it;
    int mouseCount = 0;

    for (int i = 0; i < numMice; i++)
    {
        Mice.push_back(Mouse());
        cout << "Breed:" << endl;
        cin >> userInput;
        Mice[i].SetBreed(userInput);
        cout << "Weight:" << endl;
        cin >> userFloat;
        Mice[i].SetWeight(userFloat);
        cout << "Name:" << endl;
        cin >> userInput;
        Mice[i].SetName(userInput);
        cout << "Gender:" << endl;
        cin >> userChar;
        userChar = toupper(userChar);
        do{
            switch (userChar)
            {
                case 'M':
                    loop = false;
                break;
                case 'F':
                    loop = false;
                break;
                default:
                loop = true;
                cout << "Invalid option please try again.(F/f Female, m/M Male)\nBreed:\n";
                cin >> userChar;
                userChar = toupper(userChar);
                break;

            }
        }while(loop);
        Mice[i].SetGender(userChar);
        cout << "Favorite Food:" << endl;
        cin.ignore();
        getline(cin,userInput);
        Mice[i].SetFavoriteFood(userInput);
        cout << "Color Description:" << endl;
        getline(cin,userInput);
        Mice[i].SetColorDescription(userInput);
        cout << "Other Comments:" << endl;
        getline(cin,userInput);
        Mice[i].SetOtherComments(userInput);
    }

    for (it = Mice.begin(); it < Mice.end(); it++)
    {
        cout << "Mouse " << mouseCount+1 << ":" << endl;
        ++mouseCount;
        it->printInfo();
    }
    return 0;
}