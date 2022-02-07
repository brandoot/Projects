/* Brandon Deo
 * Lab3_Ex3.cpp
 * 28 January 2019
 * This program Calculates someones electric bill
 *
 */
#include<iostream>

using namespace std;

int main()
{
	//Variable Assignment
	int  hours=0;
	float kwh=0,rate=0;

	//Prompts for User Input
	cout<<"Welcome! We will calculate your Monthly Electric Bill for you! Please enter the number of Kilowatts per Hour used!"<<endl;

	//User Input for kwh
	cin>>kwh;

	//Prompts for user input again
	cout<<"Also! Please enter the hours of elecricity being used!(per month)"<<endl;

	//User Input for hours
	cin>>hours;

	//Checks how many KWH the user has inputted and calculates bill accordingly
	if(kwh>=2000)
	{
		rate=0.35;
		cout<<"Your monthly electricity bill is:$"<<rate*hours<<endl;
	}
	else if(kwh>=1500&&kwh<=1999)
	{
		rate=0.40;
		cout<<"Your monthly electricity bill is:$"<<rate*hours<<endl;
	}
	else if(kwh>=1000&&kwh<=1499)
	{
		rate=0.45;
		cout<<"Your monthly electricity bill is:$"<<rate*hours<<endl;
	}
	else
	{
		rate=0.60;
		cout<<"Your monthly elecrticity bill is:$"<<rate*hours<<endl;
	}

	return 0;

}
