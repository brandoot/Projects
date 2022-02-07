/* Brandon Deo
 * Homework3
 */

#include "Person.h"
#include "Student.h"
#include "Employee.h"
#include "Staff.h"
#include "Faculty.h"
#include "StaffST.h"
#include <string>
using namespace std;

StaffST::StaffST():Staff(),Student()
{
	int credithours;
}

StaffST::StaffST(int ch, string ys, string p, string o, string d, double s, string n, string a, string tn, string e):Staff(p,o,d,s,n,a,tn,e),Student(ys,n,a,tn,e)
{
	credithours=ch;
}

int StaffST::getcredithours()
{
	return credithours;
}

string StaffST::whatami()
{
	return "StaffST";
}

