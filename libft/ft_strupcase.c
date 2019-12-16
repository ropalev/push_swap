/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvania <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 11:49:03 by lvania            #+#    #+#             */
/*   Updated: 2019/09/03 11:49:30 by lvania           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((str[i] <= 'z') && (str[i] >= 'a'))
		{
			str[i] -= 32;
		}
		i++;
	}
	return (str);
}