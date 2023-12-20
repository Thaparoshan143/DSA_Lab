#include<stdio.h>
#include<stdlib.h>

#define MENU_ITEM_COUNT 6
#define MAX_QUEUE_SIZE 5

const char* menuItems[] = {
    "Enqueue",
    "Dequeue",
    "Display Front",
    "Display",
    "Element Count",
    "Exit"
};

typedef struct Queue 
{
    int *data;
    int front;
    int rear;
}Queue;

void init_queue(Queue *target, int mcap)
{
    target->data = (int*)malloc(sizeof(int)*mcap);
    target->front = target->rear = 0;
}

void Enqueue(Queue *target, int data)
{
    if(target->rear>=MAX_QUEUE_SIZE)
    {
        printf("\n** Queue is already full **\n");
        return;
    }
    else
    {
        target->data[target->rear] = data;
        target->rear++;
    }
}

void Dequeue(Queue *target)
{   
    if(target->front>=target->rear)
    {
        printf("\n ** Queue Empty **\n");
        return;
    }
    else
    {
        printf("\nDequeued element is : %d\n", target->data[target->front]);
        target->front++;
    }
}

void Display_Front(Queue *target)
{
    if(target->front == target->rear)
    {
        printf("\n ** No element in Queue **\n");
        return;
    }
    else
    {
        printf("\nFront Element is : %d\n", target->data[target->front]);
    }
}

void Display(Queue *target)
{
    if(target->front == -1)
    {
        printf("\n ** No element in Queue **\n");
        return;
    }
    else
    {
        printf("\n# Queue Elements are : \n");
        for(int i=target->front;i<target->rear;i++)
        {
            printf("%d\t|\t", *(target->data+i));
        }
        printf("\n");
    }
}

void Display_Count(Queue *target)
{
    printf("\n# Queue Element Count is : %d\n", target->rear-target->front);
}

void display_menu()
{
    printf("\n==> Main Menu <==\n");
    for(int i=0;i<MENU_ITEM_COUNT;i++)
    {
        printf("%d . %s\n", i+1, menuItems[i]);
    }
    printf("-----------------------------------------\n");
}


int main()
{
    Queue mainQueue;
    init_queue(&mainQueue, MAX_QUEUE_SIZE);
    
    int exit_status = 0, choice = 0;
    while(!exit_status)
    {
        display_menu();
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            printf("Enter a number : ");
            scanf("%d", &choice);
            Enqueue(&mainQueue, choice);
            choice = 0;
            break;
            case 2:
            Dequeue(&mainQueue);
            break;
            case 3:
            Display_Front(&mainQueue);
            break;
            case 4:
            Display(&mainQueue);
            break;
            case 5:
            Display_Count(&mainQueue);
            break;
            case 6:
            exit_status = 1;
            printf("Exiting program");
            break;
            default:
            printf("\nInvalid menu choice! Try again!\n");
            break;
        }
    }    

    return 0;
}
