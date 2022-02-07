/* Brandon Deo
 * Lab7
 */

#include "Person.h"
#include "Student.h"
#include "Employee.h"
#include "Staff.h"
#include "Faculty.h"
#include "StaffST.h"
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
	reset(n,a,tn,e);
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

string Employee::whatami()
{
	return "Employee";
}
