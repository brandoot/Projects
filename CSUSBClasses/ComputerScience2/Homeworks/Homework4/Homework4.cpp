/* Brandon Deo
 * Homework4
 */
#include "mlist.cpp"
#include <vector>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	Mlist<int>m=Mlist<int>();
	m.addorder(9);
	m.addorder(3);
	m.addend(6);

	cout<<"Here we have our first number: "<<m.front()<<endl;

	Mlist<string>s=Mlist<string>();
	s.addorder("BoB");
	s.addfront("Christina");
	s.addorder("Kim");
	cout<<s.end()<<endl;
	s.removeend();
	cout<<s.end()<<endl;

	return 0;
}
