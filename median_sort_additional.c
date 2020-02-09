/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median_sort_additional.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvania <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 13:51:32 by lvania            #+#    #+#             */
/*   Updated: 2020/02/07 13:52:25 by lvania           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			*fill_mass(int len, t_stack *stack)
{
	int		i;
	t_cell	*ptr;
	int		*mass;

	if ((mass = (int *)malloc(sizeof(int) * len)) == NULL)
		return (NULL);
	ptr = stack->head;
	i = 0;
	while (i < len)
	{
		mass[i++] = ptr->nbr;
		ptr = ptr->next;
	}
	return (mass);
}

void		push_and_chunk(t_param *param, int chunk)
{
	param->stack_a->head->chunk = chunk;
	command_push_pb(param);
}
