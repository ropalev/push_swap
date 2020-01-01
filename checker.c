#include "checker.h"
/*
int    action(char *line, t_stack stack_a, t_stack stack_b)
{
    if (ft_strequ("pa", line))
        command_pa(stack_a.array, stack_b.array);
    else if (ft_strequ("pb", line))
        command_pb(stack_a.array, stack_b.array);
    else if (ft_strequ("sa", line))
        command_sa(stack_a.array);
    else if (ft_strequ("sb", line))
        command_sb(stack_b.array);
    else if (ft_strequ("ss", line))
        command_ss(stack_a.array, stack_b.array);
    else if (ft_strequ("ra", line))
        command_ra(stack_a.array);
    else if (ft_strequ("rb", line))
        command_rb(stack_b.array);
    else if (ft_strequ("rr", line))
        command_rr(stack_a.array, stack_b.array);
    else if (ft_strequ("rra", line))
        command_rra(stack_a.array);
    else if (ft_strequ("rrb", line))
        command_rrb(stack_b.array);
    else if (ft_strequ("rrr", line))
        command_rrr(stack_a.array, stack_b.array);
    else
        return (0);
    return (1);
}
int     main(int argc, char **argv)
{
    t_stack stack_a;
    t_stack stack_b;
    char    **arg;
    char    *line;

    arg = ++argv;
    stack_a.old_median = 0;
    stack_b.old_median = 0;
    stack_a.array = stack_a_create(arg);
    stack_a.len_sort = 0;
    stack_b.array = stack_b_create(arg);
    stack_b.len_sort = 0;
    stack_a.sort_flag = 0;
    while (get_next_line(0,&line) > 0) {
        printf_stack(stack_a.array, 'A');
        printf_stack(stack_b.array, 'B');
        if(!line)
            break ;
        if (!action(line, stack_a, stack_b))
        {
            printf("%s", "Error\n");
            exit(1);

        }
        if(is_ascending(stack_a.array))
            printf("%s","OK\n");
        else
            printf("%s", "KO\n");
    }
}*/