/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvania <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 14:33:44 by lvania            #+#    #+#             */
/*   Updated: 2020/02/05 15:04:15 by lvania           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sort_two(t_stack *stack)
{
	if (stack->head->nbr < stack->end->nbr)
		return ;
	else
		command_swap(stack);
}

void		sort_three(t_stack *stack)
{
	t_cell	*cell1;
	t_cell	*cell2;
	t_cell	*cell3;

	cell1 = stack->head;
	cell2 = stack->head->next;
	cell3 = stack->end;
	if (cell1->nbr > cell2->nbr && cell1->nbr < cell3->nbr)
		command_swap(stack);
	else if (cell1->nbr > cell2->nbr && cell2->nbr > cell3->nbr)
	{
		command_swap(stack);
		command_rev_rotate(stack);
	}
	else if (cell1->nbr > cell3->nbr && cell3->nbr > cell2->nbr)
		command_rotate(stack);
	else if (cell1->nbr < cell3->nbr && cell3->nbr < cell2->nbr)
	{
		command_swap(stack);
		command_rotate(stack);
	}
	else if (cell1->nbr < cell2->nbr && cell1->nbr > cell3->nbr)
		command_rev_rotate(stack);
}

void		sort_four(t_param *param)
{
	int		cnt;
	int		i;

	i = 0;
	cnt = stack_min(param->stack_a);
	if (cnt < param->stack_a->len / 2)
		while (i++ < cnt)
			command_rotate(param->stack_a);
	else
		while (i++ < param->stack_a->len - cnt)
			command_rev_rotate(param->stack_a);
	command_push_pb(param);
	sort_three(param->stack_a);
	command_push_pa(param);
}

void		no_name_sort(t_param *param)
{
	int		cnt;
	int		i;

	i = 0;
	cnt = stack_min(param->stack_a);
	if (cnt < param->stack_a->len / 2)
		while (i++ < cnt)
			command_rotate(param->stack_a);
	else
		while (i++ < param->stack_a->len - cnt)
			command_rev_rotate(param->stack_a);
	command_push_pb(param);
	i = 0;
	cnt = stack_min(param->stack_a);
	if (cnt < param->stack_a->len / 2)
		while (i++ < cnt)
			command_rotate(param->stack_a);
	else
		while (i++ < param->stack_a->len - cnt)
			command_rev_rotate(param->stack_a);
	command_push_pb(param);
	sort_three(param->stack_a);
	command_push_pa(param);
	command_push_pa(param);
}

void		sort_five(t_param *param)
{
	if (param->stack_a->len == 1)
		return ;
	else if (param->stack_a->len == 2)
		sort_two(param->stack_a);
	else if (param->stack_a->len == 3)
		sort_three(param->stack_a);
	else if (param->stack_a->len == 4)
		sort_four(param);
	else if (param->stack_a->len == 5)
		no_name_sort(param);
	else
		to_sort(param->stack_a);
}
