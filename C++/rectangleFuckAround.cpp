#include <iostream>

using namespace std;

class Rectangle
{
    int width, height;

    public:
        get();
        Rectangle();
        Rectangle(int,int);
        void set_values(int, int);
        int area() {return width*height;}
};

void Rectangle::set_values(int x, int y)
{
    width = x;
    height = y;
}

Rectangle::Rectangle()
{
    width = 1;
    height = 1;
}

/*Rectangle::Rectangle(int x, int y)
{
    width = x;
    height = y;
}*/

Rectangle::Rectangle(int x, int y): width(x),height(y){}

int main()
{
    Rectangle rect;
    Rectangle rect1;
    Rectangle rect2(3,8);
    Rectangle rect3 = {8,5};
    //rect.set_values(3,4);
    cout << "area: " << rect.area() << endl;
    cout << "area: " << rect1.area() << endl;
    cout << "area: " << rect2.area() << endl;
    cout << "area: " << rect3.area() << endl;
    return 0;
}