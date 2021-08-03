#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#define line cout<<endl;
using namespace std;

// Declaration of Binary Search Tree Node Class

template <class T> class binarysearchtreenode{
	public:
	T data;										// Data to be given to the node
	binarysearchtreenode<T> *root,*left,*right; // Keeping track of Root, Left node, Right node of the current node
	
	// Default Null Constructor for BST node
	
	binarysearchtreenode()
	{
		this->data = nullptr;
		this->left = nullptr;
		this->right = nullptr;
		this->root = nullptr;
	}
	
	// Initialize the node to some value

	binarysearchtreenode(T node_data)
	{
		this->data = node_data;
		this->left = nullptr;
		this->right = nullptr;
		this->root = nullptr;
	}
};

// Declaration of Binary Search Tree Class

template <class T>class binarysearchtree{
	private:

	// Extra variables to perform operations on the binary search tree

	binarysearchtreenode<T> *temp,*extra;

	public:
	binarysearchtreenode<T> *root;
	
	// binarysearchtree constructor

	binarysearchtree()
	{
		this->root = nullptr;
	}

	// Insert node in binary tree

	void insertNode(binarysearchtreenode<T> *node)
	{
		if (this->root == nullptr)
		{
			this->root = node;
			return ;
		}
		else
		{
			extra = this->root;
			while(true)
			{
				if (extra->data < node->data)
				{
					if (extra->right == nullptr) 
					{
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
						break;
					}
					else extra = extra->left;
				}
			}
		}
		return ;
	}

	// Find node according to data, return null if none found

	binarysearchtreenode<T>* findNode(T value)
	{
		temp = this->root;
		extra = nullptr;
		
		if (temp == NULL)
		{
			cout<<"\nNo values in the Binary Tree\n";
			return extra;
		}

		while(temp!=NULL)
		{
			if (temp->data < value) temp = temp->right;
			else if (temp->data > value) temp = temp->left;
			else return temp;
		}
		return extra;
	}

	// Find min or max node in the given subtree

	binarysearchtreenode<T>* minNode(binarysearchtreenode<T> *node)
	{
		temp = node;
		if (temp == NULL) return nullptr;
		while (temp->left!=NULL) temp = temp->left;
		return temp;
	}

	binarysearchtreenode<T>* maxNode(binarysearchtreenode<T> *node)
	{
		temp = node;
		if (temp == NULL) return nullptr;
		while (temp->right!=NULL) temp = temp->right;
		return temp;
	}

	// Delete method - by node

	void delNode(binarysearchtreenode<T> *node)
	{
		if (node->right != nullptr)	
		{
			temp = minNode(node->right);
			//cout<<"Found Min "<<temp->data<<endl;
			node->data = temp->data;
			extra = temp->root;
			delNode(temp);
			
		}
		else if (node->left != nullptr)
		{
			//cout<<"It's the left subtree\n";
			if (node->root->left == node) node->root->left = node->left;
			else node->root->right = node->left;
			node->left->root = node->root;
			extra = node->left;
			free(node);
			
		}
		else
		{
			//cout<<"I have no subtrees\n";
			if (node->root->left == node) node->root->left = nullptr;
			else node->root->right = nullptr;
			extra = node->root;
			
			free(node);
		}
	}

	// Insert value in binary tree

	binarysearchtreenode<T>* insert(T data)
	{
		temp = new binarysearchtreenode<T>(data);
		insertNode(temp);
		return temp;
	}

	
	// Verify existence of a value in the tree

	bool find(T value)
	{
		return findNode(value) != nullptr;
	}

	// Find min or max in the binary tree

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
		binarysearchtreenode<T> *node = findNode(value);
		delNode(node);
	}

	// Traversal methods

	// Inorder Iterative approach
	void inorderIterative()
	{
		stack<binarysearchtreenode<T>*> Stack;
		temp = this->root;
		while(temp != NULL || !Stack.empty())
		{
			if (temp != NULL)
			{
				Stack.push(temp);
				temp = temp->left;
			}
			else
			{
				temp = Stack.top();
				cout<<temp->data<<" ";
				Stack.pop();
				temp = temp->right;
			}
		}
	}

	// Inorder Recursive approach
	void inorderRecursive()
	{
		inorderRecursive(this->root);
	}

	void inorderRecursive(binarysearchtreenode<T> *root)
	{
		if (root == NULL) return;
		
		temp = root->left;
		inorderRecursive(temp);
		
		cout<<root->data<<" ";

		temp = root->right;
		inorderRecursive(temp);
	}

	// Preorder Iterative approach
	void preorderIterative()
	{
		stack<binarysearchtreenode<T>*> Stack;
		temp = this->root;
		while(temp != NULL || !Stack.empty())
		{
			if (temp != NULL)
			{
				cout<<temp->data<<" ";
				Stack.push(temp);
				temp = temp->left;
			}
			else
			{
				temp = Stack.top();
				Stack.pop();
				temp = temp->right;
			}
		}
	}

	// Preorder Recursive approach
	void preorderRecursive()
	{
		preorderRecursive(this->root);
	}

	void preorderRecursive(binarysearchtreenode<T> *root)
	{
		if (root == NULL) return;
		
		cout<<root->data<<" ";

		temp = root->left;
		preorderRecursive(temp);

		temp = root->right;
		preorderRecursive(temp);
	}

	// Postorder Iterative approach
	void postorderIterative()
	{
		stack<binarysearchtreenode<T>*> DecoyStack,Stack;
		temp = this->root;
		DecoyStack.push(temp);
		while(!DecoyStack.empty())
		{
			temp = DecoyStack.top();
			DecoyStack.pop();
			Stack.push(temp);
			if (temp->left != nullptr) DecoyStack.push(temp->left);
			if (temp->right != nullptr) DecoyStack.push(temp->right);
		}	
		while (!Stack.empty())	
		{
			temp = Stack.top();
			Stack.pop();
			cout<<temp->data<<" ";
		}
	}

	// Postorder Recursive approach
	void postorderRecursive()
	{
		postorderRecursive(this->root);
	}

	void postorderRecursive(binarysearchtreenode<T> *root)
	{
		if (root == NULL) return;

		temp = root->left;
		postorderRecursive(temp);

		temp = root->right;
		postorderRecursive(temp);

		cout<<root->data<<" ";
	}

	// Levelorder Iterative approach
	void levelorderIterative()
	{
		queue<binarysearchtreenode<T>*> Queue;
		Queue.push(this->root);
		while(!Queue.empty())
		{
			temp = Queue.front();
			cout<<temp->data<<" ";
			Queue.pop();
			if (temp->left != nullptr) Queue.push(temp->left);
			if (temp->right != nullptr) Queue.push(temp->right);
		}
	}

	// Levelorder Recursive approach
	void levelorderRecursive()
	{
		queue<binarysearchtreenode<T>*> Queue;
		Queue.push(this->root);
		levelorderRecursive(Queue);
	}

	void levelorderRecursive(queue<binarysearchtreenode<T>*>& Queue)
	{
		temp = Queue.front();
		cout<<temp->data<<" ";
		Queue.pop();
		if (temp->left != nullptr) Queue.push(temp->left);
		if (temp->right != nullptr) Queue.push(temp->right);
		if (!Queue.empty()) levelorderRecursive(Queue);
	}
};

int main()
{
	binarysearchtreenode<int> *temp;
	vector<int> vec = {33,53,13,61,9,8,11,21};
	binarysearchtree<int> bst;
	for(int& it:vec) bst.insert(it);
	temp = bst.findNode(13);
	bst.delNode(temp);
	cout<<bst.min()<<" "<<bst.max()<<endl;
	bst.inorderIterative();
	line
	bst.inorderRecursive();
	line
	bst.preorderIterative();
	line
	bst.preorderRecursive();
	line
	bst.postorderIterative();
	line
	bst.postorderRecursive();
	line
	bst.levelorderIterative();
	line
	bst.levelorderRecursive();
	
	return 0;
}