#include "push_swap.h"

void    command_rra(int *stack_a)
{
    int     tmp;

    if (stack_a[0] < 2)
        return ;
    tmp = stack_a[stack_a[0]];
    shift_down(stack_a);
    stack_a[1] = tmp;
    write(1, "rra\n", 4);
}

void    command_rrb(int *stack_b)
{
    int     tmp;

    if (stack_b[0] < 2)
        return ;
    tmp = stack_b[stack_b[0]];
    shift_down(stack_b);
    stack_b[1] = tmp;
    write(1, "rrb\n", 4);
}

void    command_rrr(int *stack_a, int *stack_b)
{
    command_rra(stack_a);
    command_rrb(stack_b);
    write(1, "rrr\n", 4);
}