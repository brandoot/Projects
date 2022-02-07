/* Brandon Deo
 * Lab3_Ex4.cpp
 * 30 January 2019
 * Asks for Month and displays day
 *
 */
#include<iostream>

using namespace std;

int main()
{
	//Variable Assignment
	int month;

	//Prompts for User input for a month
	cout<<"Welcome! Please enter a month to display the number of days there are!(Please use numerical values, January=1, February=2, etc.)\n";

	//Takes in user input
	cin>>month;

	//Checks value of the user input and displays a message
	switch(month)
	{
		case 1:{cout<<"There are 31 days in January.\n";break;}
		case 2:{cout<<"There are 28 or 29 days in February.\n";break;}
		case 3:{cout<<"There are 31 days in March.\n";break;}
		case 4:{cout<<"There are 30 days in April.\n";break;}
		case 5:{cout<<"There are 31 days in May.\n";break;}
		case 6:{cout<<"There are 30 days in June.\n";break;}
		case 7:{cout<<"There are 31 days in July.\n";break;}
		case 8:{cout<<"There are 31 days in August.\n";break;}
		case 9:{cout<<"There are 30 days in September.\n";break;}
		case 10:{cout<<"There are 31 days in October.\n";break;}
		case 11:{cout<<"There are 30 days in November.\n";break;}
		case 12:{cout<<"There are 31 days in December.\n";break;}

		default:{cout<<"Invalid Month.Please enter in a valid number from 1-12.\n";}

	}

	return 0;

}
