// Implementation of Selection sort

#include<stdio.h>
#include<stdlib.h>

#define ARRAY_SIZE 6
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

void _selectionsort(int *target, int size)
{
    int min_ind = 0;
    for(int i=0;i<size;i++)
    {
        min_ind = i;
        for(int j=i+1;j<size;j++)
        {
            if((*(target+min_ind) - *(target+j))*ORDER >= 0)
            {
                min_ind = j;
            }
        }
        if(min_ind != i)
        {
            swap((target+min_ind), (target+i));
        }
    }
}

int main()
{
     print_label("Implementation of Selection Sort");
    print_label("Enter elements for sorting");
    int *data = get_input_data(ARRAY_SIZE);

    _selectionsort(data, ARRAY_SIZE);

    print_label("After Sorting data in array are as:");
    print_array(data, ARRAY_SIZE);

    return 0;
}