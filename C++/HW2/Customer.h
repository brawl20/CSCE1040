#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Movie.h"
#include <string>
#include <iostream>

using namespace std;

class Customer
{
    public:
    
    //Default Constructor
    Customer();
    
    //Parameterized Constructor
    Customer(int customerID, int creditCardNum, char* customerName, string creditCardExpDate, int creditCardValKey, Movie* activeMovies);

    //Accessors
    int GetCustomerID();
    int GetCreditCardNum();
    string GetCustomerName();
    string GetCreditCardExpDate();
    int GetCreditCardValKey();
    Movie GetActiveMovies();

    //Mutators
    void SetCustomerID(int customerID);
    void SetCreditCardNum(int creditCardNum);
    void SetCustomerName(string customerName);
    void SetCreditCardExpDate(string creditCardExpDate);
    void SetCreditCardValKey(int creditCardValKey);
    void SetActiveMovies(Movie activeMovies[]);

    private:
    int customerID;
    int creditCardNum;
    string customerName;
    string creditCardExpDate;
    int creditCardValKey;
    Movie activeMovies[2];

};

#endif