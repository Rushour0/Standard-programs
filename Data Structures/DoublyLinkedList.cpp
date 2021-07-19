#include <bits/stdc++.h>
using namespace std;

// Declaration of Doubly Linked List Node Class

template <class T> class doublylinkedlistnode{
    public:
    T data;                              // Data to be given to the node   
    doublylinkedlistnode<T> *next,*prev; // Keeping track of the previous and next node in the Doubly Linked List
    
    // Default Null Constructor for the Doubly Linked List Node

    doublylinkedlistnode()
    {
        this->next = nullptr;
        this->prev = nullptr;
    }
    
    // Initializes Doubly Linked List Node to a given value

    doublylinkedlistnode(T node_data)
    {
        this->data = node_data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

// Declaration of Doubly Linked List Node Class

template <class T> class doublylinkedlist{

    private:

    // Extra variables used to perform operations on the doubly linked list

    doublylinkedlistnode<T> *temp,*extra;
    unsigned long long int length = 0;
    
    public:

    // Head and tail of the Doubly Linked List

    doublylinkedlistnode<T> *head,*tail;

    // Default Null Constructor for the Doubly Linked List

    doublylinkedlist()
    {
        this->head = nullptr;
        this->tail = nullptr;
    }
    
    // Initializes Doubly Linked List to a given value as its head

    doublylinkedlist(T node_data)
    {
        this->head = node_data;
        this->tail = node_data;
    }
    
    // Returns the size of the Doubly Linked list

    unsigned long long int size()
    {
    	return length;
    }

    // Push data to the tail of the list

    doublylinkedlistnode<T>* push(T data)
    {
        temp = new doublylinkedlistnode<T>(data);
        
        if (this->head == nullptr) this->head = temp;
        else 
        {
            temp->prev = this->tail;
            this->tail->next = temp;
        }

        this->tail = temp;
        
        length++;
        return temp;
    }

    // Insert given data at a certain position in the linked list

    doublylinkedlistnode<T>* insert(unsigned long long int position,T data)
    {
        unsigned long long int count = 0;

        extra = new doublylinkedlistnode<T>(data);
        if (position>length || position<0)
        {
            cout<<endl<<"Given position is out of bounds"<<endl;
            return extra;
        }

        else if (position == 0)
        {
            this->head->prev = extra;
            extra->next = this->head;
            this->head = extra;
            length++;
            return extra;
        }

        else if (position == length)
        {
            (*this).push(data);
            return extra;
        }
        temp = this->head;
    
        while(true)
        {
            if (++count == position)
            {
                extra->prev = temp;
                extra->next = temp->next;
                temp->next->prev = extra;
                temp->next = extra;
                break;
            }
            temp = temp->next;
        }
        length++;
        return extra;
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
            return ;
    	}
        else 
        {
            this->tail->prev->next = nullptr;
            this->tail = this->tail->prev;
        }
        length--;
        
    }

    // Pop the node at a certain position (Delete operation)

    void pop(unsigned long long int position)
    {
    	unsigned long long int count = 0;
    	
    	if (position>=length)
    	{
    		cout<<"Given position is out of bounds"<<endl;
    		return;
    	}

    	if (position == 0)
    	{
            
    		if (length-- == 1)
    		{
                this->head = nullptr;
    			this->tail = nullptr;
    		}
            this->head->next->prev = nullptr;
            this->head = this->head->next;
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
                else 
                {
                    temp->next = temp->next->next;
                    temp->next->next->prev = temp;
                }
    			break;
    		}
    		temp = temp->next;
    	}
    	length--;
    }

    // Pop a particular node in the linked list

    void popNode(doublylinkedlistnode<T> *node)
    {
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }

    // Using the [] operator to access elements/nodes in the Linked List according to their position
    
    T& operator[](unsigned long long int position)
    {
    	unsigned long long int count = 0;
    	
    	T *ret = new T();
    	if (position>=length)
    	{
    		cout<<"Given position is out of bounds"<<endl;

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
	vector<int> vec(3,1);
    doublylinkedlist<int> dll;
    doublylinkedlistnode<int> *temp;
    for(int& it:vec) dll.push(it);
    for(int i = 0;i<dll.size();i++)cout<<dll[i]<<" ";
    temp = dll.insert(2,33);
    cout<<endl;
    cout<<temp->data<<endl;
    for(int i = 0;i<dll.size();i++)cout<<dll[i]<<" ";
    cout<<endl;
    dll.popNode(temp);
    for(int i = 0;i<dll.size();i++)cout<<dll[i]<<" ";
    cout<<endl;

	return 0;
}