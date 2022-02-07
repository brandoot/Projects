/* Brandon Deo
 * Lab7
 */
#include "Person.h"
#include "Student.h"
#include "Employee.h"
#include "Faculty.h"
#include "Staff.h"

#include <iostream>
#include <string>

using namespace std;

int main()
{
	Person John=Person("John","321 Yes Road","4932028819","john213@hotmail.com");
	Student Aly=Student("Senior","Aly","438 No Street","7892341753","aly03@gmail.com");
	Employee Bertha=Employee("PE132","07/20/96",80200.00,"Bertha","912 Maybe Court","3920283802","berth75@yahoo.com");
	Faculty Daniel=Faculty("Professor","tenured","HP321","03/12/84",93244.53,"Daniel","324 Affirmative Boulevard","0924925837","dantran932@aol.com");
	Staff Sharon=Staff("Desk Assistant","JB218","05/21/18",12090.12,"Sharon","895 xd Avenue","8921095819","98shark@aim.com");

	cout<<John.getname()<<endl;
	cout<<Aly.getclass()<<endl;
	cout<<Bertha.getsalary()<<endl;
	cout<<Daniel.getrank()<<endl;
	cout<<Sharon.getposition()<<endl;

	return 0;
}
