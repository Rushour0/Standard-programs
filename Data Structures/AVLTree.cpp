#include <bits/stdc++.h>
#define line cout<<endl;
#define lli long long int
using namespace std;


template <class T> class avltreenode
{
	public:
	T data;							   // Data to be given to the node	
	avltreenode<T> *right,*left,*root; // Keeping track of Root, Left node, Right node of the current node

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

	avltreenode<T>* left_rotate(avltreenode<T> *node_x)
	{
		avltreenode<T> *node_y;
		parent = node_x->root;
		node_y = node_x->right;
		node_x->right = node_y->left;
		node_y->root = node_x->root;
		node_y->left = node_x;
		node_x->root = node_y;
		if (parent == nullptr) this->root = node_y;
		return node_y;
	}

	avltreenode<T>* right_rotate(avltreenode<T> *node_x)
	{
		avltreenode<T> *node_y;
		parent = node_x->root;
		node_y = node_x->left;
		node_x->left = node_y->right;
		node_y->root = node_x->root;
		node_y->right = node_x;
		node_x->root = node_y;
		if (parent == nullptr) this->root = node_y;
		return node_y;
	}

	// Check for rotations

	void recentlyInserted(avltreenode<T> *node)
	{
		stack<avltreenode<T>*> nodeStack;

		while (node != nullptr)
		{

			if (abs(balancefactor(node)) == 2)
			{
				temp = node;
				if (temp->right != nullptr && temp->right == nodeStack.top())
				{
					nodeStack.pop();
					if (temp->right->right != nullptr && temp->right->right == nodeStack.top())
					{
						cout<<temp->data<<" "<<temp->right->data<<" "<<temp->right->right->data<<" rr"<<endl;
						if (temp->root != nullptr && temp->root->right == temp) temp->root->right = left_rotate(temp);
						else if (temp->root != nullptr && temp->root->left == temp) temp->root->left = left_rotate(temp);
						else left_rotate(temp);
					}
					else
					{
						cout<<temp->data<<" "<<temp->right->data<<" "<<temp->right->left->data<<" rl"<<endl;
						temp->right = right_rotate(temp->right);
						if (temp->root != nullptr && temp->root->right == temp) temp->root->right = left_rotate(temp);
						else if (temp->root != nullptr && temp->root->left == temp) temp->root->left = left_rotate(temp);
						else left_rotate(temp);
					}
				}
				else
				{
					nodeStack.pop();
					if (temp->left->left != nullptr && temp->left->left == nodeStack.top())
					{
						cout<<temp->data<<" "<<temp->left->data<<" "<<temp->left->left->data<<" ll"<<endl;
						if (temp->root != nullptr && temp->root->right == temp) temp->root->right = right_rotate(temp);
						else if (temp->root != nullptr && temp->root->left == temp) temp->root->left = right_rotate(temp);
						else right_rotate(temp);
					}
					else
					{
						cout<<temp->data<<" "<<temp->left->data<<" "<<temp->left->right->data<<" lr"<<endl;
						temp->left = left_rotate(temp->left);
						if (temp->root != nullptr && temp->root->right == temp) temp->root->right = right_rotate(temp);
						else if (temp->root != nullptr && temp->root->left == temp) temp->root->left = right_rotate(temp);
						else right_rotate(temp);
					}
				}
				cout<<"done"<<endl;
				return;
			}
			nodeStack.push(node);
			node = node->root;
		}
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

	// Find min or max node in the given subtree 
	avltreenode<T>* minNode(avltreenode<T> *node)
	{
		temp = node;
		if (temp == NULL)
		{
			cout<<"\nNo values in the Binary Tree\n";
			return nullptr;
		}
		while (temp->left!=NULL) temp = temp->left;
		return temp;
	}

	avltreenode<T>* maxNode(avltreenode<T> *node)
	{
		temp = node;

		if (temp == NULL)
		{
			cout<<"\nNo values in the Binary Tree\n";
			return nullptr;
		}
		while (temp->right!=NULL) temp = temp->right;
		return temp;
	}


	// Delete methods - by data and node
	void delNode(avltreenode<T> *node)
	{
		if (node->right != nullptr)	
		{
			temp = minNode(node->right);
			//cout<<"Found Min "<<temp->data<<endl;
			node->data = temp->data;
			extra = temp->root;
			delNode(temp);
			recentlyInserted(extra);
		}
		else if (node->left != nullptr)
		{
			//cout<<"It's the left subtree\n";
			if (node->root->left == node) node->root->left = node->left;
			else node->root->right = node->left;
			node->left->root = node->root;
			extra = node->left;
			free(node);
			recentlyInserted(extra);
		}
		else
		{
			//cout<<"I have no subtrees\n";
			if (node->root->left == node) node->root->left = nullptr;
			else node->root->right = nullptr;
			extra = node->root;
			recentlyInserted(extra);
			free(node);
		}
	}

	// insert value in avl binary tree
	avltreenode<T>* insert(T data)
	{
		temp = new avltreenode<T>(data);
		insertNode(temp);
		return temp;
	}

	// Verify existence of a value in the tree
	bool find(T value)
	{
		return findNode(value) != nullptr;
	}

	// Find min or max in the avl binary tree
	T minValue()
	{
		temp = this->root;
		temp = minNode(temp);
		return temp->data;
	}

	T maxValue()
	{
		temp = this->root;
		temp = maxNode(temp);
		return temp->data;
	}
	
	// Delete methods - by data and node
	void del(T value)
	{
		avltreenode<T> *node = findNode(value);
		delNode(node);
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
	vector<int> vec = {33,53,13,61,9,8,11,21};
	avltree<int> avl;
	for(int& it:vec) avl.insert(it);
	temp = avl.findNode(13);
	avl.delNode(temp);
	cout<<avl.minValue()<<" "<<avl.maxValue()<<endl;
	avl.inorderIterative();
	line
	//avl.inorderRecursive();
	//line
	avl.preorderIterative();
	line
	//avl.preorderRecursive();
	//line
	avl.postorderIterative();
	line
	//avl.postorderRecursive();
	//line
	avl.levelorderIterative();
	line
	//avl.levelorderRecursive();
	return 0;
}