/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvania <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 12:45:36 by lvania            #+#    #+#             */
/*   Updated: 2020/02/08 14:13:45 by lvania           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			action(char *line, t_param *param)
{
	if (ft_strequ("pa", line))
		command_push_pa(param);
	else if (ft_strequ("pb", line))
		command_push_pb(param);
	else if (ft_strequ("sa", line))
		command_swap(param->stack_a);
	else if (ft_strequ("sb", line))
		command_swap(param->stack_b);
	else if (ft_strequ("ss", line))
		command_swap_ss(param);
	else if (ft_strequ("ra", line))
		command_rotate(param->stack_a);
	else if (ft_strequ("rb", line))
		command_rotate(param->stack_b);
	else if (ft_strequ("rr", line))
		command_rr(param);
	else if (ft_strequ("rra", line))
		command_rev_rotate(param->stack_a);
	else if (ft_strequ("rrb", line))
		command_rev_rotate(param->stack_b);
	else if (ft_strequ("rrr", line))
		command_rrr(param);
	else
		return (0);
	return (1);
}

int			main(int argc, char **argv)
{
	t_param	*param;
	char	*line;

	param = malloc(sizeof(t_param));
	param->prog_name = 'C';
	if ((param->len_nbrs = validator(argc, argv)) == 0 || argc == 1)
		error(param, argc);
	param->nbrs = (int *)malloc(sizeof(int) * (unsigned long)param->len_nbrs);
	put_nbrs(argc, argv, param);
	param->stack_a = list_stack_create(argc, param);
	param->stack_b = list_stack_create(0, param);
	param->stack_a->prog_name = 'C';
	param->stack_b->prog_name = 'C';
	if (!dublicator(param->stack_a))
		error(param, argc);
	list_get_length(param);
	while (get_next_line(0, &line) > 0)
	{
		if (!line)
			break ;
		if (!action(line, param))
			error(param, argc);
		ft_strdel(&line);
	}
	final_touch(param);
}

void		final_touch(t_param *param)
{
	if (is_ascending(param->stack_a) && param->stack_b->len == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_param(param);
}
