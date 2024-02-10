// Implementation of Merge Sort
#include<stdio.h>
#include<stdlib.h>

#define ARRAY_SIZE 10

void print_label(const char *label)
{
    printf("\n%s\n", label);
}

void print_array(int *data, int count)
{
    for(int i=0;i<count;i++)
    {
        printf("%d - %d\n", i+1, *(data+i));
    }
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

void _mergehelper(int *target, int left, int mid, int right)
{
    int i = 0, j = 0, k = 0;
    int n1 = mid - left + 1, n2 = right - mid;

    int arrl[n1], arrr[n2];

    for(int i=0;i<n1;i++)
    {
        arrl[i] = *(target+left+i);
    }

    for(int i=0;i<n2;i++)
    {
        arrr[i] = *(target+mid+1+i);
    }

    k = left;

    while(i < n1 && j <n2)
    {
        if(arrl[i] <= arrr[j])
        {
            *(target + k) = arrl[i];
            i++;
        }
        else
        {
            *(target + k) = arrr[j];
            j++;
        }
        k++;
    }

    while(i < n1)
    {
        *(target + k) = arrl[i];
        k++;
        i++;
    }

    while(j < n2)
    {
        *(target + k) = arrr[j];
        k++;
        j++;
    }
}

void _mergesort(int *target, int left, int right)
{
    if(left<right)
    {
        int mid = left + (right-left)/2;
        _mergesort(target, left, mid);
        _mergesort(target, mid+1, right);

        _mergehelper(target, left, mid, right);
    }
}

int main()
{
    print_label("Use of Merge sort");
    print_label("Enter elements for sorting");
    int *data = get_input_data(ARRAY_SIZE);

    _mergesort(data, 0, ARRAY_SIZE-1);

    print_label("After Sorting data in array are as:");
    print_array(data, ARRAY_SIZE);

    return 0;
}