#include "push_swap.h"
/*
void     smart_algo(int *stack_a, int *stack_b)
{
    int     median;
    int     idx;
    int     len;
    while (stack_a[0] > 4)
    {
        median = stack_a[rand_idx(stack_a)];
        printf_stack(stack_a,'A');
        printf("median %d\n", median);
        idx = 0;
        len = stack_a[0];
        while (idx <= len)
        {
            printf("%d\n", stack_a[1]);
            if (stack_a[1] < median)
                command_pb(stack_a, stack_b);
            idx++;
            command_ra(stack_a);
            printf_stack(stack_a, 'A');
            printf_stack(stack_b, 'B');
        }
    }
    while (stack_b[0] > 4)
    {
        median = stack_b[rand_idx(stack_b)];
        printf_stack(stack_b,'A');
        printf("median %d\n", median);
        idx = 0;
        len = stack_b[0];
        while (idx <= len)
        {
            printf("%d\n", stack_b[1]);
            if (stack_b[1] > median)
                command_pa(stack_a, stack_b);
            idx++;
            command_ra(stack_b);
            printf_stack(stack_a, 'A');
            printf_stack(stack_b, 'B');
        }
    }
    printf("________________________");
    while (stack_a[0] > 4)
    {
        median = stack_a[rand_idx(stack_a)];
        printf_stack(stack_a,'A');
        printf("median %d\n", median);
        idx = 0;
        len = stack_a[0];
        while (idx <= len)
        {
            printf("%d\n", stack_a[1]);
            if (stack_a[1] < median)
                command_pb(stack_a, stack_b);
            idx++;
            command_ra(stack_a);
            printf_stack(stack_a, 'A');
            printf_stack(stack_b, 'B');
        }
    }
    printf("________________________");
    while (stack_b[0] > 4)
    {
        median = stack_b[rand_idx(stack_b)];
        printf_stack(stack_b,'A');
        printf("median %d\n", median);
        idx = 0;
        len = stack_b[0];
        while (idx <= len)
        {
            printf("%d\n", stack_b[1]);
            if (stack_b[1] > median)
                command_pa(stack_a, stack_b);
            idx++;
            command_ra(stack_b);
            printf_stack(stack_a, 'A');
            printf_stack(stack_b, 'B');
        }
    }
}*/