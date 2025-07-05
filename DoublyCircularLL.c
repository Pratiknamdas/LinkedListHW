#include<stdio.h>
#include<stdlib.h>

struct  node
{
    int data ;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void InsertFirst(PPNODE first, PPNODE last, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = no;
    newn -> next = NULL;
    newn -> prev = NULL;

    if((*first == NULL) || (*last == NULL))
    {
        *first = newn;
        *last = newn;

        (*last) -> next = *first;
        (*first) -> prev = *last;
    }
    else
    {
        newn ->next = *first;
        newn -> prev = *last;

        (*first) -> prev = newn;
        

        (*last) -> next = newn;
        *first = newn;
        

    }
}

void InsertLast(PPNODE first, PPNODE last, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = no;
    newn -> next = NULL;
    newn -> prev = NULL;

    if((*first == NULL) || (*last == NULL))
    {
        *first = newn;
        *last = newn;

        (*last) -> next = *first;
        (*first) -> prev = *last;
    }
    else
    {
        (*last) -> next = newn;
        newn -> prev = *last;

        newn -> next = *first;
        (*first) -> prev = newn;
        *last = newn;
    }
}

void DeleteFirst(PPNODE first , PPNODE last)
{
    PNODE temp = NULL;
    if(*first == NULL || *last == NULL)
    {
        return;
    }

    temp = *first;

    *first = temp -> next;
    free(temp);

    (*first) -> prev = *last;
    (*last) -> next = *first;

}

void DeleteLast(PPNODE first , PPNODE last)
{
    PNODE temp = NULL;
    if(*first == NULL || *last == NULL)
    {
        return;
    }

    temp = *last;

    *last = temp -> prev;
    free(temp);

    (*last) -> next =*first;
    (*first)-> prev =*last;
}

void InsertAtPos(PPNODE first, PPNODE last, int no, int pos)
{
    PNODE newn = NULL;
    PNODE temp = NULL;
    int iCnt = 0;
    int iCount = 0;

    
    
    

    iCount = Count(first, last);
    
    if((pos < 1) || (pos > iCount +1))
    {
        print("Invalid Input\n");
        return 0;
    }
    else if(pos == 1)
    {
        InsertFirst(first,last,no);
    }
    else if(pos == iCount + 1)
    {
        InsertLast(first,last,no);
    }
    else
    {
        temp = *first;
        newn = (PNODE)malloc(sizeof(NODE));
        newn -> data = no;
        newn -> next = NULL;
        newn -> prev = NULL;

        for(iCnt =1 ; iCnt <= (pos - 1); iCnt++)
        {
            temp = temp -> next;
        }
        newn -> next = temp -> next;
        temp -> next -> prev = newn;
        temp -> next = newn;
        newn -> prev = temp;
    }
}

void DeleteAtPos(PPNODE first , PPNODE last, int pos)
{
    int iCount = 0, iCnt = 0;
    PNODE temp = NULL;
    PNODE target = NULL;

    iCount = Count(first, last);
    
    if((pos < 1) || (pos > iCount))
    {
        print("Invalid Input\n");
        return 0;
    }
    else if(pos == 1)
    {
        DeleteFirst(first,last);
    }
    else if(pos == iCount)
    {
        DeleteLast(first,last);
    }
    else
    {
        temp = *first;
        for(iCnt =1 ; iCnt <= (pos - 1); iCnt++)
        {
            temp = temp -> next;
        }
        target = temp -> next;
        temp -> next = target -> next;
        target -> next -> prev = target -> prev;

        free(target);
        
    }
}


void Display(PNODE first,PNODE last)
{
    printf("NULL <=>");
    do
    {
        printf("| %d | <=>",(first) -> data);
        first = (first) -> next;
    }while(first != last -> next);

    printf("NULL\n");


}

int Count(PNODE first,PNODE last)
{
    int iCount = 0;
    do
    {
        iCount++;
        first = first -> next;
        
    }while(first == last);

    return iCount;
}


int main()
{
    PNODE head = NULL;
    PNODE tail = NULL;

    int iChoice = 0;
    int iValue = 0;
    int iPos = 0;
    int iRet = 0;

    printf("-----------------------------------------------------------------\n");
    printf("----------------------Doubly Circular Linked List------------------\n");
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

            InsertFirst(&head,&tail,iValue);
        }

        else if(iChoice == 2 )
        {
            printf("Enter the Data that you want to insert\n");
            scanf("%d",&iValue);

            InsertLast(&head,&tail,iValue);
        }
        else if(iChoice == 3 )
        {
            printf("ENter the Data that you want to insert\n");
            scanf("%d",&iValue);

            printf("Enter the position at which you want to insert new node\n");
            scanf("%d",&iPos);

            InsertAtPos(&head,&tail,iValue,iPos);
        }
        else if(iChoice == 4 )
        {
            printf("Deleting the First element from  Linked List\n");

            DeleteFirst(&head,&tail);
        }
        else if(iChoice == 5 )
        {
            printf("Deleting the Last element from  Linked List\n");

            DeleteLast(&head,&tail);
        }

        else if(iChoice == 6 )
        {
            printf("Deleting the element from given position from  Linked List\n");
            printf("Enter the position at which you want to Delete node\n");
            scanf("%d",&iPos);

            DeleteAtPos(&head,&tail,iPos);
        }
        else if(iChoice == 7 )
        {
            printf("Element of the Linked List are: \n");

            Display(head,tail);
        }
        else if(iChoice == 8 )
        {
            printf("Number of elements in the  Linked List are: \n");

            Count(head,tail);
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