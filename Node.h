#include "NodeInterface.h"
using namespace std;

class Node :
    public NodeInterface
{
    public :
        Node() {}
    	~Node() {}
    
        /*
    	* Returns the data that is stored in this node
    	*
    	* @return the data that is stored in this node.
    	*/
    	int getData() const
    	{
    	    
    	}

        /*
    	* Returns the left child of this node or null if it doesn't have one.
    	*
    	* @return the left child of this node or null if it doesn't have one.
    	*/
    	NodeInterface * getLeftChild() const
    	{
    	    
    	}

        /*
    	* Returns the right child of this node or null if it doesn't have one.
    	*
    	* @return the right child of this node or null if it doesn't have one.
    	*/
    	NodeInterface * getRightChild() const
    	{
    	    
    	}
    private :
        int thisGuy;
        Node * rightChild;
        Node * leftChild;
};