---
layout: default
---
 <!--
<p align="center">
<h1 align="center" style="font-color:white"><img src="https://raw.githubusercontent.com/ramdeoshubham/macros/gh-pages/fav/favicon-96x96.png"><br>#macros.h</h1><p align="center">Useful C #macros<br>
   a href="http://ramdeoshubham.com/macros"><strong>Visit macros &raquo;</strong></a></p
</p>

<!--#[![Open Source Love](https://badges.frapsoft.com/os/v2/open-source.svg?v=103)](https://github.com/ellerbrock/open-source-badges/)
#[![MIT Licence](https://badges.frapsoft.com/os/mit/mit.svg?v=103)](https://opensource.org/licenses/mit-license.php)
#[![Build Status](https://travis-ci.org/ramdeoshubham/macros.svg?branch=master)](https://travis-ci.org/ramdeoshubham/macros)
#[![Codacy Badge](https://api.codacy.com/project/badge/Grade/93283a93f08e4fbc951b9629af11ae9f)](https://www.codacy.com/app/ramdeoshubham/macros?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=ramdeoshubham/macros&amp;utm_campaign=Badge_Grade)

This is a collection of commonly used C Macros I found on internet, and as suggested by my friends.
-->

## Why this is awesome

Using C Macros, we can extend C with a lot of useful functionality. For example, we can create loops like foreach which are very useful and handy when it comes to arrays. These are available in most of high level languages but not in C. But we got macros in C and so we can add on our own!

### How to use

