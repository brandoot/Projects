#ifndef MEMBERDATA_H
#define MEMBERDATA_H

#include<string>

using namespace std;

class MemberData
{
	public:
		MemberData();
		MemberData(int mn,int p,string n, double cb, double sb);
		void deposit(double amount,string account);
		bool withdraw(double amount, string account);
		double getBalance(string account);
		int getMember(){return member_num;}
		string getName(){return name;}
		int getPin(){return pin;}
		void setPin(int);

	private:
		int member_num;
		int pin;
		string name;
		double checkings_balance;
		double savings_balance;
};

#endif
