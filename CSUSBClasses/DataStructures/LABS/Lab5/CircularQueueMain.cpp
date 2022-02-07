/* Brandon Deo
 * Lab 5
 * Salloum
 * Mon Lab
 */

#include "CircularQueue.h"

using namespace std;

int main(){
	CircularQueue cq1(10);

	cq1.enqueue(8);
	cout<<cq1<<endl;
	cq1.enqueue(5);
	cout<<cq1<<endl;
	cout<<"Returned number: "<<cq1.dequeue()<<endl;
	cout<<cq1<<endl;
	cout<<"Returned number: "<<cq1.dequeue()<<endl;
	cout<<cq1<<endl;
	cq1.enqueue(7);
	cout<<cq1<<endl;
	cq1.enqueue(8);
	cout<<cq1<<endl;
	cq1.enqueue(9);
	cout<<cq1<<endl;
	cq1.enqueue(11);
	cout<<cq1<<endl;
	cout<<"Returned number: "<<cq1.dequeue()<<endl;
	cout<<cq1<<endl;
	cout<<"Returned number: "<<cq1.dequeue()<<endl;
	cout<<cq1<<endl;
	cout<<"Returned number: "<<cq1.dequeue()<<endl;
	cout<<cq1<<endl;
	cq1.enqueue(3);
	cout<<cq1<<endl;
	cq1.enqueue(4);
	cout<<cq1<<endl;
	cq1.enqueue(18);
	cout<<cq1<<endl;
	cq1.enqueue(21);
	cout<<cq1<<endl;
	cq1.enqueue(13);
	cout<<cq1<<endl;
	cq1.enqueue(15);
	cout<<cq1<<endl;
	cout<<"Returned number: "<<cq1.dequeue()<<endl;
	cout<<cq1<<endl;
	cout<<"Returned number: "<<cq1.dequeue()<<endl;
	cout<<cq1<<endl;
	
	CircularQueue cq2(7);

	cq2.enqueue(8);
	cout<<cq2<<endl;
	cq2.enqueue(5);
	cout<<cq2<<endl;
	cq2.enqueue(7);
	cout<<cq2<<endl;
	cq2.enqueue(8);
	cout<<cq2<<endl;
	cq2.enqueue(9);
	cout<<cq2<<endl;
	cq2.enqueue(11);
	cout<<cq2<<endl;
	cout<<"Returned number: "<<cq2.dequeue()<<endl;
	cout<<cq2<<endl;
	cout<<"Returned number: "<<cq2.dequeue()<<endl;
	cout<<cq2<<endl;
	cout<<"Returned number: "<<cq2.dequeue()<<endl;
	cout<<cq2<<endl;
	cq2.enqueue(3);
	cout<<cq2<<endl;
	cq2.enqueue(4);
	cout<<cq2<<endl;
	cq2.enqueue(18);
	cout<<cq2<<endl;
	cq2.enqueue(21);
	cout<<cq2<<endl;
	cq2.enqueue(13);
	cout<<cq2<<endl;
	cq2.enqueue(15);
	cout<<cq2<<endl;
	cout<<"Returned number: "<<cq2.dequeue()<<endl;
	cout<<cq2<<endl;
	cout<<"Returned number: "<<cq2.dequeue()<<endl;
	cout<<cq2<<endl;

	return 0;
}

