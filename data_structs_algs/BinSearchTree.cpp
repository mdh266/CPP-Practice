#include<iostream>
#include<cmath>

using namespace std;

template <typename E>
class BinTreeNode
{
	public:
		/// The node's value.
		E 	it;
		// Pointer to left child.
		BinTreeNode * lc;
		/// Pointer to right child.
		BinTreeNode * rc;

	public:
		/** Default constructor.*/
		BinTreeNode()
		{ 
			lc = rc = NULL;
		}
		/** With initial values.*/
		BinTreeNode(E e, BinTreeNode * l=NULL, BinTreeNode * r=NULL)
		{
			it = e; lc = l; rc = r;
		}
		/** Destructor.*/
		~BinTreeNode()
		{}

		/** Returns the node's value.*/
		E& element()
		{
			return it;
		}
		/** Set the nodes value.*/

		void setElement(const E& e)
		{
			it = e;
		}
		bool isLeaf()
		{
			return ( (lc==NULL) && (rc==NULL) );
		}
};

template<typename E>
class BinaryTree
{
	/// Private data 
	private:
		BinTreeNode<E>  * root;
	
	/// Public data and methods
	public:
		BinaryTree()
		{
			root = NULL;
		}

		~BinaryTree()
		{
		}

		bool isEmpty()
		{
			return (root == NULL);
		}

		void add(E e)
		{
			// handle case where just started the tree
			if(root == NULL)
				root = new BinTreeNode<E>(e);
			else
				insert(root,e);
		}

		int NumNodes()
		{
			return NumNodes(root);
		}	

		void PreOrder()
		{
			PreOrder(root);
			std::cout << std::endl;
		}		
		
		void InOrder()
		{
			InOrder(root);
			std::cout << std::endl;
		}	
	
		void PostOrder()
		{
			PostOrder(root);
			std::cout << std::endl;
		}	

		int Height()
		{
			return Height(root);
		}
		
		void print()
		{
			printNode(root);
		}

		bool find(E e)
		{
			return find(root,e);
		}

		bool remove(E e)
		{
			return removeNode(root,e);
		}

	/// Private methods
	private:
		
		int NumNodes(BinTreeNode<E> * root)
		{
			if(root == NULL)
				return 0;
			else
				return 1 + NumNodes(root->lc) + NumNodes(root->rc);
		}
		
		int Height(BinTreeNode<E> * root)
		{
			if(root == NULL)
				return 0;
			else
				return 1 + std::max(Height(root->lc), Height(root->rc));
		}

		void insert(BinTreeNode<E> * root, E & e)
		{
			if (root->element() > e)
			{
				if( root->lc == NULL )
					root->lc = new BinTreeNode<E>(e);
				else
					insert(root->lc, e);
			}
			else // root->element <= 
			{
				if( root->rc == NULL )
					root->rc = new BinTreeNode<E>(e);
				else
					insert(root->rc, e);
			}
		}

		void PreOrder(BinTreeNode<E> * root)
		{
			if(root == NULL)
				return;
				
			std::cout << root->element() << " " ;
			PreOrder(root->lc);
			PreOrder(root->rc);
		}

		void InOrder(BinTreeNode<E> * root)
		{
			if(root == NULL)
				return;
				
			InOrder(root->lc);
			std::cout << root->element() << " " ;
			InOrder(root->rc);
		}
	
		void PostOrder(BinTreeNode<E> * root)
		{
			if(root == NULL)
				return;
				
			PostOrder(root->lc);
			PostOrder(root->rc);
			std::cout << root->element() << " ";
		}

		void printNode(BinTreeNode<E> * root)
		{
			std::cout << "node " << root->element() << std::endl;
			std::cout << "left " << root->lc->element() << std::endl;
			std::cout << "right " << root->rc->element() << std::endl;
		}
		

		bool find(BinTreeNode<E> * root, E & e)
		{
			if(root == NULL)
			 	return false;
			else if(e < root->element() )
				return find(root->lc, e);
			else if(e > root->element() )
				return find(root->rc, e);
			else
				return true; // its found! 
		}

		BinTreeNode<E> * findMin(BinTreeNode<E> *  root)
		{
			// left most child will be smallest
			if(root->lc == NULL)
				return root;
			else
				return findMin(root->lc);
		}

		BinTreeNode<E> * deleteMin(BinTreeNode<E> * root)
		{
			if(root->lc == NULL) // found min and return right
				return root->rc; // if rc = NULL, then this is fine
			else
			{	// continue left
				// new left child is now the right child of descendent!
				root->lc = deleteMin(root->lc); 
				return root; // return all the other nodes as usual
			}
		}
		
		
		bool removeNode(BinTreeNode<E> * root, E & e)
		{
			// first find it.
			if( root == NULL)
				return false;
			else if( root->it > e)
				return removeNode(root->lc,e);
			else if ( root->it < e) 
				return removeNode(root->rc,e);
			else
			{	// now that we have found the node we need to delete in cases.
				BinTreeNode<E> * temp = root;
				// 1.) root is a leaf or left child is NULL
				if(root->lc == NULL)
				{
					root = root->rc;  // if rc == null, then sets current node to null
					delete temp;      // => handles case where node is leaf
				}
				// 2.) root is a leaf or right child is NULL
				else if(root->rc == NULL) 
				{
					root = root->lc;
					delete temp;
				}
				else // 3.) both children are non-NULL
				{
					// find the minimum value on right subtree and copy value over to
					// root with it!
					temp = findMin(root->rc);
					root->it = temp->it;
					// now delete that node just copied over and if not a leaf set 
					// its parent = to its right child
					root->rc = deleteMin(root->rc);
					delete temp;
				
				}
			}
			return true;
		}				
					
	
			
};

		

int main()
{
	BinaryTree<int> * BinTree = new BinaryTree<int>();

	// 				5
	//			   / \
	//			  2   6
	//			 / \ / \
	//			1  3 5  7
			
	BinTree->add(5);
	BinTree->add(2);
	BinTree->add(1);	
	BinTree->add(3);
	BinTree->add(6);
	BinTree->add(5);
	BinTree->add(7);

	std::cout << "PreOrder = ";
	BinTree->PreOrder();

	std::cout << "PostOrder = ";
	BinTree->PostOrder();

	std::cout << "InOrder = ";
	BinTree->InOrder();

	std::cout << "Nodes = " << BinTree->NumNodes() << std::endl;
	std::cout << "Height = " << BinTree->Height() << std::endl;

	std::cout << "Found == " << BinTree->find(9) << endl;

	std::cout << "Remove 2 == " << BinTree->remove(2) << endl;

	std::cout << "InOrder = ";
	BinTree->InOrder();

	return 0;
}

