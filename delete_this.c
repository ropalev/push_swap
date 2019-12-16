#include "push_swap.h"

void    printf_stack(int *stack, char c)
{
    int     i;

    i = 1;
    printf("%c ",c);
    while (i <= stack[0]) {
        printf("%d ", stack[i]);
        i++;
    }
    printf("\t%d",stack[0]);
    printf("\n");
}
