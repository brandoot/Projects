/* Brandon Deo
 * Homework2
 * SpringQTR
 */

#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Code
{
public:

  Code();  // Default constructor - loads and uses morse code

  Code(vector<string> codewords);  // constructor loading customized code

  string encode(vector<char>message);  // encodes a message consisting of A-Z

  string decode(vector<string>message);  // decodes a message

private:

  vector<string> codewords; // this is a codeword vector parallel to A-Z
  vector<char> alpha; // this is the vector A-Z

  vector<char>  alphacode(); // function builds the vector alpha - A B C etc.

  vector<string>  morsecode(); // function the vector codewords containing  morse code

  string encode(char x); //returns the codeword for the character x
  char decode(string c); //returns the character for the codeword c.

};

Code::Code()
{
	codewords=morsecode();
	alpha=alphacode();
}

vector<string> Code::morsecode()
{
 vector<string> temp(28);
 temp[0] =".-";
 temp[1] ="-...";
 temp[2] ="-.-.";
 temp[3] ="-..";
 temp[4] =".";
 temp[5] ="..-.";
 temp[6] ="--.";
 temp[7] ="....";
 temp[8] ="..";
 temp[9] =".---";
 temp[10] ="-.-";
 temp[11] =".-..";
 temp[12] ="--";
 temp[13] ="-.";
 temp[14] ="---";
 temp[15] =".--.";
 temp[16] ="--.--";
 temp[17] =".-.";
 temp[18] ="...";
 temp[19] ="-";
 temp[20] ="..-";
 temp[21] ="...-";
 temp[22] =".--";
 temp[23] ="-..-";
 temp[24] ="-.--";
 temp[25] ="--..";
 temp[26] =".......";
 temp[27] ="x";
 return temp;
}

vector<char> Code::alphacode()
{
	vector<char> temp;
	for (char c='A';c<='Z';c++)
		temp.push_back(c);
	temp.push_back(' ');
	temp.push_back('.');
	return temp;
}

char Code::decode(string c)
{
	char a;

	for(int i=0;i<codewords.size();i++)
	{
		if(codewords[i]==c)
		{
			a=alpha[i];
		}
	}

	return a;
}

string Code::decode(vector<string>message)
{
	string a;

	for(int i=0;i<message.size();i++)
	{
		a+=decode(message[i]);
	}

	return a;

}

string Code::encode(char x)
{
	string a;

	for(int i=0;i<alpha.size();i++)
	{
		if(alpha[i]==x)
		{
			a=codewords[i];
		}
	}

	return a;

}

string Code::encode(vector<char>message)
{
	string a;

	for(int i=0;i<message.size();i++)
	{
		a+=encode(message[i]);
	}
	
	return a;
}

Code::Code(vector<string>codewords)
{
	this -> codewords = codewords;
}

int main()
{
	Code a=Code();
	vector<char>message;
	char t;

	while(cin)
	{
		cin>>t;
		message.push_back(t);
	}
	
	string answer=a.encode(message);
	cout<<answer<<endl;


	/*Code b=Code();
	
	vector<string>message2;
	string t;

	while(cin)
	{
		cin>>t;
		message2.push_back(t);
	}

	string answer2=b.decode(message2);
	cout<<answer2<<endl;
	*/

	return 0;

}
