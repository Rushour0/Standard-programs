#include <bits/stdc++.h>
using namespace std;

// Declaration of Singly Linked List Node Class

template <class T> class singlylinkedlistnode{
    public:
    T data;                        // Data stored in the node
    singlylinkedlistnode<T> *next; // To specify the next node in line of this current node

    // Initialize to a null value

    singlylinkedlistnode()
    {
        this->data = NULL;
        this->next = nullptr;
    }
    
    // Initialize the node to some value

    singlylinkedlistnode(T node_data)
    {
        this->data = node_data;
        this->next = nullptr;
    }
};

// Declaration of Singly Linked List Class

template <class T> class singlylinkedlist{

    private:

    // extra private variables required to perform operations on the linked list

    singlylinkedlistnode<T> *temp,*extra;
    unsigned long long int length = 0;
    
    public:

    // head and tail of the Singly Linked List

    singlylinkedlistnode<T> *head,*tail;

    // Default Constructor sets head and tail to nullptr
    singlylinkedlist()
    {
        this->head = nullptr;
        this->tail = nullptr;
    }
    
    // Constructor to initialize the linked list with a value

    singlylinkedlist(T node_data)
    {
        this->head = node_data;
        this->tail = node_data;
    }
    
    // Returns size of the linked list (number of nodes in the list)

    unsigned long long int size()
    {
    	return length;
    }

    // Push data to the tail of the list

    void push(T data)
    {
        temp = new singlylinkedlistnode<T>(data);
        
        if (this->head == nullptr) this->head = temp;
        else this->tail->next = temp;

        this->tail = temp;
        
        length++;
    }

    // Insert given data at a certain position in the linked list

    void insert(unsigned long long int position,T data)
    {
        unsigned long long int count = 0;

        if (position>length || position<0)
        {
            cout<<endl<<"Given position is out of bounds"<<endl;
            return;
        }

        extra = new singlylinkedlistnode<T>(data);

        if (position == 0)
        {
            extra->next = this->head;
            this->head = extra;
            length++;
            return;
        }

        if (position == length)
        {
            (*this).push(data);
            return;
        }
        temp = this->head;
    
        while(true)
        {
            if (++count == position)
            {
                extra->next = temp->next;
                temp->next = extra;
                break;
            }
            temp = temp->next;
        }
        length++;
    }

    // Pop the last element in the list

    void pop()
    {
    	temp = this->head;

    	if (temp == NULL)
    	{
    		cout<<"Linked List is empty"<<endl;
    		return ;	
    	}

    	if (temp == this->tail)
    	{
    		this->head = nullptr;
    		this->tail = nullptr;
            free(temp);
    	}
    	
    	while(true)
    	{
    		if (temp->next == this->tail)
    		{
                extra = temp->next;
    			this->tail = temp;
    			temp->next = nullptr;
                free(extra);
    			break;
    		}
    		temp = temp->next;
    	}
    	length--;
    }

    // Pop the node at a certain position (Delete operation)

    void pop(unsigned long long int position)
    {
    	unsigned long long int count = 0;
    	
    	if (position>=length || position<0)
    	{
    		cout<<endl<<"Given position is out of bounds"<<endl;
    		return;
    	}

    	if (position == 0)
    	{
    		this->head = this->head->next;
    		if (length-- == 1)
    		{
    			this->tail = nullptr;
    		}
    		return ;
    	}

    	temp = this->head;
    	while (true)
    	{
    		if (position == ++count)
    		{
                if(temp->next == this->tail) 
                {
                    this->tail = temp;
                    this->tail->next = nullptr;
                }
                else temp->next = temp->next->next;
    			break;
    		}
    		temp = temp->next;
    	}
    	length--;
    }

    // Using the [] operator to access elements/nodes in the Linked List according to their position

    T& operator[](unsigned long long int position)
    {
    	unsigned long long int count = 0;
    	
    	T *ret = new T();
    	if (position>=length)
    	{
    		cout<<endl<<"Given position is out of bounds"<<endl;

    		return *ret;
    	}

    	temp = this->head;
    	while(true)
    	{
    		if (count++ == position)
    		{
    			return temp->data;;
    		}
    		temp = temp->next;
    	}
    }
};


int main()
{
	vector<int> vec(10000,1);
	singlylinkedlist<int> sll;
	for(int& it:vec)sll.push(it);
    for(int i = 0;i<sll.size();i++)cout<<sll[i]<<" ";
    sll.insert(9999,33);
    cout<<endl;
    for(int i = 0;i<sll.size();i++)cout<<sll[i]<<" ";
	cout<<endl;

	return 0;
}