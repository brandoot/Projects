/* Brandon Deo
 * Salloum
 * MON Lab
 * LAB4
 */
#ifndef SORTEDLIST_H
#define SORTEDLIST_H

#include <iostream>
#include <fstream>
using namespace std;

template <typename Object>
class SortedList
{
private:    
    struct Node
    {
      Object  data;
      Node   *prev;
      Node   *next;

      Node( const Object & d = Object{ }, Node * p = nullptr, Node * n = nullptr ){
      data=d;
      prev=p;
      next=n;
      }
    };

    int  theSize;
    Node *head;
    Node *tail;

  public:
    SortedList( )
    { 
      theSize = 0;
      head = new Node;
      tail = new Node;
      head->next = tail;
      tail->prev = head;
    }

    int size() const
    {
	    return theSize;
    }

    bool empty() const
    {
	    /*
	    bool x =false;
	    if(theSize==0)
		    x=true;
	    return x;
	    */
	    return (theSize == 0);
    }

    void insertItem(const Object & x)
    {
	Node *temp;
	if(empty()){
		temp=new Node(x,head,tail);
		head->next=temp;
		tail->prev=temp;
		theSize++;
	}
	else{
		for(temp=head->next;temp!=tail;temp=temp->next){
			if(x<temp->data){
				Node* newNode = new Node (x,temp->prev,temp);
				temp->prev->next=newNode;
				temp->prev=newNode;
				theSize++;
				return;
			}
		}
		Node* z= new Node(x,temp->prev,temp);
		temp->prev->next=z;
		temp->prev=z;
		theSize++;
	}
    }

    bool deleteItem(const Object & x)
    {
	    bool z = false;
	    if(empty())
	    {
		    z = false;
	    }
	    else{
		    Node *temp;
		    for(temp=head->next;temp!=tail;temp=temp->next){
			    if(x==temp->data){
				    temp->prev->next=temp->next;
				    temp->next->prev=temp->prev;
				    theSize--;
				    z=true;
				    break;
			    }
		    }
	    }
	return z;
    }

   friend ostream & operator<<(ostream &out, const SortedList & sL){
	   Node *temp;
	   for(temp=sL.head->next;temp!=sL.tail;temp=temp->next){
		   out<<temp->data<<" ";
	   }
	   out<<endl;
	   return out;
    }

};
#endif
