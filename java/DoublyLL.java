class node
{
    public int data;
    public node next;
    public node prev;

}

class DoublyLL
{
    private node first;
    private int iCount;

    DoublyLL()
    {
        first = null;
        iCount = 0;
    }
    public void InsertFirst(int no)
    {
        node newn = null;
        newn = new node();

        newn.data = no;
        newn.next = null;
        newn.prev = null;

        if(first == null)
        {
            first = newn;
            newn.prev = first;
        }
        else
        {
            newn.next = first;
            first.prev = newn;

            first = newn;
        }
        iCount++;
    }
    public void InsertLast(int no)
    {
        node newn = null;
        node temp = null;
        newn = new node();

        newn.data = no;
        newn.next = null;
        newn.prev = null;

        if(first == null)
        {
            first = newn;
            newn.prev = first;
        }
        else
        {
            temp = first;
            while(temp.next != null)
            {
                temp = temp.next;
            }   
            temp.next = newn;
            newn.prev = temp;

        }
        iCount++;
    }

    public void DeleteFirst()
    {
        if(first == null)
        {
            return;
        }
        else
        {
            first = first.next;
            first.next.prev = first;
        
            iCount--;
        }
        
    }
    public void DeleteLast()
    {
        node temp = null;

        if(first == null)
        {
            return;
        }
        else
        {
            temp = first;
            while(temp.next.next != null)
            {
                temp = temp.next;
            }
            temp.next.prev = null;
            temp.next = null;
            
        
            iCount--;
        }
    }
    public void InsertAtPos(int no,int pos)
    {
        if((pos < 1)||(pos< iCount + 1))
        {
            System.out.println("Invalid Input");
        }

        if(pos == 1)
        {
            InsertFirst(no);
        }
        else if(pos == iCount + 1)
        {
            InsertLast(no);
        }
        else
        {
            node newn = null;
            node temp = null;

            newn = new node();
            int iCnt = 0;

            newn.data = no;
            newn.next = null; 
            newn.prev = null;

            temp = first;
            for( iCnt = 1; iCnt < (pos -1); iCnt++)
            {
                temp = temp.next;
            }

            newn.next = temp.next;
            temp.next.prev = newn;

            temp.next = newn;
            newn.prev = temp;
        }
        iCount++;
    }
    public void DeleteAtPos(int pos)
    {
        node temp = null;
        int iCnt = 0;

        if((pos < 1)||(pos< iCount))
        {
            System.out.println("Invalid Input");
        }

        if(pos == 1)
        {
            DeleteFirst();
        }
        else if(pos == iCount)
        {
            DeleteLast();
        }
        else
        {
            temp = first;

            for(iCnt = 1; iCnt < (pos - 1); iCnt++)
            {
                temp = temp.next;
            }
            temp.next = temp.next.next;
            temp.next.prev = temp;

        }
        iCount--;
        
    }

    public void Display()
    {
        node temp = null;

        temp = first;
        do
        {
            System.out.print("|" + temp.data + "| -> ");
            temp = temp.next;

        }while(temp != null);
        System.out.println("null");
    }

    public int Count()
    {
        return iCount;
    }
}

class program379
{
    public static void main(String A[])
    {
        DoublyLL sobj = new DoublyLL();

        int iRet = 0;

        sobj.InsertFirst(51);
        sobj.InsertFirst(21);
        sobj.InsertFirst(11);

        sobj.InsertLast(101);
        sobj.InsertLast(111);
        sobj.InsertLast(121);

        sobj.Display();

        iRet = sobj.Count();
        System.out.println("Number of Elements in Doubly LinkedList is : "+iRet);

        sobj.InsertAtPos(105,5);

        sobj.Display();

        iRet = sobj.Count();
        System.out.println("Number of Elements in Doubly LinkedList is : "+iRet);

        sobj.DeleteAtPos(5);

        sobj.Display();

        iRet = sobj.Count();
        System.out.println("Number of Elements in Doubly LinkedList is : "+iRet);
    }
}