/* Brandon Deo
 * Change Counter
 * This program counts the total amount of change a user has
 */
#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int pen,nickl,dim,qtr;
	double sum = 0;

	cout<<"To calculate the sum of your change, please enter in the number of:Pennies, Nickles, Dimes, and Quarters. Please make sure to include spaces inbetween each amount, no commas.""\n";

	cin>>pen>>nickl>>dim>>qtr;

	sum=(pen*.01)+(nickl*.05)+(dim*.1)+(qtr*.25);

	cout<<"Your total amount of change is $"<<sum<<"\n";

	return 0;
}
