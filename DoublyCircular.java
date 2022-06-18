import java.lang.*;
import java.util.*;

import javax.lang.model.util.ElementScanner14;

class node
{
    public int data;
    public node next;
    public node prev;
};

class DoublyCL
{
    public node Head;
    public node Tail;
    public int Count;
    public DoublyCL()
    {
        Head = null;
        Tail = null;
        Count = 0;
    }

    public void InsertFirst(int no)
    {
        node newn = new node();
        newn.data = no;
        newn.next = null;
        newn.prev = null;


        if((Head == null) && (Tail == null))
        {
            Head = newn;
            Tail = newn;
        }
        else
        {
            Tail.next = newn;
            newn.prev = Tail;
            newn.next = Head;
            Tail = newn;
            newn = Head;
        }
        Tail.next = Head;
        Count++;
    }
    public void InsertLast(int no)
    {
        node newn = new node();
        newn.data = no;
        newn.next = null;
        newn.prev = null;


        if((Head == null) && (Tail == null))
        {
            Head = newn;
            Tail = newn;
        }
        else
        {
            Tail.next = newn;
            newn.prev = Tail;
            newn.next = Head;
            Tail = newn;
        }
        Tail.next = Head;
        Count++;

    }
   
    public void InsertAtPos(int no, int Pos)
    {
        int iSize = CountNode();
        node newn = new node();
        newn.data = no;
        newn.next = null;
        newn.prev = null;

        if((Pos < 1) && (Pos > iSize+1))
        {
            System.out.println("Invaild Postion");
            return;
        }
        if(Pos == 1)
        {
            InsertFirst(no);
        }
        else if(Pos == iSize+1)
        {
            InsertLast(no);
        }
        else
        {
            node temp = Head;

            for(int i = 1; i< Pos-1; i++)
            {
                temp = temp.next;
            }
            newn.next = temp.next;
            temp.next = newn;
            newn.prev = temp;
          
        }
        Tail.next = Head;
        Count++;
    }

    public void DeleteFirst()
    {
        if((Head == null) && (Tail == null))
        {
            System.out.println("Invaild Postion...");
            return;
        }
        else if(Head == Tail)
        {
            Head = null;
            Tail = null;
        }
        else
        {
            Head = Head.next;
            Tail.next = null;
        }

        Tail.next = Head;
        Count--;
    }
       
    public void DeleteLast()
    {
        if((Head == null) && (Tail == null))
        {
            System.out.println("Invaild Postion...");
            return;
        }
        else if(Head == Tail)
        {
            Head = null;
            Tail = null;
        }
        else
        {
           node temp = Head;
           while(temp.next != Tail)
           {
                temp = temp.next;
           }
           Tail = null;
           Tail = temp;
        }

        Tail.next = Head;
        Count--;
    }

    public void DeleteAtPos(int Pos)
    {
        int iSize = CountNode();

        if((Pos < 1) && (Pos > iSize))
        {
            System.out.println("Invaild Postion..");
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
            node temp = Head;
            node tempdelete;
            for(int i = 1; i<(Pos -1); i++)
            {
                temp = temp.next;
            }
            tempdelete = temp.next;
            temp.next = tempdelete.next;
            tempdelete = null;
        }
        Tail.next = Head;
        Count--;
    }

        public void Display()
        {
            node temp = Head;
            System.out.println("Elements of Linked List are :");
           
            do
            {
                System.out.print("|"+temp.data+"|->");
                temp = temp.next;
            } while(temp != Head);

            System.out.println("NULL");
        }

        public int CountNode()
        {
            return Count;
        }
}

class DoublyCircular
{
    public static void main(String arg[])
    {
        DoublyCL obj = new DoublyCL();

        obj.InsertFirst(101);
        obj.InsertFirst(51);
        obj.InsertFirst(21);
        obj.InsertFirst(11);

       

        obj.InsertAtPos(75,3);
        obj.InsertLast(100);
        obj.Display();
        System.out.println("Number of Nodes are : "+obj.CountNode());
    
        obj.DeleteFirst();

        obj.DeleteLast();

        obj.Display();
        System.out.println("Number of Nodes are : "+obj.CountNode());

        obj.DeleteAtPos(3);
        obj.Display();
        System.out.println("Number of Nodes are : "+obj.CountNode());

    }
}