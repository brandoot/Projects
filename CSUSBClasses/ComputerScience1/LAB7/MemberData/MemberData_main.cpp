/*Brandon Deo
 * Lab7_Ex2 MemberData (Most code done by instructor)
 * This program explores the use of Classes and
 * the member functions that come along with it
 *
 * 16 March 2019
 */
//include all libraries and classes
#include<iostream>
#include"MemberData.h"
#include<vector>
#include<string>

using namespace std;

int main()
{
//Declares variables sets
MemberData member1(246810,1234,"Frosty S. Man",5600.00,10500.00);
MemberData member2(135790,5678,"Rudolph R. Deer",7800.50,3400.00);
MemberData member3(123456,2468,"Mrs. Claus",500.00,20000.00);

string account;

//Vector is created, contains class objects
vector<MemberData> bank;
	
//pushes back classes into the vector
bank.push_back(member1);
bank.push_back(member2);
bank.push_back(member3);

//uses for loop and class function to display names from 
//variable sets
for(int i=0;i<bank.size();i++){
	cout<<"Member "<<i+1<<" "<<bank[i].getName()<<endl;
}

//Prompts user for input of account
cout<<"Hello, welcome to the North Pole Bank!"<<endl
<<"Please enter the member number for the account you would like to access: ";
//Creates variable for user input from prompt
int memberNumber;
cin>>memberNumber;

//for loop used to check if the member number exists in the data base
for(int i=0;i<bank.size();i++){
	if(bank[i].getMember()==memberNumber) memberNumber=i;
}
//uses if/else statements if member is not found
if(memberNumber>bank.size()-1){
	cout<<"Member not found. Goodbye\n";
	return 0;
}
//if member is found, program simulates into a bank
//now asks for pin number, uses if/else statements
//if pin number is not found then program exits
else{
	cout<<"To Proceed, Enter member pin: ";
	int pin;
	cin>>pin;
	if(pin!=bank[memberNumber].getPin()){
		cout<<"Wrong pin. Goodbye\n";
		return 0;
	}
	//prompts user for atm simulation
	else{
		cout<<"Welcome "<<bank[memberNumber].getName()<<"!"<<endl;
		string input;
	
		//While loop used for user prompt
		while(input!="Q"){
			cout<<"Select from the following menu: "<<endl
				<<"Enter B to view your balance."<<endl
				<<"Enter W to make a withdraw."<<endl
				<<"Enter D to make a deposit."<<endl
				<<"Enter Q to quit."<<endl;
			getline(cin,input);
		//If user chooses Balances
		//Asks for user input and uses class member functions
		//to execute certain actions
		//displays balance at the end
		if(input=="B"){
		cout<<"Which account's balance would you like to see?"<<endl
		<<"Enter C for checking, S for savings: ";
		string account;
		getline(cin,account);
		if(account == "C")cout<<"Checkings";
		else cout<<"Savings";

		cout<<"Balance:"<<bank[memberNumber].getBalance(account)<<endl;
		}
				
		//If user chooses Deposit
		//Asks user for input and uses class member functions
		//to modify value in bank
		//and displays balance at the end
		else if(input =="D"){
		cout<<"Which account would you like to make a deposit to?"<<endl
			<<"Enter C for checking, or S for savings ";
			string account;	
			getline(cin, account);
			double amount;
			cout<<"Please enter the amount you want"<< 
				"to deposit into your account."<<endl;
			cin>>amount;
			bank[memberNumber].deposit(amount, account);
			cout<<"Balance:"<<bank[memberNumber].getBalance(account)<<endl;
			}
		//If user chooses withdrawal
		//Asks user for input and uses class member functions
		//to modify value in bank
		//uses if/else statement to see if user is able to
		//withdraw the amount needed, if false then user is
		//penalized, if true the function carries out normally
		//then displays balances at the end
		else if(input=="W"){
			cout<<"Which account would you like to make a withdrawal from?"<<endl
			<<"Enter C for checking, or S for savings: ";
			string account;
			getline(cin, account);
			cout<<"How much would you like to withdraw from your account,";
			cout<<"it can not be greater than your current account"<<endl       
			<<"or else you will get deducted as a penalty"<<endl;
			double amount;
			cin>>amount;
			if(bank[memberNumber].withdraw(amount,account)==true){
				bank[memberNumber].withdraw(amount,account);
				cout<<"Withdrawal complete"<<endl;
				}
			else{
				bank[memberNumber].withdraw(amount,account);
				cout<<"Withdrawal unsuccessful."<<endl;
				}
			cout<<"Balance: "<<bank[memberNumber].getBalance(account)<<endl;
		}
		//If uses quits the simulation
		//Displays users stats
		//MemberName and Final Balances
		else if(input=="Q"){
			cout<<"Here are your balances, have a nice day!"<<endl;
			cout<<"Checking: "<<bank[memberNumber].getBalance("C")<<endl;
			cout<<"Savings: "<<bank[memberNumber].getBalance("S")<<endl;
			cout<<bank[memberNumber].getName()<<endl;
		}
		else cout<<"Invalid entry.\n";
	}
}
}

return 0;

}
