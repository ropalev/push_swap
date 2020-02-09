/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvania <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 12:22:21 by lvania            #+#    #+#             */
/*   Updated: 2020/02/08 13:06:27 by lvania           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		free_param(t_param *param)
{
	t_cell	*ptr;
	t_cell	*here;

	if (param->len_nbrs != 0)
	{
		ptr = param->stack_a->head;
		here = ptr;
		while (ptr)
		{
			ptr = ptr->next;
			free(here);
			here = ptr;
		}
		ptr = param->stack_b->head;
		here = ptr;
		while (ptr)
		{
			ptr = ptr->next;
			free(here);
			here = ptr;
		}
		free_them_all(param);
	}
	free(param);
}

void		free_them_all(t_param *param)
{
	free(param->nbrs);
	free(param->stack_a);
	free(param->stack_b);
}
