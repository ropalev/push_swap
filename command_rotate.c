#include "push_swap.h"

void    command_ra(int *stack_a)
{
    int     tmp;

    if (stack_a[0] < 2)
        return ;
    tmp = stack_a[1];
    shift_up(stack_a);
    stack_a[stack_a[0]] = tmp;
    write(1, "ra\n", 3);
}

void    command_rb(int *stack_b)
{
    int     tmp;

    if (stack_b[0] < 2)
        return ;
    tmp = stack_b[1];
    shift_up(stack_b);
    stack_b[stack_b[0]] = tmp;
    write(1, "rb\n", 3);
}

void    command_rr(int *stack_a, int *stack_b)
{
    command_ra(stack_a);
    command_rb(stack_b);
    write(1, "rr\n", 3);
}