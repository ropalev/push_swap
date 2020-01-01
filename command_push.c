#include "push_swap.h"

void    command_pa(int *stack_a, int *stack_b)
{
    if (stack_b[0] == 0)
        return ;
    shift_down(stack_a);
    stack_a[1] = stack_b[1];
    shift_up(stack_b);
    stack_a[0] += 1;
    stack_b[0] -= 1;
    //write(1, "pa\n", 3);
}

void    command_pb(int *stack_a, int *stack_b)
{
    if (stack_a[0] == 0)
        return ;
    shift_down(stack_b);
    stack_b[1] = stack_a[1];
    shift_up(stack_a);
    stack_a[0] -= 1;
    stack_b[0] += 1;
    //write(1, "pb\n", 3);
}