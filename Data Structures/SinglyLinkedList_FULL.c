// 9/10/2023 Author: Satvik Rajesh.

#include<stdio.h>
#include<stdlib.h>

//creating a node (i.e. element of the linked list) in the form of a structure.
struct node
{

    int ele;
    struct node* next;

}*head, *tail;

void init()
{
    head = tail = NULL;  //initialize linked list.
}

void insertatend(int ele)
{
    struct node * newn = (struct node *)malloc(sizeof(struct node));  //memory allocation
    
    if(head == NULL)
    {
        head = tail = newn;
    }
    else
    {
        tail -> next = newn;  //update tail (last node)
        tail = newn;
    }
    newn -> ele = ele;
    newn -> next = NULL;
}

void insertatfront(int ele)
{
    struct node * newn = (struct node *)malloc(sizeof(struct node));  

    if(head == NULL)
    {
        head = tail = newn;
        newn->next = NULL;
    }
    else
    {
        newn->next = head;  //update head ( first node )
        head = newn;
    }
    newn->ele = ele;
}

void deletefromfront()
{
    struct node * nodeptr = head;  //pointer to first element

    if(head == NULL)
    {
        printf("Cannot delete from an empty list.\n");
        return;
    }

    if(head->next == NULL)  //if there's only one element in the list.
    {
        head = tail = NULL;
    }

    else
    {
        head = head->next;   //free the pointer
        free(nodeptr);
    }
}

void deletefromend()
{
    if(head == NULL)
    {
        printf("Cannot delete from an empty list.\n");
        return;
    }

    if(head->next == NULL)
    {
        head = tail = NULL;
    }

    struct node* trav1 = head;     //2 nodes. one to reach last, one to reach second last.
    struct node* trav2 = head->next;
   
    while(trav2->next!=NULL)
    {
        trav1 = trav2;
        trav2 = trav2->next;
    }

    trav1->next = NULL;
    tail = trav1;
    free(trav2);
}

//insert an element at a given position. from 0 to n-1, n being size of the list.

void insert(int ele, int pos)
{
    if (pos < 0)
    {
        printf("Invalid position!\n");  
        return;
    }

    struct node* newn = (struct node*)malloc(sizeof(struct node));
    
    newn->ele = ele;

//inserting in front reusing old fn

    if (pos == 0)
    {
        insertatfront(ele);
    }

    struct node* trav = head;
    for (int i = 1; i < pos; i++)
    {
        if (trav == NULL)
        {
            printf("Invalid position!\n");  //out of bounds
            free(newn);
            return;
        }
        trav = trav->next;
    }

    newn->next = trav->next;   //need diagram to understand this
    trav->next = newn;

    if (newn->next == NULL)
    {
        tail = newn;            //checking if insertion to be done in the end.
    }
}


void delete(int ele)  //deleting a specific element
{
    if (head == NULL)
    {
        printf("Cannot delete from an empty list.\n");
        return;
    }

    struct node* temp = head;
    struct node* prev = NULL;

    // Handle the case when the element to be deleted is at the beginning of the list
    if (temp->ele == ele)
    {
        deletefromfront();
        printf("\n%d deleted from the list.", ele);
        return;
    }

    // Search for the element to be deleted and keep track of the previous node
    while (temp != NULL && temp->ele != ele)
    {
        prev = temp;
        temp = temp->next;
    }

    // If the element was not found in the list
    if (temp == NULL)
    {
        printf("Element %d not found in the list.\n", ele);
        return;
    }

    
    prev->next = temp->next;

    
    if (temp == tail)
    {
        tail = prev;  //if element to be deleted is at the end.
    }

    free(temp);
    printf("Element %d deleted from the list.\n", ele);
}



void display()
{
    struct node * temp;
    temp = head;

    printf("\nLinked List:\n");
    printf("\nAddress of Head Node: %p\n", head);

    //2 ways to display. either using for loop of while loop. comment / uncomment as per liking.

    /*for(temp=head; temp!=NULL; temp=temp->next)
    {
        printf("| %d --> %p |", temp->ele, temp->next);
    }*/

    while(temp!=NULL)
    {
        printf("| %d --> %p |", temp->ele, temp->next);
        temp = temp->next;
    }
}



struct node* search(int ele)   //search address of element. Returns struct pointer as result.
{
    struct node *temp;
    temp = head;
    while (temp!=NULL)
    {
        if (temp->ele == ele)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

//reversing the list. refer to algorithm for better understanding.

void reverse()
{
    struct node *prev, *current, *next;
    prev = NULL;
    current = head;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
    printf("\nLinked list reversed successfully.");
}


void main()
{

    init();  //initializing the LL
    int ch,ele,pos;  
    struct node* address;  //creating node pointer because our search fn returns a struct pointer

//switch case menu


    while(1)
    {
        printf("\nLinked List operations: \n");
        printf("\n1. Insert in front\n");
        printf("2. Insert in end\n");
        printf("3. Insert at given position\n");
        printf("4. Delete from front\n");
        printf("5. Delete from end\n");
        printf("6. Delete specific element\n");
        printf("7. Search for element\n");
        printf("8. Display List\n");
        printf("9. Reverse List\n");
        printf("10. Exit\n");

        printf("\n\nEnter choice: ");
        scanf("%d", &ch);
    
    switch(ch)
    {
        case 1:
            printf("\nEnter element you want to insert: ");
            scanf("%d", &ele);
            insertatfront(ele);
            break;
        
        case 2:
            printf("\nEnter element you want to insert: ");
            scanf("%d", &ele);
            insertatend(ele);
            break;

        case 3:
            printf("\nEnter element you want to insert: ");
            scanf("%d", &ele);
            printf("\nEnter position you want to insert: ");
            scanf("%d", &pos);
            insert(ele,pos);
            break;

        case 4:
            deletefromfront();
            break;

        case 5:
            deletefromend();
            break;

        case 6:
            printf("\nEnter element you want to delete: ");
            scanf("%d", &ele);
            delete(ele);
            break;
        
        case 7:
            printf("\nEnter element you want to search");
            scanf("%d", &ele);
            address = search(ele);
            printf("\nAddress of %d is %p", ele,address);
            break;
        
        case 8:
            display();
            break;

        case 9:
            reverse();
            break;

        case 10:
            exit(0);
        
        default:
            printf("\nInvalid choice.");
    }


}
}
