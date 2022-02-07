/* Brandon Deo
 * Lab4_Ex3
 * Program prints out all prime numbers between user input
 * 8 February 2019
 *
 */
#include<iostream>

using namespace std;

int main()
{
	//declares variables
	bool isPrime=true;
	int userin,userout;

	//prompts user for first input
	cout<<"Welcome, if you would like to find all the prime numbers between a set of numbers, please enter in the first number: ";

	//userinput
	cin>>userin;

	//promts user for second input
	cout<<"Now please enter in the ending number: ";

	//second input
	cin>>userout;

	//starts for loop
	for(int i=userin;i<=userout;i++){
		
		isPrime=true;

		for(int j=2;j<i;j++){
			
			if(i%j==0){
				
				isPrime=false;
				break;
			}

		}

	if(isPrime)cout<<i<<" ";

	}
	
	cout<<endl;

	return 0;

}
