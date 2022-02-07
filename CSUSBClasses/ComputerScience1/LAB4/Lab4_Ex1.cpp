/* Brandon Deo
 * Lab4_Ex1
 * Asks user for a starting and ending value and prints all even numbers between start and end
 * 4 February 2019
 *
 */
#include<iostream>

using namespace std;

int main()
{
	//initializes variables
	int startValue=0,endValue=0;

	//asks for user input
	cout<<"Welcome! Please enter in two numbers to see all the even numbers in between! (The first number will be the start and the second number will be the end, please put in chronological order)\n";

	//takes in user input
	cin>>startValue>>endValue;

	//runs a loop until test condition fails
	while(startValue<=endValue)
	{
		if(startValue%2==0)
		{
			cout<<startValue<<" ";
		}

		startValue++;

	}

	return 0;

}
