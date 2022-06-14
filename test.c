/**
    MACROS
    test.c
    Purpose: This file demostrates examples usage of macros.h.

    @author Shubham Ramdeo
    @version 0.2

    Released under MIT LICENSE (see LICENSE.txt)
*/

/* I believe we need a better example file...! */
/* MORE Comming soon... */


#include <stdio.h>
#include <time.h>

/* For ASSERT macro to work */
#define DEBUG

#include "macros.h"

/* If you compile this file with a C++ compiler, this will make it work*/
EXTERN_C_START

MAIN () {

  int x = 0, a, b, ab;

  /* Boolean */

  while (TRUE) {
    if( (x > 5) == FALSE ) break;
    x++; printf("hi ");
  }

  /* Operators */

  x = 5;
  if( x EQUALS 0 OR x > 10 AND x NOTEQUALS 15)
  {
    x IS 1;
  }
  else if ( NOT (x > 0) ) {
    x IS 0;
  }
  else x IS 100;
  printf("\n%d\n",x);

  /* Loops */

  FOREVER{
  if( x > 5 ) break;
  x++;printf("hi ");
  }

  RANGE(x, 10, 20){
  printf("%d ", x);
  }

  RANGE (x, 5, -5){
    printf("%d ", x);
  }

  STRING A[] = {"apple", "banana", "orange", "grapes"};
  FOREACH (STRING *si, A){
    printf("I love %s\n", *si);
  }

  /* ARRAYS */
  int arr[] = {1,2,3,4,5,6,7,8,9,10};
  if(IS_ARRAY(arr)) {
    SET(arr, ARRAY_SIZE(arr)-4, 10);
    ZERO(arr, 3);
  }
  RANGE(x, 0, 9) printf("%d\n", arr[x]);

  /* STRINGS */
  STRING sss = "hello";
  STRING list[] = {"book", "ball", "bucket"};

  puts ( CAT ("PenPineapple", "ApplePen") );
  puts ( STR (This is a fruit) );

  /* TOKEN */
  a = 10;
  b = 20;
  ab = 0;
  x = PASTE(a,b);
  PRINT_TOKEN( x );

  /* STMT */
  STMT (printf("it should be in a macro...\n"););

  /*Saturating -- and ++ */
  a = 0, b = 7;
  for(x=0; x<10; x++){
    SATINC(a,7);
    SATDEC(b,0);
    printf("%d %d, ",a,b);
  }

  /* Once */

  /* without ONCE */
  a = 1;
  RANGE(x,0,10) {
  /*ONCE(*/
    a++;
  /*);*/
  }
  printf(" %d ", a);

  /* With ONCE */
  a = 1;
  RANGE(x,0,10) {
  ONCE(
    a++;
  );
  }
  printf(" %d ", a);


  LOG(x=5,"Now square of x is %d", x*x);

  TRY(0>10, "We already knew its an error\n");

  /* DEFER */
  DEFER(printf("Before DEFER. Already inside. ["), printf("] After DEFER. Still inside.\n")) {
    printf("] Inside DEFER. [");
  }

  /* NOW */
  printf("UNIX epoch: %lu\n", NOW);

/* ASSERT will return -1 therefore its intentionally placed at the end. */
  ASSERT(1>2); 

  return 0;
}

EXTERN_C_END
