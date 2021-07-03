#include <bits/stdc++.h>
using namespace std;

template <typename T> class linkedlistnode{
    public:
    T data;
    linkedlistnode *next;
    linkedlistnode()
    {
        this->data = nullptr;
        this->next = nullptr;
    }
    
    linkedlistnode(T node_data)
    {
        this->data = node_data;
        this->next = nullptr;
    }
};

template <typename T> class linkedlist{
    private:
    linkedlistnode *temp;
    
    public:
    linkedlistnode *head,*tail;
    linkedlist()
    {
        this->head = nullptr;
        this->tail = nullptr;
    }
    
    linkedlistnode(T node_data)
    {
        this->head = node_data;
        this->tail = node_data;
    }
    
    void push(T data)
    {
        temp = new linkedlistnode(data);
        this->tail->next = temp;
        this->tail = temp;
    }
};

