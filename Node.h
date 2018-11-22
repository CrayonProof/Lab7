#include "NodeInterface.h"
#include <iostream>
using namespace std;

class Node :
    public NodeInterface
{
    public :
        Node()
        {
            data = -314159;
            leftChild = NULL;
            rightChild = NULL;
        }
        Node(int data) 
        {
            //cout << "new node created with data = " << data << " and no children" << endl;
            this->data = data;
            leftChild = NULL;
            rightChild = NULL;
        }
        Node(int data, Node * leftChild, Node * rightChild) 
        {
            this->data = data;
            this->rightChild = rightChild;
            this->leftChild = leftChild;
        }
    	~Node() {}
    
        /*
    	* Returns the data that is stored in this node
    	*
    	* @return the data that is stored in this node.
    	*/
    	int getData() const
    	{
    	    return data;
    	}

        /*
    	* Returns the left child of this node or null if it doesn't have one.
    	*
    	* @return the left child of this node or null if it doesn't have one.
    	*/
    	Node * getLeftChild() const
    	{
    	    return leftChild;
    	}

        /*
    	* Returns the right child of this node or null if it doesn't have one.
    	*
    	* @return the right child of this node or null if it doesn't have one.
    	*/
    	Node * getRightChild() const
    	{
    	    return rightChild;
    	}
    	
    	bool setData(int data)
    	{
    	    this->data = data;
    	    return true;
    	}
    	
    	bool setLeftChild(Node * newLeftChild)
    	{
    	    leftChild = newLeftChild;
    	    return true;
    	}
    	
    	bool setRightChild(Node * newRightChild)
    	{
    	    rightChild = newRightChild;
    	    return true;
    	}
    private :
        int data;
        Node * rightChild;
        Node * leftChild;
        friend class BST;
};