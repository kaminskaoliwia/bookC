#include <stdio.h>

char *month_name(int n);

int main()
{
    char* n = month_name(5);
    printf("%s\n", n);
    char* s = month_name(13);
    printf("%s\n", s);
    return 0;
}

char *month_name(int n)
{
    static char *name[] = {
        "Illegal month", 
        "January", "February", "March",
        "April", "May", "June",
        "July", "August", "September",
        "October", "November", "December"
    };

    return( n < 1 || n > 12) ? name[0] : name[n];
}

