#include "../include/list.h"

int main()
{
    //should be the same output and return for all replicated cases
    //cases: %c, %s, %d, %u, %o, %x, %p
    my_printf("my_printf: %s\n", "this is my printf function");
    printf("printf: %s\n", "this is printf function");
    return 0;
}

