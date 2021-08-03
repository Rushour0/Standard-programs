#include <iostream>
#include <vector>
#define line cout<<endl;
using namespace std;

// Declaration of Binary Heap Node Class

template <class T> class binaryheapnode
{
	public:
	T data;								  // Data to be given to the node 
	binaryheapnode<T> *root,*left,*right; // Keeping track of Root, Left node, Right node of the current node

	// Default Null Constructor for binary head node

	binaryheapnode()
	{
		this->data = 0 ;
		this->root = nullptr;
		this->left = nullptr;
		this->right = nullptr;
	}
	
	// Initialize the node to some value

	binaryheapnode(T node_data)
	{
		this->data = node_data;
		this->root = nullptr;
		this->left = nullptr;
		this->right = nullptr;
	}
};

// Declaration of Binary Heap Class

template <class T> class binaryheap
{
	private:

	// The heap array of the Binary Heap

	vector<binaryheapnode<T>> heaparray;

	// Extra variables to perform operations on the binary heap

	binaryheapnode<T> *temp;
	int it;

	// Used to decide whether the head is a maxHeap or minHeap

	int heapismax = 0;

	// Internal Operations for the heap

	// Swapping operation of two given nodes

	void swap(binaryheapnode<T>& node1,binaryheapnode<T>& node2)
	{
		temp->data = node1.data;
		node1.data = node2.data;
		node2.data = temp->data;
	}

	// Comparator used to compare values of two given nodes

	bool comparator(binaryheapnode<T>& node1,binaryheapnode<T>& node2)
	{
		if (heapismax) return node1.data <= node2.data;
		return node1.data >= node2.data;
	}

	// Get parent of the element at a given position

	int parent(int i)
	{
		return (i-1)/2;
	}

	// Get left node of the element at a given position

	int left(int i)
	{
		return 2*i+1;
	}

	// Get right node of the element at a given position

	int right(int i)
	{
		return 2*i+2;
	}

	public:

	// Keeping track of the size of the heap

	int heap_size;

	// Initializes the binary heap to minHeap or maxHeap dependant on the passed bool value

	binaryheap(bool heaptype)
	{
		heap_size = 0;
		heapismax = 1*heaptype; 
		cout<<"Heap type is : "<<(!heaptype ? "Min" : "Max") <<endl; 
	}

	// Default Constructor which sets the heap to maxHeap

	binaryheap()
	{
		heap_size = 0;
		heapismax = 1; 
		cout<<"Heap type is : "<<(!heapismax ? "Min" : "Max") <<"\n\n"; 
	}

	// Push data into the binary heap

	binaryheapnode<T>* push(T data)
	{
		heap_size++;
		temp = new binaryheapnode<T>(data);
		cout<<"START : ";this->all();
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
		cout<<endl;
		return temp;
	}

	// Compare the values and make the necessary swaps to make a min/max heap

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

	// Pop the data of top most node (min or max of the heap)

	T pop()
	{

		T val = heaparray[0].data;
		heaparray[0].data = heaparray[heap_size-1].data;
		heaparray.pop_back();heap_size--;
		heapify(0);
		return val;
	}

	// Just return the top most of the Heap

	T peek()
	{
		return heaparray[0].data;
	}
	
	// Print out all elements in the binary heap
	
	void all()
	{
		for(auto& iter: heaparray)cout<<iter.data<<" ";
		cout<<endl;
	}
};


int main()
{
	vector<int> values = {5,3,9,1,6,8};
	binaryheap<int> heap;
	for(int& it:values)heap.push(it);
	cout<<"First Element : "<<heap.peek()<<endl;
	cout<<"All Elements : ";heap.all();
	return 0;
}