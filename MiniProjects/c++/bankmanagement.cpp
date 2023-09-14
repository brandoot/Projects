#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;

//Open Acct, Withdraw, Deposit, Display

string flname = " ";
int balance = 0;
int saving = 0;
int credit = 0;
char accType = ' ';

void openAccount(){
    cout<<"Hello, Let us assist you in creating your first account. Please enter your first and last name."<<endl;
    cin>>flname;
    
    cout<<"Now what type of account did you want to create, a Savings(S) or a Credit(C)?"<<endl;
    cin>>accType;
    
    cout<<"Great, How much money did you want to initally deposit?"<<endl;
    cin>>balance;
        if (accType == 'S' || accType =='s'){
            saving += balance;
            cout<<setprecision(2)<<"Great,"<<flname<<" in your savings account, you have a starting balance of $"<<saving<<endl;
        }
        if (accType == 'C' || accType =='c'){
            credit += balance;
            cout<<setprecision(2)<<"Great,"<<flname<<" in your credit account, you have a starting balance of $"<<credit<<endl;
        }
}

int main (){
    
    openAccount();

    string flname = " ";
    int balance = 0;
    int saving = 0;
    int credit = 0;
    char accType = ' ';
    return 0;
}