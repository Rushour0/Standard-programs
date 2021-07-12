#include <bits/stdc++.h>
#define line cout<<endl;
#define lli long long int
using namespace std;

template <class T> class avltreenode
{
	public:
	avltreenode<T> *right,*left,*root;
	T data;

	avltreenode(T node_data)
	{
		data = node_data;
		this->right = nullptr;
		this->root = nullptr;
		this->left = nullptr;
	}
};

template <class T> class avltree
{
	private:
	avltreenode<T> *temp,*extra,*parent;

	lli treeheight(avltreenode<T> *node)
	{
		lli l_height,r_height;
		if (node!= nullptr)
		{
			l_height = treeheight(node->left);
			r_height = treeheight(node->right);
			return max(l_height,r_height)+1;
		}
		return 0;
	}

	lli balancefactor(avltreenode<T> *node)
	{
		return treeheight(node->right) - treeheight(node->left);
	}
	
	// Refer https://www.programiz.com/dsa/avl-tree for the logical explanation	

	void left_rotate(avltreenode<T> *node)
	{
		avltreenode<T> *someNode;
		someNode = node->right;
		someNode->root = node->root; // parent of node is now parent of right of the node
		if (node->root == nullptr) this->root = someNode;
		node->root = someNode; // node's root is now the initial node which was it's right
		node->right = someNode->left; // node's right is now set to left of the right of the node
		someNode->left = node; // node's right's left is now set to the node

	}

	void right_rotate(avltreenode<T> *node)
	{
		avltreenode<T> *someNode;
		someNode = node->left;
		someNode->root = node->root; // parent of node is now parent of left of the node
		if (node->root == nullptr) this->root = someNode;
		node->root = someNode; // node's root is now the initial node which was it's left
		node->left = someNode->left; // node's left is now set to right of the left of the node
		someNode->right = node; // node's left's right is now set to the node

	}

	void ll_rotate(avltreenode<T> *node)
	{
		
	}	

	void rr_rotate(avltreenode<T> *node)
	{

	}

	void lr_rotate(avltreenode<T> *node)
	{
		temp = node->right;
		rr_rotate(node);
		ll_rotate(temp);
	}
	
	void rl_rotate(avltreenode<T> *node)
	{
		temp = node->left;
		ll_rotate(node);
		rr_rotate(temp);
	}

	// Check for rotations

	void recentlyInserted(avltreenode<T> *node)
	{
		stack<avltreenode<T>*> nodeStack;
		cout<<balancefactor(node)<<" ";
		nodeStack.push(node);
		while (node != this->root)
		{
			node = node->root;
			nodeStack.push(node);
			cout<<balancefactor(node)<<" ";
			if (abs(balancefactor(node)) == 2)
			{
				temp = node;
				nodeStack.pop();
				cout<<temp->right->data<<" "<<(nodeStack.top())->data;
				if (temp->right == nodeStack.top())
				{
					extra = nodeStack.top();
					nodeStack.pop();
					if (temp->right->right == nodeStack.top())
					{
						rr_rotate(temp);
					}
					else
					{
						rl_rotate(temp);
					}
				}
				else
				{
					extra = nodeStack.top();
					nodeStack.pop();
					if (temp->left->left == nodeStack.top())
					{
						ll_rotate(temp);
					}
					else
					{
						lr_rotate(temp);
					}
				}
				break;
			}
		}
		cout<<endl;
	}

	public:
	avltreenode<T> *root;

	// avltree constructor
	avltree()
	{
		this->root = nullptr;
	}

	// insert node in avl binary tree
	void insertNode(avltreenode<T> *node)
	{
		if (this->root == nullptr)
		{
			this->root = node;
			recentlyInserted(node);
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
		recentlyInserted(node);
		return ;
	}

	// insert value in avl binary tree
	avltreenode<T>* insert(T data)
	{
		temp = new avltreenode<T>(data);
		if (this->root == nullptr)
		{
			this->root = temp;
			recentlyInserted(temp);
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
		recentlyInserted(temp);
		return temp;
	}

	// Find min or max in the avl binary tree
	T minValue()
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

	T maxValue()
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
	avltreenode<T>* findNode(T value)
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

	void delNode(avltreenode<T> *node)
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
		stack<avltreenode<T>*> Stack;
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

	void inorderRecursive(avltreenode<T> *root)
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
		stack<avltreenode<T>*> Stack;
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

	void preorderRecursive(avltreenode<T> *root)
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
		stack<avltreenode<T>*> DecoyStack,Stack;
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

	void postorderRecursive(avltreenode<T> *root)
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
		queue<avltreenode<T>*> Queue;
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
		queue<avltreenode<T>*> Queue;
		Queue.push(this->root);
		levelorderRecursive(Queue);
	}

	void levelorderRecursive(queue<avltreenode<T>*>& Queue)
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
	avltreenode<int> *temp;
	vector<int> vec = {1,4,-1,-2,-32,3,5,67,2,57,38};
	avltree<int> avl;
	for(int& it:vec) avl.insert(it);
	temp = avl.findNode(-32);
	avl.delNode(temp);
	cout<<avl.minValue()<<" "<<avl.maxValue()<<endl;
	return 0;
}