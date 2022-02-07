/* Brandon Deo
 * Salloum
 * Mon Lab
 * Lab4
 */

#include <iostream>
#include "SortedList.h"
using namespace std;

int main()
{
	SortedList<int> l;
	if(l.empty())
		cout<<"This List is empty"<<endl;
	else
		cout<<"This List is not empty"<<endl;
	cout<<"Please enter values for the list."<<endl;
	int x=0;
	for(int i=0;i<15;i++){
		cin>>x;
		l.insertItem(x);
		cout<<l;
	}
	if(l.empty())
		cout<<"This List is still empty"<<endl;
	else
		cout<<"This List is not empty."<<endl;
	x=0;
	cout<<"Please enter values to delete from the list."<<endl;
	for(int i=0;i<5;i++){
		cin>>x;
		if(l.deleteItem(x))
			cout<<x<<" has been deleted."<<endl;
		else
			cout<<x<<" is not found."<<endl;

		cout<<l;
	}
}
