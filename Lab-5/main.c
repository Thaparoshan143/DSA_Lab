// Implementation of Singly Linked List

#include<stdio.h>
#include<stdlib.h>

#define MENU_ITEM_COUNT 9

const char *menuItems[] = {
    "Insert at beginning",
    "Delete last node",
    "Traverse and Display",
    "Searching",
    "Insert at the end",
    "Insert at any specific position",
    "Delete first node",
    "Delete any specific node",
    "Exit"
};

typedef struct SinglyNode
{
    int data;
    struct SinglyNode *next;
}SNode;

void seperator(const char symbol, int count)
{
    for(int i=0;i<count;i++)
    {
        printf("%c", symbol);
    }
}

void display_menu()
{
    printf("\n==> MAIN MENU <==\n");
    for(int i=0;i<MENU_ITEM_COUNT;i++)
    {
        printf("%d. %s\n", i+1, menuItems[i]);
    }
    seperator('_', 50);
    printf("\n");
}

int get_int_input(const char *label)
{
    int temp;
    printf("%s", label);
    scanf("%d", &temp);
    return temp;
}

SNode* Get_New_Node(int data)
{
    SNode *temp = (SNode*)malloc(sizeof(SNode));
    temp->next = NULL;
    temp->data = data;
    return temp;
}

int Is_List_Empty(SNode *start)
{
    if(start == NULL)
    {
        printf("\nEmpty Singly List");
        return 1;
    }
    return 0;
}

void Insert_First(SNode **start, int ele)
{
    if(*start == NULL)
    {
        *start = Get_New_Node(ele);
        return;
    }

    SNode *newStart = Get_New_Node(ele);
    newStart->next = *start;
    *start = newStart;
}

void Delete_Last(SNode **start)
{
    if(Is_List_Empty(*start))
    {
        return;
    }

    SNode *temp = *start;
    int count = 0;
    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    temp = *start;
    if(Is_List_Empty((*start)->next))
    {
        free(*(start));
        *start = NULL;
        return;
    }

    for(int i=0;i<count-2;i++)
    {
        *start = (*start)->next;
    }
    free((*start)->next);
    (*start)->next = NULL;
    *start = temp;
}

void Display_Elements(SNode **start)
{
    if(Is_List_Empty(*start))
    {
        return;
    }

    SNode *temp = *start;
    int count = 0;
    while(temp != NULL)
    {
        printf("\n%d element is : %d", count+1, temp->data);
        temp = temp->next;
        count++;
    }
    printf("\nThe element count in the singly list is : %d", count);
}

void Search_Element(SNode **start, int ele)
{
    if(Is_List_Empty(*start))
    {
        return;
    }

    SNode *temp = *start;
    while(temp != NULL)
    {
        if(temp->data == ele)
        {
            printf("Element Found - %d", ele);
            *start = temp;
            return;
        }
        temp = temp->next;
    }
    printf("Element not found in the list");
}

void Insert_End(SNode **start, int ele)
{
    if(Is_List_Empty(*start))
    {
        *start = Get_New_Node(ele);
        return;
    }

    SNode *temp = *start;
    while((*start)->next != NULL)
    {
        (*start) = (*start)->next;
    }
    (*start)->next = Get_New_Node(ele);
    *start = temp;
}

void Insert_At(SNode **start, int ind, int ele)
{
    if(Is_List_Empty(*start))
    {
        return;
    }

    SNode *temp = *start;
    int count = 0;
    while(count<ind-1)
    {
        count++;
        (*start) = (*start)->next;
        if(*start == NULL)
        {
            printf("Given index out of List range!");
            *start = temp;
            return;
        }
    }
    SNode *newNode = Get_New_Node(ele);
    newNode->next = (*start)->next;
    (*start)->next = newNode;
    *start = temp;
}

void Delete_First(SNode **start)
{
    if(Is_List_Empty(*start))
    {
        return;
    }

    SNode *temp = *start;
    *start = (*start)->next;
    free(temp);
}

void Delete_At(SNode **start, int ind)
{
    if(Is_List_Empty(*start))
    {
        return;
    }

    SNode *temp = *start;
    int count = 0;
    while(count<ind-1)
    {
        count++;
        *start = (*start)->next;
        if(*start == NULL)
        {
            printf("Given index out of List range!");
            *start = temp;
            return;
        }
    }
    SNode *newNode = (*start)->next;
    (*start)->next = newNode->next;
    free(newNode);
    *(start) = temp;
}


int main()
{
    SNode *start = NULL;
    int choice, exit_status = 0, ele;

    while(!exit_status)   
    {
        display_menu();
        choice = get_int_input("Enter your choice : ");
        switch(choice)
        {
            case 1:
            choice = get_int_input("Enter element to insert in first : ");
            Insert_First(&start, choice);
            choice = 0;
            break;
            case 2:
            Delete_Last(&start);
            break;
            case 3:
            Display_Elements(&start);
            break;
            case 4:
            choice = get_int_input("Enter element to seach for : ");
            Search_Element(&start, choice);
            choice = 0;
            break;
            case 5:
            choice = get_int_input("Enter element to seach for : ");
            Insert_End(&start, choice);
            choice = 0;
            break;
            case 6:
            choice = get_int_input("Enter the index to insert at : ");
            ele = get_int_input("Enter element : ");
            Insert_At(&start, choice, ele);
            choice = 0;
            break;
            case 7: 
            Delete_First(&start);
            break;
            case 8:
            choice = get_int_input("Enter the index to delete from : ");
            Delete_At(&start, choice);
            choice = 0;
            break;
            case 9:
            printf("Exiting program!");
            exit_status = 1;
            break;
            default: 
            printf("Invalid menu choice! Try again");
            break;
        }
    } 

    return 0;
}