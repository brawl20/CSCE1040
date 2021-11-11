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
    Customer(int customerID, int creditCardNum, char customerName, string creditCardExpDate, int creditCardValKey, Movie activeMovies);

    //Accessors
    int GetcustomerID();
    int GetcreditCardNum();
    char GetcustomerName();
    string GetcreditCardExpDate();
    int GetcreditCardValKey();
    Movie GetactiveMovies();

    //Mutators
    void SetcustomerID(int customerID);
    void SetcreditCardNum(int creditCardNum);
    void SetcustomerName(char customerName);
    void SetcreditCardExpDate(string creditCardExpDate);
    void SetcreditCardValKey(int creditCardValKey);
    void SetactiveMovies(Movie activeMovies);

    private:
    int customerID;
    int creditCardNum;
    char customerName[40];
    string creditCardExpDate;
    int creditCardValKey;
    Movie activeMovies[2];

};

#endif