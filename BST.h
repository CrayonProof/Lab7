#include "Node.h"
#include "BSTInterface.h"
#include <iostream>
using namespace std;

class BST :
    public BSTInterface
{
    public :
    
        BST() {}
    	~BST() {}
    	
    	/*
    	* Returns the root node for this tree
    	*
    	* @return the root node for this tree.
    	*/
    	Node * getRootNode() const
    	{
    	    return rootNode;
    	}
    	
    	bool addUnderParent(Node * last, int data)
    	{
    	    cout << "addUnderParentCall" << endl;
    	    
    	    if (last != NULL)
    	    {
    	        cout << last->data << endl;
    	    }
    	    
    	    if (last == NULL)
    	    {
    	        cout << "last == NULL" << endl;
    	        return false;
    	    }
    	    else if (last->data == data)
    	    {
    	        cout << "last->data == data" << endl;
    	        return false;
    	    }
    	    else if(data < last->data)
	        {
	            cout << "data < last->data" << endl;
	            if(last->leftChild == NULL)
        	    {
        	        cout << "last->leftChild == NULL" << endl;
        	        last->leftChild = new Node(data);
	                return true;
        	    }
        	    else
        	    {
        	        cout << "recursive call to left Child" << endl;
        	        return addUnderParent(last->leftChild, data);
        	    }
	        }
	        else if(data > last->data)
	        {
	            cout << "data > last->data" << endl;
	            if(last->rightChild == NULL)
        	    {
        	        cout << "last->rightChild == NULL" << endl;
        	        last->rightChild = new Node(data);
	                return true;
        	    }
        	    else
        	    {
        	        cout << "recursive call to right Child" << endl;
        	        return addUnderParent(last->rightChild, data);
        	    }
	        }
    	    
    	}
    	
    	/*
    	* Attempts to add the given int to the BST tree
    	*
    	* @return true if added
    	* @return false if unsuccessful (i.e. the int is already in tree)
    	*/
    	bool add(int data)
    	{
    	    if (rootNode == NULL)
    	    {
    	        rootNode = new Node(data);
    	        return true;
    	    }
    	    else
    	    {
    	        Node * lookingAt = rootNode;
    	        while (true)
    	        {
    	            if (lookingAt->data == data)
    	            {
    	                return false;
    	            }
    	            else if (lookingAt->data > data)
    	            {
    	                if (lookingAt->leftChild == NULL)
    	                {
    	                    lookingAt->leftChild = new Node(data);
    	                    cout << "added node at left wtih data: " << lookingAt->leftChild->data << endl;
    	                    return true;
    	                }
    	                lookingAt = lookingAt->leftChild;
    	            }
    	            else if (lookingAt->data < data)
    	            {
    	                if (lookingAt->rightChild == NULL)
    	                {
    	                    lookingAt->rightChild = new Node(data);
    	                    cout << "added node at right wtih data: " << lookingAt->rightChild->data << endl;
    	                    return true;
    	                }
    	                lookingAt = lookingAt->rightChild;
    	            }
    	        }
    	    }
    	}
    
        bool doTheRemove(Node * parent, Node * deleteNode)
        {
            
        }
    
        bool findAndRemove(Node * last, int data)
        {
            if (last->leftChild == NULL && last->rightChild == NULL)
            {
                return false;
            }
            else if (data < last->data)
            {
                if (last->leftChild->data == data)
    	        {
    	            doTheRemove(last, last->leftChild);
    	            return true;
    	        }
    	        else
    	        {
    	            return findAndRemove(last->leftChild, data);
    	        }
            }
            else if (data > last->data)
            {
                if (last->rightChild->data == data)
        	    {
        	        doTheRemove(last, last->rightChild);
        	        return true;
        	    }
        	    else
    	        {
    	            return findAndRemove(last->rightChild, data);
    	        }
            }
        }
    
    	/*
    	* Attempts to remove the given int from the BST tree
    	*
    	* @return true if successfully removed
    	* @return false if remove is unsuccessful(i.e. the int is not in the tree)
    	*/
    	bool remove(int data)
    	{
    	    return (findAndRemove(rootNode, data));
    	}
    
    	/*
    	* Removes all nodes from the tree, resulting in an empty tree.
    	*/
    	void clear()
    	{
    	    
    	}
	private :
	    Node * rootNode;
	    
};