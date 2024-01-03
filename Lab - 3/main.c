// Implementation of Circular Queue

#include<stdio.h>
#include<stdlib.h>

#define MENU_ITEM_COUNT 6
#define MAX_QUEUE_SIZE 5

const char* menuItems[] = {
    "Enqueue",
    "Dequeue",
    "Display Front Element",
    "Display All Elements",
    "Element Count",
    "Exit"
};

typedef struct CircularQueue 
{
    int *data;
    int front;
    int rear;
}CQueue;

void init_queue(CQueue *target, int mcap)
{
    target->data = (int*)malloc(sizeof(int)*mcap);
    target->front = 0;
    target->rear = 0;
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

void Enqueue(CQueue *target, int data)
{
    if(target->front == (target->rear+1)%MAX_QUEUE_SIZE)
    {
        printf("\nCircular Queue already full");
        return;
    }
    target->rear++;
    target->rear %= MAX_QUEUE_SIZE;
    target->data[target->rear] = data;
}

void Dequeue(CQueue *target)
{
    if(target->front == target->rear)
    {
        printf("\nCircular Queue is empty!");
        return;
    }

    target->front++;
    target->front %= MAX_QUEUE_SIZE;
    printf("\nDequeued element is : %d", target->data[target->front]);
}

void Display_Front(CQueue *target)
{
    if(target->front == target->rear)
    {
        printf("\nCircular Queue is empty!");
        return;
    }
    printf("\nThe Front element is : %d", target->data[target->front+1]);
}

void Display(CQueue *target)
{
    if(target->front == target->rear)
    {
        printf("\nCircular Queue is empty!");
        return;
    }

    int _front = target->front;
    printf("\nThe elements of Ciruclar Queue are as : \n");
    while(_front != target->rear)
    {
        ++_front;
        _front %= MAX_QUEUE_SIZE;
        printf("%d\t", target->data[_front]);
    }
}

void Display_Count(CQueue *target)
{
    if(target->front == target->rear)
    {
        printf("\nCircular Queue is empty!");
        return;
    }

    int _front = target->front, count = 0;
    while(_front != target->rear)
    {
        ++_front;
        _front %= MAX_QUEUE_SIZE;
        count++;
    }
    printf("\nThe Element Count of Ciruclar Queue is : %d\n", count);
}

int main()
{
    CQueue mainQueue;
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
            printf("Program Exited");
            break;
            default:
            printf("\nInvalid menu choice! Try again!\n");
            break;
        }
    }    
}
