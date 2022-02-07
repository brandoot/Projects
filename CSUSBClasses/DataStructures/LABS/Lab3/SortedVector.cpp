/* Brandon Deo
 * Lab3
*/
#include "SortedVector.h"
#include <vector>
using namespace std;

SortedVector::SortedVector(int cap){
	vector<int> sorted_vector(cap);
}

int SortedVector::getCapacity() const{
	return sorted_vector.capacity();
}

int SortedVector::getSize() const{
	return sorted_vector.size();
}

bool SortedVector::isEmpty() const{
	return sorted_vector.empty();
}

void SortedVector::insertVal(int val){
	if(isEmpty()){
		sorted_vector.push_back(val);
	}
	else{
	vector<int>::iterator ix;	
	ix=sorted_vector.begin();
	while((ix!=sorted_vector.end())&&(val>=*ix)){
		ix++;
	}
	sorted_vector.insert(ix,val);
	}
}

int binarySearch(vector<int> v,int left, int right, int x){
if(right>=left){
	int mid=(left+right)/2;
	if(v[mid]==x)
		return mid;
	if(v[mid]>x)
		return binarySearch(v,left,mid-1,x);
	return binarySearch(v,mid+1,right,x);
}
return -1;
}

int SortedVector::find(int val) const{
	return binarySearch(sorted_vector,0,getSize()-1,val);
}

bool SortedVector::deleteVal(int val){
	bool x;
	int y=find(val);
	if(y==-1){
		x=false;
	}
	else{
		for(int i=y;i<getSize()-1;i++){
			swap(sorted_vector[i],sorted_vector[i+1]);
		}
		sorted_vector.pop_back();
		x=true;
	}
	return x;
}

ostream & operator<<(ostream &out, const SortedVector & sV)
{
	for(int i=0;i<sV.sorted_vector.size();i++){
		out<<sV.sorted_vector[i]<<" ";
	}
	out<<endl;
	return out;
}

