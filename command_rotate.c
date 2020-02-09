/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvania <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 15:52:05 by lvania            #+#    #+#             */
/*   Updated: 2020/02/07 17:52:42 by lvania           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		command_rotate(t_stack *stack)
{
	t_cell	*ptr;

	if (stack->len <= 1)
		return ;
	ptr = stack->head;
	stack->head = stack->head->next;
	stack->head->prev = NULL;
	stack->end->next = ptr;
	ptr->next = NULL;
	ptr->prev = stack->end;
	stack->end = ptr;
	if (stack->prog_name == 'P')
	{
		if (stack->name == 'A')
			write(1, "ra\n", 3);
		else
			write(1, "rb\n", 3);
	}
}

void		command_rr(t_param *param)
{
	t_cell	*ptr;

	if (param->stack_a->len <= 1)
		return ;
	ptr = param->stack_a->head;
	param->stack_a->head = param->stack_a->head->next;
	param->stack_a->head->prev = NULL;
	param->stack_a->end->next = ptr;
	ptr->next = NULL;
	ptr->prev = param->stack_a->end;
	param->stack_a->end = ptr;
	if (param->stack_b->len <= 1)
		return ;
	ptr = param->stack_b->head;
	param->stack_b->head = param->stack_b->head->next;
	param->stack_b->head->prev = NULL;
	param->stack_b->end->next = ptr;
	ptr->next = NULL;
	ptr->prev = param->stack_b->end;
	param->stack_b->end = ptr;
	if (param->prog_name == 'P')
		write(1, "rr\n", 3);
}

void		command_rev_rotate(t_stack *stack)
{
	t_cell		*ptr;

	if (stack->len <= 1)
		return ;
	ptr = stack->end;
	stack->end = stack->end->prev;
	stack->end->next = NULL;
	stack->head->prev = ptr;
	ptr->next = stack->head;
	ptr->prev = NULL;
	stack->head = ptr;
	if (stack->prog_name == 'P')
	{
		if (stack->name == 'A')
			write(1, "rra\n", 4);
		else
			write(1, "rrb\n", 4);
	}
}

void		command_rrr(t_param *param)
{
	t_cell		*ptr;

	if (param->stack_a->len <= 1)
		return ;
	ptr = param->stack_a->end;
	param->stack_a->end = param->stack_a->end->prev;
	param->stack_a->end->next = NULL;
	param->stack_a->head->prev = ptr;
	ptr->next = param->stack_a->head;
	ptr->prev = NULL;
	param->stack_a->head = ptr;
	if (param->stack_b->len <= 1)
		return ;
	ptr = param->stack_b->end;
	param->stack_b->end = param->stack_b->end->prev;
	param->stack_b->end->next = NULL;
	param->stack_b->head->prev = ptr;
	ptr->next = param->stack_b->head;
	ptr->prev = NULL;
	param->stack_b->head = ptr;
	if (param->prog_name == 'P')
		write(1, "rrr\n", 4);
}
