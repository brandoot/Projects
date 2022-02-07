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

Staff::Staff():Employee()
{
	string position;
}

Staff::Staff(string p,string o, string d, double s, string n, string a, string tn, string e):Employee(o,d,s,n,a,tn,e)
{
	position=p;
}

string Staff::getposition()
{
	return position;
}

string Staff::whatami()
{
	return "Staff";
}
