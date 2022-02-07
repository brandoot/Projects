/* Brandon Deo
 * Lab7
 */

#ifndef STAFF_H
#define STAFF_H
#include "Employee.h"
#include "Person.h"
#include <string>

using namespace std;

class Staff:public virtual  Employee
{
	public:
		Staff();
		Staff(string p, string o, string d, double s, string n, string a, string tn, string e);
		string getposition();
		virtual string whatami();
	private:
		string position;
};
#endif
