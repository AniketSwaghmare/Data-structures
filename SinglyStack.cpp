#include<iostream>
using namespace std;

template<class T>
struct node
{
    T data;
    struct node *next;
};

template<class T>
class stack
{
    public:
    struct node<T>*Head;
    int Count;

    stack();
    void Push(T);       //InsertFirst
    void Pop();         //DeleteFirst
    void InsertLast(T);
    void Display();
    int countNode();
};

template<class T>
stack<T>::stack()
{
    Head = NULL;
    Count = 0;
}

template<class T>
void stack<T>:: Push(T No)
{
    struct node<T> *newn = NULL;
    newn = new node<T>;
    newn->data = No;
    newn->next = NULL;

    newn->next = Head;
    Head = newn;

    Count++;
}


template<class T>
void stack<T>::Pop()
{
    T No;
    if(Count == 0)
    {
        cout<<"Stack is Empty"<<endl;
    }
    if(Count == 1)
    {
        No = Head->data;
        delete Head;
        Head = NULL;
        Count--;

        cout<<"Removed Element is :"<<No<<endl;
    }

    No = Head->data;
    struct node<T>*temp = Head;
    Head = Head->next;
    delete temp;
    Count--;;
    cout<<"Removed Element is :"<<No<<endl;
}

template<class T>
 void  stack<T>:: Display()
 {
    cout<<"Elements from stack are : "<<endl;
    struct node<T> *temp = Head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
 }
template<class T>
int  stack<T>:: countNode()
{
    return Count;
}

int main()
{
    stack<char>obj1;
    obj1.Push('A');
    obj1.Push('B');
    obj1.Push('C');
    obj1.Push('D');

    obj1.Display();

    obj1.Pop();
    obj1.Pop();
    obj1.Display();

    obj1.Push('Z');
    obj1.Pop();

    return 0;
}
