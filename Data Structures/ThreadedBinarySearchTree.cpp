#include <bits/stdc++.h>
#define line cout<<endl;
using namespace std;

// Declaration of threadedbinary Search Tree Node Class

template <class T> class threadedbinarysearchtreenode{
	public:
	T data;										// Data to be given to the node
	threadedbinarysearchtreenode<T> *root,*left,*right; // Keeping track of Root, Left node, Right node of the current node
	bool rightThread;
	
	// Default Null Constructor for tbst node
	
	threadedbinarysearchtreenode()
	{
		this->data = nullptr;
		this->left = nullptr;
		this->right = nullptr;
		this->root = nullptr;
		this->rightThread = false;
	}
	
	// Initialize the node to some value

	threadedbinarysearchtreenode(T node_data)
	{
		this->data = node_data;
		this->left = nullptr;
		this->right = nullptr;
		this->root = nullptr;
		this->rightThread = false;
	}
};

// Declaration of threadedbinary Search Tree Class

template <class T>class threadedbinarysearchtree{
	private:

	// Extra variables to perform operations on the threadedbinary search tree

	threadedbinarysearchtreenode<T> *temp,*extra;

	public:

	// Root of the binary tree

	threadedbinarysearchtreenode<T> *root;
	
	// threadedbinarysearchtree constructor

	threadedbinarysearchtree()
	{
		this->root = nullptr;
	}


	// Node based methods

	// Insert node in threadedbinary tree

	void insertNode(threadedbinarysearchtreenode<T> *node)
	{
		if (this->root == nullptr)
		{
			this->root = node;
			return ;
		}
		else
		{
			// Here extra is the parent node

			extra = this->root;
			while(true)
			{
				if (extra->data < node->data)
				{
					if (extra->rightThread || extra->right == nullptr) 
					{
						if (extra->rightThread)
						{
							extra->rightThread = false;
							node->rightThread = true;
							node->right = extra->right;
						}
						node->root = extra;
						extra->right = node;
						break;
					}
					else extra = extra->right;
				}
				else 
				{
					if (extra->left == nullptr) 
					{
						node->root = extra;
						extra->left = node;
						node->rightThread = true;
						node->right = extra;
						break;
					}
					else extra = extra->left;
				}
			}
		}
		return ;
	}

	// Find node according to data, return null if none found

	threadedbinarysearchtreenode<T>* findNode(T value)
	{
		temp = this->root;
		extra = nullptr;
		
		if (temp == NULL)
		{
			cout<<"\nNo values in the threadedbinary Tree\n";
			return extra;
		}

		while( temp != NULL )
		{
			if (temp->data < value) temp = temp->right;
			else if (temp->data > value) temp = temp->left;
			else return temp;
		}
		return extra;
	}

	// Find min or max node in the given subtree

	threadedbinarysearchtreenode<T>* minNode(threadedbinarysearchtreenode<T> *node)
	{
		temp = node;
		if (temp == NULL) return nullptr;
		while (temp->left!=NULL) temp = temp->left;
		return temp;
	}

	threadedbinarysearchtreenode<T>* maxNode(threadedbinarysearchtreenode<T> *node)
	{
		temp = node;
		if (temp == NULL) return nullptr;
		while (temp->right!=NULL) temp = temp->right;
		return temp;
	}

	// Delete method - by node

	void delNode(threadedbinarysearchtreenode<T> *node)
	{
		if (node->right != nullptr && !(node->rightThread))
		{
			temp = minNode(node->right);
			node->data = temp->data;
			delNode(temp);
			return;
			
		}
		else if (node->left != nullptr)
		{
			if (node->root->left == node) node->root->left = node->left;
			else node->root->right = node->left;
			node->left->root = node->root;

			
		}
		else
		{
			if (node->root->left == node ) node->root->left = nullptr;
			else 
			{
				node->root->right = node->right;
				if (node->rightThread) node->root->rightThread = true;
			}
			
		}
		
		free(node);
	}

	// Value based methods

	// Insert value in threadedbinary tree

	threadedbinarysearchtreenode<T>* insert(T data)
	{
		temp = new threadedbinarysearchtreenode<T>(data);
		insertNode(temp);
		
		return temp;
	}

	// Verify existence of a value in the tree

	bool find(T value)
	{
		return findNode(value) != nullptr;
	}

	// Find min or max in the threadedbinary tree

	T min()
	{
		temp = this->root;
		temp = minNode(temp);
		return temp->data;
	}

	T max()
	{
		temp = this->root;
		temp = maxNode(temp);
		return temp->data;
	}
	

	// Delete method - by data

	void del(T value)
	{
		threadedbinarysearchtreenode<T> *node = findNode(value);
		delNode(node);
	}

	// Traversal methods

	// Inorder Iterative approach
	void inorderTraversal()
	{
		temp = minNode(root);

		while (temp != NULL)
		{
			cout<<temp->data<<" ";

			if (temp->rightThread) temp = temp->right;

			else temp = minNode(temp->right);
		}

	}
	
};

int main()
{
	threadedbinarysearchtreenode<int> *temp;
	vector<int> vec = {33,53,13,61,9,8,11,21};
	threadedbinarysearchtree<int> tbst;
	for(int& it:vec) tbst.insert(it);
	temp = tbst.findNode(13);
	tbst.delNode(temp);
	cout<<tbst.min()<<" "<<tbst.max()<<endl;
	tbst.inorderTraversal();
	line
	
	return 0;
}