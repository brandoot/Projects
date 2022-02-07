/* Brandon Deo
 * Lab3_Ex1.cpp
 * 28 January 2019
 * Prompts User for two intergers then will display whether they are equal or larger
 *
 */

#include<iostream>

using namespace std;

int main()
{
	//assigning variables
	int num1,num2;

	//prompts user to input 2 numbers
	cout<<"Welcome! Please Enter in 2 numbers:"<<endl;

	//user input
	cin>>num1>>num2;

	//checks the values of user input and displays a message accordingly
	if(num1==num2)
		cout<<num1<<" is equal to "<<num2<<endl;
	else if(num1>=num2)
		cout<<num1<<" is larger than "<<num2<<endl;
	else
		cout<<num1<<" is smaller than "<<num2<<endl;

	return 0;

}
