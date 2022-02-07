/* Brandon Deo
 * Lab7
 */

#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include "Person.h"
using namespace std;

class Student:public virtual Person
{
	public:
		Student();
		Student(string ys,string n,string a, string tn, string e);
		string getclass();
		virtual string whatami();
	private:
		string yearstatus;
};
#endif
