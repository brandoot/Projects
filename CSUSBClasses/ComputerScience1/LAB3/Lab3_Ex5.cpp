/* Brandon Deo
 * Lab3_Ex5.cpp
 * 30 January 2019
 * User can check with their balance, do a withdrawal or deposit
 *
 */
#include<iostream>
#include<string>

using namespace std;

int main()
{
	//Assigns Variables for existing balance and calculations
	float OriginalBalance = 32500;
	float withdrawal, deposit, newbalance;

	//Assigns string variable for user input
	string UserInput;

	//Prompts user for a command
	cout<<"Greetings! Please enter one of the following commands to view or modify your balance!\n"
		<<"B to check Balance, W for Withdrawal, D for Deposit, or any other key to quit.\n";

	//User inputs a command
	cin>>UserInput;

	//Checks for which command user has inputted and performs actions accordingly
	if(UserInput=="B"||UserInput=="b")
	{
		cout<<"Your balance is $"<<OriginalBalance<<endl;
	}
	else if(UserInput=="W"||UserInput=="w")
	{
		cout<<"For withdrawal, please enter a value no more than $"<<OriginalBalance<<endl;

		cin>>withdrawal;

		newbalance=OriginalBalance-withdrawal;

		cout<<"Your balance is now $"<<newbalance<<endl;

	}
	else if(UserInput=="D"||UserInput=="d")
	{
		cout<<"For deposit, please enter a value larger than 0."<<endl;

		cin>>deposit;

		newbalance=OriginalBalance-deposit;

		cout<<"Your balance is now $"<<newbalance<<endl;
	}	
	else
	{
		cout<<"Thank you. Goodbye!\n";
	}

}
