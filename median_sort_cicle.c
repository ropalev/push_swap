/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median_sort_cicle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvania <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 15:21:51 by lvania            #+#    #+#             */
/*   Updated: 2020/02/07 13:52:49 by lvania           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		median_sort(t_param *param)
{
	if (param->stack_a->len < 6)
		sort_five(param);
	else
		sort(param);
}

void		sort(t_param *param)
{
	int		chunk;

	while (1)
	{
		chunk = param->stack_a->head->chunk;
		while (param->stack_a->len - param->stack_a->sort_len > 3 && ++chunk)
			drop_below_median(param, chunk);
		if (param->stack_a->len - param->stack_a->sort_len <= 3 &&
				1 < param->stack_a->len - param->stack_a->sort_len)
			to_sort(param->stack_a);
		param->stack_a->sort_len = param->stack_a->len;
		if (is_ascending(param->stack_a) && param->stack_b->len == 0)
			break ;
		from_b_to_a(param);
	}
}

void		drop_below_median(t_param *param, int chunk)
{
	float	median;
	t_cell	*ptr;
	int		cnt;

	param->stack_a->cnt_op = 0;
	cnt = param->stack_a->len - param->stack_a->sort_len;
	median = (float)find_median(param);
	ptr = param->stack_a->end;
	while (param->stack_a->head != ptr && cnt--)
	{
		if ((float)param->stack_a->head->nbr <= median)
			push_and_chunk(param, chunk);
		else
		{
			command_rotate(param->stack_a);
			param->stack_a->cnt_op++;
		}
	}
	if (param->stack_a->head->nbr <= median)
		push_and_chunk(param, chunk);
	while (param->stack_a->cnt_op--)
		command_rev_rotate(param->stack_a);
}

void		from_b_to_a(t_param *param)
{
	int		max_chunk;
	int		i;
	int		len;
	float	median;

	i = 0;
	if ((len = param->stack_b->len) == 0)
		return ;
	max_chunk = param->stack_b->head->chunk > param->stack_b->end->chunk ?
		param->stack_b->head->chunk : param->stack_b->end->chunk;
	median = chunk_median(param->stack_b);
	if (median < 0)
		while (median++ < 0)
			command_push_pa(param);
	while (param->stack_b->head && param->stack_b->head->chunk == max_chunk && i
			< len)
	{
		if (++i && param->stack_b->head->nbr >= median)
			command_push_pa(param);
		else
			command_rotate(param->stack_b);
	}
	while (param->stack_b->end && param->stack_b->end->chunk == max_chunk && i
			!= len)
		command_rev_rotate(param->stack_b);
}

float		chunk_median(t_stack *stack)
{
	int		*mass1;
	t_cell	*ptr;
	int		len;
	int		chunk;
	float	median;

	ptr = stack->head;
	len = 0;
	chunk = ptr->chunk;
	while (ptr && ptr->chunk == chunk && ++len)
		ptr = ptr->next;
	if (len < 4)
		return (float)(-1 * len);
	if ((mass1 = fill_mass(len, stack)) == NULL)
		return (0);
	buble_sort(mass1, len);
	median = (float)mass1[len / 2];
	free(mass1);
	return (median);
}
