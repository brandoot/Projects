#include"Number.h"

	//Initializes the variable to be zero
	Number::Number(){
		num=0;
	}
	
	//Allows the private variable to be modified
	Number::Number(int n){
		num=n;
	}

	//Changes the value of the variable
	void Number::setValue(int n){
		num=n;
	}

	//Returns the current value of the private variable
	int Number::getValue(){
		return num;
	}

	//Returns T/F if current num is prime
	bool Number::isPrime(){
		for(int i=2;i<num;i++){
			if(num%i==0)
				return false;
			}
		return true;
	}

	//Returns T/F is num is divisible by 7
	bool Number::isLucky(){
		if(num%7==0){
			return true;
		}
		return false;
	}
