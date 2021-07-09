#define MIN_BALANCE 500
#include "Bank.h"
//#include"Account.cpp"

//#include"Account.h"

int main(){

    //creating objects of both bank and Accont class
    Bank b;
    Account acc;
    

    int choice;

    string fname, lname;

    long accountNumber;
    float balance;
    float amount;
    cout<<"***********Banking System*********"<<endl;
    do{
        cout<<"\n\tSelect one option below ";
        cout<<"\n\t1 Open an Account";
        cout<<"\n\t2 Balance Enquiry";
        cout<<"\n\t3 Deposit";
        cout<<"\n\t4 Withdrawal";
        cout<<"\n\t5 Close an Account";
        cout<<"\n\t6 Show All Accounts";
        cout<<"\n\t7 Quit";
        cout<<"\nEnter your choice: ";

        cin>>choice;

        //using switch statements for checking the choices
        //storing the informations in the acc object
        //runs until choice selection is 7
        switch(choice){
            case 1:
                cout<<"Enter First Name: ";
                cin>>fname;
                cout<<"Enter Last Name: ";
                cin>>lname;
                cout<<"Enter initil Balance: ";
                cin>>balance;
                acc=b.openAccount(fname,lname,balance);
                cout<<endl<<"Congratulation Account is Created"<<endl;
                cout<<acc;
                break;

            case 2:
                cout<<"Enter Account Number:";
                cin>>accountNumber;
                acc=b.balanceEnquiry(accountNumber);
                cout<<endl<<"Your Account Details"<<endl;
                cout<<acc;
                break;


            case 3:
                cout<<"Enter Account Number:";
                cin>>accountNumber;
                cout<<"Enter Balance:";
                cin>>amount;
                acc=b.Deposit(accountNumber, amount);
                cout<<endl<<"Amount is Deposited"<<endl;
                cout<<acc;
                break;

            case 4:
                cout<<"Enter Account Number:";
                cin>>accountNumber;
                cout<<"Enter Balance:";
                cin>>amount;
                acc=b.Withdraw(accountNumber, amount);
                cout<<endl<<"Amount Withdrawn"<<endl;
                cout<<acc;
                break;

            case 5:
                cout<<"Enter Account Number:";
                cin>>accountNumber;
                b.closeAccount(accountNumber);
                cout<<endl<<"Account is Closed"<<endl;
                cout<<acc;
                break;

            case 6:
                b.showAllAccounts();
                break;


            case 7:
                break;

            default:
                cout<<"\nEnter corret choice";
                exit(0);


        }




    }while(choice!=7);


    return 0;

}
