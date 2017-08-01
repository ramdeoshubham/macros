#define TRUE 1
#define FALSE 0

#define MAX(a,b)                     ( (a) > (b) ? (a) : (b))
#define MIN(a,b)                     ( (a) < (b) ? (a) : (b))

#define IS_ODD( num )   ((num) & 1)
#define IS_EVEN( num )  (!IS_ODD( (num) ))

#define IS_BETWEEN( numToTest, numLow, numHigh ) ((unsigned char)((numToTest) >= (numLow) && (numToTest) <= (numHigh)))

#define CAT(str1,str2) (str1 "" str2)

#define SWAP(a, b)  do { a ^= b; b ^= a; a ^= b; } while ( 0 )
#define SORT(a, b)  do { if ((a) > (b)) SWAP((a), (b)); } while (0)

#define PRINT_TOKEN(token) printf(#token " is %d", token)

#define IMPLIES(x, y) (!(x) || (y))

#define COMPARE(x, y) (((x) > (y)) - ((x) < (y)))
#define SIGN(x) COMPARE(x, 0)

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(*a))

#define SET(d, n, v) do{ size_t i_, n_; for (n_ = (n), i_ = 0; n_ > 0; --n_, ++i_) (d)[i_] = (v); } while(0)
#define ZERO(d, n) SET(d, n, 0)

#define COLUMNS(S,E) ( (E) - (S) + 1 )

#define ISNAN(x) ((x) != (x))

#define IS_ARRAY(a) ((void *)&a == (void *)a)

#ifndef DEBUG
#define ASSERT(n)
#else
#define ASSERT(n) \
if(!(n)) { \
printf("%s - Failed",#n); \
printf("On %s ",__DATE__); \
printf("At %s ",__TIME__); \
printf("In File %s ",__FILE__); \
printf("At Line %d\n",__LINE__); \
exit(1);}
#endif

#define FOREACH(item, array) \
    for(int _keep=1, \
            _count=0,\
            _size=sizeof (array)/sizeof *(array); \
        _keep && _count != size; \
        _keep = !_keep, _count++) \
      for(item = (array)+_count; _keep; _keep = !_keep)
      
  
