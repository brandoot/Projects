/*Brandon Deo
 * Lab6_Ex2
 * this program explores functions of vectors and modifies them
 *
 * 3 March 2019
 */

#include<iostream>
#include<vector>
using namespace std;

//Prototypes functions
void print_vector(const vector<int>&v);
int maximum(const vector<int>&v);
bool linearsearch(const vector<int>&v,int value);
void insertvector(vector<int>&v,int value);
void appendvector(vector<int>&v,const vector<int>&w);
void userinput(vector<int>&v,int value);
void bubblesort(vector<int>&v);
void swap(int&x,int&y);

int main(){
	
	//Declares userinput variable, creates vectors
	int globalsize=3;
	vector<int>yeezy(globalsize,0);
	vector<int>jordans(globalsize,0);
	int input;

	//Program displays original values of vector
	cout<<"Hello, this program explores functions of vectors. Here are the current elements of vector yeezy: "<<endl;
	print_vector(yeezy);
	cout<<endl;

	//asks for user input using userinput function that changes values of vector
	cout<<"Let us change the value of these shall we?"<<endl;
	userinput(yeezy,input);

	//prints new values of vector
	cout<<"Great! Now here are the elements of vector yeezy: "<<endl;
	print_vector(yeezy);

	//uses maximum function to find largest value
	cout<<"Let's see which one of these numbers is the largest. Ah, "<<maximum(yeezy)<<" is the largest number."<<endl;

	//uses linear search function to find if the value from userinput is in the vector
	cout<<"Now lets check if a value exists in vector yeezy. Please enter in a number: ";
	cin>>input;
	cout<<endl;
	if(linearsearch(yeezy,input)){
		cout<<"This value exists in vector yeezy!"<<endl;
	}
	else{
		cout<<"This value does NOT exist in vector yeezy!"<<endl;
	}

	//Asks for user input for values of the second vector
	cout<<"Let's create another vector shall we? Luckily I already made one, all you need to do is just input some values."<<endl;
	userinput(jordans,input);

	//Uses the appendvector function to pushback values of the second vector into the first one
	cout<<"Now that we have two vectors, let's combine them together!"<<endl;
	appendvector(yeezy,jordans);

	//prints content of vector after changed
	cout<<"Here is what vector yeezy looks like now."<<endl;
	print_vector(yeezy);

	//sorts the whole vector into numerical order
	cout<<"Let's sort yeezy into numerical order. It should look like this now: ";
	bubblesort(yeezy);
	print_vector(yeezy);
	cout<<endl;

	//takes input from user and uses insert algorithm
	cout<<"Since the vector is now sorted, lets insert one last value."<<endl;
	cin>>input;
	insertvector(yeezy,input);

	//displays final elements of vector
	cout<<"The final elements of vector yeezy are now: ";
	print_vector(yeezy);

	return 0;
}

//function used to take user input and replace existing values of a vector
void userinput(vector<int>&v,int value){
	for(int i=0;i<v.size();i++){
		cout<<"Please enter in a value to change the element: ";
		cin>>value;
		v[i]=value;
	}	
}

//function used to print all elements of a vector
void print_vector(const vector<int>& v){
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
}

//function used to find the maximum value of the vector
int maximum(const vector<int>&v){
       int bigmax=v[0];
	for(int i=1;i<v.size();i++){
		if(bigmax<v[i]){
			bigmax=v[i];
		}
	}
	
	return bigmax;
}

//function checks if a value is in the vector or not
bool linearsearch(const vector<int>&v,int value){

	//bool statement used for the return if the value does
	//exist or if it does not
	bool oof=false;

	//for loop used to find if the the value inputted exists in the vector
	for(int i=0;i<v.size();i++){
		if(v[i]==value)
			oof=true;
	}

	return oof;
}

//function used to insert a value into a sorted vector
void insertvector(vector<int>&v,int value){

	//checks if the vector is empty or if the value of the wanted number
	//is less than the last value, if so, then pushes back value to end
	if(v.empty()||value>v[v.size()-1]){
		v.push_back(value);
		}
	//if above statment fails, then the for loop is used to see where
	//the value can be placed in the vector to stay numerical order
	else{
		for(vector<int>::iterator it=v.begin(); it!=v.end();++it){
			if(value<=*it){
				v.insert(it,value);
				break;
			}
		}
	}
}

//uses the push_back funtion of vectors to put values of a second vector in the back of the first vector
void appendvector(vector<int>&v,const vector<int>&w){
	for(int i=0;i<w.size();i++){
		v.push_back(w[i]);
	}
}

//Sorts out a vector into a numerical order
void bubblesort(vector<int>&v){

	//bool statement to check if the loop needs to be sorted anymore
	//second statement checks how many passes were made to sort
	bool issorted=false;
	int amtofpasses=0;

	//while loop used to sort vectors
	while(!issorted){

		//bool statement set to true because vector is in need to be sorted
		issorted=true;

		//for loop used to check if the previous value is larger than preceding, if so, then swaps the values
		for(int i=0;i<v.size()-1;i++){
			if(v[i]>v[i+1]){
				swap(v[i],v[i+1]);
				issorted=false;
			}
		}
		amtofpasses++;
	}

	cout<<"It took, "<<amtofpasses<<" passes to sort the vector."<<endl;
}

//Swap function, needed to swap two values
void swap(int&x,int&y){
	int z=x;
	x=y;
	y=z;
}
