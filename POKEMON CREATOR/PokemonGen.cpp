#include <iostream>
#include <string>
#include "Pokemon.h"
#include <ctime>

int main(){

    Pokemon A;
    string b = "";
    int n = 0;
    bool f = false;

    unsigned seed = time(0);
    srand(seed);

    cout<<"Hello! We are going to create a pokemon, what will be their name?"<<endl;
    do {
        cin>>b;
        if(b.empty()){
            cout<<"Please enter in a name"<<endl;
        }
    } while(b.empty());
    A.setName(b);

    cout<<"And which region are we from?"<<endl;
    do {
        cin>>b;
        if(b.empty()){
            cout<<"Please enter in a region name"<<endl;
        }
    } while(b.empty());
    A.setRegion(b);

    cout<<"Please pick a number between 1 - 18"<<endl;
    do {
        cin>>n;
        if(n > 18 || n < 1){
            cout<<"Please enter in a number in the range"<<endl;
        }
    } while(!(n >= 1) || !(n <= 18));
    n -= 1;
    A.setType1(n);

    n= rand() % 18;
    A.setType2(n);

    cout<<"Is this Pokemon a legendary? TRUE = 1 OR FALSE = 0"<<endl;
    cin>> f;

    cout<<"Creating your Pokemon..."<<endl;

    A.randomizeStat(f);

    A.print();

    return 0;
}