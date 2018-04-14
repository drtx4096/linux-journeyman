#include <stdio.h>

extern "C" int otherFunction( int val )
{
    return 23 ;
}

int myGlobInt = 12;

int buzz( void )
{
   int intVal ;

   intVal = myGlobInt + otherFunction( 5 ) ;

   return intVal ;
}

int main( )
{
   printf( "buzz: %d\n", buzz() ) ;

   return 0 ;
}
