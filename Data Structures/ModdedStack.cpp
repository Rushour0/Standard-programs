#include <bits/stdc++.h>
using namespace std;

template <class T> class stacknode
{
    public:
    T data;
    stacknode<T> *next;
    stacknode()
    {
        this->data = nullptr;
        this->next = nullptr;
    }
    
    stacknode(T node_data)
    {
        this->data = node_data;
        this->next = nullptr;
    }
};

template <class T> class moddedstack
{
    private:
    stacknode<T> *temp;
    moddedstack<T> *otherStack;
    public:
    stacknode<T> *head,*tail;
    moddedstack()
    {
        this->head = nullptr;
        this->tail = nullptr;
    }
    
    void push(T data)
    {
        temp = new stacknode<T>(data);
        
        if (this->head == nullptr) this->tail = temp;
        else temp->next = this->head;
        
        this->head = temp;
    }
    
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
    
    T& top()
    {
        return this->head->data;
    }

    T& bottom()
    {
        return this->tail->data;
    }
    
    bool empty()
    {
        return (this->head == nullptr );
    }
    
    void mergestack(moddedstack<T> MyStack)
    {
        otherStack = &MyStack;
        this->tail->next = otherStack->head;
        this->tail = otherStack->tail;
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

    Stack.mergestack(MergeStack);

    cout<<Stack.top()<<" "<<Stack.bottom()<<endl;
    
    while (!Stack.empty()){
        cout<<Stack.top()<<" ";
        Stack.pop();
    }
     
    return 0;
}