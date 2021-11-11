#ifndef LOANCOLLECTION_H
#define LOANCOLLECTION_H

#include <string>
#include <iostream>
#include "Loan.h"
#include <vector>

using namespace std;

class LoanCollection : public Loan
{
    void addLoan(); // Add a Loan to the collection
    void editLoan(); // Edit Loan information if Loan is in the collection
    void deleteLoan(); // Delete a specific Loan
    void findLoan(); // Search for a specific Loan
    void printLoanInfo(); // Print all the info for a specific Loan
    void printAllLoans(); // Print a list of all Active (future and current) Loans, all completed Loans and all Overdue or lost Loans
};



#endif