import java.lang.*;
import java.util.*;

import javax.lang.model.util.ElementScanner14;



class node
{
    
    public int data;
    public node next;           //struct node *next;
    public node prev;
};

class DoublyLL
{
  
    public node Head;
    public int Count;

    public DoublyLL()
    {
        Head = null;
        Count = 0;
    }

    public void InsertFirst(int no)
    {
        node newn = new node();
        newn.data = no;
        newn.next = null;
        newn.prev = null;

        if(Head == null)
        {
            Head = newn;
        }
        else
        {
            newn.next = Head;
            Head.prev = newn;
            Head = newn;
        }
        Count++;
        
    }
    public int CountNode()
    {
        return Count;
    }


    public void Display()
    {
        node temp = Head;

        System.out.println("Elements of Linked list are : ");
        while(temp != null)
        {
            System.out.print("|"+temp.data+"|->");
            temp = temp.next;
        }
           System.out.println("NULL");
    }




    public void InsertLast(int no)
    {
        node newn = new node();
        newn.data = no;
        newn.next = null;
        newn.prev = null;

        if(Head == null)
        {
            Head = newn;
        }
        else
        {
            node temp = Head;
            while(temp.next != null)
            {
                temp = temp.next;
            }
            temp.next = newn;
            newn.prev = temp;
        }
      Count++;
    }
   
     

    public void DeleteFirst()
    {
        if(Count == 0)
        {
            return;
        }
        else if(Count == 1)
        {
            Head = null;
        }
        else
        {
            node temp = Head;
            Head = temp.next;
            temp.next.prev = null;
            
        }
       Count--;
    }
  
    public void DeleteLast()
    {
        if(Count == 0)
        {
            return;
        }
        else if(Count == 1)
        {
            Head = null;
        }
        else
        {
            node temp = Head;

            while(temp.next.next != null)
            {
                temp = temp.next;
            }
            temp.next = null;
        }
        Count--;
    }
    public void InsertAtPos(int no, int pos)
    {
        if((pos < 1) || (pos >Count+1))
        {
            return;
        }
        if(pos == 1)
        {
            InsertFirst(no);
        }
        else if(pos == Count+1)
        {
            InsertLast(no);
        }
        else
        {
            node newn = new node();
            newn.data = no;
            newn.next = null;
            newn.prev = null;
            node temp = Head;

            for(int i = 1; i<pos-1; i++)
            {
                temp = temp.next;
            }
            newn.next = temp.next;
            temp.next = newn;

        }
        Count++;
    }

    public void DeleteAtPos(int pos)
    {
        if((pos < 1) || (pos >Count+1))
        {
            return;
        }
        if(pos == 1)
        {
           DeleteFirst();
        }
        else if(pos == Count+1)
        {
            DeleteLast();
        }
        else
        {
            node temp = Head;

            for(int i = 1; i<pos-1;i++)
            {
                temp = temp.next;
            }
            temp.next = temp.next.next;

        }
        Count--;
    }
}

class DoublyL
{
    public static void main(String arg[])
    {
        DoublyLL obj = new DoublyLL();

        obj.InsertFirst(101);
        obj.InsertFirst(51);
        obj.InsertFirst(21);
        obj.InsertFirst(11);

        obj.Display();
        System.out.println("Number of Elements are : "+obj.CountNode());

        obj.InsertLast(75);

       

        obj.Display();
        System.out.println("Number of Elements are : "+obj.CountNode());

        obj.DeleteFirst();
        obj.Display();
        System.out.println("Number of Elements are : "+obj.CountNode());

        obj.DeleteLast();
        obj.Display();
        System.out.println("Number of Elements are : "+obj.CountNode());

        obj.InsertAtPos(100,3);
        obj.Display();
        System.out.println("Number of Elements are : "+obj.CountNode());

        obj.DeleteAtPos(3);
        obj.Display();
        System.out.println("Number of Elements are : "+obj.CountNode());

    }   
}