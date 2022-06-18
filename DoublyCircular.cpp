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
    struct node<T>*Head;
    struct node<T>*Tail;
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
    Tail = NULL;
    Count = 0;

 }

template<class T>
 void DoublyCLL<T>::InsertFirst(T No)
 {
    struct node<T>*newn = NULL;
    newn = new node<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if((Head == NULL) && (Tail == NULL))
    {
        Head = newn;
        Tail = newn;
    }  
    else
    {
    Tail->next = newn;
    newn->prev = Tail;
    newn->next = Head;
    Tail = newn;
    newn = Head;
      
    }
    Tail->next = Head;
    Count++;
 }

 template<class T>
 void DoublyCLL<T>::InsertLast(T No)
 {
    struct node<T>*newn = NULL;
    newn = new node<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if((Head == NULL) && (Tail == NULL))
    {
        Head = newn;
        Tail = newn;
    }  
    else
    {
       Tail->next = newn;
       newn->prev =Tail;
      
       Tail = newn;
    }
    Tail->next = Head;

    Count++;
}

template<class T>
  void  DoublyCLL<T>::InsertAtPos(T No,T Pos)
  {
    int iSize = countNode();
     struct node<T>*newn = NULL;
      struct node<T>*temp = Head;
    newn = new node<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;


    if((Pos < 1) || (Pos > iSize+1))
    {
        cout<<"Invaild Postion..\n";
        return;
    }
    if(Pos == 1)
    {
        InsertFirst(No);
    }
    else if(Pos == iSize+1)
    {
        InsertLast(No);
    }
    else
    {
        for(int i = 1; i< Pos-1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        newn->prev = temp;
        temp->next = newn;
    }
    Tail->next = Head;
    Count++;

  }

template<class T>
void  DoublyCLL<T>::DeleteFirst()
{
    if((Head == NULL) && (Tail == NULL))
    {
        return;
    }
    else if(Head == Tail)
    {
        delete(Head);
        Head = NULL;
        Tail = NULL;
    }
    else
    {
        Head = Head->next;
        delete(Tail->next);

    }
    Tail->next = Head;
    Count--;
}

template<class T>
void  DoublyCLL<T>::DeleteLast()
{
    struct node<T>*temp = Head;

    if((Head == NULL) && (Tail == NULL))
    {
        return;
    }
    else if(Head->next == NULL)
    {
        delete(Head);
        Head = NULL;
        Tail = NULL;
    }
    else
    {
       

       while(temp->next != Tail)
       {
            temp = temp->next;
       }
      delete(Tail);
      Tail = temp;

    }
    Tail->next = Head;
  Count--;
}

template<class T>
 void DoublyCLL<T>:: DeleteAtPos(T Pos)
 {
    int iSize = countNode();

    if((Pos < 1) || (Pos > iSize+1))
    {
        cout<<"Invaild Position..\n";
        return;
    }
    if(Pos == 1)
    {
        DeleteFirst();
    }
    else if(Pos == iSize)
    {
        DeleteLast();
    }
    else
    {
        struct node<T>*temp = Head;
        struct node<T>*tempdelete;
        for(int i = 1; i<(Pos -1); i++)
        {
            temp = temp->next;
        }
        tempdelete = temp->next;
        temp->next = tempdelete->next;
        delete(tempdelete);
    }
    Count--;
 }


template<class T>
void  DoublyCLL<T>::Display()
{
    struct node<T>*temp = Head;
    cout<<"Elements from Linked List are : "<<endl;

    if((Head == NULL) && (Tail == NULL))
    {
        return;
    }

   do
    {
        cout<<"|"<<temp->data<<"->";
        temp = temp->next;
    } while(temp != Head);
    cout<<"NULL";
    cout<<endl;
}

template<class T>
int  DoublyCLL<T>::countNode()
{
    return Count;
}

int main()
{
    DoublyCLL<int>obj1;

    obj1.InsertFirst(11);
    obj1.InsertFirst(21);
    obj1.InsertFirst(51);
    obj1.InsertFirst(101);

    obj1.InsertLast(75);
   

    obj1.Display();
    cout<<"The Number of Nodes are : "<<obj1.countNode()<<endl;

    obj1.InsertAtPos(100,4);
     obj1.Display();
    cout<<"The Number of Nodes are : "<<obj1.countNode()<<endl;

    obj1.DeleteFirst();

    obj1.DeleteLast();

     obj1.Display();
    cout<<"The Number of Nodes are : "<<obj1.countNode()<<endl;

    
    obj1.DeleteAtPos(3);
    obj1.Display();
    cout<<"The Number of Nodes are : "<<obj1.countNode()<<endl;

    return 0;
}