## Contribute

First off, thank you very much for considering contributing to macros.h.

A good Macro is : Portable, safe, involves as less arbitrary variables as possible. Although I am trying my best, there might be some exception errors, please correct if you find any. Also, if I missed some other interesting macros, please contribute to make this collection complete and more usable.

### Conventions

1. All macros are in UPPERCASE.
2. In case of any Boolean Macro, the `IS_ prefix` should be used. For example, `IS_EVEN(x)`. And they should return a `1` or `0` value.
3. Macros for loops and conditionals should not end with braces so that the user can have the option for single line as well as block style.
4. A helper macro, which are expanded by some other main macro, usually they are not intended to be used directly. So they should be mentioned with their expansion level as prefix. For example, `PASTE(a,b)` expands into `PASTE2(a,b)` which further expands into `a##b`.
