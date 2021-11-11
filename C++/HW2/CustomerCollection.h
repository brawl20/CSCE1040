#ifndef CUSTOMERCOLLECTION_H
#define CUSTOMERCOLLECTION_H

#include "Customer.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class CustomerCollection : public Customer
{
    public:
        void addMovie(); // Add a customer to the collection
        void editCustomer(); // Edit customer information if customer is in the collection
        void deleteCustomer(); // Delete a specific customer
        void findCustomer(); // Search for a specific customer
        void printCustomerInfo(); // Print all the info for a specific customer
        void printCollectionEntries(); // Print ALL of the customers.
        void moviesLoaned(); // Print a list of all Loans for a Particular Customer
        void printAllLoans(); // Print a list of all Active (future and current) Loans, all completed Loans and all Overdue or lost Loans

    private:
        vector<Customer> Customers;
};

#endif