
#include <stdio.h>

int strlen( char *s );

#define ALLOCSIZE 1000 // size of available space
static char allocbuf[ALLOCSIZE]; // storage for alloc
static char *allocp = allocbuf; // next free position
char *alloc(int n);
void afree(char *p);

void strcpyARRAY(char *s, char *t);
void strcpyPTRS(char *s, char *t);
void strcpyCORRECT(char *s, char *t);

int main()
{
// 5.1 pointers and addresses

int x = 1, y =2, z[10];
printf("Przed: x = %d, y = %d\n", x, y);
int* ip; // ip is a pointer to int
ip = &x; // ip now points to x
y = *ip; // y is now 1
*ip = 0; // x is now 0
printf("Po: x = %d, y = %d\n", *ip, y);


ip = &z[10]; // ip now points to z[0]

// if ip points to the integer x, then *ip can occur in any context where 5 could, so:
*ip = *ip + 10; // increments *ip by 10
printf("x zwiększył się o 10: %d\n", x);
// * and & bonds more tightly than arithmetic operators, so y will be incremented by 1
y = *ip + 1;
printf("%d\n", y);

// increments what ip POINTS TO
++*ip;
*ip+=1;
(*ip)++; //parentheses needed because unary operators associate right to left

// 5.3 pointers and arrays

int a[10];
int *pa;
pa = &a[0];
x = *pa;

*(pa+1); // points to a[1]

// since thr name of an array is a synonym for the location of the initial element is a synonym
// for the location of the initil element pa=&a[0] can be written as:
pa = a;

// the difference between pointers and array names is that pointers are variables
pa = a;
pa++;
// ale legal but a = pa; and a++; are illegal

strlen("hello, world"); // string constant

// 5.4 Address Arithmetic
/* rudimentary(prymitywny) storage allocator
 the easiest implementation is to have alloc hand out pieces 
 of large character array we will call allocbuf
 we use a pointer called allocp, that points to the next free element
 when alloc is asked for n characters, it checks if there is enough
room left in allocbuf, if so alloc returns the current value of allocp
(the beginning of the free block) and increments to the next free area
 */

// 5.5 Character Pointers and Functions
// copies string t into string s, s=t copies the pointer not the character

return 0;
}

int strlen( char *s ) // 5.3
{
    int n;

    for( n=0; *s != '\0'; s++)
        n++;
    return n;
}

char *alloc(int n) // 5.4; returns pointer to n characters
{
    if (allocbuf + ALLOCSIZE - allocp >= n){    // it fits
        allocp += n;
        return allocp - n; // old pointer
    }
    else  // not enough room
        return 0;
}

void afree(char *p)
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE) // free storage pointed to by p
        allocp = p;
}

void strcpyARRAY(char *s, char *t)
{
    int i = 0;
    while ((s[i] = t[i]) != '\0')
        i++;

}

void strcpyPTRS(char *s, char *t)
{
    while ((*s = *t) != '\0')   {
        s++;
        t++;
    }

}

void strcpyCORRECT(char *s, char *t)
{
    while (*s++ = *t++) // != 0 is redundant because it will end at the same time
    ;

}