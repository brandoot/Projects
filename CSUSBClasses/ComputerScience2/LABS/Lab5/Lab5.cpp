/* Brandon Deo
 * Lab5
 */

/*  Simple buffer overflow example             RJBotting 9/27/2004
    Warning this is an example with many pieces of insecure code and information.
    Inspired by
	INSIDE THE BUFFER OVERFLOW ATTACK: MECHANISM, METHOD, & PREVENTION
	Mark E. Donaldson, SANS Corporation.
	April 3, 2002
	GSEC Version 1.3
*/

#include <iostream>
#include <string>

using namespace std;

string get(string askfor);
string getpasswd(string name);;

int main()
{
    //  Change these character arrays to strings.

	string name; string pwd; string passwd;
	string Name="Name: ";
	string Password="Password: ";

	bool authenticated=false;
	while(! authenticated)
	{
	       	// input the name here
		name=get(Name);
                // get the password pwd for the name
		pwd=getpasswd(name);
                // input a password passwd
		passwd=get(Password);
	 	//cout <<pwd<<" vs " <<passwd<<endl;
                // compare the two passwords
		
		if(pwd==passwd)

			authenticated=true;

		if(!authenticated)

			cout << "Please try again\n";
	}
	cout << "Welcome "<<name<<"\n";

	//...
	return 0;
}
string get(string askfor)
{
   // this inputs a chracter array from input ... change it to input a string
	string input;
	cout << askfor;
	cin>>input;
	return input;
}
string getpasswd(string name)
{
        // Yuch! This returns pwd depending on the variable name
        // Rewrite so it accepts a string name and returns a string

	string pwd;

	if(name=="botting")
		pwd="123456";
	else if(name=="ernesto")
		pwd="765432";
	else if(name=="tong")
		pwd="234567";
	else
		pwd="qwert";

	return pwd;
}
