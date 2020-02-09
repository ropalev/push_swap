/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvania <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 10:57:19 by lvania            #+#    #+#             */
/*   Updated: 2020/02/07 11:18:46 by lvania           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	to_sort(t_stack *stack)
{
	if (stack->len <= 2)
	{
		if (stack->len == 2 && stack->head->nbr > stack->end->nbr)
			command_swap(stack);
		return ;
	}
	if (stack->head->nbr < stack->head->next->nbr && stack->head->next->nbr <
			stack->head->next->next->nbr)
		return ;
	else if (stack->head->nbr < stack->head->next->next->nbr &&
			stack->head->next->nbr > stack->head->next->next->nbr)
		fts(stack);
	else if (stack->head->nbr > stack->head->next->nbr &&
			stack->head->nbr < stack->head->next->next->nbr)
		command_swap(stack);
	else if (stack->head->nbr < stack->head->next->nbr &&
			stack->head->next->nbr > stack->head->next->next->nbr)
		stf(stack);
	else if (stack->head->nbr > stack->head->next->next->nbr &&
			stack->head->next->next->nbr > stack->head->next->nbr)
		tfs(stack);
	else if (stack->head->nbr > stack->head->next->nbr &&
			stack->head->next->nbr > stack->head->next->next->nbr)
		tsf(stack);
}

void	fts(t_stack *stack)
{
	command_rotate(stack);
	command_swap(stack);
	command_rev_rotate(stack);
}

void	tsf(t_stack *stack)
{
	command_swap(stack);
	command_rotate(stack);
	command_swap(stack);
	command_rev_rotate(stack);
	command_swap(stack);
}

void	tfs(t_stack *stack)
{
	command_swap(stack);
	command_rotate(stack);
	command_swap(stack);
	command_rev_rotate(stack);
}

void	stf(t_stack *stack)
{
	command_rotate(stack);
	command_swap(stack);
	command_rev_rotate(stack);
	command_swap(stack);
}
