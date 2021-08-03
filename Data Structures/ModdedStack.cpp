#include <iostream>
#include <vector>
using namespace std;

// Declaration of Stack Node Class

template <class T> class stacknode
{
    public:
    T data;             // Data of the given node
    stacknode<T> *next; // To specify the next node in the stack

    // Default Null Constructor for stacknode
    
    stacknode()
    {
        this->data = nullptr;
        this->next = nullptr;
    }
    
    // Initialize the stacknode to given a data

    stacknode(T node_data)
    {
        this->data = node_data;
        this->next = nullptr;
    }
};

// Declaration of Stack Class
// Modded Stack because STL already has a stack class 
// This class contains extra feature of keeping track of the bottom of the stack 
// Extra feature of merging two stacks ie keep one stack on another

template <class T> class moddedstack
{
    private:

    // extra private variables required to perform operations on the modded stack

    stacknode<T> *temp;
    moddedstack<T> *otherStack;

    // Head(Top) and tail(bottom) of the stack
    stacknode<T> *head,*tail;

    public:
    
    // Default Null Constructor

    moddedstack()
    {
        this->head = nullptr;
        this->tail = nullptr;
    }
    
    // Pushes data on to the top of the stack

    void push(T data)
    {
        temp = new stacknode<T>(data);
        
        if (this->head == nullptr) this->tail = temp;
        else temp->next = this->head;
        
        this->head = temp;
    }
    
    // Pops the top most element in the stack

    void pop()
    {
        temp = this->head;
        if (this->head == this->tail)
        {
            this->head = nullptr;
            this->tail = nullptr;
        }
        else this->head = this->head->next;
        free(temp);
    }
    
    // Returns the data in the top most node

    T& top()
    {
        // if (this->head == nullptr) return NULL;
        return this->head->data;
    }

    // Returns the data in the bottom most node

    T& bottom()
    {
        // if (this->head == nullptr) return NULL;
        return this->tail->data;
    }
    
    // Returns a boolean on whether the stack is empty or not

    bool empty()
    {
        return (this->head == nullptr);
    }
    
    // Method to merge two stacks

    void mergestack(moddedstack<T> MyStack)
    {
        otherStack = &MyStack;
        this->tail->next = otherStack->head;
        this->tail = otherStack->tail;
    }

    // Using + operator to merge two stacks in the given order

    moddedstack<T>& operator+(moddedstack<T> MyStack)
    {
        otherStack = &MyStack;
        this->tail->next = otherStack->head;
        this->tail = otherStack->tail;
        return *this;
    }
};


int main()
{
    moddedstack<int> Stack,MergeStack;
    vector<int> vec = {1,2,3,4,5,6,7,8,9};

    for(int& it:vec){
        Stack.push(it);
        MergeStack.push(-it);
    }

    Stack = Stack+MergeStack;

    cout<<Stack.top()<<" "<<Stack.bottom()<<endl;
    
    while (!Stack.empty()){
        cout<<Stack.top()<<" ";
        Stack.pop();
    }
     
    return 0;
}