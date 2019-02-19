# my_malloc
A reproduction of the lib C's function malloc only using brk and sbrk system calls

The makefile produces a dynamic library or shared object (.so) that can be load directly to your env using LD_PRELOAD variable
This library reproduces the behaviour of the functions malloc, free and realloc
