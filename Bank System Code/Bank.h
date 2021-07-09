
#include "Account.h"
//#include"Account.h"

#include<map>
#include<vector>
#include<cstdlib>

class Bank{

    private:
        map<long, Account> accounts;//map type data structure

    public:
        Bank();
        Account openAccount(string firstName, string lastName, float balance );//constructo rused for opeining account
        Account balanceEnquiry(long accountNumber);//for checking balance in existing account
        Account Deposit(long accountNumber , float dep);//for making deposit in any account
        Account Withdraw(long accountNumber , float widraw);//for withdrawing amount from an account

        void closeAccount(long accountNumber);//used for deleting an account
        void showAllAccounts();//for displaying all accounts
        ~Bank();//used for destrying all the accounts and the information


};

