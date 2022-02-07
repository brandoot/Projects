/* Brandon Deo
 * Lab5_Ex4
 * This program stimulates an atm service
 *
 * 24 February 2019
 */
#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

//Declare global constants
const double InitialCheck=1500.00;
const double InitialSaving=3500.00;
double CheckBalance = InitialCheck;
double SavingBalance = InitialSaving;

//Prototype Functions
void print_balance(string account);
void deposit(string account);
void withdraw(string account);

int main(){
	//Declare variables
	string input, account;
	
	cout<<"Welcome to the Bank"<<endl;

	//While Loop
	while(input!="Q"){
		//Prompt user for which input
		cout<<"Please enter \'B\' to check your balance."<<
			endl<<"Please enter \'W\' to withdraw from your accounts."<<
			endl<<"Please enter \'D\' to deposit into your accounts."<<
			endl<<"Or enter \'Q\' to quit."<<endl;
		
		cin>>input;
	
		//If user Chooses to view Balance
		if(input=="B"){
			cout<<"Would you like to view the balance of your checkings(C),savings(S),or both(A)?"<<endl;
			cin>>account;
			print_balance(account);
		}
		//If user chooses to withdraw
		else if(input=="W"){
			cout<<"Would you like to withdraw from your checkings(C) or savings(S)?"<<endl;
			cin>>account;
			withdraw(account);
		}
		//If user wants to deposit
		else if(input=="D"){
			cout<<"Would you like to deposit into your checkings(C) or savings(S)?"<<endl;
			cin>>account;
			deposit(account);
		}

	}

		//Lets user know final statement on bank account
		cout<<endl<<"Your initial balances were: "<<endl;
		cout<<fixed<<setprecision(2)<<"Savings: $"<<InitialSaving
			<<endl<<"Checkings: $"<<InitialCheck<<endl;
		cout<<"Your final balances are: "<<endl;
		print_balance("A");
		cout<<endl<<"Thank you! Have a wonderful day!";
		cout<<endl;

	return 0;

}
//Functions Prints current balance of account
//gives options of seeing different accounts
void print_balance(string account){
	if(account=="A"){
		cout<<setprecision(2)<<"Savings Balance Account: $"<<SavingBalance<<endl;
		cout<<setprecision(2)<<"Checking Balance Account: $"<<CheckBalance<<endl;
	}
	else if(account=="S"){
		cout<<setprecision(2)<<"Savings Balance Account: $"<<SavingBalance<<endl;
	}
	else if(account=="C"){
		cout<<setprecision(2)<<"Checking Balance Account: $"<<CheckBalance<<endl;
	}
	else
		cout<<"Account not recognized"<<endl;
}
//Function allows user to deposit money into account
//uses if/else statements to prompts user which account
//and asks for input for how much money
void deposit(string account){
	
	double x;

	if(account=="C"){
		cout<<"How much money would you like to deposit into your checkings?"<<endl;
		cin>>x;
		CheckBalance+=x;
		cout<<setprecision(2)<<"Your Checkings is now: $"<<CheckBalance<<endl;

	}
	else if(account=="S"){
		cout<<"How much money would you like to deposit into your savings?"<<endl;
		cin>>x;
		SavingBalance+=x;
		cout<<setprecision(2)<<"Your Savings is now: $"<<SavingBalance<<endl;
	}
	else
		cout<<"Account not recognized"<<endl;
}
//Functions allows usert to withdraw money from their account
//uses if/else statements to prompt user which account and
//asks how much money to take out
void withdraw(string account){
	double y;

	if(account=="C"){
		cout<<"How much money would you like to withdraw from your checkings?"<<endl;
		cin>>y;
		CheckBalance-=y;
		cout<<setprecision(2)<<"Your Checkings is now: $"<<CheckBalance<<endl;
	}
	else if(account=="S"){
		cout<<"How much money would you like to withdraw from your savings?"<<endl;
		cin>>y;
		SavingBalance-=y;
		cout<<setprecision(2)<<"Your Savings is now: $"<<SavingBalance<<endl;
	}
	else
		cout<<"Account not recognized"<<endl;
}


