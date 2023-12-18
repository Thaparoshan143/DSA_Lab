#include<stdio.h>
#include<stdlib.h>

#define MENU_ITEM_COUNT 6
#define STACK_MAX_CAP 5

const char* menuItems[] ={
    "PUSH",
    "POP",
    "Display",
    "Element Count",
    "Peek",
    "Exit"
};

typedef struct Stack
{
    int *data;
    int top;
}Stack;

void init_stack(Stack *target, int mcap)
{
    target->top = mcap-1;
    target->data = malloc(sizeof(int)*mcap);
}


void Push(Stack *target, int data)
{
    if(target->top == -1)
    {
        printf("\n# Stack is full cannot add more\n");
        return;
    }
    else
    {
        *(target->data+target->top) = data;
        target->top--;
    }
}

void Pop(Stack *target)
{
    if(target->top+1>=STACK_MAX_CAP)
    {
        printf("\n** Stack Empty **\n");
        return;
    }
    else
    {
        target->top++;
        printf("%d\n", target->data[target->top]);
    }
}

void Display(Stack *target)
{
    if(target->top+1>=STACK_MAX_CAP)
    {
        printf("\n** Stack Empty **\n");
        return;
    }
    printf("\n-- Stack elements are as --\n");
    for(int i=target->top+1;i<STACK_MAX_CAP;i++)
    {
        printf("%d\t", target->data[i]);
    }
    printf("\n");
}

void Element_Count(Stack *target)
{
    printf("\n# Stack element count : %d\n", STACK_MAX_CAP - target->top - 1);
}

void Peek(Stack *target)
{
    if(target->top+1>=STACK_MAX_CAP)
    {
        printf("\n** Stack Empty **\n");
        return;
    }
    printf("\n# Peek/Top element on the stack is : %d\n", target->data[target->top+1]);
}

void display_menu()
{
    printf("\n==> Menu <==");
    for(int i=0;i<MENU_ITEM_COUNT;i++)
    {
        printf(" \n%d . %s", i+1, menuItems[i]);
    }
    printf("\n-----------------------------------------------\n");
}

int main()
{

    Stack mainStack;
    init_stack(&mainStack, STACK_MAX_CAP);

    int choice = 0;
    int exit_status = 0;
    while(exit_status==0)
    {
        display_menu();
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            printf("Enter number to push in stack : ");
            scanf("%d", &choice);
            Push(&mainStack, choice);
            choice = 0;
            break;
            case 2:
            Pop(&mainStack);
            break;
            case 3:
            Display(&mainStack);
            break;
            case 4:
            Element_Count(&mainStack);
            break;
            case 5:
            Peek(&mainStack);
            break;
            case 6:
            printf("Exiting program\n");
            exit_status = 1;
            break;
            default:
            printf("Invalid choice ! Try again");
            break;
        }
    }
    
    printf("Program Terminating!");
    return 0;
}