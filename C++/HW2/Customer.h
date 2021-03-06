#ifndef CUSTOMER_H
#define CUSTOMER_H

/*
	Author:			Micheal Landsbaum (MichealLandsbaum@my.unt.edu)
	Date:			11/16/2021
	Course:         CSCE1040
	Assignment:     Homework 3
*/

#include "Movie.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Customer
{
    public:
    
    //Default Constructor
    Customer();
    
    //Parameterized Constructor
    Customer(int customerID, int creditCardNum, string customerName, string creditCardExpDate, int creditCardValKey, Movie* activeMovies);

    //Accessors
    int GetCustomerID();
    long long unsigned int GetCreditCardNum();
    string GetCustomerName();
    string GetCreditCardExpDate();
    int GetCreditCardValKey();
    Movie GetActiveMovies(int index);
    int GetActiveMovieCount();

    //Mutators
    void SetCustomerID(int customerID);
    void SetCreditCardNum(long long unsigned int creditCardNum);
    void SetCustomerName(string customerName);
    void SetCreditCardExpDate(string creditCardExpDate);
    void SetCreditCardValKey(int creditCardValKey);
    void SetActiveMovies(Movie activeMovie);

    private:
    int customerID;
    long long unsigned int creditCardNum;
    string customerName;
    string creditCardExpDate;
    int creditCardValKey;
    vector<Movie> activeMovies;

};

#endif