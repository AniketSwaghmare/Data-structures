import java.lang.*;
import java.util.*;

class node
{
    public char data;
    public node next;
};

class stack
{
    public node Head;
    public int Count;


   public stack()
    {   
        Head = null;
        Count = 0;
    }


    public void Push(char No)       //InsertFirst
    {
        node newn = new node();
        newn.data = No;
        newn.next = null;

        newn.next = Head;
        Head = newn;

        Count++;

    }
    public void Pop()        //DeleteFirst
    {
        char No;

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
        System.out.println("Elements from stack are : ");
        node temp = Head;
        while(temp != null)
        {
            System.out.print(temp.data+" ");
            temp = temp.next;
        }
        System.out.println(" ");
    }
    int countNode()
    {
        return Count;
    }
}

class SinglyStack
{
    public static void main(String arg[])
    {
        stack obj = new stack();

        obj.Push('A');
        obj.Push('B');
        obj.Push('C');
        obj.Push('D');

        obj.Display();
       

        obj.Pop();
        obj.Pop();
       
        obj.Display();
       
        obj.Push('Z');
        obj.Pop();
       
       
    }
}