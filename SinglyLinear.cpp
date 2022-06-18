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
    Count = 0;
 }
template<class T>

void SinglyLL<T>::InsertFirst(T no)
{
    struct node<T>*newn = NULL;
    newn = new node<T>;

    newn->data = no;
    newn->next = NULL;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
        newn->next = Head;
        Head = newn;
    }
    Count++;
}

template<class T>
void SinglyLL<T>::InsertLast(T no)
{
    struct node<T>*newn = NULL;
    newn = new node<T>;

    newn->data = no;
    newn->next = NULL;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
        struct node<T>*temp = Head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        
    }
    Count++;

}
template<class T>
 void SinglyLL<T>:: InsertAtPos(T no,T Pos)
 {  
    int iSize = countNode();

    if((Pos < 1) || (Pos > iSize+1))
    {
        cout<<"invaild Position\n";
        return;
    }
    if(Pos == 1)
    {
        InsertFirst(no);
    }
    else if(Pos == iSize +1)
    {
        InsertLast(no);
    }
    else
    {
        struct node<T>*newn = NULL;
        newn = new node<T>;

        newn->data = no;
        newn->next = NULL;

        struct node<T>*temp = Head;
        int iCnt = 0;
        for(iCnt = 1; iCnt < Pos-1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
    Count++;
 }
 template<class T>
  void SinglyLL<T>:: DeleteFirst()
{
    struct node<T>*temp = Head;

    if(Head == NULL)
    {
        return;
    }
    else
    {
        Head = temp->next;
        delete(temp);
    }
    Count--;
}

 template<class T>
void SinglyLL<T>:: DeleteLast()
{
    struct node<T>*temp = NULL;
    if(Head == NULL)
    {
        return;
    }
    else
    {
        temp = Head;
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
void SinglyLL<T>:: DeleteAtPos(T Pos)
{
    struct node<T>*temp = Head;
    struct node<T>*temp1 = NULL;
     int iSize = countNode();
    
    if((Pos < 1) || (Pos > iSize+1))
    {
        cout<<"invaild Position\n";
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
        int iCnt = 0;
        for(iCnt = 0; iCnt < (Pos-1); iCnt++)
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
    cout<<"Elements from Linked List are : "<<endl;
    struct node<T>*temp = Head;
    while(temp != NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL";
    cout<<endl;
}

template<class T>
 int SinglyLL<T>::countNode()
 {
    return Count;
 }
int main()
{

    SinglyLL<int>obj1;
   SinglyLL<float>obj2;

    obj1.InsertFirst(21);
    obj1.InsertFirst(11);
    obj1.InsertLast(51);
    obj1.InsertLast(101);
      obj1.InsertLast(151);
    obj1.InsertLast(160);

    obj1.DeleteFirst();
    obj1.InsertAtPos(75,3);


    obj1.DeleteLast();

    obj1.DeleteAtPos(3);
    obj1.Display();
    cout<<"Number of nodes are : "<<obj1.countNode()<<endl;


     obj2.InsertFirst(21.11);
    obj2.InsertFirst(11.11);
    obj2.InsertLast(51.11);
    obj2.InsertLast(101.11);
      obj2.InsertLast(151.11);
    obj2.InsertLast(160.11);

    
    obj2.InsertAtPos(75.00,3);


    obj2.DeleteLast();

    obj2.DeleteAtPos(3);
    obj2.Display();
    cout<<"Number of nodes are : "<<obj2.countNode()<<endl;

    return 0;
}