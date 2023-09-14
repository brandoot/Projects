//Program to check if CC input is valid using Luhn algorithm
#include <iostream>
#include <string.h>
using namespace std;


//return this number if it is a single digit
//else return sum of two digits
int getDigit(int num){
    if(num < 9){
        return num;
    }
    return num/10 + num%10;
}

//return number of digits in x
int getSize(long x){
    string num = to_string(x);
    return num.length();
}

//return first x number of digits from number
//if number of figits in number is less than x, return number
long getPrefix(long num, int x){
    if(getSize(num)>x){
        string numb = to_string(num);
        return stol(numb.substr(0,x));
    }
    return num;
}

//return true if digit x id a prefix for a number
bool prefixMatch(long number, int x){
    return getPrefix(number, getSize(x)) == x;
}

//Get double of every other number
int sumOtherDigit(long int num){
    int sum = 0;
    string numb = to_string(num);
    for(int i = getSize(num)-2; i>= 0; i-=2){
        sum+= getDigit(int(numb[i]-'0')*2);
    }
    return sum;
}

//return sum of odd palced numbner
int sumOddNum(long num){
    int sum = 0;
    string numb = to_string(num);
    for(int i=getSize(num)-1; i>=0;i-=2){
        sum += numb[i]-'0';
    }
    return sum;
}

//Returrn if CC is valid
bool isValidCC(long int num){
    return 
    (getSize(num) >= 13 && getSize(16) &&
        (
            prefixMatch(num,4) || prefixMatch(num,5) ||
            prefixMatch(num,37) || prefixMatch(num,6)
        ) &&
        (
            (sumOtherDigit(num)+sumOddNum(num))%10==0
        )
    );
}

int main(){
    long int num = 379354508162306;
    cout<<num<< " is " << (isValidCC(num) ? "valid" : "invalid")<<endl;
    return 0;
}