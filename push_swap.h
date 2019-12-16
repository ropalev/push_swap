#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdarg.h>
#include "libft/libft.h"
#include <stdlib.h>
#include <unistd.h>


////// DELETE THIS
#include <stdio.h>
///// DELETE THIS

void    printf_stack(int *stack, char c); // delete this too
void    stupid_algo(int *stack_a,int *stack_b);
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
int     min_max(int *stack_a, int *stack_b);
int     find_max_idx(int *stack);
#endif
