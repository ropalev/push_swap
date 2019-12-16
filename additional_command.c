#include "push_swap.h"

void shift_down(int *stack)
{
    int     i;

    if (stack[0] == 0)
        return ;
    i = stack[0];
    while (i >=1)
    {
        stack[i + 1] = stack[i];
        i--;
    }
}

void shift_up(int *stack)
{
    int     i;

    if (stack[0] == 0)
        return;
    i = 1;
    while (i < stack[0])
    {
        stack[i] = stack[i + 1];
        i++;
    }
}

int     is_ascending(int *stack)
{
    int     i;

    i = 1;
    while (i < stack[0])
    {
        if (stack[i] > stack[i + 1])
            return (0);
        i++;
    }
    return (1);
}

void    to_ascending(int *stack)
{
    int     idx;

    idx = find_max_idx(stack);
    if (idx > stack[1] - 1 - idx)
    {
        while (!is_ascending(stack)) {
            printf_stack(stack, 'a');
            command_ra(stack);
        }
    }
    else
    {
        while (!is_ascending(stack)) {
            printf_stack(stack, 'b');
            command_rra(stack);
        }
    }
}