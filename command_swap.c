
#include "push_swap.h"
void command_sa(int *stack_a)
{
    int     tmp;

    if (stack_a[0] < 2)
        return ;
    tmp = stack_a[1];
    stack_a[1] = stack_a[2];
    stack_a[2] = tmp;
    write(1, "sa\n", 3);
}

void command_sb(int *stack_b)
{
    int     tmp;

    if (stack_b[0] < 2)
        return ;
    tmp = stack_b[1];
    stack_b[1] = stack_b[2];
    stack_b[2] = tmp;
    write(1, "sb\n", 3);
}

void command_ss(int *stack_a, int *stack_b)
{
    command_sa(stack_a);
    command_sb(stack_b);
}