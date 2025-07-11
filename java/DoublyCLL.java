class node
{
    public int data;
    public node next;
    public node prev;
}

class DoublyCLL
{
    private node first;
    private node last;
    private int iCount;

    DoublyCLL()
    {
        first = null;
        last = null;
        iCount = 0;
    }
    public void InsertFirst(int no)
    {
        node newn = null;
        newn = new node();

        newn.data = no;
        newn.next = null;
        newn.prev = null;

        if((first == null) || (last == null))
        {
            first = newn;
            last = newn;

            first.prev = last;
            last.next = first;
        }
        else
        {
            newn.next = first;
            newn.prev = last;

            first.prev = newn;
            last.next = newn;

            first =  newn;
        }

        iCount++;
    }
    public void InsertLast(int no)
    {
        node newn = null;
        newn = new node();

        newn.data = no;
        newn.next = null;
        newn.prev = null;

        if((first == null) || (last == null))
        {
            first = newn;
            last = first;


            last.next = first;
        }
        else
        {
            newn.next = first;
            first.prev= newn;

            last.next = newn;
            newn.prev = last;

            last = newn;
        }

        iCount++;
    }
    

    public void DeleteFirst()
    {
        if((first == null) || (last == null))
        {
            return;
        }
        else
        {
            first = first.next;
            first.next.prev = first;

            last.next = first;
            first.prev = last;
            iCount--;
        }
    }
    public void DeleteLast()
    {
        node temp = null;

        if((first == null) || (last == null))
        {
            return;
        }
        else
        {
            temp = first;

            while(temp.next.next != first)
            {
                temp = temp.next;

            }
            temp.next = first;
            first.prev = temp;

            last.next = first;
            first.prev = last;

            iCount--;
        }
        
    }

    public void InsertAtPos(int no,int pos)
    {
        node temp = null;
        int iCnt = 0;

        if((pos < 1) || (pos > iCount + 1))
        {
            System.out.println("Invalid Input");
            return;
        }

        if(pos == 1)
        {
            InsertFirst(no);
        }
        else if(pos == iCount +1)
        {
            InsertLast(no);
        }
        else
        {
            node newn = null;
            newn = new node();

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

        if((pos < 1) || (pos > iCount))
        {
            System.out.println("Invalid Input");
            return;
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
            
            for( iCnt = 1; iCnt < (pos -1); iCnt++)
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
            System.out.print(" <-|" + temp.data + "|-> ");
            temp = temp.next;

        }while(temp != first );
        System.out.println("null");
    }

    public int Count()
    {
        return iCount;
    }
}

class program378
{
    public static void main(String A[])
    {
        DoublyCLL sobj = new DoublyCLL();
        int iRet = 0;

        sobj.InsertFirst(51);
        sobj.InsertFirst(21);
        sobj.InsertFirst(11);

        sobj.InsertLast(101);
        sobj.InsertLast(111);
        sobj.InsertLast(121);

        sobj.Display();

        iRet = sobj.Count();
        System.out.println("Number of Elements in Doubly Circular LinkedList is : "+iRet);

        sobj.InsertAtPos(105,5);

        sobj.Display();

        iRet = sobj.Count();
        System.out.println("Number of Elements in Doubly Circular LinkedList is : "+iRet);

        sobj.DeleteAtPos(5);

        sobj.Display();

        iRet = sobj.Count();
        System.out.println("Number of Elements in Doubly Circular LinkedList is : "+iRet);
        
    }
}