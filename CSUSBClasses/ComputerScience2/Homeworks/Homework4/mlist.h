/* Brandon Deo
 * Homework4
 */

#ifndef MLIST_H
#define MLIST_H
#include <vector>
using namespace std;

template<class T>

class Mlist
{
   public:
    	Mlist();//creates the list
    	T front();//returns the front of the list
    	T end();//returns the end of the list
    	bool in(T x);//returns true if x is in the list and false otherwise
    	bool empty(); // returns true if the list is empty
    	void addfront(T entry);//add entry to the back of the list
    	void addend(T entry);//add entry to the back of the list
    	void addorder(T entry);//add entry to an ordered list
    	void removefront();//removes the front of the list
    	void removeend();//removes the back of the list
    	void remove(T n);//searches the list and removes the entry with value n
    private:
    	vector<T> mlist;
    	void remove(typename vector<T>::iterator ix, T n);//uses an iterator and recursion to remove value n
	void addorder(typename vector<T>::iterator ix, T n);//uses an iterator and recursion to add value n in an ordered list
};
#endif
