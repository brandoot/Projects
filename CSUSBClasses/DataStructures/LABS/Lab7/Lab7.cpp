/* Brandon Deo
 * Salloum
 * Lab7
 * Mon Lab
 */
#include <iostream>
#include <set>
#include <map>
#include <unordered_map>
#include <chrono>

using namespace std;

int main()
{

	set<int>s;
	while(s.size()<10000)
	{
		s.insert(rand()%20000);
	}

	map<int,int> mp;
	unordered_map<int,int> unmap(10007);

	set<int>::iterator itr=s.begin();

	auto start = chrono::high_resolution_clock::now();

	for(int i=0;itr!=s.end();i++){
		mp[i]=*itr;
		itr++;
	}

	auto end=chrono::high_resolution_clock::now();

	itr=s.begin();

	auto start2=chrono::high_resolution_clock::now();

	for(int i=0;itr!=s.end();i++){
		unmap[i]=*itr;
		itr++;
	}
	
	auto end2=chrono::high_resolution_clock::now();

	auto runTime1 = chrono::duration_cast<chrono::nanoseconds>(end-start).count();
	auto runTime2 = chrono::duration_cast<chrono::nanoseconds>(end2-start2).count();

	cout<<"The runtime of inserting the elements in the map is: "<<runTime1<<endl;
	cout<<"The runtime of inserting the elements into the unordered map is: "<<runTime2<<endl;

	auto start3=chrono::high_resolution_clock::now();

	for(itr=s.begin();itr!=s.end();itr++){
		mp.find(*itr);
	}

	auto end3=chrono::high_resolution_clock::now();
	auto runTime3 = chrono::duration_cast<chrono::nanoseconds>(end3-start3).count();

	auto start4=chrono::high_resolution_clock::now();

	for(itr=s.begin();itr!=s.end();itr++){
		unmap.find(*itr);
	}

	auto end4=chrono::high_resolution_clock::now();
	auto runTime4 = chrono::duration_cast<chrono::nanoseconds>(end4-start4).count();

	cout<<"The runtime of finding the keys in the map is: "<<runTime3<<endl;
	cout<<"The runtime of finding the keys in the unordered map is: "<<runTime4<<endl;

	return 0;
}
