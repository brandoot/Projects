/* Brandon Deo
 * Lab4_Ex2
 * Program Picks a random number between 1 and 15 and then asks user to keep guessing number until correct
 * 7 February 2019
 *
 */
#include<iostream>
#include<cstdlib>

using namespace std;

int main()
{
	srand(time(NULL));

	int randomnum=rand()%15+1;

	int userin,count;

	cout<<"This program has generated a number between 1 and 15, please try to guess the correct number.\n";

	while(userin!=randomnum)
	{
		
		cout<<"Please enter in a whole number.\n";

		cin>>userin;

		count++;

		if(userin<randomnum){
			cout<<userin<<" is not the number, it is too small. Try again.\n";
		}		
		else{
			cout<<userin<<" is not the number, it is too big.Try again.\n";
		}

	}

	cout<<"Congrats, it took you "<<count<<" tries to get to, "<<randomnum<<". Goodbye.\n";
	return 0;

}
