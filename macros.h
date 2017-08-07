/**
    MACROS
    macros.h
    Purpose: A collection of commonly used Useful C macros.

    @author Shubham Ramdeo
    @version 0.2

    Released under MIT LICENSE (see LICENSE.txt)
*/

#ifndef MACROS_H
#define MACROS_H

/* Bool */

#define TRUE  1
#define FALSE 0

/* Identifier */

#define AND       &&
#define OR        ||
#define NOT       !
#define NOTEQUALS !=
#define EQUALS    ==
#define IS        =

/* Loops */

#define FOREVER       for(;;)
#define RANGE(i,y,x)  for(i=(y);(((x)>=(y))?(i<=(x)):(i>=x));\
                      (((x)>=(y))?((i)++):((i)--)))
#define FOREACH(i, A) for(int _keep=1, \
                      _count=0,\
                      _size=sizeof (A) / sizeof *(A); \
                      _keep && _count != _size; \
                      _keep = !_keep, _count++) \
                      for(i = (A)+_count; _keep; _keep = !_keep)

/* Maths */

#define PI                  3.14159265
#define RAD2DEG(x)          ((x)/PI*180)
#define DEG2RAD(x)          ((x)*PI/180)
#define ALIGNB(x, align)    (((x) + ((align) - 1)) & ~((align) - 1))
#define ALIGN(x, align)     ((((x) + ((align) - 1)) / (align)) * (align))
#define FLOORB(x, align)    ((x) & ~((align) - 1))
#define FLOOR(x, align)     (((x) / (align)) * (align))
#define CEILB(x, align)     ALIGNB(x, align)
#define CEIL(x, align)      ALIGN(x, align)
#define CLIP(x, min, max)   (((x) < (min)) ? (min) : \
                            (((x) > (max)) ? (max) : (x)))
#define UCLIP(x, max)       (((x) > (max)) ? (max) : (x))
#define LCLIP(x, min)       (((x) < (min)) ? (min) : (x))
#define MIN(x, y)           (((x) < (y)) ?  (x) : (y))
#define MAX(x, y)           (((x) > (y)) ?  (x) : (y))
#define ABS(x)              (((x) <  0) ? -(x) : (x))
#define DIFF(a,b)           ABS((a)-(b))
#define IS_NAN(x)            ((x) != (x))
#define IMPLIES(x, y)       (!(x) || (y))
#define SWAP(a, b)          do { a ^= b; b ^= a; a ^= b; } while ( 0 )
#define SORT(a, b)          do { if ((a) > (b)) SWAP((a), (b)); } while (0)
#define COMPARE(x, y)       (((x) > (y)) - ((x) < (y)))
#define SIGN(x)             COMPARE(x, 0)
#define IS_ODD( num )       ((num) & 1)
#define IS_EVEN( num )      (!IS_ODD( (num) ))
#define IS_BETWEEN(n,L,H)   ((unsigned char)((n) >= (L) && (n) <= (H)))

/* BITS */

#define BIT(x)          (1<<(x))
#define SETBIT(x,p)     ((x)|(1<<(p)))
#define CLEARBIT(x,p)   ((x)&(~(1<<(p))))
#define GETBIT(x,p)     (((x)>>(p))&1)
#define TOGGLEBIT(x,p)  ((x)^(1<<(p)))

/* ARRAYS */

#define ARRAY_SIZE(a) (sizeof(a) / sizeof((a)[0]))
#define SET(d, n, v)  do{ size_t i_, n_; \
                      for ( n_ = (n), i_ = 0; n_ > 0; --n_, ++i_) \
                      (d)[i_] = (v); } while(0)
#define ZERO(d, n)    SET(d, n, 0)
#define COLUMNS(S,E)  ( (E) - (S) + 1 )
#define IS_ARRAY(a)   ((void *)&a == (void *)a)

/* STRINGS */

#define STRING char*
#define STR2(s)             #s
#define STR(s)              STR2(s)
#define CAT(str1,str2)      (str1 "" str2)

/* TOKENS */

#define PASTE2(a,b)         a##b
#define PASTE(a,b)          PASTE2(a,b)
#define PRINT_TOKEN(token)  printf(#token " is %d", token)

/* DEBUGGING */

#define LOG(x, fmt, ...)    if(x){printf("%s:%d: " fmt "\n",\
                            __FILE__, __LINE__,__VA_ARGS__);}
#define TRY(x,s)            if(!(x)){printf("%s:%d:%s",__FILE__, __LINE__,s);}
/*you have to  #define DEBUG to enable ASSERT*/
#ifndef DEBUG
#define ASSERT(n)
#else
#define ASSERT(n)           if(!(n)) { \
                            printf("%s - Failed ",#n); \
                            printf("On %s ",__DATE__); \
                            printf("At %s ",__TIME__); \
                            printf("In File %s ",__FILE__); \
                            printf("At Line %d\n",__LINE__); \
                            return(-1);}
#endif

/* STMT, useful for creating multiple statements macros */

#define STMT( stuff )  do { stuff } while (0)

/* Saturating ++ and -- */

#define SATINC(w,L) (w = (((w) == (L)) ? (w) : ((w) + 1)) )
#define SATDEC(w,L) (w = (((w) == (L)) ? (w) : ((w) - 1)) )

/* ONCE */
#define ONCE2(stmts, onceVar)	      {static int onceVar = 1;\
		                                if(onceVar){stmts\
			                              onceVar = 0;}}
#define ONCE(stmts)                 ONCE2(stmts, __onceVar__##__COUNTER__)

/* C in C++ Environment */

#ifdef __cplusplus
#   define EXTERN_C_START  extern "C" {
#   define EXTERN_C_END    }
#else
#   define EXTERN_C_START
#   define EXTERN_C_END
#endif

#endif /* MACROS_H */
