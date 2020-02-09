/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvania <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 15:51:12 by lvania            #+#    #+#             */
/*   Updated: 2020/02/07 19:30:59 by lvania           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		command_swap(t_stack *stack)
{
	t_cell	*top;
	t_cell	*ptr;
	int		tmp;

	if (stack->len <= 1)
		return ;
	top = stack->head;
	ptr = top->next;
	tmp = top->nbr;
	top->nbr = ptr->nbr;
	ptr->nbr = tmp;
	if (stack->prog_name == 'P')
	{
		if (stack->name == 'A')
			write(1, "sa\n", 3);
		else
			write(1, "sb\n", 3);
	}
}

void		command_swap_ss(t_param *param)
{
	t_cell	*top;
	t_cell	*ptr;
	int		tmp;

	if (param->stack_a->len <= 1)
		return ;
	top = param->stack_a->head;
	ptr = top->next;
	tmp = top->nbr;
	top->nbr = ptr->nbr;
	ptr->nbr = tmp;
	if (param->stack_b->len <= 1)
		return ;
	top = param->stack_b->head;
	ptr = top->next;
	tmp = top->nbr;
	top->nbr = ptr->nbr;
	ptr->nbr = tmp;
	if (param->prog_name == 'P')
		write(1, "ss\n", 3);
}
