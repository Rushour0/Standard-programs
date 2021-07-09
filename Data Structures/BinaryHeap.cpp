#include <bits/stdc++.h>
#define line cout<<endl;
using namespace std;

template <class T> class binaryheapnode
{
	public:
	T data;
	binaryheapnode<T> *root,*left,*right;

	binaryheapnode(T node_data)
	{
		this->data = node_data;
		this->root = nullptr;
		this->left = nullptr;
		this->right = nullptr;
	}
	binaryheapnode()
	{
		this->data = 0 ;
		this->root = nullptr;
		this->left = nullptr;
		this->right = nullptr;
	}
};

template <class T> class binaryheap
{
	private:
	vector<binaryheapnode<T>> heaparray;

	binaryheapnode<T> *temp;
	int it;
	int heapismax = 0;

	void swap(binaryheapnode<T>& node1,binaryheapnode<T>& node2)
	{
		temp->data = node1.data;
		node1.data = node2.data;
		node2.data = temp->data;
	}

	bool comparator(binaryheapnode<T>& node1,binaryheapnode<T>& node2)
	{
		if (heapismax) return node1.data <= node2.data;
		return node1.data >= node2.data;
	}

	int parent(int i)
	{
		return (i-1)/2;
	}

	int left(int i)
	{
		return 2*i+1;
	}

	int right(int i)
	{
		return 2*i+2;
	}

	public:
	int heap_size;
	binaryheap(bool heaptype)
	{
		heap_size = 0;
		heapismax = 1*heaptype; 
		cout<<"Heap type is : "<<(!heaptype ? "Min" : "Max") <<endl; 
	}

	binaryheap()
	{
		heap_size = 0;
		heapismax = 1; 
		cout<<"heap type is : "<<(!heaptype ? "Min" : "Max") <<endl; 
	}

	binaryheapnode<T>* push(T data)
	{
		heap_size++;
		temp = new binaryheapnode<T>(data);
		cout<<"INITIAL : ";this->all();
		if (heaparray.size() == 0) 
		{
			heaparray.push_back(*temp);
		}
		else 
		{
			heaparray.push_back(*temp);
			it = heaparray.size()-1;
			while (true)
			{
				if(comparator(heaparray[parent(it)],heaparray[it]))
				{
					swap(heaparray[parent(it)],heaparray[it]);
					it = parent(it);
				}
				else break;
				if (it == 0 && parent(it) == 0) break;

			}
		}
		cout<<"FINAL : ";this->all();
		return temp;
	}

	void heapify(int start)
	{
		int l = left(start),r = right(start),toSwap = start;

		if (l < heap_size && comparator(heaparray[start],heaparray[l])) toSwap = l;
		if (r < heap_size && comparator(heaparray[toSwap],heaparray[r])) toSwap = r;
		if (toSwap!=start)
		{
			swap(heaparray[start],heaparray[toSwap]);
			heapify(toSwap);
		}
	}

	T pop()
	{

		T val = heaparray[0].data;
		heaparray[0].data = heaparray[heap_size-1].data;
		heaparray.pop_back();heap_size--;
		heapify(0);
		return val;
	}

	void all()
	{
		for(auto& iter: heaparray)cout<<iter.data<<" ";
		cout<<endl;
	}
};


int main()
{
	cout<<"Hello World!\n";
	vector<int> values = {5,3,9,1,6,8};
	binaryheap<int> heap();
	for(int& it:values)heap.push(it);
	cout<<heap.pop()<<endl;
	heap.all();
	return 0;
}