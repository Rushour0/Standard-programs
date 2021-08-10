#include <iostream>
#include <vector>
#define line cout<<endl;
using namespace std;

// red black tree node class

template <class T> class redblacktreenode
{
	public:

	// Necessary variables, the right, left and root of the tree

	redblacktreenode<T> *right,*root,*left;
	
	T data; // Storing the data in the node
	bool color;	// Color of the node

	redblacktreenode(T node_data)
	{
		this->data = node_data;
		this->right = nullptr;
		this->left = nullptr;
		this->root = nullptr;
	}
};

template <class T> class redblacktree
{
	private:

	redblacktreenode<T> *temp, *extra;

	
	redblacktreenode<T>* left_rotate(redblacktreenode<T> *node_x)
	{
		redblacktreenode<T> *node_y;					// The other node
		parent = node_x->root;							// Marking parent node of given node
		node_y = node_x->right;							// node_y is pointing to right of node_x
		node_x->right = node_y->left;					
		node_y->root = node_x->root;
		node_y->left = node_x;
		node_x->root = node_y;
		if (parent == nullptr) this->root = node_y;
		return node_y;
	}

	redblacktreenode<T>* right_rotate(redblacktreenode<T> *node_x)
	{
		redblacktreenode<T> *node_y;
		parent = node_x->root;
		node_y = node_x->left;
		node_x->left = node_y->right;
		node_y->root = node_x->root;
		node_y->right = node_x;
		node_x->root = node_y;
		if (parent == nullptr) this->root = node_y;
		return node_y;
	}


	public:

	// Root of the tree
	redblacktreenode<T> *root;

	// redblacktree constructor
	redblacktree()
	{
		this->root = nullptr;
	}


}