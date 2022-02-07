/* Brandon Deo
 * Lab8
 */

#include "PasswordFile.h"
#include <iostream>

using namespace std;

int main()
{
	PasswordFile passfile("password.txt");

 	passfile.addpw("dbotting","123qwe");
 	passfile.addpw("egomez","qwerty");
	passfile.addpw("tongyu","liberty");
	passfile.delpw("egomez");

	bool authenticated = passfile.checkpw("tongyu","password");

	if(authenticated)
		cout<<"Valid"<<endl;
	else
		cout<<"Please leave."<<endl;

	return 0;
}
