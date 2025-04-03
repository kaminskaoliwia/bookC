
// DO DOKOŃCZENIA!

#include <stdhio.h>
#include <string.h>

#define MACLINES 5000
#define MAXLEN 1000 // max length of an input line

char *lineptr[MAXLINES]; // pointers to text lines

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

int getline(char*, int);
char *alloc(int);

/* Since pointers are variables themselves, they can be stored in arrays just as 
other variables can. Writing a program that will sort text lines into an alphabetic order 

The same algorithms (sorts) will work, but we have to deal with lines of text, which are of different lengths
and unlike integers can't be compared with a single operation

the sorting proccess has three steps:
read all the lines of input
sort them
print them in order
*/

int main()
{
    int nlines; // number of input lines read

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0){
        qsort(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return 0;
    }
    else    {
        printf("error: input too big to sort!!\n");
        return 1;
    }

}

int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines=0;

    // do dokończenia

}