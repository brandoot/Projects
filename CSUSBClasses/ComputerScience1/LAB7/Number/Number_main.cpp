/*Brandon Deo
 * Lab7(Coding done by Instructor)
 * Program uses class member functions 
 *
 * 16 March 2019
 */

#include<iostream>
#include"Number.h"

using namespace std;

int main()
{
	//Makes value of num 7
	Number seven(7);

	//Uses class member functions to cout certain statements
	//checks if 7 is a prime number and performs cout statement if it is or isn't
	if(seven.isPrime())
		cout<<seven.getValue()<<" is a prime number!"<<endl;
	else
		cout<<seven.getValue()<<" is not a prime number!"<<endl;

	//checks if 7 is divisible by 7 and performs a cout statement if it is
	if(seven.isLucky())
		cout<<seven.getValue()<<" is a lucky number!"<<endl;
	else
		cout<<seven.getValue()<<" is not a lucky number! Bummer..."<<endl;

	//Creates another variable labelled twentySeven and
	//initializes the variable to 27
	Number twentySeven;
	twentySeven.setValue(27);

	//checks if new variable is prime or not
	cout<<twentySeven.getValue()<<" is";
	if(twentySeven.isPrime())
		cout<<" prime! yay!"<<endl;
	else
		cout<<" not prime! ://"<<endl;

	//checks if the new number is divisible by 7
	if(twentySeven.isLucky())
		cout<<twentySeven.getValue()<<" is lucky hm."<<endl;
	else
		cout<<twentySeven.getValue()<<" is a not a lucky number! :0"<<endl;

	return 0;
}
