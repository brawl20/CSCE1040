#ifndef LOANCOLLECTION_H
#define LOANCOLLECTION_H

/*
	Author:			Micheal Landsbaum (MichealLandsbaum@my.unt.edu)
	Date:			11/16/2021
	Course:         CSCE1040
	Assignment:     Homework 3
*/

#include <string>
#include <iostream>
#include "Loan.h"
#include <vector>

using namespace std;

class LoanCollection
{
    public:
    void addLoan(); // Add a Loan to the collection
    void editLoan(); // Edit Loan information if Loan is in the collection
    void deleteLoan(); // Delete a specific Loan
    void findLoan(); // Search for a specific Loan
    void printLoanInfo(); // Print all the info for a specific Loan
    void printAllLoans(); // Print a list of all Active (future and current) Loans, all completed Loans and all Overdue or lost Loans
    bool movieAvalible(); // Check that movie is available
    bool overdueMovies(); // Check to see if the customer has overdue movies
    bool movieLimit(); // Check to see if the Customer has more than 2 movies out that are not overdue
    bool cardAccpeted(); // Check to see if the charge card can accept the charges
    private:
    vector<Loan> Loans;
};



#endif