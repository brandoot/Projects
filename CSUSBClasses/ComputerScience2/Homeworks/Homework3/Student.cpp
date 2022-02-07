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

Student::Student():Person()
{
	string yearstatus;
}

Student::Student(string ys,string n,string a,string tn,string e):Person(n,a,tn,e)
{
	yearstatus=ys;
	reset(n,a,tn,e);
}

string Student::getclass()
{
	return yearstatus;
}

string Student::whatami()
{
	return "Student";
}
