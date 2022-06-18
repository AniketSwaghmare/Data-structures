#include<iostream>
using namespace std;



struct node
{
   int data;
    struct node *next;
    struct node *prev;
};
typedef struct node NODE;
typedef struct node * PNODE;

class DoublyCLL
{
     public:
     PNODE Head;
     PNODE Tail;
     int Count;

    DoublyCLL();
     void InsertFirst(int);
        void InsertLast(int);
        void InsertAtPos(int,int);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
        void Display();
        int countNode();
};


 DoublyCLL::DoublyCLL()
 {
    Head = NULL;
    Tail = NULL;
   int Count = 0;

 }


 void DoublyCLL::InsertFirst(int No)
 {
     PNODE newn = NULL;
    newn = new NODE;

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
   
 }


 void DoublyCLL::InsertLast(int No)
 {
   PNODE newn = NULL;
    newn = new NODE;

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

   
}


  void  DoublyCLL::InsertAtPos(int No,int Pos)
  {
    int iSize = countNode();
    PNODE newn = NULL;
     PNODE temp = Head;
    newn = new NODE;

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
   

  }


void DoublyCLL::DeleteFirst()
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
 
}


void  DoublyCLL::DeleteLast()
{
  PNODE temp = Head;

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
 
}


 void DoublyCLL:: DeleteAtPos(int Pos)
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
        PNODE temp = Head;
       PNODE tempdelete;
        for(int i = 1; i<(Pos -1); i++)
        {
            temp = temp->next;
        }
        tempdelete = temp->next;
        temp->next = tempdelete->next;
        delete(tempdelete);
    }
 
 }



void  DoublyCLL::Display()
{
    PNODE temp = Head;
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


int DoublyCLL::countNode()
{
   int iCnt = 0;
  PNODE temp = Head;

  if((Head == NULL) && (Tail == NULL))
  {
    return 0;
  }

  do
  {
    iCnt++;
    temp = temp->next;
  } while (temp != Head);
  return iCnt;
}

int main()
{
    DoublyCLL obj1;
    int iRet = 0;
    obj1.InsertFirst(11);
    obj1.InsertFirst(21);
    obj1.InsertFirst(51);
    obj1.InsertFirst(101);

    obj1.InsertLast(75);
   

    obj1.Display();
    iRet = obj1.countNode();
    cout<<"The Number of Nodes are : "<<iRet<<endl;

    obj1.InsertAtPos(100,4);
    obj1.Display();
    iRet = obj1.countNode();
    cout<<"The Number of Nodes are : "<<iRet<<endl;

    obj1.DeleteFirst();

    obj1.DeleteLast();

     obj1.Display();
    iRet = obj1.countNode();
    cout<<"The Number of Nodes are : "<<iRet<<endl;

    
    obj1.DeleteAtPos(3);
    obj1.Display();
    iRet = obj1.countNode();
    cout<<"The Number of Nodes are : "<<iRet<<endl;

    return 0;
}