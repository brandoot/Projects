/* Brandon Deo
 * Lab2
 */
#ifndef SORTEDARRAY_H
#define SORTEDARRAY_H

#include<fstream>

using namespace std;

class SortedArray
{
	public:	
	SortedArray(int cap=10);
	~SortedArray();
	int getCapacity();
	int getSize();
	int find(int val);
	bool isFull();
	bool isEmpty();
	bool deleteVal(int val);
	void expand();
	void insertVal(int val);
	friend ostream & operator<<(ostream &out, const SortedArray & sA);
	private:
	int capacity;
	int size;
	int* arr;
};
#endif
