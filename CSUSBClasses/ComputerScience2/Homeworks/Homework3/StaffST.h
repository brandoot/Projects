/* Brandon Deo
 * Homework3
 */

#ifndef STAFFST_H
#define STAFFST_H
#include <string>
#include "Student.h"
#include "Staff.h"

using namespace std;

class StaffST:public Student,public Staff
{
	public:
		StaffST();
		StaffST(int ch, string ys, string p, string o, string d, double s, string n, string a, string tn, string e);
		int getcredithours();
		virtual string whatami();
	private:
		int credithours;
};
#endif
