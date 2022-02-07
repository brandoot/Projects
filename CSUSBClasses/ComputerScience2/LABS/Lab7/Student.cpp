/* Brandon Deo
 * Lab7
 */

#include "Student.h"
#include "Person.h"
#include <string>
using namespace std;

Student::Student():Person()
{
	string yearstatus;
}

Student::Student(string ys,string n,string a,string tn,string e):Person(n,a,tn,e)
{
	yearstatus=ys;
}

string Student::getclass()
{
	return yearstatus;
}
