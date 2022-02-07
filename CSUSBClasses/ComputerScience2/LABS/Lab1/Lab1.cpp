/* Brandon Deo
 * LAB 1
 * Tuesday 4/2
 */

#include<iostream>
#include<cmath>
#include<cassert>

using namespace std;

double squareroot(double x){
	assert(x>=0);
	if(x==0) return 0;

	double xhi=x;
	double xlo=0;
	double guess = x/2.0;

	if(guess<1){
		xhi=1;
	}

	while(abs(guess*guess-x)>0.00001)
	{	
		if(guess*guess>x)xhi=guess;
		else xlo = guess;
		guess=(xhi+xlo)/2.0;
	}

	
	return guess;

}

int main()
{
	double testvalue;
	cout<<endl<<"Please enter in a value: ";
	cin>>testvalue;
	double testresult = squareroot(testvalue);
	cout<<endl<<"Square root is: "<<testresult<<endl;
	return 0;
}
