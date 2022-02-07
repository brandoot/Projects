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
#include <vector>
using namespace std;

Person::Person()
{
	string name;
	string address;
	string tnumber;
	string email;
	//vector<Person*>p;
}

Person::Person(string n, string a, string tn, string e)
{
	name=n;
	address=a;
	tnumber=tn;
	email=e;
}

string Person::getname()
{
	return name;
}

string Person::getaddress()
{
	return address;
}

string Person::getnumber()
{
	return tnumber;
}

string Person::getemail()
{
	return email;
}

string Person::whatami()
{
	return "Person";
}

void Person::reset(string n, string a, string tn, string e)
{
	name=n;
	address=a;
	tnumber=tn;
	email=e;
}

