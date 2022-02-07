/* Brandon Deo
 * LAB5_EX2
 * this program finds all prime number inbetween an interval
 *
 * 24 February 2019
 */
#include<iostream>
using namespace std;

//Prototypes functions
bool isPrime(int n);

int main(){

	//Initializes Variables
	int start=0,end=0;

	//Prompts user for input
	cout<<"This program prints all the prime numbers inbetween your two choices of numbers. Please enter in the starting number: "<<endl;
	cin>>start;

	cout<<"Now please enter in the ending number: "<<endl;
	cin>>end;

	//Uses for loops to check all numbers in between
	for(int i=start;i<=end;i++){

		//if statement outputs which values are prime
		//uses functions
		if(isPrime(i)==true)
			cout<<i<<" ";
	}
	cout<<endl;

	return 0;
}

//bool function that outputs true if a number is prime
bool isPrime(int n)
{
	bool yeezy = true;
	for(int j = 2;j<n;j++){
		if(n%j==0){
			yeezy = false;
			break;
		}
	}
	return yeezy;
}
