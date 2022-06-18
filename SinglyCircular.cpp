#include<iostream>
using namespace std;

template<class T>

struct node
{
    T data;
    struct node *next;
};

template<class T>
class SinglyLL
{
    public:
        struct node<T> *Head;
        struct node<T> *Tail;
        int Count;

        SinglyLL();
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
 SinglyLL<T>::SinglyLL()
 {
    Head = NULL;
    Tail = NULL;
    Count = 0;
 }
template<class T>

void SinglyLL<T>::InsertFirst(T no)
{
    struct node<T>*newn = NULL;
    newn = new node<T>;

    newn->data = no;
    newn->next = NULL;

    if((Head == NULL) && (Tail == NULL))
    {
        Head = newn;
        Tail = newn;

    }
    else
    {
        Tail->next = newn;
        newn->next = Head;
        Tail = newn;
        newn = Head;
    }
    Tail->next = Head;

    Count++;
   
}

template<class T>
void SinglyLL<T>::InsertLast(T no)
{
  struct node<T>*newn = NULL;
    newn = new node<T>;

    newn->data = no;
    newn->next = NULL;

    if((Head == NULL) && (Tail == NULL))
    {
        Head = newn;
        Tail = newn;

    }
    else
    {
        Tail->next = newn;
        Tail = newn;
       

       
    }
    Tail->next = Head;
    Count++;
}


template<class T>
void SinglyLL<T>::InsertAtPos(T No,T Pos)
{
    int iSize = countNode();

    if((Pos < 1) || (Pos > iSize+1))
    {
        cout<<"Invaild Position";
        return;
    }
    if(Pos == 1)
    {
        InsertFirst(No);
    }
    else if(Pos == iSize)
    {
        InsertLast(No);
    }
    else
    {

        struct node<T>*newn = NULL;
        struct node<T>*temp = Head;
        newn = new node<T>;

        newn->data = No;
        newn->next = NULL;

    for(int i = 1; i<(Pos-1); i++)
    {
        temp = temp->next;
    }
        newn->next = temp->next;
        temp->next = newn;

       
    }
     Tail->next = Head;
    Count++;
}

template<class T>
void SinglyLL<T>::DeleteFirst()
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
        delete (Tail->next);

        
    }
    Tail->next = Head;
    Count--;
}

template<class T>
void SinglyLL<T>::DeleteLast()
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
        struct node<T>*temp = Head;

        while(temp->next != Tail)
        {
            temp = temp->next;
        }
        delete Tail;
        Tail = temp;

        
    }
    Tail->next = Head;
    Count--;
}

template<class T>
void SinglyLL<T>::DeleteAtPos(T Pos)
{
    struct node<T>*temp = Head;
    struct node<T>*temp1 = NULL;
   int iSize = countNode();

   if((Pos < 1) || (Pos > iSize+1))
   {
        cout<<"Invaild Postion..\n";
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
        

        for(int i = 1; i< Pos-1; i++)
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
 void SinglyLL<T>:: Display()
 {  
   struct node<T>*temp = Head;

   if((Head == NULL) && (Tail == NULL))
   {
        return;
   }
   do
   {
        cout<<"|"<<temp->data<<"|->";
        temp = temp->next;

   } while (temp != Head);
   cout<<"NULL";
   cout<<endl;

 }
 template<class T>
  int SinglyLL<T>:: countNode()
{
   return Count;
}

int main()
{
    SinglyLL<int>obj1;

    obj1.InsertFirst(11);
    obj1.InsertFirst(21);
    obj1.InsertFirst(51);
    obj1.InsertFirst(101);

    obj1.DeleteFirst();

    obj1.InsertLast(200);

    obj1.Display();
    cout<<"The Number of Nodes are : "<<obj1.countNode()<<endl;

    obj1.InsertAtPos(75,3);

     obj1.Display();
    cout<<"The Number of Nodes are : "<<obj1.countNode()<<endl;

    obj1.DeleteLast();

    obj1.Display();
    cout<<"The Number of Nodes are : "<<obj1.countNode()<<endl;


    obj1.DeleteAtPos(3);

     obj1.Display();
    cout<<"The Number of Nodes are : "<<obj1.countNode()<<endl;

    

}