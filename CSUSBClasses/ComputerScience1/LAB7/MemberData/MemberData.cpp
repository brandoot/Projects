#include"MemberData.h"
#include<iostream>

	MemberData::MemberData(){
		member_num=0;
		pin=0;
		checkings_balance=0;
		savings_balance=0;
	}
	
	MemberData::MemberData(int mn, int p, string n, double cb, double sb){
		member_num=mn;
		pin=p;
		name=n;
		checkings_balance=cb;
		savings_balance=sb;
	}
	
	void MemberData::deposit(double amount, string account){
		if(account=="C"){
			checkings_balance+=amount;
		}
		else if(account=="S"){
			savings_balance+=amount;
		}
		else{
			cout<<"Invalid account."<<endl;
		}
	}

	bool MemberData::withdraw(double amount, string account){
		bool valid;
		if(account=="C"){
			if(amount>checkings_balance){
				checkings_balance-=5.00;
				valid=false;
			}
			else{
				checkings_balance-=amount;
				valid=true;
			}
		}
		else{
			if(amount>savings_balance){
				savings_balance-=5.00;
				valid=false;
			}
			else{
				savings_balance-=amount;
				valid=true;
			}
		}
		return valid;
	}

	double  MemberData::getBalance(string account){
		if(account=="C"){
			return checkings_balance;
		}
		else if(account=="S"){
			return savings_balance;
		}
		else{
			cout<<"Invalid."<<endl;
			return 0;
		}
	}

	void MemberData::setPin(int mn){
		member_num=mn;
	}

