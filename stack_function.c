#include "push_swap.h"

int     *stack_a_create(char **argv)
{
    char    **tmp;
    int     len;
    int     *stack_a;
    int     i;

    i = 1;
    len = 0;
    tmp = argv;
    while (*tmp++)
        len++;
    if (!(stack_a = (int *)malloc(sizeof(int) * (len + 1))))
        exit(0);
    stack_a[0] = len;
    while (*argv) {
        stack_a[i] = ft_atoi(*argv++);
        i++;
    }
    i = 0;
    return(stack_a);
}

int     *stack_b_create(char **argv)
{
    char    **tmp;
    int     len;
    int     *stack_b;
    int     i;

    i = 1;
    len = 0;
    tmp = argv;
    while (*tmp++)
        len++;
    if (!(stack_b = (int *)malloc(sizeof(int) * (len + 1))))
        exit(0);
    stack_b[0] = 0;
    return(stack_b);
}