/* Brandon Deo
 * Lab7
 */
#include "Faculty.h"
#include "Employee.h"
#include <string>
using namespace std;

Faculty::Faculty():Employee()
{
	string rank;
	string status;
}

Faculty::Faculty(string r, string st,string o, string d, double s, string n, string a, string tn, string e):Employee(o,d,s,n,a,tn,e)
{
	rank = r;
	status = st;
}

string Faculty::getrank()
{
	return rank;
}

string Faculty::getstatus()
{
	return status;
}
