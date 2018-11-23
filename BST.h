#include "Node.h"
#include "BSTInterface.h"
#include <iostream>
using namespace std;

class BST :
    public BSTInterface
{
    public :
    
        BST()
        {
            rootNode = NULL;
        }
    	~BST()
    	{
    	    clear();
    	}
    	
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
    
    
    int maxValueAtN(Node* n)
{
	if(n==NULL)
		return -1;
	int value= n->getData();
	Node* left=n->leftChild;
	if(left!=NULL)
	{
		int leftValue=maxValueAtN(left);
		if(leftValue>value)
		{
			value=leftValue;
		}
	}
	Node* right=n->rightChild;
	if(right!=NULL)
	{
		int rightValue = maxValueAtN(right);
		if(rightValue>value)
		{
			value=rightValue;
		}
	}
	return value;
}
    
    
        bool removeItemAt(Node*& n,int data)
{
	if(n==NULL)
	{
		//cout<<"empty tree"<<endl;
		return false;
	}
	if(data==n->data)
	{
		if(n->leftChild==NULL&&n->rightChild!=NULL)
		{
			//cout<<"single right child"<<endl;
			Node* temp=n;
			n=n->rightChild;
			delete temp;
			return true;
		}
		else if(n->rightChild==NULL&&n->leftChild!=NULL)
		{
			//cout<<"single left child"<<endl;
			Node* temp=n;
			n=n->leftChild;
			delete temp;
			return true;
		}
		else if(n->rightChild==NULL&&n->leftChild==NULL)
		{
			Node* temp=n;
			n=NULL;
			delete temp;
			return true;

		}
		else
		{
			n->data=maxValueAtN(n->leftChild);//*max value in left*
			removeItemAt(n->leftChild,n->data);
		}
	}
	else if(data < n->data)
	{
		removeItemAt(n->leftChild,data);
	}
	else 
		removeItemAt(n->rightChild,data);
}
    
        bool findAndRemove(Node * &localRoot, int data)
        {
            cout << "recursive call to findAndRemove" << endl;
            if (localRoot == NULL)
            {
                return false;
            }
            else if (data < localRoot->data)
            {
                return findAndRemove(localRoot->leftChild, data);
            }
            else if (data > localRoot->data)
            {
                return findAndRemove(localRoot->rightChild, data);
            }
            else
            {
                
                if (localRoot->leftChild == NULL && localRoot->rightChild == NULL)
                {
                    cout << "ONE" << endl;
                    Node * toRemove = localRoot;
                    
                    localRoot == NULL;
                    
                    delete toRemove;
                    return true;
                }
                else if (localRoot->rightChild != NULL)
                {
                    cout << "TWO" << endl;
                    Node * toRemove = localRoot;
                    
                    localRoot == localRoot->rightChild;
                    
                    //delete toRemove;
                    return true;
                }
                else if (localRoot->leftChild != NULL)
                {
                    cout << "THREE" << endl;
                    Node * toRemove = localRoot;
                    
                    localRoot == localRoot->leftChild;
                    
                    delete toRemove;
                    return true;
                }
                else
                {
                    cout << "FOUR" << endl;
                    if (localRoot->leftChild->rightChild == NULL)
                    {
                        Node * toRemove = localRoot;
                        
                        localRoot = localRoot->leftChild;
                        
                        delete toRemove;
                        return true;
                    }
                    else
                    {
                        Node * toRemove = localRoot;
                        Node * inordPred = localRoot->leftChild;
                        
                        while(inordPred->rightChild != NULL)
                        {
                            inordPred = inordPred->rightChild;
                        }
                        
                        localRoot->data = inordPred->data;
                        inordPred = inordPred->leftChild;
                        
                        delete toRemove;
                        return true;
                    }
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
    	    cout << "remove()" << endl;
    	    return findAndRemove(rootNode, data);
    	}
    
        void travClear(Node * node)
        {
            cout << "travClear" << endl;
            
            if(node->leftChild != NULL)
                travClear(node->leftChild);
            if(node->rightChild != NULL)
                travClear(node->rightChild);
            delete node;
        }
    
    	/*
    	* Removes all nodes from the tree, resulting in an empty tree.
    	*/
    	void clear()
    	{
    	    /*
    	    if (rootNode != NULL)
    	    {
    	        travClear(rootNode);
    	        rootNode = NULL;
    	    }
    	    */
    	    
    	    while (rootNode != NULL)
    	    {
    	        remove(rootNode->data);
    	    }
    	}
	private :
	    Node * rootNode;
	    
};