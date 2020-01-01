/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvania <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:31:26 by lvania            #+#    #+#             */
/*   Updated: 2019/12/31 23:22:40 by lvania           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				awesome_function(char **s, char **line)
{
	int			pos;
	char		*temp;

	pos = 0;
	while ((*s)[pos] != '\n' && (*s)[pos] != '\0')
		pos++;
	if ((*s)[pos] == '\n')
	{
		*line = ft_strsub(*s, 0, pos);
		temp = ft_strdup(&((*s)[pos + 1]));
		free(*s);
		*s = temp;
		if ((*s)[0] == '\0')
			ft_strdel(s);
	}
	else
	{
		*line = ft_strdup(*s);
		ft_strdel(s);
	}
	return (1);
}

int				get_result(char **s, char **line, int result, int fd)
{
	if (result < 0)
		return (-1);
	else if (result == 0 && s[fd] == NULL)
		return (0);
	else
		return (awesome_function(&s[fd], line));
}

int				get_next_line(const int fd, char **line)
{
	int			result;
	static char *s[4095];
	char		buf[BUFF_SIZE + 1];
	char		*temp;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((result = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[result] = '\0';
		if (!s[fd])
			s[fd] = ft_strnew(1);
		temp = ft_strjoin(s[fd], buf);
		free(s[fd]);
		s[fd] = temp;
		if (ft_strchr(s[fd], '\n'))
			break ;
	}
	return (get_result(s, line, result, fd));
}
