#include<iostream>
using namespace std;



struct node
{
   int data;
    struct node *next;
};
typedef struct node NODE;
typedef struct node *PNODE;

class SinglyLL
{
    public:
        PNODE Head;

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
    int Count = 0;
 }


void SinglyLL ::InsertFirst(int no)
{
      PNODE newn = NULL;
      newn = new NODE;
  

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
   
}


void SinglyLL::InsertLast(int no)
{
    PNODE newn = NULL;
    newn = new NODE;

    newn->data = no;
    newn->next = NULL;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
       PNODE temp = Head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        
    }
   

}

 void SinglyLL:: InsertAtPos(int no,int Pos)
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
        PNODE newn = NULL;
        newn = new node;

        newn->data = no;
        newn->next = NULL;

        PNODE temp = Head;
        int iCnt = 0;
        for(iCnt = 1; iCnt < Pos-1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
  
 }

  void SinglyLL:: DeleteFirst()
{
    PNODE temp = Head;

    if(Head == NULL)
    {
        return;
    }
    else
    {
        Head = temp->next;
        delete(temp);
    }

}


void SinglyLL:: DeleteLast()
{
   PNODE temp = Head;
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

}


void SinglyLL:: DeleteAtPos(int Pos)
{
   PNODE temp = Head;
   PNODE temp1 = NULL;
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
      


}


void SinglyLL:: Display()
{
    cout<<"Elements from Linked List are : "<<endl;
   PNODE temp = Head;
   if(Head == NULL)
   {
    return;
   }
    while(temp != NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL";
    cout<<endl;
}


 int SinglyLL::countNode()
 {
    int iCnt = 0;
    PNODE temp = Head;
    if(Head == NULL)
    {
        return 0;
    }

    while(temp != NULL)
    {
        iCnt++;
        temp = temp->next;
    }
    return iCnt;
 }
int main()
{

    int iRet = 0;
    SinglyLL obj1;

    obj1.InsertFirst(21);
    obj1.InsertFirst(11);
    obj1.InsertLast(51);
    obj1.InsertLast(101);
      obj1.InsertLast(151);
    obj1.InsertLast(160);

    iRet = obj1.countNode();
    cout<<"Number of nodes are : "<<iRet<<endl;


    obj1.DeleteFirst();
    obj1.InsertAtPos(75,3);


    obj1.DeleteLast();

    obj1.DeleteAtPos(3);
    obj1.Display();
    iRet = obj1.countNode();
    cout<<"Number of nodes are : "<<iRet<<endl;



    return 0;
}