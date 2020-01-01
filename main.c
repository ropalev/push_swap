//
// Created by Leto Vania on 25/11/2019.
//
#include "push_swap.h"

int     main(int argc, char **argv)
{
    t_stack stack_a;
    t_stack stack_b;
    char    **arg;

    arg = ++argv;
    stack_a.old_median = 0;
    stack_b.old_median = 0;
    stack_a.array = stack_a_create(arg);
    stack_a.len_sort = 0;
    stack_b.array = stack_b_create(arg);
    stack_b.len_sort = 0;
    stack_a.sort_flag = 0;
    //sort_func(stack_a, stack_b);
    //printf_stack(stack_a.array, 'A');
    //parser(--argc, arg);
    int     i;
    i = 0;
    arg = ft_strsplit(argv[1],' ');
    while (i < argc)
        printf("%s", arg[i++]);
    return (0);
}