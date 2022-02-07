/* Brandon Deo
 * Salloum CSE330
 * MON LAB
 * Lab3
 */

#ifndef SORTEDVECTOR_H
#define SORTEDVECTOR_H
#include<vector>
#include<fstream>
using namespace std;
class SortedVector{
	public:
	SortedVector(int cap);
	int getCapacity() const;
	int getSize() const;
	bool isEmpty()const;
	void insertVal(int val);
	int find(int val) const;
	bool deleteVal(int val);
	friend ostream & operator<<(ostream &out,const SortedVector & sV);
	private:
	vector<int>sorted_vector;
};
#endif
