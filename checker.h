#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdarg.h>
#include "libft/libft.h"
#include <stdlib.h>
#include <unistd.h>


////// DELETE THIS
#include <stdio.h>
///// DELETE THIS

typedef struct      s_stack
{
    int             *array;
    int             len_sort;
    int             sort_flag;
    int             old_median;
}                   t_stack;
void    printf_stack(int *stack, char c); // delete this too
void    stupid_algo(int *stack_a, int *stack_b);
void    smart_algo(int *stack_a, int *stack_b);
/*
 *      stack_function
 */
int     *stack_a_create(char **argv);
int     *stack_b_create(char **argv);
/*
 *      command_swap
 */
void    command_sa(int *stack);
void    command_sb(int *stack);
void    command_ss(int *stack_a, int *stack_b);
/*
 *      additional_command
 */
void    shift_down(int *stack);
void    shift_up(int *stack);
int     is_ascending(int *stack);
void    to_ascending(int *stack);
/*
 *      command_push
 */
void    command_pa(int *stack_a, int *stack_b);
void    command_pb(int *stack_a, int *stack_b);
/*
 *      command_rotate
 */
void    command_ra(int *stack);
void    command_rb(int *stack);
void    command_rr(int *stack_a, int *stack_b);

/*
 *      command_rotate_rev
 */
void    command_rra(int *stack);
void    command_rrb(int *stack);
void    command_rrr(int *stack_a, int *stack_b);
/*
 *      additional_function
 */
int     find_max_idx(int *stack);
int     min_max(t_stack stack);
void    to_sort(t_stack stack_a);
int     randd(t_stack stack);
void    quicksort(int *list, int low, int high);
int     choose_median(t_stack stack);

/*
 *      sort_func
 */
void    sort_func(t_stack stack_a, t_stack stack_b);
void    from_b_to_a(t_stack stack_a, t_stack stack_b);
#endif
