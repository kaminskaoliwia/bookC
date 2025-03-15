#include <stdio.h>

void swap_incorrect(int x, int y);
void swap(int *px, int *py);
/* C passes argument to functions by value, so you cannot alter the variable in the calling function*/

int main()
{
    int a = 6;
    int b = 4;
    printf("Przed zamianą: a = %d, b = %d\n",a ,b);
    swap_incorrect(a,b);
    printf("Zamiana niepoprawna: a = %d, b = %d\n", a, b);
    swap(&a, &b); // & - assigns a pointer to a variable
    printf("Zamiana poprawna: a = %d, b = %d", a, b);
    return 0;
}

void swap_incorrect(int x, int y) 
{
    int temp;

    temp = x;
    x = y;
    y = temp;
}

void swap(int *px, int *py)
{
    int temp;

    temp = *px;
    *px = *py;
    *py = temp;
}


