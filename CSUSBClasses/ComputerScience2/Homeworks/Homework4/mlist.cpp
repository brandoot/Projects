/* Brandon Deo
 * Homework4
 */

#include "mlist.h"
#include <vector>
using namespace std;

template<typename T>
Mlist<T>::Mlist()
{
	vector<T>mlist;
}

template<typename T>
T Mlist<T>::front()
{
	return mlist[0];
}

template<typename T>
T Mlist<T>::end()
{
	return mlist[mlist.size()-1];
}

template<typename T>
bool Mlist<T>::in(T x)
{
	bool yee=true;
	for(int i=0;i<mlist.size();i++)
	{
		if(mlist[i]==x)
		{
			yee=true;
		}
		else
			yee=false;
	}
	return yee;
}

template<typename T>
bool Mlist<T>::empty()
{
	bool ya;
	if(mlist.size()==0)
	{
		ya=true;
	}
	else
	{
		ya=false;
	}
	return ya;
}

template<typename T>
void Mlist<T>::addfront(T entry)
{
	mlist.insert(mlist.begin(),entry);
}

template<typename T>
void Mlist<T>::addend(T entry)
{
	mlist.push_back(entry);
}

template<typename T>
void Mlist<T>::removefront()
{
	mlist.erase(mlist.begin());
}

template<typename T>
void Mlist<T>::removeend()
{
	mlist.pop_back();
}

template<typename T>
void Mlist<T>::addorder(T entry)
{
	addorder(mlist.begin(),entry);
}

template<typename T>
void Mlist<T>::addorder(typename vector<T>::iterator ix, T n)
{
	if(ix==mlist.end())
	{
		mlist.insert(mlist.end(),n);
		return;
	}
	if(n<=*ix)
	{
		mlist.insert(ix,n);
		return;
	}
	addorder(++ix,n);
}

template<typename T>
void Mlist<T>::remove(T n)
{
	remove(mlist.begin(),n);
}

template<typename T>
void Mlist<T>::remove(typename vector<T>::iterator ix, T n)
{
	if(ix==mlist.end())
	{
		return;
	}
	if(*ix==n)
	{
		mlist.erase(ix);
	}
	else
	{
		++ix;
	}
	remove(ix,n);
}
