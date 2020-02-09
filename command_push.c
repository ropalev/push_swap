/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvania <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 15:52:55 by lvania            #+#    #+#             */
/*   Updated: 2020/02/07 12:41:39 by lvania           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		command_push_pb(t_param *param)
{
	if (param->stack_a->len == 0)
		return ;
	push_a_add(param);
	param->stack_a->len--;
	param->stack_b->len++;
	if (param->prog_name == 'P')
		write(1, "pb\n", 3);
}

void		command_push_pa(t_param *param)
{
	if (param->stack_b->len == 0)
		return ;
	push_b_add(param);
	param->stack_b->len--;
	param->stack_a->len++;
	if (param->prog_name == 'P')
		write(1, "pa\n", 3);
}

void		push_a_add(t_param *param)
{
	t_cell	*ptr;

	ptr = param->stack_a->head;
	if (!param->stack_a->head->next)
	{
		param->stack_a->head = NULL;
		param->stack_a->end = NULL;
	}
	else
	{
		param->stack_a->head = param->stack_a->head->next;
		param->stack_a->head->prev = NULL;
	}
	if (!param->stack_b->head)
	{
		param->stack_b->head = ptr;
		param->stack_b->head->next = NULL;
		param->stack_b->end = ptr;
	}
	else
	{
		param->stack_b->head->prev = ptr;
		ptr->next = param->stack_b->head;
		param->stack_b->head = ptr;
	}
}

void		push_b_add(t_param *param)
{
	t_cell	*ptr;

	ptr = param->stack_b->head;
	if (!param->stack_b->head->next)
	{
		param->stack_b->head = NULL;
		param->stack_b->end = NULL;
	}
	else
	{
		param->stack_b->head = param->stack_b->head->next;
		param->stack_b->head->prev = NULL;
	}
	if (!param->stack_a->head)
	{
		param->stack_a->head = ptr;
		param->stack_a->head->next = NULL;
		param->stack_a->end = ptr;
	}
	else
	{
		param->stack_a->head->prev = ptr;
		ptr->next = param->stack_a->head;
		param->stack_a->head = ptr;
	}
}
