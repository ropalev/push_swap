/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvania <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 12:25:15 by lvania            #+#    #+#             */
/*   Updated: 2020/02/08 14:14:08 by lvania           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			main(int argc, char **argv)
{
	t_param	*param;

	param = malloc(sizeof(t_param));
	if (argc == 1 || (param->len_nbrs = validator(argc, argv)) == 0)
	{
		write(1, "Error\n", 6);
		free(param);
		exit(0);
	}
	param->nbrs = (int *)malloc(sizeof(int) * (unsigned long)param->len_nbrs);
	put_nbrs(argc, argv, param);
	param->stack_a = list_stack_create(argc, param);
	param->stack_b = list_stack_create(0, param);
	list_get_length(param);
	param->prog_name = 'P';
	param->stack_a->prog_name = 'P';
	param->stack_b->prog_name = 'P';
	if (!dublicator(param->stack_a))
		error(param, argc);
	if (!is_ascending(param->stack_a))
		median_sort(param);
	free_param(param);
	return (0);
}
