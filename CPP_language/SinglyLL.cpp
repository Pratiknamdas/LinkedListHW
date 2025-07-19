#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

class SinglyCLL
{
    private:
        PNODE first;
        PNODE last;
        int iCount;

    public:
        SinglyCLL()
        {
            cout<<"Inside Constructor of SinglyCLL\n";

            this-> first = NULL;
            this -> last = NULL;    
            this->iCount =0;
        }

        void InsertFirst(int no)
        {
            PNODE newn = NULL;
            newn = new NODE;

            newn -> data = no;
            newn -> next = NULL;

            if((first == NULL) && (last == NULL))   //if(iCount ==  0)
            {
                first = newn;
                last = newn;

                last -> next = first;
            }
            else
            {
                newn -> next = first;
                first = newn;

                last -> next = first;

            }
            iCount++;
        }

        void InserLast(int no)
        {
             PNODE newn = NULL;
            newn = new NODE;

            newn -> data = no;
            newn -> next = NULL;

            if((first == NULL) && (last == NULL))   //if(iCount ==  0)
            {
                first = newn;
                last = newn;

                last -> next = first;
            }
            else
            {
                last -> next = newn;
                last = newn;

                last -> next - first;
            }
            iCount++;
        }

        void DeleteFisrt()
        {
            if((first == NULL) && (last == NULL))
            {
                return;
            }
            else if(first == last)
            {
                delete first;

                first = NULL;
                last = NULL;
            }
            else
            {
                first = first -> next;
                delete last -> next;
                last -> next = first;
            }
            iCount--;
        }

        void DeleteLast()
        {
            PNODE temp= NULL;

            if((first == NULL) && (last == NULL))
            {
                return;
            }
            else if(first == last)
            {
                delete first;

                first = NULL;
                last = NULL;
            }
            else
            {
                temp = first;
                while((temp -> next!= last))
                {
                    temp = temp -> next;
                }

                delete last;

                last = temp;

                last -> next = first;
                
            }
            iCount--;

        }
        void DeleteAtPos(int pos)
        {
            PNODE temp = NULL;
            PNODE target = NULL;
            int i = 0;

            if((pos < 1) || (pos > iCount))
            {
                cout<<"Position is invalid\n";
            } 
            else if(pos ==1 )
            {
                DeleteFisrt();
            }
            else if (pos == iCount)
            {
                DeleteLast();    
            }
            else
            {
                temp = first;

                for(i = 1; i < (pos -1); i++)
                {
                    temp = temp -> next;
                }

                target = temp -> next;
                temp -> next = target -> next;
                delete target;

                iCount--;
            }
        }

        void InsertAtPos(int no,int pos)
        {
            PNODE temp = NULL;
            PNODE newn = NULL;
            int i = 0;

            if((pos < 1) || (pos > iCount + 1 ))
            {
                cout<<"Position is invalid\n";
            } 
            else if(pos ==1 )
            {
                InsertFirst(no);
            }
            else if (pos == iCount +1)
            {
                InserLast(no);    
            }
            else
            {
                newn  = new NODE;

                newn -> data = no;
                newn -> next = NULL;
                temp = first;

                for( i = 1; i < (pos -1);i++)
                {
                    temp = temp -> next;
                }

                newn -> next = temp -> next;
                temp -> next = newn;
                

                iCount++;
            }

        }



        void Display()
        {
            PNODE temp = NULL;
            temp = first;

            if((first == NULL && last == NULL))
            {
                return ;
            }
            do
            {
                cout<<" | " << temp-> data << " | -> ";
                temp = temp-> next;
            }while(temp != last -> next);
        }

        int Count()
        {
            return iCount;
        }
};

int main()
{   
    int iRet = 0 ;
    SinglyCLL sobj;

    sobj.InsertFirst(51);
    sobj.InsertFirst(21);
    sobj.InsertFirst(11);

    sobj.InserLast(101);
    sobj.InserLast(111);
    sobj.InserLast(121);

    sobj.InsertAtPos(105,5);

    sobj.Display();
    
    iRet = sobj.Count();

    cout<<"Number of elements are:"<<iRet<<"\n";

    sobj.DeleteAtPos(5);

    sobj.Display();
    
    iRet = sobj.Count();

    cout<<"Number of elements are:"<<iRet<<"\n";

    sobj.DeleteFisrt();


    sobj.Display();
    
    iRet = sobj.Count();

    cout<<"Number of elements are:"<<iRet<<"\n";

    sobj.DeleteLast();

    sobj.Display();
    
    iRet = sobj.Count();

    cout<<"Number of elements are:"<<iRet<<"\n";

    return 0;
}