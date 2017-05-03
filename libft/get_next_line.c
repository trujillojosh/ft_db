/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 14:51:04 by jtrujill          #+#    #+#             */
/*   Updated: 2017/03/20 14:52:31 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static char		*ft_until_next(char *str)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	while ((str[i] != '\n') && (str[i] != '\0'))
		i++;
	if (str[i] == '\0')
		return (str);
	else
	{
		res = ft_strnew(i + 1);
		while (j < i)
		{
			res[j] = str[j];
			j++;
		}
		res[j] = '\0';
		return (res);
	}
}

static int		ft_read_into(const int fd, char **s1)
{
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*tmp;

	if ((ret = read(fd, buf, BUFF_SIZE)) <= 0)
		return (ret);
	buf[ret] = '\0';
	tmp = ft_strdup(*s1);
	*s1 = ft_strnew((ft_strlen(tmp) + ft_strlen(buf)));
	ft_strcat(*s1, tmp);
	ft_strcat(*s1, buf);
	ft_strdel(&tmp);
	ft_strclr(buf);
	return (ret);
}

int				get_next_line(const int fd, char **line)
{
	int				ret;
	static char		*s1;
	int				i;

	i = 0;
	if (!s1)
		s1 = ft_strnew(1);
	while (ft_strchr(s1, '\n') == 0)
	{
		if ((ret = ft_read_into(fd, &s1)) <= 0)
			break ;
		i++;
	}
	if ((ret < 0) || (!line))
		return (-1);
	*line = ft_until_next(s1);
	s1 = ft_strchr(s1, '\n');
	if (s1)
	{
		s1++;
		i++;
	}
	if (((ret == 0) && (i == 0)) && (ft_strlen(*line) <= 0))
		return (0);
	return (1);
}
