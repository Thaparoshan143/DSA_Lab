// Implementation of Binary Search

#include<stdio.h>
#include<stdlib.h>

#define ARRAY_SIZE 10

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

int get_int_input(const char *title)
{
    int temp;
    printf("%s", title);
    scanf("%d", &temp);
    return temp;
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

int _binary_search(int *arr, int size, int val)
{
    int l = 0, r = size-1, mid;
    while(l <= r)
    {
        mid = l + (r - l) / 2;

        if(arr[mid] == val)
        {
            printf("Element %d found in array in index %d\n", val, mid);
            return val;
        }

        if(arr[mid] > val)
        {
            r = mid;
        }
        else
        {
            l = mid+1;
        }
    }

    print_label("Cannot find the element in the array");
    return -1;
}

int main()
{   
    print_label("First populate the data in array");
    int *data = get_input_data(ARRAY_SIZE);

    print_label("Elements are as:");
    print_array(data, ARRAY_SIZE);
    int val = get_int_input("Enter element to search in array : ");
    _binary_search(data, ARRAY_SIZE, val);
    
    return 0;
}