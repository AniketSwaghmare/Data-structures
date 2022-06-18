#include<iostream>
using namespace std;



struct node
{
    int data;
    struct node *next;
};
typedef struct node NODE;
typedef struct node * PNODE;


class SinglyLL
{
    public:
       PNODE Head = NULL;
       PNODE Tail = NULL;
        int Count;

        SinglyLL();
        void InsertFirst(int);
        void InsertLast(int);
        void InsertAtPos(int,int);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
        void Display();
        int countNode();
};


 SinglyLL::SinglyLL()
 {
    Head = NULL;
    Tail = NULL;
    Count = 0;
 }


void SinglyLL::InsertFirst(int no)
{
    PNODE newn = NULL;
   newn = new NODE;

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


void SinglyLL::InsertLast(int no)
{
    PNODE newn = NULL;
    newn = new node;

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



void SinglyLL::InsertAtPos(int No,int Pos)
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

       PNODE newn = NULL;
       PNODE temp = Head;
       newn = new NODE;

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


void SinglyLL::DeleteFirst()
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


void SinglyLL::DeleteLast()
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
       PNODE temp = Head;

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


void SinglyLL::DeleteAtPos(int Pos)
{
    PNODE temp = Head;
    PNODE temp1 = NULL;
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


 void SinglyLL:: Display()
 {  
    PNODE temp = Head;
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


  int SinglyLL:: countNode()
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
    int iRet = 0;
    SinglyLL obj1;

    obj1.InsertFirst(11);
    obj1.InsertFirst(21);
    obj1.InsertFirst(51);
    obj1.InsertFirst(101);

    obj1.DeleteFirst();

    obj1.InsertLast(200);

    obj1.Display();
    iRet = obj1.countNode();
    cout<<"The Number of Nodes are : "<<iRet<<endl;

    obj1.InsertAtPos(75,3);

     obj1.Display();
     iRet = obj1.countNode();
    cout<<"The Number of Nodes are : "<<iRet<<endl;

    obj1.DeleteLast();

    obj1.Display();
     iRet = obj1.countNode();
    cout<<"The Number of Nodes are : "<<iRet<<endl;


    obj1.DeleteAtPos(3);

     obj1.Display();
     iRet = obj1.countNode();
    cout<<"The Number of Nodes are : "<<iRet<<endl;

    

}