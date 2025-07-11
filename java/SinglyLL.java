class node
{
    public int data;
    public node next;
}

class SinglyLL
{
    private node first;
    private int iCount;
    public SinglyLL()
    {
        System.out.println("Inside Constructor");
        first = null;
        iCount = 0;
    }

    public void InsertFirst(int no)
    {
        node newn = null;
        
        newn = new node();

        newn.data = no;
        newn.next = null;

        if(first == null)   //LL is empty
        {
            first = newn;
        }
        else                // LL Conatains at least 1 node
        {
            newn.next = first;
            first = newn;            
        }
        iCount++;
    }

    public void InsertLast(int no)
    {
        node temp = null;

        node newn = null;
        
        newn = new node();

        newn.data = no;
        newn.next = null;

        if(first == null)   //LL is empty
        {
            first = newn;
        }
        else                // LL Conatains at least 1 node
        {
            
            temp = first;
            while(temp.next  != null)
            {
                temp = temp.next;
            }
            temp.next = newn;
        }
        iCount++;
    }

    public void Display()
    {        
        node temp = null;
        temp = first;

        while(temp != null)
        {
            System.out.print(" | "+temp.data+" |->");
            temp = temp.next;

        }
        System.out.println("null");
        
    }

    public int Count()
    {
        return iCount++;
    }
    
    public void DeleteFirst()
    {
        if(first == null)           //LL is Empty
        {
            return;
        }
        else if(first.next == null) //LL is contains at least 1 node
        {
            first = null;
        }
        else
        {
            first = first.next;
        }
        
    }
    public void DeleteLast()
    {
        node temp = null;
        if(first == null)           //LL is Empty
        {
            return;
        }
        else if(first.next == null) //LL is contains at least 1 node
        {
            first = null;
        }
        else
        {
            temp = first;
            while(temp.next.next != null)
            {
                temp = temp.next;
            }
            temp.next = null;
        }
    }

    public void InsertAtpos(int no,int pos)
    {
        node newn = null;
        node temp = null;
        iCount = 0;
        int iCnt = 0;

        if(pos < 1 || pos > iCount +1)
        {
            System.out.println("Invalid Position");
            return;
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
            newn = new node();

            newn.data = no;
            newn.next = null;

            temp = first;

            for(iCnt = 1; iCnt < (pos-1); iCnt++)
            {
                temp = temp.next;
            }
            newn.next = temp.next;
            temp.next = newn;

            iCount++;
        }

        
            
        }


    public void DeleteAtpos(int pos)
    {   
        int iCnt = 0;
        node temp = null;
        iCount = 0;


        if(pos < 1 || pos > iCount)
        {
            System.out.println("Invalid Position");
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
            for(iCnt = 1; iCnt<(pos-1); iCnt++)
            {
                temp = temp.next;
            }
            temp.next = temp.next.next;
            iCount--;
        }
        
    }
    
}

class program375
{
    public static void main(String A[])
    {
        SinglyLL sobj = new SinglyLL();

        int iRet = 0;

        //Calling Insert

        sobj.InsertFirst(51);
        sobj.InsertFirst(21);
        sobj.InsertFirst(11);

        sobj.InsertLast(101);
        sobj.InsertLast(111);
        sobj.InsertLast(121);
        
        sobj.Display();

        iRet = sobj.Count();

        System.out.println("Number of Elements in the linkedlist are "+iRet);

        //Calling InsertAtpos

        sobj.InsertAtpos(105, 5);

        sobj.Display();

        iRet = sobj.Count();

        System.out.println("Number of Elements in the linkedlist are "+iRet);

        //Calling DeleteAtpos

        sobj.DeleteAtpos(5);

        sobj.Display();

        iRet = sobj.Count();

        System.out.println("Number of Elements in the linkedlist are "+iRet);


        
        //CAllling
    
    }

}