/* Brandon Deo
 * Lab5_Ex1
 * This program increments numbers by 1
 *
 * 24 February 2019
 */
#include<iostream>
#include<cassert>
using namespace std;

//prototypes function
int addOne(int k);
void addOne2(int &d);

int main(){
	//declare variable
	int q=0;
	int yes=0;

	//prompt user for input
	cout<<"Please enter a number to increment it by one: ";
	cin>>q;

	//cout statement that utilizes funtion
	cout<<"Your number is now "<<addOne(q)<<"."<<endl;

	return 0;
}
//function that adds
int addOne(int k){
	int ans = k + 1;
	return ans;
}

void addOne2(int &d){
	 int ans = d+1;
}
