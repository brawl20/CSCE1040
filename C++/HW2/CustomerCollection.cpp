/*
	Author:			Micheal Landsbaum (MichealLandsbaum@my.unt.edu)
	Date:			11/16/2021
	Course:         CSCE1040
	Assignment:     Homework 3
*/

#include "Customer.h"
#include "CustomerCollection.h"
#include "Movie.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <ctime>


using namespace std;

void CustomerCollection::loadDataBase()
{
    ofstream fout;
    ifstream fin;
    string tempHolder;
    int tempInt;
    Movie tempMovie;

    fout.open("GreenBox-Data.txt", ios::app);
    fin.open("GreenBox-Data.txt"); 

    // Check how many Customers are in the system
    while(!fin.eof())
    {
        getline(fin, tempHolder);
        // cout << tempHolder << endl;
        if (tempHolder == "Customer ID:")
        {
            getline(fin,tempHolder);
            Customers.push_back(Customer());
            Customers.back().SetCustomerID(stoi(tempHolder));
        }
        if (tempHolder == "Customer Name:")
        {
            getline(fin,tempHolder);
            Customers.back().SetCustomerName(tempHolder);
        }
        if (tempHolder == "Credit Card Number:")
        {
            long long unsigned int cardNumber = 0;
            getline(fin,tempHolder);
            cardNumber = stoll(tempHolder, nullptr, 10);
            Customers.back().SetCreditCardNum(cardNumber);
        }
        if (tempHolder == "Expiration Date:")
        {
            getline(fin,tempHolder);
            Customers.back().SetCreditCardExpDate(tempHolder);
        }
        if (tempHolder == "Validation Key:")
        {
            int valKey;
            getline(fin,tempHolder);
            valKey = stoi(tempHolder);
            Customers.back().SetCreditCardValKey(valKey);
        }
        if (tempHolder == "Movie ID:")
        {
            getline(fin, tempHolder);
            tempInt = stoi(tempHolder);
            tempMovie.SetmovieID(tempInt);
        }
        
        if (tempHolder == "Movie Title:")
        {
            getline(fin, tempHolder);
            tempMovie.SetmovieTitle(tempHolder);
        }
        if (tempHolder == "Release Date:")
        {
            getline(fin, tempHolder);
            tempMovie.SetreleaseDate(tempHolder);
        }
        if (tempHolder == "Rating:")
        {
            getline(fin, tempHolder);
            tempMovie.Setrating(tempHolder);
        }
        if (tempHolder == "Duration:")
        {
            getline(fin, tempHolder);
            tempMovie.Setduration(tempHolder);
        }
        if (tempHolder == "Rental Cost:")
        {
            getline(fin, tempHolder);
            tempMovie.SetrentalCost(tempHolder);
        }
        if (tempHolder == "Replacement Cost:")
        {
            getline(fin, tempHolder);
            tempMovie.SetreplacementCost(tempHolder);
            Customers.back().SetActiveMovies(tempMovie);
        } 
    }
}



void CustomerCollection::addCustomer()
{
    //Variables
    long long unsigned int creditCardNum;
    int expirationDateMonth;
    int expirationDateYear;
    int userChoice;
    int cardValKey;
    int randNum;
    string userName;
    ofstream fout;
    ifstream fin;
    string tempHolder;
    bool inSystem = false;

    cout << "\nPlease enter your name:\n";
    getline(cin,userName);
    fout.open("GreenBox-Data.txt", ios::app);
    fin.open("GreenBox-Data.txt"); 
    while(!fin.eof())
    {
        inSystem = false;
        getline(fin, tempHolder);
        if (tempHolder == userName)
        {
            inSystem = true;
            cout << "\nThis customer is already in our system.\n";
            fin.close();
            fout.close();
        }
    }
    if (!inSystem)
    {
        Customers.push_back(Customer());
        //Create Customer ID
        srand(time(NULL));
        randNum = (rand() % 899999) + 100000;
        Customers.back().SetCustomerID(randNum);
        fout << "Customer ID:\n" << randNum << endl;

        fout << "Customer Name:\n" << userName << "\n";
        Customers.back().SetCustomerName(userName);

            
        // Loop if card number is invalid
        do
        {
            cout << "What is your Credit Card Number? (12 digits)" << endl;
            cin >> creditCardNum;
        }while(creditCardNum < 111111111111 || creditCardNum > 999999999999);
        fout << "Credit Card Number:\n" << creditCardNum << endl;
            
        // Loop if month isnt valid
        do
        {
            cout << "Expiration date\nMonth:\n";
            cin >> expirationDateMonth;
        }while(expirationDateMonth < 1 || expirationDateMonth > 12);
            
        // Loop if year isnt valid
        do
        {
            cout << "Year:\n";
            cin >> expirationDateYear;
        }while(expirationDateYear < 1111 || expirationDateYear > 9999);
        fout << "Expiration Date:\n" << expirationDateMonth << "/" << expirationDateYear << endl;

        do
        {
            cout << "Validation Key:\n";
            cin >> cardValKey; 
        }while(cardValKey < 111 || cardValKey > 999);
        fout << "Validation Key:\n" << cardValKey << endl;
        fout << "Movies Loaned:" << endl << endl;
        cout << "Your Customer ID is: " << randNum << endl;
        fout.close();
        fin.close();
    }
}
// void editCustomer(int customerID)
// {

// }
void CustomerCollection::deleteCustomer(int customerIndex)
{
    Customers.erase(Customers.begin() + (customerIndex));
} 
Customer CustomerCollection::findCustomer(int customerIndex)
{
    return Customers[customerIndex];
}
//void printCustomerInfo(); 
void CustomerCollection::printCollectionEntries()
{
    cout << Customers.size() << endl;
    for(int i = 0; i < Customers.size(); i++)
    {
        cout << Customers[i].GetCustomerName() << "\nCard Numbers:\n" << Customers[i].GetCreditCardNum() << endl;
    }
}
//void moviesLoaned(); 
//void printAllLoans();
int CustomerCollection::getCustomersSize()
{
    return Customers.size();
}

void CustomerCollection::saveDataBase()
{
    ofstream fout;

    fout.open("GreenBox-Data.txt", ios::trunc);
    
    if (Customers.size() != 0){
        for(int i = 0; i < Customers.size(); i++)
        {
            // cout << "Customer ID:\n" << Customers[i].GetCustomerID() << endl;
            // cout << "Customer Name:\n" << Customers[i].GetCustomerName() << endl;
            // cout << "Credit Card Number:\n" << Customers[i].GetCreditCardNum() << endl;
            // cout << "Expiration Date:\n" << Customers[i].GetCreditCardExpDate() << endl;
            // cout << "Validation Key:\n" << Customers[i].GetCreditCardValKey() << endl;
            // cout << "Movies Loaned:\n";
            fout << "Customer ID:\n" << Customers[i].GetCustomerID() << endl;
            fout << "Customer Name:\n" << Customers[i].GetCustomerName() << endl;
            fout << "Credit Card Number:\n" << Customers[i].GetCreditCardNum() << endl;
            fout << "Expiration Date:\n" << Customers[i].GetCreditCardExpDate() << endl;
            fout << "Validation Key:\n" << Customers[i].GetCreditCardValKey() << endl;
            fout << "Movies Loaned:\n";
            if (Customers[i].GetActiveMovieCount() != 0)
            {
                for (int i = 0; i < Customers[i].GetActiveMovieCount(); i++)
                {
                    fout << "Movie Place Holder\n";
                }
            }
            fout << endl;
        }
    }
}