/* Brandon Deo
 * Lab7
 */

#include "Employee.h"
#include "Person.h"
#include <string>
using namespace std;

Employee::Employee():Person()
{
	string office;
	string datehired;
	salary=0;
}

Employee::Employee(string o, string d, double s,string n, string a, string tn, string e):Person(n,a,tn,e)
{
	office=o;
	datehired=d;
	salary=s;
}

string Employee::getoffice()
{
	return office;
}

string Employee::getdatehired()
{
	return datehired;
}

double Employee::getsalary()
{
	return salary;
}

