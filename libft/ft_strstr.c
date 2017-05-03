/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 18:47:56 by jtrujill          #+#    #+#             */
/*   Updated: 2016/12/01 13:05:29 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strstr(const char *s, const char *tf)
{
	char	*str;
	char	*to_find;
	int		i;
	int		a;

	i = 0;
	a = 0;
	str = (char *)s;
	to_find = (char *)tf;
	if (to_find[i] == '\0' || ft_strcmp(s, tf) == 0)
		return (str);
	while (str[i] != '\0')
	{
		while (str[i + a] == to_find[a])
		{
			if (to_find[a + 1] == '\0')
				return (&str[i]);
			a++;
		}
		i++;
		a = 0;
	}
	return (NULL);
}
