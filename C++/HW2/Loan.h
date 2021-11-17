#ifndef LOAN_H
#define LOAN_H

/*
	Author:			Micheal Landsbaum (MichealLandsbaum@my.unt.edu)
	Date:			11/16/2021
	Course:         CSCE1040
	Assignment:     Homework 3
*/

#include <string>
#include <iostream>

using namespace std;

enum status
{
    Out, In, Overdue, Lost
};

class Loan
{
    public:

    //Default Constructor
    Loan();
    
    //Parameterized Constructor
    Loan(int loanID, int movieID, int customerID, string dueDate, string dueTime, status loanStatus);

    // Accessors
    int GetLoanID();
    int GetmovieID();
    int GetcustomerID();
    string GetdueDate();
    string GetdueTime();
    status GetloanStatus();

    //Mutators
    void SetLoanID(int loanID);
    void SetmovieID(int movieID);
    void SetcustomerID(int customerID);
    void SetdueDate(string dueDate);
    void SetdueTime(string dueTime);
    void SetloanStatus(status loanStatus);

    private:
    int loanID;
    int movieID;
    int customerID;
    string dueDate;
    string dueTime;
    status loanStatus;
};

#endif