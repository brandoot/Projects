/* Brandon Deo
 * Lab7
 */

#ifndef PERSON_H
#define PERSON_H
#include <string>
using namespace std;

class Person
{
	public:
		Person();
		Person(string n, string a, string tn, string e);
		string getname();
		string getaddress();
		string getnumber();
		string getemail();
	private:
		string name;
		string address;
		string tnumber;
		string email;
};
#endif
