/* Brandon Deo
 * Lab6
 */

#include "Person.h"
#include <iostream>


using namespace std;

int main()
{
	Person t("Bill", "Gates", "Microsoft");

        cout << t.getName() << endl;
        cout << t.getCompany() << endl;

	return 0;
}
