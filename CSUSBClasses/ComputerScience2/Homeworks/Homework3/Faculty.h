/* Brandon Deo
 * Lab7
 */

#ifndef FACULTY_H
#define FACULTY_H
#include "Employee.h"
#include "Person.h"
#include <string>

using namespace std;

class Faculty:public Employee
{
	public:
		Faculty();
		Faculty(string r, string st, string o, string d, double s, string n, string a, string tn, string e);
		string getrank();
		string getstatus();
		virtual string whatami();
	private:
		string rank;
		string status;
};
#endif
