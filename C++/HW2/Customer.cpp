#include "Customer.h"
#include "Movie.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

    //Default Constructor
    Customer::Customer()
    {
        customerID = 0;
        creditCardNum = 0;
        customerName = "No Name";
        creditCardExpDate = "Nothing";
        creditCardValKey = 000;
        for(int i = 0; i < 2; i++)
        {
            activeMovies[i] = Movie();
        }

    }
    
    //Parameterized Constructor
    Customer::Customer(int customerID, int creditCardNum, char* customerName, string creditCardExpDate, int creditCardValKey, Movie* activeMovies)
    {
        Customer::customerID = customerID;
        Customer::creditCardNum = creditCardNum;
        Customer::customerName = customerName;
        Customer::creditCardExpDate = creditCardExpDate;
        Customer::creditCardValKey = creditCardValKey;
        for(int i = 0; i < 2; i++)
        {
            Customer::activeMovies[i] = activeMovies[i];
        }
    }

    //Accessors
    // int Customer::GetCustomerID();
    long long unsigned int Customer::GetCreditCardNum()
    {
        return creditCardNum;
    }
    string Customer::GetCustomerName()
    {
       return customerName;
    }
    string Customer::GetCreditCardExpDate()
    {
        return creditCardExpDate;
    }
    // int Customer::GetCreditCardValKey();
    // Movie Customer::GetActiveMovies();

    //Mutators
    // void Customer::SetCustomerID(int customerID);
    void Customer::SetCreditCardNum(long long unsigned int creditCardNum)
    {
        Customer::creditCardNum = creditCardNum;
    }

    void Customer::SetCustomerName(string passedCustomerName)
    {
        Customer::customerName = passedCustomerName;
    }

    void Customer::SetCreditCardExpDate(string creditCardExpDate)
    {
        Customer::creditCardExpDate = creditCardExpDate;
    }
    // void Customer::SetCreditCardValKey(int creditCardValKey);
    void Customer::SetActiveMovies(Movie activeMovie)
    {
        if(activeMovies.size() != 2)
        {
            activeMovies.push_back(activeMovie);
        }
        else
        {
            cout << "This customer already has two movies checked out\n";
        }
    }