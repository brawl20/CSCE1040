#include <iostream>
#include <vector>

using namespace std;

class TestClass
{
    private:
    vector<int> Test_Vector;

    public:
    void addVector(int input)
    {
        Test_Vector.push_back(input);
    }
    int getVector(int input)
    {
        return Test_Vector.at(input);
    }
    void printVector()
    {
        for (int i = 0; i < Test_Vector.size(); ++i){
            cout << Test_Vector.at(i) << endl;
        }
    }
    void insertVector(int input, int location)
    {
        Test_Vector.insert((Test_Vector.begin() + location), input);
    }

    void removeVector(int location)
    {
        Test_Vector.erase((Test_Vector.begin() + location - 1));
    }

};


int main()
{
    TestClass test;

    for (int i = 0; i < 8; ++i){
        test.addVector(i);
    }

    cout << "First list of original values:" << endl;
    test.printVector();

    test.removeVector(5);

    cout << "List of values after removing element 5:" << endl;
    test.printVector();

    cout << "Value at element 3: " << test.getVector(3) << endl;

    cout << "List after inserting 4 to element 5: " << endl;
    test.insertVector(4, 5);
    test.printVector();
    

    return 0;
}