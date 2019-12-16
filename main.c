//
// Created by Leto Vania on 25/11/2019.
//
#include "push_swap.h"

int     main(int argc, char **argv)
{
    int     *stack_a;
    int     *stack_b;
    char    **arg;

    arg = ++argv;
    stack_a = stack_a_create(arg);
    stack_b = stack_b_create(arg);
    to_ascending(stack_a);

    printf_stack(stack_a, 'A');
    /*stupid_algo(stack_a,stack_b);
    printf_stack(stack_a, 'A');
    printf_stack(stack_b, 'B');*/
    return (0);
}