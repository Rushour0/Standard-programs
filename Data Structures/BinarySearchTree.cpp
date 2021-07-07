#include <bits/stdc++.h>
#define line cout<<endl;
using namespace std;

template <class T> class binarysearchtreenode{
	public:
	T data;
	binarysearchtreenode<T> *root,*left,*right;
	binarysearchtreenode()
	{
		this->data = nullptr;
		this->left = nullptr;
		this->right = nullptr;
		this->root = nullptr;
	}
	
	binarysearchtreenode(T node_data)
	{
		this->data = node_data;
		this->left = nullptr;
		this->right = nullptr;
		this->root = nullptr;
	}
};

template <class T>class binarysearchtree{
	private:
	binarysearchtreenode<T> *temp,*extra;

	public:
	binarysearchtreenode<T> *root;
	
	// binarysearchtree constructor
	binarysearchtree()
	{
		this->root = nullptr;
	}

	// insert node in binary tree
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

	// insert value in binary tree
	binarysearchtreenode<T>* insert(T data)
	{
		temp = new binarysearchtreenode<T>(data);
		if (this->root == nullptr)
		{
			this->root = temp;
			return temp;
		}
		else
		{
			extra = this->root;
			while(true)
			{
				if (extra->data < temp->data)
				{
					if (extra->right == nullptr) 
					{
						temp->root = extra;
						extra->right = temp;
						break;
					}
					else extra = extra->right;
				}
				else 
				{
					if (extra->left == nullptr) 
					{
						temp->root = extra;
						extra->left = temp;
						break;
					}
					else extra = extra->left;
				}
			}
		}
		return temp;
	}

	// Find min or max in the binary tree
	T min()
	{
		temp = this->root;
		T *extra = new T();
		if (temp == NULL)
		{
			cout<<"\nNo values in the Binary Tree\n";
			return *extra;
		}
		while (temp->left!=NULL) temp = temp->left;
		return temp->data;
	}

	T max()
	{
		temp = this->root;
		T *extra = new T();
		if (temp == NULL)
		{
			cout<<"\nNo values in the Binary Tree\n";
			return *extra;
		}
		while (temp->right!=NULL) temp = temp->right;
		return temp->data;
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
	
	// Verify existence of a value in the tree
	bool find(T value)
	{
		temp = this->root;
		extra = nullptr;
		
		if (temp == NULL)
		{
			cout<<"\nNo values in the Binary Tree\n";
			return false;
		}

		while(temp!=NULL)
		{
			if (temp->data < value) temp = temp->right;
			else if (temp->data > value) temp = temp->left;
			else return true;
		}
		return false;
	}
	// Delete methods - by data and node
	void del(T value)
	{
		temp = this->root;
		
		if (temp == NULL)
		{
			cout<<"\nNo values in the Binary Tree\n";
			return;
		}

		while(temp!=NULL)
		{
			if (temp->data < value) temp = temp->right;
			else if (temp->data > value) temp = temp->left;
			else if (temp->data == value)
			{
				if (temp->root->left == temp)
				{	
					if (temp->left != nullptr)
					{
						temp->root->left = temp->left;
						temp->left->root = temp->root;
						if (temp->right != nullptr)
						{
							extra = temp->left;
							while(extra->right != nullptr) extra = extra->right;
							temp->right->root = extra;
							extra->right = temp->right;
						}
					}
					else if(temp->right != nullptr)
					{
						temp->root->left = temp->right;
						temp->right->root = temp->root;
					}
					else temp->root->left = nullptr;
				}

				else if (temp->root->right == temp)
				{	
					if (temp->left != nullptr)
					{
						temp->root->right = temp->left;
						temp->left->root = temp->root;
						if (temp->right != nullptr)
						{
							extra = temp->left;
							while(extra->right != nullptr) extra = extra->right;
							temp->right->root = extra;
							extra->right = temp->right;
						}
					}
					else if(temp->right != nullptr)
					{
						temp->root->right = temp->right;
						temp->right->root = temp->root;
					}
					else temp->root->right = nullptr;
				}
				break;
			}
		}
	}

	void delNode(binarysearchtreenode<T> *node)
	{
		if (node == NULL) cout<<"NULL VALUE IS ASKED TO BE DELETED"<<endl;
		temp = this->root;
		
		if (temp == NULL)
		{
			cout<<"\nNo values in the Binary Tree\n";
			return;
		}

		while(temp!=NULL)
		{
			if (temp->data < node->data) temp = temp->right;
			else if (temp->data > node->data) temp = temp->left;
			else if (temp->data == node->data)
			{
				if (temp->root->left == temp)
				{	
					if (temp->left != nullptr)
					{
						temp->root->left = temp->left;
						temp->left->root = temp->root;
						if (temp->right != nullptr)
						{
							extra = temp->left;
							while(extra->right != nullptr) extra = extra->right;
							temp->right->root = extra;
							extra->right = temp->right;
						}
					}
					else if(temp->right != nullptr)
					{
						temp->root->left = temp->right;
						temp->right->root = temp->root;
					}
					else temp->root->left = nullptr;
				}

				else if (temp->root->right == temp)
				{	
					if (temp->left != nullptr)
					{
						temp->root->right = temp->left;
						temp->left->root = temp->root;
						if (temp->right != nullptr)
						{
							extra = temp->left;
							while(extra->right != nullptr) extra = extra->right;
							temp->right->root = extra;
							extra->right = temp->right;
						}
					}
					else if(temp->right != nullptr)
					{
						temp->root->right = temp->right;
						temp->right->root = temp->root;
					}
					else temp->root->right = nullptr;
				}
				break;
			}
		}
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
		temp = this->root;
		queue<binarysearchtreenode<T>*> Queue;
		Queue.push(temp);
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
		levelorderRecursive(this->root);
	}

	void levelorderRecursive(binarysearchtreenode<T> *root)
	{

	}
};

int main()
{
	binarysearchtreenode<int> *temp;
	vector<int> vec = {1,4,-1,-2,-32,3,5,67,2,57,38};
	binarysearchtree<int> bst;
	for(int& it:vec) bst.insert(it);
	temp = bst.findNode(-32);
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
	
	return 0;
}