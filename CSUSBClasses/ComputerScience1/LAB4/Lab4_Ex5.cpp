/* Brandon Deo
 * Lab4_Ex5
 * Program prints tests entered, average, and calculates standard deviation
 * 11 February 2019
 *
 */
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main()
{
	//declares variables
	double userin=0,avg=0,sum=0,standev=0;
	int c=0;
	
	//starts a loop
	while(userin!=-1)
	{
		//prompts user for input
		cout<<"Please enter your test scores(ie 32.4), please enter -1 when you are done.\n";

		//userinput
		cin>>userin;
		
		//updates counter
		c++;
		
		//continues to calculate sum
		sum+=userin;
	}
	
	//corrects sum and count from last input
	sum+=1;
	c-=1;
	
	//calculates standard deviation and average
	standev=sqrt(((c*(c+1)*(2*c+1)/6)-((1/c)*pow((c*(c+1)/2),2)))/c-1);
	avg=sum/c;

	//outputs results
	cout<<fixed<<setprecision(1)<<"Hello, the number of tests you have entered are: "<<c<<", your test average is: "<<avg<<", and the standard deviation is: "<<standev<<" Have a nice day.\n";

	return 0;

}
