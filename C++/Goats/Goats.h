#ifndef GOATSH
#define GOATSH
#include <string>

using namespace std;

class Goat
{
    private:
    string furColor;
    int Age;
    
    public:
    string getFurColor();
    int getAge();
    
    void setFurColor(string color);
    void setAge(int inputAge);
};


#endif