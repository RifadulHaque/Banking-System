#include "Account.h"


long Account::NextAccountNumber=0;

Account::Account(){
//cout<<"Test";
};


//parametrized constructor that initizlizes the Name, balane and increments the NextAccountNumber
Account:: Account(string fname, string lname, float bal){

    NextAccountNumber++;
    accountNumber=NextAccountNumber;
    firstName=fname;
    lastName=lname;
    balance=bal;
}

//getters and setters

long Account::getAccountNumber(){
    return accountNumber;
}

string Account::getFirstName(){
    return firstName;
}

string Account::getLastName(){
    return lastName;
}

float Account::getBalance(){
    return balance;
}

//increases the balanace by amaount
void Account::Deposit(float amount){
    balance+=amount;
}

//implementation if withdraw as it checks if the the amount after withdraw is less than minimum balance or not
void Account::Withdraw(float amount){
    if(balance-amount<MIN_BALANCE){
        throw string("Insufficient Balance");
    }else{
        balance-=amount;
    }

}

void Account::setLastAccountNumber(long accountNumber){
    NextAccountNumber=accountNumber;
}

long Account::getLastAccountNumber(){
    return NextAccountNumber;
}

//writing into the file
ofstream & operator<<(ofstream &ofs, Account &acc){
    ofs<<acc.accountNumber<<endl;
    ofs<<acc.firstName<<endl;
    ofs<<acc.lastName<<endl;
    ofs<<acc.balance<<endl;

    return ofs;
}

//reading from the file
ifstream & operator>>(ifstream &ifs, Account &acc){
    ifs>>acc.accountNumber;
    ifs>>acc.firstName;
    ifs>>acc.lastName;
    ifs>>acc.balance;

    return ifs;

}

//overloading the << operator for printing objects
ostream &operator<<(ostream &out,Account &acc){
    out<<"First Name :"<<acc.getFirstName()<<endl;
    out<<"Last Name :"<<acc.getLastName()<<endl;
    out<<"Balance :"<<acc.getBalance()<<endl;
    out<<"Account Number :"<<acc.getAccountNumber()<<endl;

    return out;
}

