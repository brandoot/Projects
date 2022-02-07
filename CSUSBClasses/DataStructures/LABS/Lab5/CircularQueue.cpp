/* Brandon Deo
 * Lab 5 Ex 2
 * Salloum
 * Mon Lab
 */

#include "CircularQueue.h"

CircularQueue::CircularQueue(int cap){
	capacity=cap;
	currentSize=0;
	front=0;
	back=-1;
	theArray=new int[capacity];
}
CircularQueue::~CircularQueue(){
	delete[] theArray;
}
int CircularQueue::getCapacity() const{
	return capacity;
}
int CircularQueue::getSize() const{
	return currentSize;
}
int CircularQueue::getFront() const{
	return front;
}
int CircularQueue::getBack() const{
	return back;
}
bool CircularQueue::isFull() const{
	return (getSize()==getCapacity());
}
bool CircularQueue::isEmpty() const{
	return (getSize()==0);
}
void CircularQueue::expand(){
	int *temp=new int[2*capacity];
	int count=-1;
	for(int i=front;i!=back;i=(i+1)%capacity){
		temp[i]=theArray[i];
		count++;
	}
	temp[back]=theArray[back];
	count++;
	front=0;
	back=count;
	theArray=temp;
	capacity*=2;
}
void CircularQueue::enqueue(int val){
	if(isFull()){
		expand();
	}
	else{
		currentSize+=1;
		back=(back+1)%capacity;
		theArray[back]=val;
	}
}
int CircularQueue::dequeue(){
	if(isEmpty()){
		cout<<"Queue is empty, unable to return any value."<<endl;
		return INT_MIN;
	}
	else{
		int x = getFront();
		currentSize-=1;
		front=(front+1)%capacity;
		return theArray[x];
	}
}

ostream & operator<<(ostream &out, const CircularQueue & cQ){
	if(cQ.isEmpty()){
		out<<endl<<"Empty queue"<<endl;
		return out;

	}
	else{	
	out<<"The queue is: ";

		for(int i=cQ.getFront();i!=cQ.getBack();i=(i+1)%cQ.getCapacity()){
		out<<cQ.theArray[i]<<" ";
		}
		out<<cQ.theArray[cQ.getBack()];
	}

	out<<endl;
	out<<"Current size = "<<cQ.getSize()<<endl;
	out<<"Front = "<<cQ.getFront()<<endl;
	out<<"Back = "<<cQ.getBack()<<endl;
	out<<"Capacity = "<<cQ.getCapacity()<<endl;
	
	return out;
}	


