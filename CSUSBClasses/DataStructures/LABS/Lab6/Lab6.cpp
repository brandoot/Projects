/* Brandon Deo
 * Salloum
 * Mon Lab
 * Lab6
 */
#include "BinarySearchTree.h"
#include <iostream>
using namespace std;
int main(){
	BinarySearchTree<int> t1;
	t1.insert(6);
	t1.insert(2);
	t1.insert(8);
	t1.insert(1);
	t1.insert(4);
	t1.insert(3);
	cout<<"Here is tree one printed in Pre-Order: ";
	t1.printTreePreOrder();
	cout<<endl<<"Here is tree one printed in Post-Order: ";
	t1.printTreePostOrder();
	cout<<endl;
	
	if(t1.isBalanced())
		cout<<"Tree is balanced."<<endl;
	else
		cout<<"Tree is unbalanced."<<endl;
		
	cout<<"The height of the tree is "<<t1.height()<<endl;


	BinarySearchTree<int> t2;
	t2.insert(6);
	t2.insert(4);
	t2.insert(2);
	t2.insert(5);
	t2.insert(7);
	t2.insert(8);
	t2.insert(9);
	cout<<endl<<"Here is tree two printed in Pre-Order: ";
	t2.printTreePreOrder();
	cout<<endl<<"Here is tree two printed in Post-Order: ";
	t2.printTreePostOrder();
	cout<<endl;
	
	if(t2.isBalanced())
		cout<<"Tree is balanced."<<endl;
	else
		cout<<"Tree is unbalanced."<<endl;
		
	cout<<"The height of the tree is "<<t2.height()<<endl;

	BinarySearchTree<int> t3;
	t3.insert(7);
	t3.insert(5);
	t3.insert(2);
	t3.insert(6);
	t3.insert(10);
	t3.insert(8);
	t3.insert(12);
	cout<<endl<<"Here is tree three printed in Pre-Order: ";
	t3.printTreePreOrder();
	cout<<endl<<"Here is tree three printed Post-Order: ";
	t3.printTreePostOrder();
	cout<<endl;
	
	if(t3.isBalanced())
		cout<<"Tree is balanced."<<endl;
	else
		cout<<"Tree is unbalanced."<<endl;
		
	cout<<"The height of the tree is "<<t3.height()<<endl;

	return 0;
}
