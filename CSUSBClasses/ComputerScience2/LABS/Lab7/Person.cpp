/* Brandon Deo
 * Lab7
 */

#include "Person.h"
#include <string>
using namespace std;

Person::Person()
{
	string name;
	string address;
	string tnumber;
	string email;
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

