/* Brandon Deo
 * Lab7
 */
#include "Person.h"
#include "Student.h"
#include "Employee.h"
#include "Faculty.h"
#include "Staff.h"
#include "StaffST.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	vector<Person*>p;

	p.push_back(new Person("John","321 Yes Road","4932028819","john213@hotmail.com"));
	p.push_back(new Student("Senior","Aly","438 No Street","7892341753","aly03@gmail.com"));
	p.push_back(new Employee("PE132","07/20/96",80200.00,"Bertha","912 Maybe Court","3920283802","berth75@yahoo.com"));
	p.push_back(new Faculty("Professor","tenured","HP321","03/12/84",93244.53,"Daniel","324 Affirmative Boulevard","0924925837","dantran932@aol.com"));
	p.push_back(new Staff("Desk Assistant","JB218","05/21/18",12090.12,"Sharon","895 xd Avenue","8921095819","98shark@aim.com"));
	p.push_back(new StaffST(22,"Junior","TA","Jb-222A","09/10/19",1280.39,"Benjamin","329 River Circle","9092381239","98BenRen@yahoo.com"));

	for(int i=0;i<p.size();i++)
	{
		cout<<p[i]->getname()<<" "<<p[i]->whatami()<<endl;
	}

	return 0;
}
