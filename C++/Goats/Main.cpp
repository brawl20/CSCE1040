#include <iostream>
#include "Goats.h"

using namespace std;


int main() 
{
    int goatNums, age;
    string color;
    Goat *goats;
    
    cout << "How many goats?" << endl;
    cin >> goatNums;

    goats = new Goat[goatNums];

    for (int i = 0; i < goatNums; ++i)
    {
        cout << "Goat " << i+1 << " age:" << endl;
        cin >> age;
        goats[i].setAge(age);
        cout << "Goat " << i+1 << " color:" << endl;
        cin >> color;
        goats[i].setFurColor(color);
    }

    for (int i = 0; i < goatNums; ++i)
    {
        cout << "Goat " << i+1 << " Age: " << goats[i].getAge() << " Fur Color: " << goats[i].getFurColor() << endl;
    }

    delete goats;

    return 0;
}