/*
A structure is a collection of one or more variables, possibly of different types
grouped together under a single name for covenient handling. They help to organize 
complicated data
*/

#include <stdio.h>
#include <math.h>

#define X 10
#define Y 10
#define MAXX 20
#define MAXY 30

struct point {
    int x;  // members
    int y;
};

struct rect {
    struct point pt1;
    struct point pt2;
}; //!!!!!!!

struct point makepoint( int x, int y );
struct point addpoint(struct point p1, struct point p2);
int ptinrect(struct point p, struct rect r);

int main()
{
    struct point pt = {X, Y};
    struct point maxpt = {320, 200};
    printf("Maxpt = (%d, %d)\n", maxpt.x, maxpt.y);

    double dist;
    dist = sqrt((double)pt.x * pt.x + (double)pt.y*pt.y);

    // makepoint can be used to initialize any structure dynamically, or to provide structure arguments to a function
    struct rect screen;
    struct point middle;
    screen.pt1 = makepoint(0,0);
    screen.pt2 = makepoint(MAXX, MAXY);

    middle = makepoint((screen.pt1.x + screen.pt2.x)/2, (screen.pt1.y+screen.pt2.y)/2);

    printf("Pierwsza koordynata drugiego punktu screen = (%d)\n", screen.pt2.x);

    if (ptinrect(pt, screen))
    {
        printf("Punkt (%d, %d) znajduje się w środku prostokąta o punktach (%d, %d), (%d, %d)\n",
                pt.x, pt.y, screen.pt1.x, screen.pt1.y, screen.pt2.x, screen.pt2.y);
    }
    else    {
        printf("Punkt (%d, %d) nie znajduje się w środku prostokąta o punktach (%d, %d), (%d, %d)\n",
                pt.x, pt.y, screen.pt1.x, screen.pt1.y, screen.pt2.x, screen.pt2.y);
    }

    /*
    If a structure is to be passed to a function, it is generally more efficient to pass a pointer
    than to copy the whole structure. 
    
    */

    struct point *pp;
    pp = &maxpt;

    printf("Maxpt przy pomocy wskaźników - sposób pierwszy = (%d,%d)\n", (*pp).x, (*pp).y);

    // Pointers are so frequently used that an alternative notation is provided as a shorthand
    printf("Sposób drugi = (%d,%d)\n", pp->x, pp->y);

    /* Both . and -> associate from left to right so all are equivalent:
    r.pt1.x;
    rp->pt1.x
    (r.pt1).x
    (rp->pt1).x

    */
    return 0;
}

// 6.2 Structures and Functions

struct point makepoint( int x, int y ) // zwraca struct point
{
    struct point temp;

    temp.x = x;
    temp.y = y;
    return temp;
}

struct point addpoint(struct point p1, struct point p2)
{
    p1.x += p2.x;
    p1.y += p2.y;

    return p1;  // both the arguments and the return value are structures
}

// return 1 if p in r, 0 if not
int ptinrect(struct point p, struct rect r)
{
    return p.x >= r.pt1.x && p.x < r.pt2.x && p.y >= r.pt1.y && p.y < r.pt2.y;
}

