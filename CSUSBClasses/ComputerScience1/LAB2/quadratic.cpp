/* Brandon Deo
 * Quadratic
 * Finds solution for a quadratic equation
 */

#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	double a=0,b=0,c=0;

	cin>>a>>b>>c;

	double x1=(-b+sqrt(pow(b,2)-(4*a*c)))/(2*a);
	double x2=(-b-sqrt(pow(b,2)-(4*a*c)))/(2*a);

	cout<<"The two solutions are x1="<<x1<<" and "<<x2<<"\n";

	return 0;
}
