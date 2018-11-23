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
    	        cout << "added node at root wtih data: " << rootNode->data << endl;
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
    
        bool findAndRemove(Node * &localRoot, int data)
        {
            cout << "call to findAndRemove(" << data << ")" << endl;
            if (localRoot == NULL)
            {
                return false;
            }
            else if (data < localRoot->data)
            {
                cout << "recCall ONE" << endl;
                return findAndRemove(localRoot->leftChild, data);
            }
            else if (data > localRoot->data)
            {
                cout << "recCall TWO" << endl;
                return findAndRemove(localRoot->rightChild, data);
            }
            else if (data == localRoot->data)
            {
                
                if (localRoot->leftChild == NULL && localRoot->rightChild == NULL)
                {
                    cout << "ONE" << endl;
                    Node * toRemove = localRoot;
                    
                    localRoot = NULL;
                    
                    delete toRemove;
                    return true;
                }
                else if (localRoot->rightChild != NULL && localRoot->leftChild == NULL)
                {
                    cout << "TWO" << endl;
                    Node * toRemove = localRoot;
                    
                    localRoot = localRoot->rightChild;
                    
                    delete toRemove;
                    return true;
                }
                else if (localRoot->leftChild != NULL && localRoot->rightChild == NULL)
                {
                    cout << "THREE" << endl;
                    Node * toRemove = localRoot;
                    
                    localRoot = localRoot->leftChild;
                    
                    delete toRemove;
                    return true;
                }
                else if (localRoot->leftChild != NULL && localRoot->rightChild != NULL)
                {
                    if (false) //(localRoot->leftChild->rightChild == NULL)
                    {
                        cout << "FOUR LR NULL: " << data << endl;
                        Node * toRemove = localRoot;
                        
                        localRoot = localRoot->leftChild;
                        
                        delete toRemove;
                        return true;
                    }
                    else
                    {
                        cout << "FOUR INORD PRED: " << data << endl;
                        Node * toRemove = localRoot;
                        Node * inordPred = localRoot->leftChild;
                        
                        while(inordPred->rightChild != NULL)
                        {
                            inordPred = inordPred->rightChild;
                        }
                        
                        localRoot->data = inordPred->data;
                        findAndRemove(localRoot->leftChild, localRoot->data);
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
    	    cout << "clear()" << endl;
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