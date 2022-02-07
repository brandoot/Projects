/* Brandon Deo
 * Lab8
 */

#include "PasswordFile.h"

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

PasswordFile::PasswordFile(string filename)
{
	this -> filename = filename;
	ifstream inFS;
	inFS.open(filename);

	while(!inFS.eof())
	{
		string temp;
		inFS>>temp;
		user.push_back(temp);
		inFS>>temp;
		password.push_back(temp);
	}

	inFS.close();	
}

void PasswordFile::addpw(string u, string p)
{
	user.push_back(u);
	password.push_back(p);
	ofstream outFS;
	outFS.open(filename);

	for(int i=0;i<user.size();i++)
	{
		outFS<<user[i]<<"_"<<password[i]<<endl;
	}

	outFS.close();
}

void PasswordFile::delpw(string u)
{
	for(int i=0;i<user.size();i++)
	{
		if(user[i]==u)
		{	
			user.erase(user.begin()+i);
			password.erase(password.begin()+i);

			ofstream outFS;
			outFS.open(filename);

			for(int j=0;j<user.size();j++)
			{
				outFS<<user[j]<<"_"<<password[j]<<endl;
			}

		}
	}
	

}

bool PasswordFile::checkpw(string u, string p)
{
	bool valid = false;

	for(int i=0;i<user.size();i++)
	{
		if(user[i]==u)
		{
			if(password[i]==p)
			{
				valid=true;
			}
		}
	}

	return valid;
}
