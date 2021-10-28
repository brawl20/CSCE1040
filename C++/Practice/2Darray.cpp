// Last test edited with VIM
#include <iostream>

using namespace std;

int main()
{
    int **Array2D;
    int userInput, jInput;

    cout << "How many I levels?" << endl;
    cin >> userInput;

    *Array2D = new int[userInput];

    

    for (int i = 0; i < userInput; ++i)
    {
        cout << "How many J levels on I level " << i+1 << endl;
        cin >> jInput;
        Array2D[i] = new int[jInput]; 
    }

    for (int i = 0; i < userInput; ++i)
    {
        for (int j = 0; j < jInput; ++j)
        {
            cout << "Enter value for " << i+1 << " : " << j+1 << endl; 
            cin >> Array2D[i][j];
        }
    }

    for (int i = 0; i < userInput; ++i)
    {
        for (int j = 0; j < jInput; ++j)
        {
            cout << Array2D[i][j] << "\t";
        }
    }



    delete [] Array2D;
    return 0;
}