Just download macros.h from [here](https://github.com/ramdeoshubham/macros/archive/master.zip) and include it to the top.

```C
#include "macros.h"
```

Note that there is an `ASSERT` macro useful for debugging purposes. To enable it, you need to `#define DEBUG` before including `macros.h`.

# Available macros

### Boolean

- TRUE
- FALSE

We get `TRUE` as `1` and `FALSE` as `0`.

```C
  while (TRUE) {
    if( (x > 5) == FALSE ) break;
    x++; printf("hi ");
  }
```

### Operators

- AND       
- OR        
- NOT       
- NOTEQUALS
- EQUALS    
- IS

These can be used to perform logical operations more conveniently. Specially, `==` is `EQUALS` and `=` is `IS`. So the age old confusion gets clear here.

```C
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
```

### Loops

- FOREVER

A simple infinite loop. It needs to be break from the scope to stop it.

```C
FOREVER{
  if( x > 5 ) break;
  x++;printf("hi ");
}
```

- RANGE (var, from, to)

A simple from - to ranged loop.  

```C
int i;
RANGE (i, 10, 20){
  printf("%d ", i);
}

/* OUTPUT:
   10 11 12 13 14 15 16 17 18 19 20 */
```

It works in both direction way without any modifications required. It will decide on its on when to decrement or increment. Its smart isn't it?

```C
int i;
RANGE (i, 5, -5){
  printf("%d ", i);
}

/* OUTPUT:
   5 4 3 2 1 0 -1 -2 -3 -4 -5 */
```

- FOREACH (item, array)

A C implementation of foreach loop, it will go through each element of an array, and will perform operations on each element as returned into pointer item variable.

```C
STRING A[] = {"apple", "banana", "orange", "grapes"};
FOREACH (STRING *i, A){
  printf("I love %s\n", *i);
}

/* OUTPUT:
   I love apple
   I love banana
   I love orange
   I love grapes */
```

See also `STRING` in strings section.

Obviously, for single line statements, `{}` are not required.

### Math

There are a lot of macros for mathematical purposes.

- PI                  
- RAD2DEG(x)         
- DEG2RAD(x)

These can be used to convert angles, where PI is a constant.

```C
printf("%d ", RAD2DEG(PI) );

/* OUTPUT:
   180 */
```

- ALIGNB(x, align)    
- ALIGN(x, align)     
- FLOORB(x, align)    
- FLOOR(x, align)     
- CEILB(x, align)     
- CEIL(x, align)      
- CLIP(x, min, max)   
- UCLIP(x, max)       
- LCLIP(x, min)     
- MIN(x, y)          
- MAX(x, y)          
- ABS(x)              
- DIFF(a,b)

Functioning of above Macros are quite obvious. **(TL;D write!)**          

- ISNAN(x)            

For example, ISNAN (0.0/0.0), It Checks if x is NOT A NUMBER.

- IMPLIES(x, y)       

- SWAP(a, b)          
- SORT(a, b)

These two are interesting. Also if you look at their #defines, they don't have any temporary variable.

```C
int x = 10, y = 5, z = 0;
SORT(x,y); /*now x should be smaller one*/
SWAP(x,z); /*now z and x swaps */
printf("%d", z);

/* OUTPUT:
   5 */

```

- COMPARE(x, y)       
- SIGN(x)        

Returns `1` on positive and `-1` on negative.     

- IS_ODD( num )       
- IS_EVEN( num )      
- IS_BETWEEN(n,L,H)   

For example:

```C
int x;
printf("Enter a num: ");
scanf("%d", &x);
if ( IS_EVEN (x) && IS_BETWEEN(x, 0, 20) ){
  printf("working... \n");
}

/* OUTPUT:
   Enter a num: 12
   working...*/

```


### Bits

- BIT(x)          
- SETBIT(x,p)     
- CLEARBIT(x,p)   
- GETBIT(x,p)     
- TOGGLEBIT(x,p)  

People use constant 1024 many times, now you can get it simply by `BIT(10)`.

### Arrays

- ARRAY_SIZE(a)
- SET(d, n, v)
- ZERO(d, n)
- COLUMNS(S,E)
- IS_ARRAY(a)   

```C
int arr[] = {1,2,3,4,5,6,7,8,9,10};
if(IS_ARRAY(arr)) {
  SET(arr, ARRAY_SIZE(arr)-4, 10);
  ZERO(arr, 3);
}
RANGE(x, 0, 9) printf("%d ", arr[x]);

/* OUTPUT:
0 0 0 10 10 10 7 8 9 10 */
```

### Strings

- STRING

Its translates to char*.

```C
STRING x = "hello";
STRING list[] = {"book", "ball", "bucket"};
```

- CAT(str1, str2)

Concatenation of two pure strings.

 ```C
 puts ( CAT ("PenPineapple", "ApplePen") );

 /* OUTPUT:
    PenPineappleApplePen */
 ```

- STR(s)

Expands s as a string.

```C
puts ( STR (This is a fruit) );

/* OUTPUT:
   This is a fruit */
```

### Tokens

- PASTE(a,b)
- PRINT_TOKEN(token)

```C
a = 10;
b = 20;
ab = 0;
x = PASTE(a,b);
PRINT_TOKEN( x );

/* OUTPUT:
   x is 0 */
```

### Debugging

- LOG (x, fmt, ...)
- TRY (x, s)
- ASSERT (n)

ASSERT Macro will require DEBUG to be defined. Also on error, it will return -1 to exit. TRY performs x. Only on error, it shows custom error message. LOG is reverse, it produces message on success of x.

```C
#define DEBUG /* To use ASSERT */
#include "macro.h"
...
  LOG(x=5,"Now square of x is %d", x*x);
  TRY(0>10, "We already knew its an error\n");
  ASSERT(1>2);

/* OUTPUT:
   test.c@125: Now square of x is 25
   test.c@127: We already knew its an errortest.c@138: `1>2` - Failed | Compilation: Jun 14 2022 10:20:12
```

### Saturation

- SATINC(v,L)
- SATDEC(w,L)

A saturating macro which does v++ and w-- respectively on every call, and does nothing on reaching L limit.

```C
a = 0, b = 7;
for(x=0; x<10; x++){
  SATINC(a,7);
  SATDEC(b,0);
  printf("%d %d, ",a,b);
}

/* OUTPUT:
   1 6, 2 5, 3 4, 4 3, 5 2, 6 1, 7 0, 7 0, 7 0, 7 0, */
```

### Statements

- STMT(stuff)

Macros involving multiple statements needs braces which are safer to define with a do_while(0) for single execution. STMT expands statements the same way.

```C
STMT (printf("it should be in a macro...\n"););
```

- ONCE ( stmts )

This Macro make it sure that the statements within it are performed only once.

```C
a = 1;
RANGE(x,0,10) {
/*ONCE(*/
  a++;
/*);*/
}
printf("%d\n", a);

/* With ONCE */
a = 1;
RANGE(x,0,10) {
ONCE(
  a++;
);
}
printf("%d\n", a);

/* OUTPUT:
   12
   2 */
```

See also `FOREVER` in Loops section.

- DEFER

Run an init and a cleanup statement. The init, cleanup and block statements are all under the same scope. One line statements are fine without braces.

```
/* DEFER */
DEFER(FILE *f = fopen("file.txt", "w+"), fclose(f)) {
    fprintf(f, "I love %s!\n", "coffee");
}
```

### Extern C

- EXTERN_C_START
- EXTERN_C_END

These macros are for C++ users. To compile a piece of C code in C++ environment, you can use these macros as follows:

```C
//somecppfile.cpp

// CPP
EXTERN_C_START

    /* C */

    #include <stdio.h>
    int main(void)
    {
      int new = 10;
      printf("%d", new);
    }

EXTERN_C_END
// CPP

/* OUTPUT:
   10 */
```

As 'new' is a C++ keyword, this would never be compiled with a C++ compiler, but its valid in C. So we used those macros to mix C in C++.

### Functions shorthands

- MAIN()

A shorthand for `int main (int argc, const char **argv)`

- NOW()

A shorthand `time(NULL)`. Please do note that `#include <time.h>` is required for the time related types.

## Contribute

The source is very clear and the macros available are too common you will find them everywhere. A good Macro is : Portable, safe, involves as less arbitrary variables as possible. Although I am trying my best, there might be some exception errors, please correct if you find any. Also, if I missed some other interesting macros, please contribute to make this collection complete and more usable.

### Conventions

1. All macros are in UPPERCASE.
2. In case of any Boolean Macro, the `IS_ prefix` should be used. For example, `IS_EVEN(x)`. And they should return a `1` or `0` value.
3. Macros for loops and conditionals should not end with braces so that the user can have the option for single line as well as block style.
4. A helper macro, which are expanded by some other main macro, usually they are not intended to be used directly. So they should be mentioned with their expansion level as prefix. For example, `PASTE(a,b)` expands into `PASTE2(a,b)` which further expands into `a##b`.

## Credit

>The real credits goes to all those great C coders who came up with such creative use of C Macros to extend C. I made this collection in honor of The C language and those unknown programmers. I can only take credit for the efforts I made to collect and bringing it to you.

### Contributors ✨

<a href="https://github.com/ramdeoshubham/macros/graphs/contributors">
  <img src="https://contrib.rocks/image?repo=ramdeoshubham/macros" />
</a>

<!--Made with [contrib.rocks](https://contrib.rocks).-->

## License

Copyright 2017, Shubham Ramdeo. Code released under the [MIT License](https://github.com/ramdeoshubham/macros/blob/master/LICENSE).


>#Handpicked C #Macros with &hearts; #love !

Don't forget to [&#9733;`STAR`](https://github.com/ramdeoshubham/macros) if you like it.
