#include "push_swap.h"

void stupid_algo(int *stack_a, int *stack_b)
{
    while (stack_a[0] > 2)
        command_pb(stack_a, stack_b);
    to_ascending(stack_a);
    while (stack_b[0] > 0) {
        if (min_max(stack_a, stack_b))
    }
}