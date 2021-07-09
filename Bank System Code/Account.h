#include<iostream>
#include<fstream>
#include<string>
using namespace std;

#define MIN_BALANCE 500

//It holds information of the person with their first and last name
//The person's account number, balance

//Balance can be deposited in this account aswell as withdraw
//Last Account number is noted so that upon exiting, the info is not lost

class Account{
    private:
        long accountNumber;
        string firstName;
        string lastName;
        float balance;
        static long NextAccountNumber;
    
    public:
        Account();
        Account(string, string, float);
        long getAccountNumber();//setting the number of acconts
        string getFirstName();
        string getLastName();
        float getBalance();//returns the balacees in accounts

        void Deposit(float );//depositng money in accounts
        void Withdraw(float);//withdraw money from accounts
        static void setLastAccountNumber(long accountNumber);
        static long getLastAccountNumber();
        friend ofstream & operator<<(ofstream & ofs, Account &acc);//writing in a file
        friend ifstream & operator>>(ifstream & ifs, Account &acc);//reading from the file
        friend ostream & operator<<(ostream & out, Account &acc);//overloading the operator
        

};
