import java.lang.*;
import java.util.*;

class node
{
    public int data;
    public node next;
};

class Queue
{
    public node Head;
    public int Count;


   public Queue()
    {   
        Head = null;
        Count = 0;
    }


    public void Enqueue(int No)       //InsertFirst
    {
        node newn = new node();
        newn.data = No;
        newn.next = null;

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
        }
        Count++;

    }
    public void Dequeue()        //DeleteFirst
    {
        int No;

        if(Count == 0)
        {
            System.out.println("Queue is Empty");
            return;
        }
        if(Count == 1)
        {
          No = Head.data;
          Head = null;
          Count--;

          System.out.println("Removed Element is : "+No);
        }
        No = Head.data;
        node temp = Head;

        Head = Head.next;
        temp = null;
        Count--;

        System.out.println("Removed Element is : "+No);
    }
   
    public void Display()
    {
        System.out.println("Elements from Queue are : ");
        node temp = Head;
        while(temp != null)
        {
            System.out.print("|"+temp.data+"|->");
            temp = temp.next;
        }
        System.out.println("NULL");
    }
    int countNode()
    {
        return Count;
    }
}

class SinglyQueue
{
    public static void main(String arg[])
    {
        Queue obj = new Queue();

        obj.Enqueue(11);
        obj.Enqueue(21);
        obj.Enqueue(51);
        obj.Enqueue(101);

        obj.Display();
        System.out.println("Number of Elements in Queue : "+obj.countNode());

        obj.Dequeue();
        obj.Dequeue();
        obj.Dequeue();
        obj.Display();
        System.out.println("Number of Elements in Queue : "+obj.countNode());

       
    }
}