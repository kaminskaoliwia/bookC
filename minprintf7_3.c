
#include <stdarg.h> 
#include <iostream>

/* contains a set of macro definitions that define how to step through an argument list 
va_list is used to declare a variable that will refer to each argument in turn
va_start initializes ap to point to the first unnamed argument !it must be called once ap is used
!there must be at least one names argument. Each call of va_arg returns one argument
and steps ap to the next. va_arg uses a type name to determine what to return. 
va_end does clean up, must be called before the function returns*/

void minprintf( const char *fmt, ... );

void minprintf( const char *fmt, ... )
{
  va_list ap;
  char *p;
  char *sval;
  int ival;
  double dval;

  va_start(ap, fmt);
  for(p = fmt; *p; p++) {
    if( *p != '%' ) {
      putchar(*p);
      continue;
    }
    switch (*++p) {
    case 'd': ival = va_arg(ap, int); printf("%d", ival); break; 
    case 'f': ival = va_arg(ap, double); printf("%f", dval); break;
    case 's':
      for(sval = va_arg(ap, char*); *sval; sval++ )
        putchar(*sval);
      break;
    default:
      putchar(*p); break;
    }
  }
  va_end(ap);
}