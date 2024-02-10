// Implementation of Bubble Sort

#include<stdio.h>
#include<stdlib.h>

#define ARRAY_SIZE 8
// Order defines ascending (1) or descending (-1)
#define ORDER -1

void print_label(const char *label)
{
    printf("\n%s\n", label);
}

void print_array(int *data, int count)
{
    printf("[");
    for(int i=0;i<count;i++)
    {
        printf("%d,\t", *(data+i));
    }
    printf("]\n");
}

int* get_input_data(int size)
{
    int *temp = malloc(sizeof(int)*size);
    int ind = 0;
    do
    {
        printf("%d - ", ind+1);
        scanf("%d", &temp[ind]);
        ind++;
    }while(ind<size);
    return temp;
}

void swap(int *a, int *b)
{
    int temp = *(a);
    *(a) = *(b);
    *(b) = temp;
}

void _bubblesort(int *target, int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=i;j<size;j++)
        {
            if((*(target+i)-*(target+j))*ORDER >= 0)
            {
                swap((target+i), (target+j));
            }
        }
    }
}

int main()
{   
    print_label("Implementation of Bubble Sort");
    print_label("Enter elements for sorting");
    int *data = get_input_data(ARRAY_SIZE);

    _bubblesort(data, ARRAY_SIZE);

    print_label("After Sorting data in array are as:");
    print_array(data, ARRAY_SIZE);

    return 0;
}