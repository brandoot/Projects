/* Brandon Deo
 * Salloum
 * MON Lab
 * Lab 1
 */

#include<iostream>

using namespace std;

void swap(int a,int b);
void intersect(int x[],int x_size,int y[],int y_size);
void unionize(int s[], int s_size,int z[],int z_size,int a[]);
void fillarray(int x[],int x_size);
void print(int a[],int a_size);
int main()
{
	int a_size;
	int b_size;

	cout<<"Please determine the size of the first array ";
	cin>>a_size;
	int* a=new int[a_size];
	fillarray(a,a_size);

	cout<<"and now this second array ";
	cin>>b_size;
	int* b=new int[b_size];
	fillarray(b,b_size);

	cout<<"Your first array ";
	print(a,a_size);
	cout<<"and your second array ";
	print(b,b_size);
	cout<<endl;
	
	int p=a_size+b_size;
	int* m=new int[p];
		
	unionize(a,a_size,b,b_size,m);
	intersect(a,a_size,b,b_size);

	delete[] a;
	delete[] b;
	delete[] m;

	return 0;

}
void print(int a[],int a_size){
for(int i=0;i<a_size;i++){
cout<<a[i]<<" ";
}}

void swap(int a, int b){
int c;
c=a;
a=b;
b=c;}
	
void fillarray(int x[],int x_size){
int r;
int cc=0;

cout<<"Please enter numbers in ascending order until the array is full ";

while(cc!=x_size){
cin>>r;
if(cc==0||r>=x[cc-1]){
	x[cc]=r;
	cc++;
}
else{
	cout<<"Number too small compared to previous"<<endl;
}
cout<<"Next ";
}
cout<<"Thank you"<<endl<<endl;
}

void intersect(int x[],int x_size,int y[],int y_size)
{
int count=0;
int x_index=0;
int y_index=0;
while(x_index<x_size&&y_index<y_size){
if(x[x_index]<y[y_index]){
x_index++;
}
else if(x[x_index]>y[y_index]){
y_index++;
}
else if(x[x_index]==y[y_index]){
if(x[x_index-1]==y[y_index]){
x_index++;
y_index++;}
else{
cout<<x[x_index]<<" ";
count++;
x_index++;
y_index++;
}
}}
if(count!=1){
cout<<endl<<"There are "<<count<<" elements in this intersection."<<endl;}
else{
cout<<endl<<"There is 1 element in this intersection."<<endl;}}

void unionize(int s[], int s_size,int z[],int z_size,int a[])
{
int s_index = 0;
int z_index = 0;
int a_index = 0;

while(s_index < s_size && z_index < z_size){	
if(s[s_index] == z[z_index])
{
	if((a[a_index-1]!=s[s_index])||(a[a_index-1]!=z[z_index])){
		a[a_index] = s[s_index];
 		a_index++;
  		s_index++;
   		z_index++;
	}
	else{
		s_index++;
		z_index++;
	}
}
else if(s[s_index] > z[z_index]){	
	if(a[a_index-1]!=z[z_index]){
		a[a_index]=z[z_index];
		a_index++;
		z_index++;
	}
	else{
		z_index++;
	}
}
else if(s[s_index] < z[z_index]){
	if(a[a_index-1]!=s[s_index]){
		a[a_index]=s[s_index];
		a_index++;
		s_index++;
	}
	else{
		s_index++;
	}
}
}

while(s_index < s_size){
if(a[a_index-1]!=s[s_index]){
	a[a_index]=s[s_index];
	a_index++;
	s_index++;
}
else{
	s_index++;
}
}

while(z_index < z_size){
if(a[a_index-1]!=z[z_index]){
	a[a_index]=z[z_index];
	a_index++;
	z_index++;
}
else{
	z_index++;
}
}
print(a,a_index);
cout<<endl<<"There are "<<a_index<<" elements in this union."<<endl;
}
