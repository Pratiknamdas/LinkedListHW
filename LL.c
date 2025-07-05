#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node**PPNODE;

void InsertFirst(PPNODE First, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = no;
    newn -> next = NULL;

    if(*First == NULL)
    {
        *First = newn;
    }
    else
    {
        newn -> next = *First;
        *First = newn;
    }
}

void InsertLast(PPNODE First, int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = no;
    newn -> next = NULL;

    if(*First == NULL)
    {
        *First = newn;
    }
    else
    {
        temp = *First;

        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
        newn -> next = NULL;
        
    }

}

void DeleteFirst(PPNODE First)
{
    PNODE temp = NULL;

    if(*First == NULL)
    {
        return;
    }
    else
    {
        temp = *First;
        *First = (*First) -> next;
        free(temp);
    }
}

void DeleteLast(PPNODE First)
{
    PNODE temp = NULL;

    if(*First == NULL)
    {
        return;
    }
    else
    {
        temp = *First;
        while(temp -> next -> next != NULL)
        {
            temp = temp -> next;
        }

        free(temp -> next);
        temp -> next = NULL;
    }

}

void Display(PNODE First)
{
    while(First != NULL)
    {
        printf("| %d | -> ",(First) -> data) ;
        First = (First) -> next;
    }
    printf("NULL\n");
}

int Count(PNODE First)
{   
    int iCount = 0;
    while(First != NULL)
    {
        iCount++ ;
        First = (First) -> next;
    }
    return iCount;
}

void InsertAtPos(PPNODE First, int no , int pos)
{
    PNODE temp = NULL;
    int i = 0, iCount = 0;

    iCount = Count(*First);

    if((pos < 1) || (pos > iCount +1))
    {
        printf("Invalid Position");
        return;
    }

    if(pos == 1)
    {
        InsertFirst(First,no);
    }
    if(pos == iCount + 1)
    {
        InsertLast(First,no);
    }
    else
    {
        PNODE newn = NULL;
        newn = (PNODE)malloc(sizeof(NODE));

        newn -> data = no;
        newn -> next = NULL;

        temp = *First;
        
        for(i = 0; i < (pos - 2) ; i++)
        {
            temp = temp -> next;
        }
        
        newn -> next = temp -> next;
        temp -> next = newn;
    }
    

}
void DeleteAtPos(PPNODE First, int pos)
{
    PNODE temp = NULL;
    PNODE target = NULL;
    int i = 0, iCount = 0;

    iCount = Count(*First);

    if((pos < 1) || (pos > iCount))
    {
        printf("Invalid Position");
        return;
    }

    if(pos == 1)
    {
        DeleteFirst(First);
    }
    if(pos == iCount)
    {
        DeleteLast(First);
    }
    else
    {

        temp = *First;
        
        for(i = 0; i < (pos - 2) ; i++)
        {
            temp = temp -> next;
        }
        target = temp -> next;
        temp -> next  = target -> next;
        free(target);
    }
}


int main()
{
    PNODE head = NULL;

    int iChoice = 0;
    int iValue = 0;
    int iPos = 0;
    int iRet = 0;

    printf("-----------------------------------------------------------------\n");
    printf("----------------------Doubly Linear Linked List------------------\n");
    printf("-----------------------------------------------------------------\n\n");
    while(1)
    {
        printf("-----------------------------------------------------------------\n");
        printf("----------------------Please Select the Option------------------\n");
        printf("-----------------------------------------------------------------\n");
        printf("1 :Insert new node at First position\n ");
        printf("2 :Insert new node at Last position\n ");
        printf("3 :Insert new node at Given position\n ");
        printf("4 :Delete the node from First position\n ");
        printf("5 :Delete the node from Last position\n ");
        printf("6 :Delete the node from Given position\n ");
        printf("7 :Display all the elements of LinkedList\n ");
        printf("8 :Count all the elements of LinkedList\n ");
        printf("0 :Terminate the application\n ");
        printf("-----------------------------------------------------------------\n");

        scanf("%d",&iChoice);

        if(iChoice == 1 )
        {
            printf("Enter the Data that you want to insert\n");
            scanf("%d",&iValue);

            InsertFirst(&head,iValue);
        }

        else if(iChoice == 2 )
        {
            printf("Enter the Data that you want to insert\n");
            scanf("%d",&iValue);

            InsertLast(&head,iValue);
        }
        else if(iChoice == 3 )
        {
            printf("ENter the Data that you want to insert\n");
            scanf("%d",&iValue);

            printf("Enter the position at which you want to insert new node\n");
            scanf("%d",&iPos);

            InsertAtPos(&head,iValue,iPos);
        }
        else if(iChoice == 4 )
        {
            printf("Deleting the First element from  Linked List\n");

            DeleteFirst(&head);
        }
        else if(iChoice == 5 )
        {
            printf("Deleting the Last element from  Linked List\n");

            DeleteLast(&head);
        }

        else if(iChoice == 6 )
        {
            printf("Deleting the element from given position from  Linked List\n");
            printf("Enter the position at which you want to Delete node\n");
            scanf("%d",&iPos);

            DeleteAtPos(&head,iPos);
        }
        else if(iChoice == 7 )
        {
            printf("Element of the Linked List are: \n");

            Display(head);
        }
        else if(iChoice == 8 )
        {
            printf("Number of elements in the  Linked List are: \n");

            Count(head);
        }
        else if(iChoice == 0 )
        {
            printf("Thank you for using ou application \n");

            break;
        }

        else
        {
            printf("Invalid Chooice\n");
        }
        printf("-----------------------------------------------------------------\n");
    }


    return 0;
}