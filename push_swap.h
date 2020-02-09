/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvania <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 17:58:00 by lvania            #+#    #+#             */
/*   Updated: 2020/02/07 18:01:14 by lvania           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "stdlib.h"
# include "libft/libft.h"

typedef struct			s_cell
{
	int					nbr;
	int					chunk;
	struct s_cell		*next;
	struct s_cell		*prev;
}						t_cell;

typedef struct			s_stack
{
	t_cell				*head;
	t_cell				*end;
	int					len;
	int					sort_len;
	int					cnt_op;
	char				name;
	char				prog_name;
}						t_stack;

typedef struct			s_param
{
	t_stack				*stack_a;
	t_stack				*stack_b;
	int					*nbrs;
	int					len_nbrs;
	char				prog_name;
}						t_param;

t_stack					*list_stack_create(int argc, t_param *param);
t_cell					*list_create_cell(int nbr);
void					list_get_length(t_param *param);
int						validator(int argc, char **argv);
int						valid_numeric(char *str);
int						valid_string(char *str, int *cnt);
int						dublicator(t_stack *stack);
void					put_nbrs(int argc, char **argv, t_param *param);
void					command_swap(t_stack *stack);
void					command_swap_ss(t_param *param);
void					command_rotate(t_stack *stack);
void					command_rr(t_param *param);
void					command_rev_rotate(t_stack *stack);
void					command_rrr(t_param *param);
void					command_push_pb(t_param *param);
void					push_b_add(t_param *param);
void					command_push_pa(t_param *param);
void					push_a_add(t_param *param);
int						is_ascending(t_stack *stack);
int						stack_min(t_stack *stack);
void					error(t_param *param, int argc);
int						find_median(t_param *param);
void					buble_sort(int *mass, int len);
void					swap_rev(t_stack *stack);
void					sort_five(t_param *param);
void					sort_three(t_stack *stack);
void					sort_two(t_stack *stack);
int						count_less(t_cell *cell);
void					no_name_sort(t_param *param);
void					free_param(t_param *param);
int						place_to_insert(t_param *param);
void					insert_sort(t_param *param);
void					sort_func(t_param *param);
void					ft_free(void **data);
void					median_sort(t_param *param);
void					drop_below_median(t_param *param, int chunk);
float					chunk_median(t_stack *stack);
void					from_b_to_a(t_param *param);
void					to_sort(t_stack *stack);
void					push_and_chunk(t_param *param, int chunk);
void					sort(t_param *param);
void					fts(t_stack *stack);
void					tsf(t_stack *stack);
void					tfs(t_stack *stack);
void					stf(t_stack *stack);
int						*fill_mass(int len, t_stack *stack);
void					final_touch(t_param *param);
void					free_split_str(char ***tab);
void					free_them_all(t_param *param);
void					what_if(t_param **param);
#endif
