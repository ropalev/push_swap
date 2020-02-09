/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvania <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 11:56:37 by lvania            #+#    #+#             */
/*   Updated: 2020/02/07 11:57:39 by lvania           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cell		*list_create_cell(int nbr)
{
	t_cell	*cell;

	if ((cell = (t_cell *)malloc(sizeof(t_cell))) == NULL)
		return (NULL);
	cell->nbr = nbr;
	cell->chunk = 0;
	cell->prev = NULL;
	cell->next = NULL;
	return (cell);
}

t_cell		*get_last_el(t_cell *head)
{
	while (head->next)
		head = head->next;
	return (head);
}

t_stack		*list_stack_create(int argc, t_param *param)
{
	t_stack	*stack;
	int		i;
	t_cell	*ptr;

	i = -1;
	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->head = NULL;
	if (argc == 0)
		return (stack);
	while (++i < param->len_nbrs)
	{
		if (!stack->head)
		{
			stack->head = list_create_cell(param->nbrs[i]);
		}
		else
		{
			ptr = list_create_cell(param->nbrs[i]);
			stack->end = get_last_el(stack->head);
			stack->end->next = ptr;
			stack->end->next->prev = stack->end;
			stack->end = ptr;
		}
	}
	return (stack);
}

void		list_get_length(t_param *param)
{
	t_cell	*ptr;

	ptr = param->stack_a->head;
	param->stack_a->len = 0;
	param->stack_a->sort_len = 0;
	param->stack_a->name = 'A';
	while (ptr)
	{
		ptr = ptr->next;
		param->stack_a->len++;
	}
	param->stack_b->len = 0;
	param->stack_b->head = NULL;
	param->stack_b->end = NULL;
	param->stack_b->name = 'B';
}
