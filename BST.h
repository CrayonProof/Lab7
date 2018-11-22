#include "Node.h"
#include "BSTInterface.h"
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
    	    if(last->data == data)
    	    {
    	        return false;
    	    }
    	    else if(data < last->data)
	        {
	            if(last->leftChild == NULL)
        	    {
        	        last->leftChild = new Node(data);
	                return true;
        	    }
        	    else
        	    {
        	        return addUnderParent(last->leftChild, data);
        	    }
	        }
	        else if(data > last->data)
	        {
	            if(last->rightChild == NULL)
        	    {
        	        last->rightChild = new Node(data);
	                return true;
        	    }
        	    else
        	    {
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
    	    return addUnderParent(rootNode, data);
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