<p align="center">
<h1 align="center"><img src="http://ramdeoshubham.com/macros/fav/favicon-96x96.png"><br>#macros.h</h1><p align="center">Useful C #macros<br>
    <a href="http://ramdeoshubham.com/macros"><strong>Visit macros &raquo;</strong></a></p>
</p>

[![Open Source Love](https://badges.frapsoft.com/os/v2/open-source.svg?v=103)](https://github.com/ellerbrock/open-source-badges/)
[![MIT Licence](https://badges.frapsoft.com/os/mit/mit.svg?v=103)](https://opensource.org/licenses/mit-license.php)
[![Build Status](https://travis-ci.org/ramdeoshubham/macros.svg?branch=master)](https://travis-ci.org/ramdeoshubham/macros)
[![Codacy Badge](https://api.codacy.com/project/badge/Grade/93283a93f08e4fbc951b9629af11ae9f)](https://www.codacy.com/app/ramdeoshubham/macros?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=ramdeoshubham/macros&amp;utm_campaign=Badge_Grade)

This is a collection of commonly used C Macros I found on internet, and as suggested by my friends.

## Why this is awesome

Using C Macros, we can extend C with a lot of useful functionality. For example, we can create loops like foreach which are very useful and handy when it comes to arrays. These are available in most of high level languages but not in C. But we got macros in C and so we can add on our own!

### How to use

Just download macros.h from [here](https://github.com/ramdeoshubham/macros/archive/master.zip) and include it to the top.

```C
#include "macros.h"
```

Note that there is an `ASSET` macro useful for debugging purpose. To enable it, you need to `#define DEBUG` before including `macros.h`.

### And these are the macros...

For docs, visit [ramdeoshubham.com/macros](http://ramdeoshubham.com/macros) to learn more about the available macros and their usage.

## Contribute

The source is very clear and the macros available are too common you will find them everywhere. A good Macro is : Portable, safe, involves as less arbitrary variables as possible. Although I am trying my best, there might be some exception errors, please correct if you find any. Also, if I missed some other interesting macros, please contribute to make this collection complete and more usable.

### Conventions

1. All macros are in UPPERCASE.
2. In case of any Boolean Macro, the `IS_ prefix` should be used. For example, `IS_EVEN(x)`. And they should return a `1` or `0` value.
3. Macros for loops and conditionals should not end with braces so that the user can have the option for single line as well as block style.
4. A helper macro, which are expanded by some other main macro, usually they are not intended to be used directly. So they should be mentioned with their expansion level as prefix. For example, `PASTE(a,b)` expands into `PASTE2(a,b)` which further expands into `a##b`.

## Credit

>The real credits goes to all those great C coders who came up with such creative use of C Macros to extend C. I made this collection in honor of The C language and those unknown programmers. I can only take credit for the efforts I made to collect and bringing it to you.

## License

Copyright 2017, Shubham Ramdeo. Code released under the [MIT License](https://github.com/ramdeoshubham/macros/blob/master/LICENSE).


>#Handpicked C #Macros with &hearts; #love !

Don't forget to [&#9733;`STAR`](https://github.com/ramdeoshubham/macros) if you like it.
