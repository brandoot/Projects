/* Brandon Deo
 * Lab2
 */
#include "SortedArray.h"

using namespace std;

SortedArray::SortedArray(int cap)
{	
	size=0;
	capacity=cap;
	arr=new int[capacity];
}

SortedArray::~SortedArray()
{
	delete[] arr;
}

int SortedArray::getCapacity()
{
	return capacity;
}

int SortedArray::getSize()
{
	return size;
}

bool SortedArray::isFull()
{
	if(size==capacity)
		return true;
	else
		return false;
}

bool SortedArray::isEmpty()
{
	if(size==0)
		return true;
	else
		return false;
}

void SortedArray::expand()
{	int* temp=new int[capacity*2];
	for(int i=0;i<size;i++){
		temp[i]=arr[i];
	}
	delete[] arr;
	arr=temp;
	capacity*=2;
}

void SortedArray::insertVal(int val)
{
if(isFull()){
expand();
}
int i=0;
while((i<size)&&(val>=arr[i])){
i++;
}
for(int j=size-1;j>=i;j--){
arr[j+1]=arr[j];
}
arr[i]=val;
size++;
}

int binarySearch(int arr[],int left,int right, int x){
if(right>=left){
	int mid=(left+right)/2;
	if(arr[mid]==x)
		return mid;
	if(arr[mid]>x)
		return binarySearch(arr,left,mid-1,x);
	return binarySearch(arr, mid+1,right,x);
}
return -1;
}

int SortedArray::find(int val)
{	
return binarySearch(arr,0,size-1,val);
}

bool SortedArray::deleteVal(int val)
{
	bool deletus;
	int x=find(val);
	if(x==-1){
		deletus=false;
	}
	else{
		for(int i=x;i<size-1;i++){
			arr[i]=arr[i+1];
		}
		deletus=true;
		size--;
	}
	return  deletus;
}

ostream & operator<<(ostream &out, const SortedArray & sA){
	for(int i=0;i<sA.size;i++){
		out<<sA.arr[i]<<" ";
	}
	out<<endl;
	return out;
}
