/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_function.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvania <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 12:04:00 by lvania            #+#    #+#             */
/*   Updated: 2020/02/07 12:58:48 by lvania           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			is_ascending(t_stack *stack)
{
	t_cell	*tmp;

	if (!stack->head)
		return (0);
	tmp = stack->head;
	while (tmp->next)
	{
		if (tmp->nbr > tmp->next->nbr)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int			stack_min(t_stack *stack)
{
	int		min;
	t_cell	*ptr;
	int		cnt;

	cnt = 0;
	min = stack->head->nbr;
	ptr = stack->head;
	while (ptr)
	{
		if (ptr->nbr < min)
		{
			min = ptr->nbr;
		}
		ptr = ptr->next;
	}
	ptr = stack->head;
	while (ptr->nbr != min)
	{
		cnt++;
		ptr = ptr->next;
	}
	return (cnt);
}

int			find_median(t_param *param)
{
	int		*mass;
	int		median;
	int		len;

	len = param->stack_a->len - param->stack_a->sort_len;
	if ((mass = fill_mass(len, param->stack_a)) == NULL)
		return (0);
	buble_sort(mass, len);
	median = (len % 2 == 0) ? (mass[len / 2] + mass[len / 2 + 1]) / 2 :
		mass[len / 2 + 1];
	free(mass);
	return (median);
}

void		buble_sort(int *mass, int len)
{
	int		i;
	int		j;
	int		tmp;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (mass[i] > mass[j])
			{
				tmp = mass[i];
				mass[i] = mass[j];
				mass[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void		error(t_param *param, int argc)
{
	free_param(param);
	if (argc == 1 && param->prog_name == 'C')
		exit(0);
	write(1, "Error\n", 6);
	exit(0);
}
