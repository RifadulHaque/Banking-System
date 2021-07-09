#include "Bank.h"

//#include"Account.cpp"


//deafult construcot that reads the file


Bank:: Bank(){

    Account account;//object of Account class
    
    ifstream infile;//reading from a file
    infile.open("BankData.txt");//opeing BankData file
    
    //if no file is found
    if(!infile)  { 
         cout<<"Error in Opening! File Not Found!!"<<endl;  
         return;  
    }
    //reads untill the end of the file
    while(!infile.eof()){
        infile>>account;
        accounts.insert(pair<long,Account>(account.getAccountNumber(),account));
    }

    // it is used to keep track of the last account number
    Account::setLastAccountNumber(account.getAccountNumber());

    //closing file
    infile.close();

}



//writing in a txt file about the account informations
Account Bank::openAccount(string fname,string lname, float bal){
    ofstream outfile;
    //opening a file named BankData
    outfile.open("BankData.txt");//by deafult trunc is used
    Account account(fname, lname , bal);
    //inserting data in map as pair
    accounts.insert(pair<long,Account>(account.getAccountNumber(),account));

    map<long,Account>::iterator itr;

    //using iterator for writing writing in an account
    for(itr=accounts.begin(); itr!=accounts.end();itr++){
        outfile<<itr->second;
    }

    //closing the file
    outfile.close();

    return account;

}

//using for finding the account using iterator
Account Bank :: balanceEnquiry(long accountNumber){
    map<long,Account>::iterator itr=accounts.find(accountNumber);
    return itr->second;
}

//used for depositing amount into acconts using iterators
Account Bank:: Deposit(long accountNumber, float dep){
    map<long,Account>::iterator itr=accounts.find(accountNumber);
    itr->second.Deposit(dep);
    return itr->second;
}

//using iterator to withdraw cash from account
Account Bank::Withdraw(long accountNumber,float widraw){
     map<long,Account>::iterator itr=accounts.find(accountNumber);
     itr->second.Withdraw(widraw);
     return itr->second;
}

//using iterator to search through the map to close an account
void Bank :: closeAccount(long accountNumber){
    map<long,Account>::iterator itr=accounts.find(accountNumber);
    cout<<"Account Deleted "<<itr->second;
    accounts.erase(accountNumber);
}

//used to show all the accounts using iterator in map
void Bank :: showAllAccounts(){
    map<long,Account> :: iterator itr;
    for(itr=accounts.begin(); itr!=accounts.end(); itr++){
        cout<<"Account "<<itr->first<<endl<<itr->second<<endl;
    }
}

//destructor
Bank::~Bank(){
    ofstream outfile;
    outfile.open("BankData.txt");

    map<long,Account>::iterator itr;
    for(itr=accounts.begin(); itr!=accounts.end(); itr++){
        outfile<<itr->second;
    }

}



