/* Brandon Deo
 * Lab4_Ex4
 * This program prints out all the prime factors of a number
 *
 */
#include<iostream>

using namespace std;

int main()
{
	//declares variable
	int x;

	//prompts user
	cout<<"Welcome! Please enter a number to see all prime factors.\n";
	
	//userinput
	cin>>x;

	//starts for loop
	for(int i=2;i<=x;i++)
	{
		while(x%i==0)
		{
			cout<<i<<" ";
			x/=i;
			if(x==0)
			{
				break;
			}
		}
	}

	return 0;

}
