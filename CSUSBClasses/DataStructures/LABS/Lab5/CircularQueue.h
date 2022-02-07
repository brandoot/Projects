/* Brandon Deo
 * Lab 5 Ex 2
 * Salloum
 * Mon Lab
 */
#ifndef CIRCULARQUEUE_H
#define CIRCULARQUEUE_H

#include <fstream>
#include <climits>
#include <iostream>

using namespace std;

class CircularQueue{
	public:
		CircularQueue(int cap);
		~CircularQueue();
		int getCapacity() const;
		int getSize() const;
		bool isFull() const;
		bool isEmpty() const;
		int getFront() const;
		int getBack() const;
		void expand();
		void enqueue(int val);
		int dequeue();
		friend ostream & operator<<(ostream &out, const CircularQueue & cQ);
	private:
		int *theArray;
		int currentSize;
		int front;
		int back;
		int capacity;
};
#endif
