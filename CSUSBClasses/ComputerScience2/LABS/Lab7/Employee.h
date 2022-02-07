/* Brandon Deo
 * Lab7
 */

#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "Person.h"
#include <string>

using namespace std;

class Employee:Person
{
	public:
		Employee();
		Employee(string o, string d, double s, string n, string a, string tn, string e);
		string getoffice();
		string getdatehired();
		double getsalary();
	private:
		string office;
		string datehired;
		double salary;
};
#endif
