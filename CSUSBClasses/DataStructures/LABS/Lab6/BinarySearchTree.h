/* Brandon Deo
 * Salloum
 * Mon Lab
 * Lab6
 */

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <algorithm>
#include <iostream>
using namespace std;       

template <typename Comparable>
class BinarySearchTree
{
  public:
    BinarySearchTree( ) : root{ nullptr }
    {
    }

    ~BinarySearchTree( )
    {
        makeEmpty( );
    }

    bool isEmpty( ) const
    {
        return root == nullptr;
    }

    //in-order traversal
    void printTree( ostream & out = cout ) const
    {
        if( isEmpty( ) )
            out << "Empty tree" << endl;
        else
            printTree( root, out );
    }

    void makeEmpty( )
    {
        makeEmpty( root );
    }


    void insert( const Comparable & x )
    {
        insert( x, root );
    }

    void printTreePreOrder(ostream & out = cout ) const{
	    if(isEmpty())
		    out<<"Empty tree"<<endl;
	    else
		    printTreePreOrder(root,out);
    }

    void printTreePostOrder(ostream & out = cout) const{
	    if(isEmpty())
		    out<<"Empty tree"<<endl;
	    else
		    printTreePostOrder(root,out);
    }

    int height() const{
	    return height(root);
    }

    bool isBalanced() const{
	    return isBalanced(root);
    }

  private:
    struct BinaryNode
    {
        Comparable element;
        BinaryNode *left;
        BinaryNode *right;

        BinaryNode( const Comparable & theElement, BinaryNode *lt, BinaryNode *rt )
          : element{ theElement }, left{ lt }, right{ rt } { }
        
        BinaryNode( Comparable && theElement, BinaryNode *lt, BinaryNode *rt )
          : element{ std::move( theElement ) }, left{ lt }, right{ rt } { }
    };

    BinaryNode *root;


    void insert( const Comparable & x, BinaryNode * & t )
    {
        if( t == nullptr )
            t = new BinaryNode{ x, nullptr, nullptr };
        else if( x < t->element )
            insert( x, t->left );
        else if( t->element < x )
            insert( x, t->right );
        else
            ;  // Duplicate; do nothing
    }
    
    void makeEmpty( BinaryNode * & t )
    {
        if( t != nullptr )
        {
            makeEmpty( t->left );
            makeEmpty( t->right );
            delete t;
        }
        t = nullptr;
    }

    //in-order traversal
    void printTree( BinaryNode *t, ostream & out ) const
    {
        if( t != nullptr )
        {
            printTree( t->left, out );
            out << t->element << " ";
            printTree( t->right, out );
        }
    }

    void printTreePreOrder (BinaryNode *t, ostream & out) const{
	if(t!=nullptr){
        	out<<t->element<<" ";
        	printTreePreOrder(t->left,out);
        	printTreePreOrder(t->right,out);
		}	
	}	


    void printTreePostOrder (BinaryNode *t, ostream & out) const{
    	if(t!=nullptr){
        	printTreePostOrder(t->left,out);
        	printTreePostOrder(t->right,out);
        	out<<t->element<<" ";
		}		
	}

    int height(BinaryNode *t) const{
	
	if(t==nullptr)
		return -1;
	else{
		return (max(height(t->left),height(t->right)))+1;
	}

    }	

    bool isBalanced(BinaryNode *t) const{
	if(t==nullptr)
		return true;
	if(abs(height(t->left)-height(t->right))<=1&&isBalanced(t->left)&&isBalanced(t->right))
		return true;
	return false;
    }

};

#endif


