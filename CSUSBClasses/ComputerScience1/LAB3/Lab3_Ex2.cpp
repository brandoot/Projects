/* Brandon Deo
 * Lab3_Ex2.cpp
 * 28 January 2019
 * Prompts for user input to determine whether their number is good or bad
 *
 */

#include<iostream>

using namespace std;

int main()
{
	//variable assignment
	int x;

	//Prompts for user input
	cout<<"Hello! Please enter in a number between 3 and 12, if you don't listen, you'll be a bad egg."<<endl;

	//user input
	cin>>x;

	//Checks if the number is between 3 and 12 and gives a display message
	if(x>=3&&x<=12)
	{	cout<<"Good job, "<<x<<" is a good number!"<<endl;
		if(x%2==0)
			cout<<x<<" is an even number!"<<endl;
		else
			cout<<x<<" is an odd number!"<<endl;
	}	
	else
		cout<<"Poor work, "<<x<<" is a bad number!"<<endl;

	return 0;

}
