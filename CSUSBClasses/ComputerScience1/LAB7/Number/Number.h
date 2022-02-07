#ifndef NUMBER_H
#define NUMBER_H
class Number
{
	public:
		Number();//default constructor
		Number(int n);//overload constructor
		void setValue(int n);//mutator function that changes value of private data
		int getValue();//Accesor function that returns value of private data "num"
		bool isPrime();//returns if num is prime
		bool isLucky();//return if number is divisible by 7
		
	private:
		int num;//private data that reps a number
};

#endif
