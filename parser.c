/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvania <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 15:20:12 by lvania            #+#    #+#             */
/*   Updated: 2020/02/07 19:29:53 by lvania           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			valid_numeric(char *str)
{
	if (str[0] == '-')
	{
		if (ft_strlen(str) > 11)
			return (0);
		if (ft_str_is_numeric(str + 1))
		{
			if ((ft_strlen(str + 1) == 10 && ft_strcmp("-2147483648", str) < 0))
			{
				return (0);
			}
			return (1);
		}
	}
	else if (ft_str_is_numeric(str))
	{
		if (ft_strlen(str) > 10)
			return (0);
		else if ((ft_strlen(str) == 10 && ft_strcmp("2147483647", str) < 0))
			return (0);
		return (1);
	}
	return (0);
}

int			valid_string(char *str, int *cnt)
{
	char	**argv;
	char	**start;

	argv = ft_strsplit(str, ' ');
	start = argv;
	while (*argv)
	{
		if (!valid_numeric(*argv++))
		{
			free_split_str(&start);
			return (0);
		}
		(*cnt)++;
	}
	free_split_str(&start);
	return (1);
}

int			validator(int argc, char **argv)
{
	int		i;
	int		cnt;

	cnt = 0;
	i = 1;
	while (i < argc)
	{
		if (valid_numeric(argv[i]))
		{
			i++;
			cnt++;
		}
		else if (valid_string(argv[i], &cnt))
			i++;
		else
		{
			return (0);
		}
	}
	return (cnt);
}

int			dublicator(t_stack *stack)
{
	t_cell	*ptr;
	t_cell	*iter;

	ptr = stack->head;
	while (ptr->next)
	{
		iter = ptr->next;
		while (iter)
		{
			if (iter->nbr == ptr->nbr)
				return (0);
			iter = iter->next;
		}
		ptr = ptr->next;
	}
	return (1);
}
