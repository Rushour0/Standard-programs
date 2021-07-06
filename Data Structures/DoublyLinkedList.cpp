#include <bits/stdc++.h>
using namespace std;

template <class T> class doublylinkedlistnode{
    public:
    T data;
    doublylinkedlistnode<T> *next,*prev;
    doublylinkedlistnode()
    {
        this->next = nullptr;
        this->prev = nullptr;
    }
    
    doublylinkedlistnode(T node_data)
    {
        this->data = node_data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

template <class T> class doublylinkedlist{

    private:
    doublylinkedlistnode<T> *temp,*extra;
    unsigned long long int length = 0;
    
    public:
    doublylinkedlistnode<T> *head,*tail;

    doublylinkedlist()
    {
        this->head = nullptr;
        this->tail = nullptr;
    }
    
    doublylinkedlist(T node_data)
    {
        this->head = node_data;
        this->tail = node_data;
    }
    
    unsigned long long int size()
    {
    	return length;
    }

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

    void popNode(doublylinkedlistnode<T> *node)
    {
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }

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