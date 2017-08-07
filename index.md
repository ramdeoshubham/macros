---
layout: default
---

### Hand picked C Macros!

This is a collection of commonly used C Macros I found on internet, and as suggested by my friends.

#### How to use

Just download **macros.h** from **[here](https://github.com/ramdeoshubham/macros/archive/master.zip)** and include it to the top.

```C
#include "macros.h"
```

### Available macros

#### Boolean

- TRUE
- FALSE

> We get `TRUE` as `1` and `FALSE` as `0`.

```C
while (TRUE) {
  if( (x > 6) == FALSE ) break;
}
```

#### Operators

- AND       
- OR        
- NOT       
- NOTEQUALS
- EQUALS    
- IS

> These can be used to perform logical operations more conveniently. Specially, `==` is `EQUALS` and `=` is `IS`. So the age old confusion gets clear here.

```C
int x;
scanf("%d", x);
if( x EQUALS 0 OR x > 10 AND x NOTEQUALS 15)          
{
  x IS 1;
}
else if ( NOT (x > 0) ) {
  x IS 0;
}
```

#### Loops

- FORVER

> A simple infinite loop. It needs to be break from the scope to stop it.

```C
FOREVER{
  if( x > 10 ) break;
  x++;
}
```

- RANGE (var, from, to)

> A simple from - to ranged loop.  

```C
int i;
RANGE (i, 10, 20){
  printf("%d ", i);
}

/* OUTPUT:
   10 11 12 13 14 15 16 17 18 19 20 */
```

> It works in both direction way without any modifications required. It will decide on its on when to decrement or increament. Its smart isn't it?

```C
int i;
RANGE (i, 5, -5){
  printf("%d ", i);
}

/* OUTPUT:
   5 4 3 2 1 0 -1 -2 -3 -4 -5 */
```

- FOREACH (item, array)

> A C implementation of foreach loop, it will traverse each element of array, and can do operations on each element as returned into pointer item variable.

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


#### Math

There are a lot of macros for mathematical purposes.

- PI                  
- RAD2DEG(x)         
- DEG2RAD(x)

> These can be used to convert angles, where PI is a constant.

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
- ISNAN(x)            
- IMPLIES(x, y)       

- SWAP(a, b)          
- SORT(a, b)          

- COMPARE(x, y)       
- SIGN(x)             

- IS_ODD( num )       
- IS_EVEN( num )      
- IS_BETWEEN(n,L,H)   

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


#### Bits

- BIT(x)          
- SETBIT(x,p)     
- CLEARBIT(x,p)   
- GETBIT(x,p)     
- TOGGLEBIT(x,p)  

#### Arrays

- ARRAY_SIZE(a)
- SET(d, n, v)
- ZERO(d, n)
- COLUMNS(S,E)
- IS_ARRAY(a)   

#### Strings

- STRING

> Its translates to char*.

```C
STRING x = "hello";
STRING list[] = {"book", "ball", "bucket"};
```

- CAT(str1, str2)

> Concatenation of two pure strings.

 ```C
 puts ( CAT ("PenPineapple", "ApplePen") );

 /* OUTPUT:
    PenPineappleApplePen */
 ```

- STR(s)

> Expands s as a string.

```C
puts ( STR (This is a fruit) );

/* OUTPUT:
   This is a fruit */
```

#### Tokens

- PASTE(a,b)
- PRINT_TOKEN(token)

#### Debugging

- LOG (x, fmt, ...)
- TRY (x, s)
- LOGERROR (M, ...)
- ASSERT (n)

#### Statements

- STMT(stuff)

#### Saturation

- SATINC(v,L)
- SATDEC(w,L)

```C
int x = 3;
for(int i=0; i<10; i++){
  SATINC(x,8);
  printf("%d ");
}

/* OUTPUT:
   3 4 5 6 7 8 8 8 8 8 */
```

#### Once

- ONCE ( stmts )

> This Macro make it sure that the statements within it are performed only once.

```C
int x;
RANGE(x,1,10) {
  ONCE(
    printf("hello once\n");
  )
}

ONCE(
  FOREVER printf("hello forever\n");
)

/* OUTPUT:
   hello once
   hello forever */
```

See also `FOREVER` in Loops section.

#### Extern C

- EXTERN_C_START
- EXTERN_C_END

> This macro is for C++ users. To compile a piece of C code in C++ environment, you can use these macros as follows:

```C
//somecppfile.cpp

// CPP
EXTERN_C_START

    / *C */

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

### Contribute

Macros are usually insulted for their dirty behavior. But we can see that some features of C language cannot be used to their max without macros. A good Macro is : Portable, safe, involves as less arbitrary variables as possible. Although I am trying my best, there might be some exception errors, please correct if you find any. Also, if I missed some other interesting macros, please contribute to make this collection complete and more usable.

The following conventions were followed:

1. All macros are in UPPERCASE.
2. In case of any Boolean Macro, the `IS_` prefix should be used. For example, `IS_EVEN(x)`. And they should return a 1 or 0 value.
3. Macros for loops and conditionals should not end with braces so that the user can have the option for single line as well as block style.
4. A helper macro, which are expanded by some other main macro, usually they are not intended to be used directly. So they should be mentioned with their expansion level as prefix. For example, <code>PASTE(a,b)</code> expands into <code>PASTE2(a,b)</code> which further expands into <code>a##b</code>.

>Caught a mistake or want to contribute to this documentation? You can edit this page on [Github](https://github.com/ramdeoshubham/)

### Credit

**The real credits goes to all those great C coders who came up with such creative use of C Macros to extend C.**
I made this collection in honor of The C language and those unknown coders.
I can only take credit for the efforts I made to collect and bringing it to you.
A special thanks to Mohit Khatri for designing looks of this site that make this topic look so interesting here.

Don't forget to [ &#9733; STAR](https://github.com/ramdeoshubham/macros) this project if you like it.
