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
    int Count = 0;
}



void DoublyCLL::InsertFirst(int no)
{
   PNODE newn = NULL;
    newn = new NODE;

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
   

}


void DoublyCLL:: InsertLast(int no)
{
   PNODE newn = NULL;
   PNODE temp = Head;
    newn = new NODE;

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
      
    
}   


 void DoublyCLL:: InsertAtPos(int no,int Pos)
 {
         PNODE newn = NULL;
        PNODE temp = Head;
        newn = new NODE;

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
      
 }
 

 void  DoublyCLL::DeleteFirst()
 {
    PNODE temp = Head;

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
  
 }


  void  DoublyCLL:: DeleteLast()
  {
     PNODE temp = Head;

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
      
  }


   void  DoublyCLL::DeleteAtPos(int Pos)
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
       PNODE temp = Head;
        PNODE temp1 = NULL;
        for(int i = 0; i<(Pos-1); i++)
        {
            temp = temp->next;
        }
        temp1 = temp->next;
        temp->next = temp1->next;
        delete(temp1);

    }

  }


void DoublyCLL:: Display()
{
   PNODE temp = Head;
    cout<<"Elements from Linked List are : "<<endl;

    while(temp != NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->next;

    }
    cout<<"NULL";
    cout<<endl;
}


 int DoublyCLL::countNode()
 {
   int iCnt = 0;
   PNODE temp = Head;

   while(temp != NULL)
   {
    iCnt++;
    temp = temp->next;
   }
   return iCnt;
 }
 

int main()
{
    DoublyCLL obj1;
   
    obj1.InsertFirst(101);
    obj1.InsertFirst(51);
    obj1.InsertFirst(31);
    obj1.InsertFirst(20);
     obj1.InsertFirst(11);

    
    obj1.DeleteLast();

     obj1.Display();
    int iRet = obj1.countNode();
 
    cout<<"Number of node are : "<<iRet<<endl;

    obj1.InsertLast(75);
    obj1.InsertAtPos(100,3);

    obj1.DeleteAtPos(3);
   
    obj1.DeleteFirst();
    
     obj1.Display();
      iRet = obj1.countNode();
 
    cout<<"Number of node are : "<<iRet<<endl;
    
    return 0;
}