/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvania <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 15:20:12 by lvania            #+#    #+#             */
/*   Updated: 2020/02/07 19:30:32 by lvania           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			put_string(char *str, int *cnt, t_param *param)
{
	char	**argv;
	char	**start;

	argv = ft_strsplit(str, ' ');
	start = argv;
	while (*argv)
	{
		if (!valid_numeric(*argv))
		{
			free_split_str(&start);
			return (0);
		}
		param->nbrs[(*cnt)++] = ft_atoi(*argv++);
	}
	free_split_str(&start);
	return (1);
}

void		put_nbrs(int argc, char **argv, t_param *param)
{
	int		i;
	int		cnt;

	cnt = 0;
	i = 1;
	while (i < argc)
	{
		if (valid_numeric(argv[i]))
		{
			param->nbrs[cnt++] = ft_atoi(argv[i]);
			i++;
		}
		else if (put_string(argv[i], &cnt, param))
			i++;
	}
}
