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
    Movie tempMovie;
    int tempInt;

    fout.open("GreenBox-Data.txt", ios::app);
    fin.open("GreenBox-Data.txt"); 

    // Check how many Customers are in the system
    while(!fin.eof())
    {
        getline(fin, tempHolder);
        if (tempHolder == "Customer ID:")
        {
            getline(fin,tempHolder);
            Customers.push_back(Customer());
            Customers.back().SetCustomerID(stoi(tempHolder));
            getline(fin,tempHolder);
            // ++customerIndex;
            if (tempHolder == "Customer Name:")
            {
                getline(fin,tempHolder);
                Customers.back().SetCustomerName(tempHolder);
            }
            getline(fin,tempHolder);
            if (tempHolder == "Credit Card Number:")
            {
                long long unsigned int cardNumber = 0;
                getline(fin,tempHolder);
                cardNumber = stoll(tempHolder, nullptr, 10);
                Customers.back().SetCreditCardNum(cardNumber);
            }
            getline(fin,tempHolder);
            if (tempHolder == "Expiration Date:")
            {
                getline(fin,tempHolder);
                Customers.back().SetCreditCardExpDate(tempHolder);
            }
            getline(fin,tempHolder);
            if (tempHolder == "Validation Key:")
            {
                int valKey;
                getline(fin,tempHolder);
                valKey = stoi(tempHolder);
                Customers.back().SetCreditCardValKey(valKey);
            }
            getline(fin,tempHolder);
            if (tempHolder == "Movies Loaned:")
            {
                getline(fin, tempHolder);
                if (tempHolder == "Movie ID:")
                {
                    getline(fin, tempHolder);
                    tempInt = stoi(tempHolder);
                    tempMovie.SetmovieID(tempInt);
                }
                getline(fin, tempHolder);
                if (tempHolder == "Movie Title:")
                {
                    getline(fin, tempHolder);
                    tempMovie.SetmovieTitle(tempHolder);
                }
                getline(fin, tempHolder);
                if (tempHolder == "Release Date:")
                {
                    getline(fin, tempHolder);
                    tempMovie.SetreleaseDate(tempHolder);
                }
                getline(fin, tempHolder);
                if (tempHolder == "Rating:")
                {
                    getline(fin, tempHolder);
                    tempMovie.Setrating(tempHolder);
                }
                getline(fin, tempHolder);
                if (tempHolder == "Duration:")
                {
                    getline(fin, tempHolder);
                    tempMovie.Setduration(tempHolder);
                }
                getline(fin, tempHolder);
                if (tempHolder == "Rental Cost:")
                {
                    getline(fin, tempHolder);
                    tempMovie.SetrentalCost(tempHolder);
                }
                getline(fin, tempHolder);
                if (tempHolder == "Replacement Cost:")
                {
                    getline(fin, tempHolder);
                    tempMovie.SetreplacementCost(tempHolder);
                }

                Customers.back().SetActiveMovies(tempMovie);
            }
        }
    }
    fin.close();
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

    loadDataBase();

    cout << "\nPlease enter your name:\n";
    getline(cin,userName);
    fout.open("GreenBox-Data.txt", ios::app);
    fin.open("GreenBox-Data.txt"); 
    while(!fin.eof())
    {
        getline(fin, tempHolder);
        if (tempHolder == userName)
        {
            inSystem = true;
            cout << "\nThis customer is already in our system.\n";
            fin.close();
            fout.close();
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
                cout << "\nWhat is your Credit Card Number? (12 digits)" << endl;
                cin >> creditCardNum;
            }while(creditCardNum < 111111111111 || creditCardNum > 999999999999);
            fout << "Credit Card Number:\n" << creditCardNum << endl;
                
            // Loop if month isnt valid
            do
            {
                cout << "\nExpiration date\nMonth:\n";
                cin >> expirationDateMonth;
            }while(expirationDateMonth < 1 || expirationDateMonth > 12);
                
            // Loop if year isnt valid
            do
            {
                cout << "\nYear:\n";
                cin >> expirationDateYear;
            }while(expirationDateYear < 1111 || expirationDateYear > 9999);
            fout << "Expiration Date:\n" << expirationDateMonth << "/" << expirationDateYear << endl;

            do
            {
                cout << "\nValidation Key:\n";
                cin >> cardValKey; 
            }while(cardValKey < 111 || cardValKey > 999);
            fout << "Validation Key:\n" << cardValKey << endl;
            fout << "Movies Loaned:" << endl << endl;
            cout << "\nYour Customer ID is: " << randNum << endl;
            fout.close();
            fin.close();
        }
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