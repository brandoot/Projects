/* Brandon Deo
 * Lab6_Ex1
 * This program deals with different functions about arrays
 *
 * 25 February 2019
 */
#include<iostream>

using namespace std;

//Prototypes functions
void print_array(const int a[],int a_size);
int maximum(const int a[], int a_size);
bool isStrictlyIncreasing(const int a[], int a_size);
void bubblesort(int a[],int a_size);
void swap(int&x,int&y);
bool appendArray(int a[],int& a_size);

//Declares a global constant for the array size
const int globalsize = 6;

int main(){
	
	//Declaring array, creating variable for input
	int input=0;
	int a[globalsize];

	//Creating values inside the array
	a[0]=1;
	a[1]=5;
	a[2]=3;
	a[3]=54;
	a[4]=9;
	a[5]=22;

	//Let's the user know what elements are inside of array a
	cout<<"Here is array  \"a\" elements:"<<endl;
	print_array(a,globalsize);

	//Displays the highest number
	cout<<"The highest number in array a is: "<<maximum(a,globalsize)<<endl;

	//Asks rhetorical question if the array is in order
	cout<<"Now is this array increasing in order?"<<endl;

	//Prompts user input
	if(appendArray==true){
	cout<<"Please enter in a value to input into the array."<<endl;
	cin>>input;
	}

	//if/else statements that check if the order is increasing or not 
	if(isStrictlyIncreasing(a,globalsize)){
		cout<<"Yes it is increasing."<<endl;
		}
	//Tells the user the array is not in increasing
	//order and sorts it to an increasing order
	else{
		cout<<"No it is not increasing. Let's fix that."<<endl;
		bubblesort(a,globalsize);
		cout<<"Now the array should be in order!"<<endl;
		print_array(a,globalsize);
		cout<<endl;
	}

	return 0;

}
//function prints all elements of an array
void print_array(const int a[],int a_size){
	for(int i=0;i<a_size;i++){
		cout<<a[i]<<" ";
	}
}
//function checks which value of the array 
//is largest and displays to user
int maximum(const int a[], int a_size){
	double max=a[0];
	for(int i=1;i<a_size;i++){
		if(a[i]>max)
			max=a[i];
	}
	return max;
}

	//function that outputs a T/F statement
	//whether or not the array is increasing order
	bool isStrictlyIncreasing(const int a[], int a_size){

	//declares a variable for a previous number to check
	//bool statement for return statement
	int previousnumber=a[0];
	bool isincrease = false;

	//for loop checks if the previous number is less than the preceding number
	for(int i=1; i<a_size; i++){
		if(previousnumber<a[i]){
			previousnumber=a[i];
			isincrease =  true;
		}
		else
			isincrease = false;
	}
	
	return isincrease;
}

//sorts the array out into numerical order
void bubblesort(int a[], int a_size){
	//declares a bool to check whether or not the loop needs to sort anymore
	bool incr = false;
	int passes = 0;

	while(incr!=true){

		//for loop checks if the previous value
		//is larger than preceding, if so, swaps the two
		for(int i=0;i<a_size-1;i++){
			if(a[i]>a[i+1]){
				swap(a[i],a[i+1]);
				incr=true;		
			}
		}
	passes++;	
	}
	//cout statement of how many passes it took to sort the whole array
	cout<<"It has taken "<<passes<<" passes to sort the array."<<endl;
}

//swap function, used to swap two values
void swap(int&x,int&y){
	int temp=x;
	x=y;
	y=temp;
}

//array used to insert a value into the array
bool appendArray(int a[],int& a_size){

	bool abletoappend = true;

	if(a_size!=globalsize){
		for(int i=a_size;i<globalsize;i++){
		}
	}
	else{
		abletoappend=false;	

}

return abletoappend;

}
