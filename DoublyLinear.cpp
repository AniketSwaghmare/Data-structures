#include<iostream>
using namespace std;

template<class T>

struct node
{
    T data;
    struct node *next;
    struct node *prev;

};

template<class T>
class DoublyCLL
{
    public:
        struct node<T> *Head;
        int Count;

        DoublyCLL();
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,T);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(T);
        void Display();
        int countNode();
};

template<class T>
DoublyCLL<T>::DoublyCLL()
{
    Head = NULL;
    Count = 0;
}


template<class T>
void DoublyCLL<T>::InsertFirst(T no)
{
    struct node<T>*newn = NULL;
    newn = new node<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
        newn->next = Head;
        Head->prev = newn;
        Head = newn;
    
    }
    Count++;

}


template<class T>
void DoublyCLL<T>:: InsertLast(T no)
{
    struct node<T>*newn = NULL;
    struct node<T>*temp = Head;
    newn = new node<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;

         
    }
   Count++;
    
}   

template<class T>
 void DoublyCLL<T>:: InsertAtPos(T no,T Pos)
 {
     struct node<T>*newn = NULL;
        struct node<T>*temp = Head;
        newn = new node<T>;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

    int Size = countNode();
    if((Pos < 1) || (Pos > Size+1))
    {
        cout<<"invaild Position..\n";
        return;
    }
    if(Pos == 1)
    {
        InsertFirst(no);
    }
    else if(Pos == Size)
    {
        InsertLast(no);
    }
    else
    {
       
        for(int iCnt = 1; iCnt <(Pos-1); iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
    }
   Count++;
 }
 
  template<class T>
 void  DoublyCLL<T>::DeleteFirst()
 {
    struct node<T>*temp = Head;

    if(Head == NULL)
    {
        return;
    }
    else if(Head->next == NULL)
    {
        delete(Head);
        Head = NULL;
    }
    else
    {
        Head = Head->next;
        delete(Head->prev);
        Head->prev = NULL;

      
    }
    Count--;
 }

 template<class T>
  void  DoublyCLL<T>:: DeleteLast()
  {
    struct node<T>*temp = Head;

    if(Head == NULL)
    {
        return;
    }
    else if(Head->next == NULL)
    {
        delete(Head);
        Head = NULL;
    }
    else
    {
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete(temp->next);
        temp->next = NULL;
   
    }
    Count--;
  }

   template<class T>
   void  DoublyCLL<T>::DeleteAtPos(T Pos)
  {
   
   
    int Size = countNode();
    if((Pos < 1) || (Pos > Size+1))
    {
        cout<<"invaild Position..\n";
        return; 
    }
    if(Pos == 1)
    {
       DeleteFirst();
    }
    else if(Pos == Size)
    {
        DeleteLast();
    }
    else
    {
        struct node<T>*temp = Head;
         struct node<T>*temp1;
        for(int i = 0; i<(Pos-1); i++)
        {
            temp = temp->next;
        }
        temp1 = temp->next;
        temp->next = temp1->next;
        delete(temp1);

    }
       Count--; 
  }

template<class T>
void DoublyCLL<T>:: Display()
{
    struct node<T>*temp = Head;
    cout<<"Elements from Linked List are : "<<endl;

    while(temp != NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->next;

    }
    cout<<"NULL";
    cout<<endl;
}

template<class T>
 int DoublyCLL<T>::countNode()
 {
    return Count;
 }
 

int main()
{
    DoublyCLL<int>obj1;

    obj1.InsertFirst(101);
    obj1.InsertFirst(51);
    obj1.InsertFirst(31);
    obj1.InsertFirst(20);


    obj1.DeleteLast();
    
     obj1.Display();
    cout<<"Number of node are : "<<obj1.countNode()<<endl;


    obj1.InsertLast(75);
    obj1.InsertAtPos(100,3);

    obj1.DeleteAtPos(3);
   
    obj1.DeleteFirst();
    
     obj1.Display();
    cout<<"Number of node are : "<<obj1.countNode()<<endl;
    
    return 0;
}