#include <iostream>
#include "Goats.h"
using namespace std;
   
    string Goat::getFurColor()
    {
        return (furColor);
    }
    void Goat::setFurColor(string color)
    {
        furColor = color;
    }
    int Goat::getAge()
    {
        return Age;
    }
    void Goat::setAge(int inputAge)
    {
        Goat::Age = inputAge;
    }


