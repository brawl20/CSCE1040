#include <iostream>
#include <iomanip>

using namespace std;

struct EmployeeStruct
{
    int EmployeeID;
    char name[15];


};
struct CustomerStruct
{
    int CustomerID;
    char name[15];
    float balance;
};
struct Transaction
{
    int CustomerID,EmployeeID;
    char transactionType;
    float transactionAmount;
};



int main()
{

    string data;
    char transactionChar, Name[15];
    float amount;
    int Employee = 0, Customer = 0, EID = 0, CID = 0, customerBalance = 0, transactionsNum = 0;
    EmployeeStruct employee[50];
    CustomerStruct customer[50];
    Transaction transactions[50];


    while(cin.eof() != true)
    {
        cin >> data;
        if(data.at(0) == 'e')
        {
            cin >> EID;
            cin >> Name;
            employee[EID].EmployeeID = EID;
            for (int i = 0; i < 15; ++i)
            {
                employee[EID].name[i] = Name[i];
            }
        }  
        
        else if(data.at(0) == 'c')
        {
            cin >> CID;
            cin >> Name;
            cin >> customerBalance;
            customer[CID].CustomerID = CID;
            for (int i = 0; i < 15; ++i)
            {
                customer[CID].name[i] = Name[i];
            }
            customer[CID].balance = customerBalance;
        }
        else if(data.at(0) == 't')
        {
           cin >> CID;
           cin >> EID;
           cin >> transactionChar;
           cin >> amount;
           cout.width(15);
           cout << fixed;
           cout << setprecision(2);
           transactions[transactionsNum].CustomerID = CID;
           transactions[transactionsNum].EmployeeID = EID;
           transactions[transactionsNum].transactionType = transactionChar;
           transactions[transactionsNum].transactionAmount = amount;
           

           if(transactionChar == 'w')
           {
               amount *= -1;
               customer[CID].balance += amount; 
               cout << customer[CID].name << "\t" << right << setw(15) << employee[EID].name << " -$" << transactions[transactionsNum].transactionAmount << " $" << customer[CID].balance << endl;
           }
           else if(transactionChar == 'd')
           {
               customer[CID].balance += amount; 
               cout << customer[CID].name << "\t" << right << setw(15) << employee[EID].name << " +$" << transactions[transactionsNum].transactionAmount << " $" << customer[CID].balance << endl;    
           }
           ++transactionsNum;
        }
    }

    return 0;
}