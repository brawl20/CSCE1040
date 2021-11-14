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
        for(int i = 0; i < 40; i++)
        {
            customerName[i] = ' ';
        }
        creditCardExpDate = "00/0000";
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
        for(int i = 0; i < 40; i++){
            Customer::customerName[i] = customerName[i];
        }
        Customer::creditCardExpDate = creditCardExpDate;
        Customer::creditCardValKey = creditCardValKey;
        for(int i = 0; i < 2; i++)
        {
            Customer::activeMovies[i] = activeMovies[i];
        }
    }

    //Accessors
    // int Customer::GetCustomerID();
    // int Customer::GetCreditCardNum();
    string Customer::GetCustomerName()
    {
       return customerName;
    }
    // string Customer::GetCreditCardExpDate();
    // int Customer::GetCreditCardValKey();
    // Movie Customer::GetActiveMovies();

    //Mutators
    // void Customer::SetCustomerID(int customerID);
    // void Customer::SetCreditCardNum(int creditCardNum);
    void Customer::SetCustomerName(string passedCustomerName)
    {
        Customer::customerName = passedCustomerName;
    }
    // void Customer::SetCreditCardExpDate(string creditCardExpDate);
    // void Customer::SetCreditCardValKey(int creditCardValKey);
    // void Customer::SetActiveMovies(Movie activeMovies[]);