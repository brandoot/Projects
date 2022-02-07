/* Brandon Deo
 * Lab2
 * Salloum
 * MON Lab
 */
#include "SortedArray.h"
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	SortedArray a1(10);

	if(a1.isEmpty()){
		cout<<"This array is empty."<<endl;
	}
	else{
		cout<<"This array is not empty."<<endl;
	}

	for(int i=0;i<15;i++){
		int x;
		cout<<"Insert a value.";
		cin>>x;
		a1.insertVal(x);
		cout<<a1;
	}

	if(a1.isEmpty()){
		cout<<endl<<"This array is empty."<<endl;
	}
	else{
		cout<<endl<<"This array is not empty."<<endl;
	}

	for(int i=0;i<5;i++){
		int y;
		cout<<"Delete a value.";
		cin>>y;
		if(a1.deleteVal(y)){
			cout<<y<<" has been deleted."<<endl;
			cout<<a1;
		}
		else{
			cout<<y<<" not found,therefore,not deleted."<<endl;
			cout<<a1;
		}
	}
	
	cout<<a1;

	return 0;
}
