/* Brandon Deo
 * EmployeeInformation.cpp
 * This program has cin and cout statements that calculate the raise of a person
 */
#include<iostream>
#include<string>

using namespace std;

int main()
{
	string fnam,lnam;
	float salary=0,raisedsalary=0;

	cout <<"Welcome! Were you ever curious on what an employee's salary could be if they preform well? Please enter the employee's first and last name.""\n";

	cin >>fnam>>lnam;

	cout <<"What is " <<fnam<<" "<<lnam<<"'s starting salary?"<<endl;

	cin >>salary;

	raisedsalary=salary*1.05;

	string f=fnam.substr(0,1),l=lnam.substr(0,1);

	cout <<"If "<<f<<"."<<l<<" performs well, their fruits of labor can increase their salary by 5%, which would look like such: $"<<raisedsalary<<endl;

	return 0;

}
