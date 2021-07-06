#include <bits/stdc++.h>
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
	
	binarysearchtree()
	{
		this->root = nullptr;
	}

	void insertNode(binarysearchtreenode<T> *node)
	{
		data = node->data;
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

	bool find(T value)
	{
		temp = this->root;
		
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
			}
		}
	}
	
};

int main()
{
	binarysearchtreenode<int> *temp;
	vector<int> vec = {-1,-2,-32,3,4,1,5,67,2,57,38};
	binarysearchtree<int> bst;
	for(int& it:vec) bst.insert(it);
	bst.del(-32);
	cout<<bst.min()<<" "<<bst.max();
	
	return 0;
}