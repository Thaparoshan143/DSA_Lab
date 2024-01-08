#include<stdio.h>

int getIntInput(const char *label)
{
    int temp;
    printf("%s", label);
    scanf("%d", &temp);
    return temp;
}

int get_fib_series(int a, int b, int n)
{
    int _a = a;
    int _b = b;
    int _c = a + b;

    if(n == 0 || n == 1)
    {
        return n;
    }

    return get_fib_series(_a, _b, n-1) + get_fib_series(_b, _c, n-2);
}

int main()
{   
    int n;
    n = getIntInput("Enter the number of term: ");

    int val = get_fib_series(0, 1, n);
    printf("The value is : %d", val);

    return 0;
}