/* Brandon Deo
 * Salloum
 * CSE330
 * Lab3
 * MON LAB
 */

#include "SortedVector.h"
#include <iostream>
using namespace std;

int main(){
	SortedVector v(10);
	cout<<"The size of this vector is: "<<v.getSize()<<endl;
	cout<<"The capacity of this vector is: "<<v.getCapacity()<<endl;
	if(v.isEmpty()){
		cout<<"This vector is empty."<<endl;
	}
	else{
		cout<<"This vector is not empty."<<endl;
	}
	int x=0;
	cout<<"Please enter a value for the vector"<<endl;
	for(int i=0;i<15;i++){
		cin>>x;
		v.insertVal(x);
		cout<<v;
	}
	cout<<"The size is now: "<<v.getSize()<<endl;
	if(v.isEmpty()){
		cout<<"This vector is still empty."<<endl;
	}
	else{
		cout<<"This vector now has values."<<endl;
	}
	cout<<"Time to delete values from this vector."<<endl;
	for(int i=0;i<5;i++){
		cin>>x;
		if(v.find(x)==-1)
			cout<<x<<" was not found"<<endl;
		else
			v.deleteVal(x);
		cout<<v;
	}
	cout<<"The size of the vector is now: "<<v.getSize()<<endl;
}


