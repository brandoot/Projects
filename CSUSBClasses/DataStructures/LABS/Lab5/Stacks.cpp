/* Brandon Deo
 * Salloum
 * Lab5
 * Mon Lab
 */
using namespace std;

#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

void tokenize(string str, vector<string> & tokens){
	stringstream ss(str);
	string temp;

	while(getline(ss,temp,' '))
	{
		tokens.push_back(temp);
	}
}
int evaluatePostFix(string str){
	vector<string> tokens;
	tokenize(str,tokens);

	stack<int> s;

	int val1;
	int val2;
	int counter=0;

	while(counter!=tokens.size()){
		if(tokens[counter]=="+"){
			val1 = s.top();
			s.pop();

			val2 = s.top();
			s.pop();
			s.push(val1+val2);
		}
		else if(tokens[counter]=="-"){
			val1 = s.top();
			s.pop();
			
			val2 = s.top();
			s.pop();
			s.push(val1-val2);
		}
		else if(tokens[counter]=="*"){
			val1 = s.top();
			s.pop();

			val2 = s.top();
			s.pop();
			s.push(val1*val2);
		}
		else{
			val1=stoi(tokens[counter]);
			s.push(val1);
		}
		counter++;
	}
	return s.top();
}
int main(){
	string str1="6 5 2 3 + 8 * + 3 + * ";
	string str2="6 5 2 3 - 8 * + 3 - * ";
	string str3="5 8 9 + * 7 4 * 5 3 2 * * + * ";
	string str4="15 -2 3 + * -12 4 * -3 2 4 * * + * ";

	cout<<"Expression 1 = "<<evaluatePostFix(str1)<<endl;
	cout<<"Expression 2 = "<<evaluatePostFix(str2)<<endl;
	cout<<"Expression 3 = "<<evaluatePostFix(str3)<<endl;
	cout<<"Expression 4 = "<<evaluatePostFix(str4)<<endl;

	return 0;
}
